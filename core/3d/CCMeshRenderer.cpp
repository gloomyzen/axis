/****************************************************************************
 Copyright (c) 2014-2016 Chukong Technologies Inc.
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 https://axis-project.github.io/

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "3d/CCMeshRenderer.h"
#include "3d/CCObjLoader.h"
#include "3d/CCMeshSkin.h"
#include "3d/CCBundle3D.h"
#include "3d/CCMeshMaterial.h"
#include "3d/CCAttachNode.h"
#include "3d/CCMesh.h"

#include "base/CCDirector.h"
#include "base/CCAsyncTaskPool.h"
#include "base/ccUTF8.h"
#include "base/ccUtils.h"
#include "2d/CCLight.h"
#include "2d/CCCamera.h"
#include "base/ccMacros.h"
#include "platform/CCPlatformMacros.h"
#include "platform/CCFileUtils.h"
#include "renderer/CCTextureCache.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCMaterial.h"
#include "renderer/CCTechnique.h"
#include "renderer/CCPass.h"

NS_AX_BEGIN

static MeshMaterial* getMeshRendererMaterialForAttribs(MeshVertexData* meshVertexData, bool usesLight);

MeshRenderer* MeshRenderer::create()
{
    auto mesh = new MeshRenderer();
    if (mesh->init())
    {
        mesh->autorelease();
        return mesh;
    }
    CC_SAFE_DELETE(mesh);
    return nullptr;
}

MeshRenderer* MeshRenderer::create(std::string_view modelPath)
{
    CCASSERT(modelPath.length() >= 4, "Invalid filename.");

    auto mesh = new MeshRenderer();
    if (mesh->initWithFile(modelPath))
    {
        mesh->_contentSize = mesh->getBoundingBox().size;
        mesh->autorelease();
        return mesh;
    }
    CC_SAFE_DELETE(mesh);
    return nullptr;
}
MeshRenderer* MeshRenderer::create(std::string_view modelPath, std::string_view texturePath)
{
    auto mesh = create(modelPath);
    if (mesh)
    {
        mesh->setTexture(texturePath);
    }

    return mesh;
}

void MeshRenderer::createAsync(std::string_view modelPath,
                           const std::function<void(MeshRenderer*, void*)>& callback,
                           void* callbackparam)
{
    createAsync(modelPath, "", callback, callbackparam);
}

void MeshRenderer::createAsync(std::string_view modelPath,
                           std::string_view texturePath,
                           const std::function<void(MeshRenderer*, void*)>& callback,
                           void* callbackparam)
{
    MeshRenderer* mesh = new MeshRenderer();
    if (mesh->loadFromCache(modelPath))
    {
        mesh->autorelease();
        if (!texturePath.empty())
            mesh->setTexture(texturePath);
        callback(mesh, callbackparam);
        return;
    }

    mesh->_asyncLoadParam.afterLoadCallback   = callback;
    mesh->_asyncLoadParam.texPath             = texturePath;
    mesh->_asyncLoadParam.modelPath           = modelPath;
    mesh->_asyncLoadParam.modelFullPath       = FileUtils::getInstance()->fullPathForFilename(modelPath);
    mesh->_asyncLoadParam.callbackParam       = callbackparam;
    mesh->_asyncLoadParam.materialdatas       = new MaterialDatas();
    mesh->_asyncLoadParam.meshdatas           = new MeshDatas();
    mesh->_asyncLoadParam.nodeDatas           = new NodeDatas();
    AsyncTaskPool::getInstance()->enqueue(
        AsyncTaskPool::TaskType::TASK_IO, CC_CALLBACK_1(MeshRenderer::afterAsyncLoad, mesh),
        (void*)(&mesh->_asyncLoadParam), [mesh]() {
            mesh->_asyncLoadParam.result =
                mesh->loadFromFile(mesh->_asyncLoadParam.modelFullPath, mesh->_asyncLoadParam.nodeDatas,
                                     mesh->_asyncLoadParam.meshdatas, mesh->_asyncLoadParam.materialdatas);
        });
}

void MeshRenderer::afterAsyncLoad(void* param)
{
    MeshRenderer::AsyncLoadParam* asyncParam = (MeshRenderer::AsyncLoadParam*)param;
    autorelease();
    if (asyncParam)
    {
        if (asyncParam->result)
        {
            _meshes.clear();
            _meshVertexDatas.clear();
            CC_SAFE_RELEASE_NULL(_skeleton);
            removeAllAttachNode();

            // create in the main thread
            auto& meshdatas     = asyncParam->meshdatas;
            auto& materialdatas = asyncParam->materialdatas;
            auto& nodeDatas     = asyncParam->nodeDatas;
            if (initFrom(*nodeDatas, *meshdatas, *materialdatas))
            {
                auto meshdata = MeshRendererCache::getInstance()->getMeshData(asyncParam->modelPath);
                if (meshdata == nullptr)
                {
                    // add to cache
                    auto data             = new MeshRendererCache::MeshRendererData();
                    data->materialdatas   = materialdatas;
                    data->nodedatas       = nodeDatas;
                    data->meshVertexDatas = _meshVertexDatas;
                    for (const auto mesh : _meshes)
                    {
                        data->programStates.pushBack(mesh->getProgramState());
                    }

                    MeshRendererCache::getInstance()->addMeshRendererData(asyncParam->modelPath, data);

                    CC_SAFE_DELETE(meshdatas);
                    materialdatas = nullptr;
                    nodeDatas     = nullptr;
                }
            }
            CC_SAFE_DELETE(meshdatas);
            CC_SAFE_DELETE(materialdatas);
            CC_SAFE_DELETE(nodeDatas);

            if (asyncParam->texPath != "")
            {
                setTexture(asyncParam->texPath);
            }
        }
        else
        {
            CCLOG("file load failed: %s\n", asyncParam->modelPath.c_str());
        }
        asyncParam->afterLoadCallback(this, asyncParam->callbackParam);
    }
}

AABB MeshRenderer::getAABBRecursivelyImp(Node* node)
{
    AABB aabb;
    for (auto iter : node->getChildren())
    {
        aabb.merge(getAABBRecursivelyImp(iter));
    }

    MeshRenderer* meshRenderer = dynamic_cast<MeshRenderer*>(node);
    if (meshRenderer)
        aabb.merge(meshRenderer->getAABB());

    return aabb;
}

bool MeshRenderer::loadFromCache(std::string_view path)
{
    auto meshdata = MeshRendererCache::getInstance()->getMeshData(path);
    if (meshdata)
    {
        for (auto it : meshdata->meshVertexDatas)
        {
            _meshVertexDatas.pushBack(it);
        }
        _skeleton = Skeleton3D::create(meshdata->nodedatas->skeleton);
        CC_SAFE_RETAIN(_skeleton);

        const bool singleMesh = (meshdata->nodedatas->nodes.size() == 1);
        for (const auto& it : meshdata->nodedatas->nodes)
        {
            if (it)
            {
                createNode(it, this, *(meshdata->materialdatas), singleMesh);
            }
        }

        for (const auto& it : meshdata->nodedatas->skeleton)
        {
            if (it)
            {
                createAttachMeshRendererNode(it, *(meshdata->materialdatas));
            }
        }

        for (ssize_t i = 0, size = _meshes.size(); i < size; ++i)
        {
            // cloning is needed in order to have one state per mesh
            auto glstate = meshdata->programStates.at(i);
            _meshes.at(i)->setProgramState(glstate->clone());
        }
        return true;
    }

    return false;
}

bool MeshRenderer::loadFromFile(std::string_view path,
                            NodeDatas* nodedatas,
                            MeshDatas* meshdatas,
                            MaterialDatas* materialdatas)
{
    std::string fullPath = FileUtils::getInstance()->fullPathForFilename(path);

    std::string ext = FileUtils::getInstance()->getFileExtension(path);
    if (ext == ".obj")
    {
        return Bundle3D::loadObj(*meshdatas, *materialdatas, *nodedatas, fullPath);
    }
    else if (ext == ".c3b" || ext == ".c3t")
    {
        // load from .c3b or .c3t
        auto bundle = Bundle3D::createBundle();
        if (!bundle->load(fullPath))
        {
            Bundle3D::destroyBundle(bundle);
            return false;
        }

        auto ret =
            bundle->loadMeshDatas(*meshdatas) && bundle->loadMaterials(*materialdatas) && bundle->loadNodes(*nodedatas);
        Bundle3D::destroyBundle(bundle);

        return ret;
    }
    return false;
}

MeshRenderer::MeshRenderer()
    : _skeleton(nullptr)
    , _blend(BlendFunc::ALPHA_NON_PREMULTIPLIED)
    , _aabbDirty(true)
    , _lightMask(-1)
    , _shaderUsingLight(false)
    , _forceDepthWrite(false)
    , _usingAutogeneratedGLProgram(true)
{}

MeshRenderer::~MeshRenderer()
{
    _meshes.clear();
    _meshVertexDatas.clear();
    CC_SAFE_RELEASE_NULL(_skeleton);
    removeAllAttachNode();
}

bool MeshRenderer::init()
{
    if (Node::init())
    {
        return true;
    }
    return false;
}

bool MeshRenderer::initWithFile(std::string_view path)
{
    _aabbDirty = true;
    _meshes.clear();
    _meshVertexDatas.clear();
    CC_SAFE_RELEASE_NULL(_skeleton);
    removeAllAttachNode();

    if (loadFromCache(path))
        return true;

    MeshDatas* meshdatas         = new MeshDatas();
    MaterialDatas* materialdatas = new MaterialDatas();
    NodeDatas* nodeDatas         = new NodeDatas();
    if (loadFromFile(path, nodeDatas, meshdatas, materialdatas))
    {
        if (initFrom(*nodeDatas, *meshdatas, *materialdatas))
        {
            // add to cache
            auto data             = new MeshRendererCache::MeshRendererData();
            data->materialdatas   = materialdatas;
            data->nodedatas       = nodeDatas;
            data->meshVertexDatas = _meshVertexDatas;
            for (const auto mesh : _meshes)
            {
                data->programStates.pushBack(mesh->getProgramState());
            }

            MeshRendererCache::getInstance()->addMeshRendererData(path, data);
            CC_SAFE_DELETE(meshdatas);
            _contentSize = getBoundingBox().size;
            return true;
        }
    }
    CC_SAFE_DELETE(meshdatas);
    CC_SAFE_DELETE(materialdatas);
    CC_SAFE_DELETE(nodeDatas);

    return false;
}

bool MeshRenderer::initFrom(const NodeDatas& nodeDatas, const MeshDatas& meshdatas, const MaterialDatas& materialdatas)
{
    for (const auto& it : meshdatas.meshDatas)
    {
        if (it)
        {
            //            Mesh* mesh = Mesh::create(*it);
            //            _meshes.pushBack(mesh);
            auto meshvertex = MeshVertexData::create(*it);
            _meshVertexDatas.pushBack(meshvertex);
        }
    }
    _skeleton = Skeleton3D::create(nodeDatas.skeleton);
    CC_SAFE_RETAIN(_skeleton);

    auto size = nodeDatas.nodes.size();
    for (const auto& it : nodeDatas.nodes)
    {
        if (it)
        {
            createNode(it, this, materialdatas, size == 1);
        }
    }
    for (const auto& it : nodeDatas.skeleton)
    {
        if (it)
        {
            createAttachMeshRendererNode(it, materialdatas);
        }
    }
    genMaterial();

    return true;
}

MeshRenderer* MeshRenderer::createMeshRendererNode(NodeData* nodedata, ModelData* modeldata, const MaterialDatas& materialdatas)
{
    auto meshRenderer = new MeshRenderer();

    meshRenderer->setName(nodedata->id);
    auto mesh = Mesh::create(nodedata->id, getMeshIndexData(modeldata->subMeshId));

    if (_skeleton && modeldata->bones.size())
    {
        auto skin = MeshSkin::create(_skeleton, modeldata->bones, modeldata->invBindPose);
        mesh->setSkin(skin);
    }

    if (modeldata->materialId == "" && materialdatas.materials.size())
    {
        const NTextureData* textureData = materialdatas.materials[0].getTextureData(NTextureData::Usage::Diffuse);
        mesh->setTexture(textureData->filename);
    }
    else
    {
        const NMaterialData* materialData = materialdatas.getMaterialData(modeldata->materialId);
        if (materialData)
        {
            const NTextureData* textureData = materialData->getTextureData(NTextureData::Usage::Diffuse);
            if (textureData)
            {
                mesh->setTexture(textureData->filename);
                auto tex = mesh->getTexture();
                if (tex)
                {
                    Texture2D::TexParams texParams;
                    texParams.minFilter    = backend::SamplerFilter::LINEAR;
                    texParams.magFilter    = backend::SamplerFilter::LINEAR;
                    texParams.sAddressMode = textureData->wrapS;
                    texParams.tAddressMode = textureData->wrapT;
                    tex->setTexParameters(texParams);
                    mesh->_isTransparent = (materialData->getTextureData(NTextureData::Usage::Transparency) != nullptr);
                }
            }
            textureData = materialData->getTextureData(NTextureData::Usage::Normal);
            if (textureData)
            {
                auto tex = _director->getTextureCache()->addImage(textureData->filename);
                if (tex)
                {
                    Texture2D::TexParams texParams;
                    texParams.minFilter    = backend::SamplerFilter::LINEAR;
                    texParams.magFilter    = backend::SamplerFilter::LINEAR;
                    texParams.sAddressMode = textureData->wrapS;
                    texParams.tAddressMode = textureData->wrapT;
                    tex->setTexParameters(texParams);
                }
                mesh->setTexture(tex, NTextureData::Usage::Normal);
            }
        }
    }

    // set locale transform
    Vec3 pos;
    Quaternion qua;
    Vec3 scale;
    nodedata->transform.decompose(&scale, &qua, &pos);
    meshRenderer->setPosition3D(pos);
    meshRenderer->setRotationQuat(qua);
    meshRenderer->setScaleX(scale.x);
    meshRenderer->setScaleY(scale.y);
    meshRenderer->setScaleZ(scale.z);

    meshRenderer->addMesh(mesh);
    meshRenderer->autorelease();
    meshRenderer->genMaterial();

    return meshRenderer;
}
void MeshRenderer::createAttachMeshRendererNode(NodeData* nodedata, const MaterialDatas& materialdatas)
{
    for (const auto& it : nodedata->modelNodeDatas)
    {
        if (it && getAttachNode(nodedata->id))
        {
            auto mesh = createMeshRendererNode(nodedata, it, materialdatas);
            if (mesh)
            {
                getAttachNode(nodedata->id)->addChild(mesh);
            }
        }
    }
    for (const auto& it : nodedata->children)
    {
        createAttachMeshRendererNode(it, materialdatas);
    }
}

void MeshRenderer::setMaterial(Material* material)
{
    setMaterial(material, -1);
}

void MeshRenderer::setMaterial(Material* material, int meshIndex)
{
    CCASSERT(material, "Invalid Material");
    CCASSERT(meshIndex == -1 || (meshIndex >= 0 && meshIndex < _meshes.size()), "Invalid meshIndex.");

    if (meshIndex == -1)
    {
        for (ssize_t i = 0, size = _meshes.size(); i < size; ++i)
        {
            _meshes.at(i)->setMaterial(i == 0 ? material : material->clone());
        }
    }
    else
    {
        auto mesh = _meshes.at(meshIndex);
        mesh->setMaterial(material);
    }

    _usingAutogeneratedGLProgram = false;
}

Material* MeshRenderer::getMaterial(int meshIndex) const
{
    CCASSERT(meshIndex >= 0 && meshIndex < _meshes.size(), "Invalid meshIndex.");
    return _meshes.at(meshIndex)->getMaterial();
}

void MeshRenderer::genMaterial(bool useLight)
{
    _shaderUsingLight = useLight;

    std::unordered_map<const MeshVertexData*, MeshMaterial*> materials;
    for (auto meshVertexData : _meshVertexDatas)
    {
        auto material = getMeshRendererMaterialForAttribs(meshVertexData, useLight);
        CCASSERT(material, "material should cannot be null.");
        materials[meshVertexData] = material;
    }

    for (auto& mesh : _meshes)
    {
        auto material = materials[mesh->getMeshIndexData()->getMeshVertexData()];
        // keep original state block if exist
        auto oldmaterial = mesh->getMaterial();
        if (oldmaterial)
        {
            material->setStateBlock(oldmaterial->getStateBlock());
        }

        if (material->getReferenceCount() == 1)
            mesh->setMaterial(material);
        else
            mesh->setMaterial(material->clone());
    }
}

void MeshRenderer::createNode(NodeData* nodedata, Node* root, const MaterialDatas& materialdatas, bool singleMesh)
{
    Node* node = nullptr;
    for (const auto& it : nodedata->modelNodeDatas)
    {
        if (it)
        {
            if (!it->bones.empty() || singleMesh)
            {
                if (singleMesh && root != nullptr)
                    root->setName(nodedata->id);
                auto mesh = Mesh::create(nodedata->id, getMeshIndexData(it->subMeshId));
                if (mesh)
                {
                    _meshes.pushBack(mesh);
                    if (_skeleton && it->bones.size())
                    {
                        auto skin = MeshSkin::create(_skeleton, it->bones, it->invBindPose);
                        mesh->setSkin(skin);
                    }
                    mesh->_visibleChanged = std::bind(&MeshRenderer::onAABBDirty, this);

                    if (it->materialId == "" && materialdatas.materials.size())
                    {
                        const NTextureData* textureData =
                            materialdatas.materials[0].getTextureData(NTextureData::Usage::Diffuse);
                        mesh->setTexture(textureData->filename);
                    }
                    else
                    {
                        const NMaterialData* materialData = materialdatas.getMaterialData(it->materialId);
                        if (materialData)
                        {
                            const NTextureData* textureData =
                                materialData->getTextureData(NTextureData::Usage::Diffuse);
                            if (textureData)
                            {
                                mesh->setTexture(textureData->filename);
                                auto tex = mesh->getTexture();
                                if (tex)
                                {
                                    Texture2D::TexParams texParams;
                                    texParams.minFilter    = backend::SamplerFilter::LINEAR;
                                    texParams.magFilter    = backend::SamplerFilter::LINEAR;
                                    texParams.sAddressMode = textureData->wrapS;
                                    texParams.tAddressMode = textureData->wrapT;
                                    tex->setTexParameters(texParams);
                                    mesh->_isTransparent =
                                        (materialData->getTextureData(NTextureData::Usage::Transparency) != nullptr);
                                }
                            }
                            textureData = materialData->getTextureData(NTextureData::Usage::Normal);
                            if (textureData)
                            {
                                auto tex = _director->getTextureCache()->addImage(textureData->filename);
                                if (tex)
                                {
                                    Texture2D::TexParams texParams;
                                    texParams.minFilter    = backend::SamplerFilter::LINEAR;
                                    texParams.magFilter    = backend::SamplerFilter::LINEAR;
                                    texParams.sAddressMode = textureData->wrapS;
                                    texParams.tAddressMode = textureData->wrapT;
                                    tex->setTexParameters(texParams);
                                }
                                mesh->setTexture(tex, NTextureData::Usage::Normal);
                            }
                        }
                    }

                    Vec3 pos;
                    Quaternion qua;
                    Vec3 scale;
                    nodedata->transform.decompose(&scale, &qua, &pos);
                    setPosition3D(pos);
                    setRotationQuat(qua);
                    setScaleX(scale.x);
                    setScaleY(scale.y);
                    setScaleZ(scale.z);

                    node = this;
                }
            }
            else
            {
                auto mesh = createMeshRendererNode(nodedata, it, materialdatas);
                if (mesh)
                {
                    if (root)
                    {
                        root->addChild(mesh);
                    }
                }
                node = mesh;
            }
        }
    }
    if (nodedata->modelNodeDatas.size() == 0)
    {
        node = Node::create();
        if (node)
        {
            node->setName(nodedata->id);

            // set locale transform
            Vec3 pos;
            Quaternion qua;
            Vec3 scale;
            nodedata->transform.decompose(&scale, &qua, &pos);
            node->setPosition3D(pos);
            node->setRotationQuat(qua);
            node->setScaleX(scale.x);
            node->setScaleY(scale.y);
            node->setScaleZ(scale.z);

            if (root)
            {
                root->addChild(node);
            }
        }
    }

    auto size = nodedata->children.size();
    for (const auto& it : nodedata->children)
    {
        createNode(it, node, materialdatas, size == 1);
    }
}

MeshIndexData* MeshRenderer::getMeshIndexData(std::string_view indexId) const
{
    for (auto it : _meshVertexDatas)
    {
        auto index = it->getMeshIndexDataById(indexId);
        if (index)
            return index;
    }
    return nullptr;
}

void MeshRenderer::addMesh(Mesh* mesh)
{
    auto meshVertex = mesh->getMeshIndexData()->_vertexData;
    _meshVertexDatas.pushBack(meshVertex);
    _meshes.pushBack(mesh);
}

void MeshRenderer::setTexture(std::string_view texFile)
{
    auto tex = _director->getTextureCache()->addImage(texFile);
    setTexture(tex);
}

void MeshRenderer::setTexture(Texture2D* texture)
{
    for (auto mesh : _meshes)
    {
        mesh->setTexture(texture);
    }
}
AttachNode* MeshRenderer::getAttachNode(std::string_view boneName)
{
    auto it = _attachments.find(boneName);
    if (it != _attachments.end())
        return it->second;

    if (_skeleton)
    {
        auto bone = _skeleton->getBoneByName(boneName);
        if (bone)
        {
            auto attachNode = AttachNode::create(bone);
            addChild(attachNode);
            _attachments.emplace(boneName, attachNode);  // _attachments[boneName] = attachNode;
            return attachNode;
        }
    }

    return nullptr;
}

void MeshRenderer::removeAttachNode(std::string_view boneName)
{
    auto it = _attachments.find(boneName);
    if (it != _attachments.end())
    {
        removeChild(it->second);
        _attachments.erase(it);
    }
}

void MeshRenderer::removeAllAttachNode()
{
    for (auto& it : _attachments)
    {
        removeChild(it.second);
    }
    _attachments.clear();
}

void MeshRenderer::visit(axis::Renderer* renderer, const axis::Mat4& parentTransform, uint32_t parentFlags)
{
    // quick return if not visible. children won't be drawn.
    if (!_visible)
    {
        return;
    }

    uint32_t flags = processParentFlags(parentTransform, parentFlags);
    flags |= FLAGS_RENDER_AS_3D;

    //
    _director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    _director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, _modelViewTransform);

    bool visibleByCamera = isVisitableByVisitingCamera();

    int i = 0;

    if (!_children.empty())
    {
        sortAllChildren();
        // draw children zOrder < 0
        for (auto size = _children.size(); i < size; i++)
        {
            auto node = _children.at(i);

            if (node && node->getLocalZOrder() < 0)
                node->visit(renderer, _modelViewTransform, flags);
            else
                break;
        }
        // self draw
        if (visibleByCamera)
            this->draw(renderer, _modelViewTransform, flags);

        for (auto it = _children.cbegin() + i, itCend = _children.cend(); it != itCend; ++it)
            (*it)->visit(renderer, _modelViewTransform, flags);
    }
    else if (visibleByCamera)
    {
        this->draw(renderer, _modelViewTransform, flags);
    }

    _director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}

void MeshRenderer::draw(Renderer* renderer, const Mat4& transform, uint32_t flags)
{
#if CC_USE_CULLING
    // TODO new-renderer: interface isVisibleInFrustum removal
    //  camera clipping
//    if(_children.empty() && Camera::getVisitingCamera() &&
//    !Camera::getVisitingCamera()->isVisibleInFrustum(&getAABB()))
//        return;
#endif

    if (_skeleton)
        _skeleton->updateBoneMatrix();

    Color4F color(getDisplayedColor());
    color.a = getDisplayedOpacity() / 255.0f;

    // check light and determine the shader used
    const auto& scene = Director::getInstance()->getRunningScene();

    // Don't override GLProgramState if using manually set Material
    if (_usingAutogeneratedGLProgram && scene)
    {
        const auto lights = scene->getLights();
        bool usingLight   = false;
        for (const auto light : lights)
        {
            usingLight = light->isEnabled() && ((static_cast<unsigned int>(light->getLightFlag()) & _lightMask) > 0);
            if (usingLight)
                break;
        }
        if (usingLight != _shaderUsingLight)
        {
            genMaterial(usingLight);
        }
    }

    for (auto mesh : _meshes)
    {
        mesh->draw(renderer, _globalZOrder, transform, flags, _lightMask, Vec4(color.r, color.g, color.b, color.a),
                   _forceDepthWrite);
    }
}

bool MeshRenderer::setProgramState(backend::ProgramState* programState, bool needsRetain)
{
    if (Node::setProgramState(programState, needsRetain))
    {
        for (auto state : _meshes)
        {
            state->setProgramState(programState);
        }
        return true;
    }
    return false;
}

void MeshRenderer::setBlendFunc(const BlendFunc& blendFunc)
{
    if (_blend.src != blendFunc.src || _blend.dst != blendFunc.dst)
    {
        _blend = blendFunc;
        for (auto mesh : _meshes)
        {
            mesh->setBlendFunc(blendFunc);
        }
    }
}

const BlendFunc& MeshRenderer::getBlendFunc() const
{
    return _blend;
}

AABB MeshRenderer::getAABBRecursively()
{
    return getAABBRecursivelyImp(this);
}

const AABB& MeshRenderer::getAABB() const
{
    Mat4 nodeToWorldTransform(getNodeToWorldTransform());

    // If nodeToWorldTransform matrix isn't changed, we don't need to transform aabb.
    if (memcmp(_nodeToWorldTransform.m, nodeToWorldTransform.m, sizeof(Mat4)) == 0 && !_aabbDirty)
    {
        return _aabb;
    }
    else
    {
        _aabb.reset();
        if (_meshes.size())
        {
            Mat4 transform(nodeToWorldTransform);
            for (const auto& it : _meshes)
            {
                if (it->isVisible())
                    _aabb.merge(it->getAABB());
            }

            _aabb.transform(transform);
            _nodeToWorldTransform = nodeToWorldTransform;
            _aabbDirty            = false;
        }
    }

    return _aabb;
}

Action* MeshRenderer::runAction(Action* action)
{
    setForceDepthWrite(true);
    return Node::runAction(action);
}

Rect MeshRenderer::getBoundingBox() const
{
    AABB aabb = getAABB();
    Rect ret(aabb._min.x, aabb._min.y, (aabb._max.x - aabb._min.x), (aabb._max.y - aabb._min.y));
    return ret;
}

void MeshRenderer::setCullFace(CullFaceSide side)
{
    for (auto& it : _meshes)
    {
        it->getMaterial()->getStateBlock().setCullFaceSide(side);
    }
}

void MeshRenderer::setCullFaceEnabled(bool enable)
{
    for (auto& it : _meshes)
    {
        it->getMaterial()->getStateBlock().setCullFace(enable);
    }
}

Mesh* MeshRenderer::getMeshByIndex(int index) const
{
    CCASSERT(index < _meshes.size(), "Invalid index.");
    return _meshes.at(index);
}

/**get Mesh by Name */
Mesh* MeshRenderer::getMeshByName(std::string_view name) const
{
    for (const auto& it : _meshes)
    {
        if (it->getName() == name)
            return it;
    }
    return nullptr;
}

std::vector<Mesh*> MeshRenderer::getMeshArrayByName(std::string_view name) const
{
    std::vector<Mesh*> meshes;
    for (const auto& it : _meshes)
    {
        if (it->getName() == name)
            meshes.push_back(it);
    }
    return meshes;
}

Mesh* MeshRenderer::getMesh() const
{
    if (_meshes.empty())
    {
        return nullptr;
    }
    return _meshes.at(0);
}

void MeshRenderer::setForce2DQueue(bool force2D)
{
    for (const auto& mesh : _meshes)
    {
        mesh->setForce2DQueue(force2D);
    }
}

///////////////////////////////////////////////////////////////////////////////////
MeshRendererCache* MeshRendererCache::_cacheInstance = nullptr;
MeshRendererCache* MeshRendererCache::getInstance()
{
    if (_cacheInstance == nullptr)
        _cacheInstance = new MeshRendererCache();
    return _cacheInstance;
}
void MeshRendererCache::destroyInstance()
{
    if (_cacheInstance)
    {
        delete _cacheInstance;
        _cacheInstance = nullptr;
    }
}

MeshRendererCache::MeshRendererData* MeshRendererCache::getMeshData(std::string_view key) const
{
    auto it = _meshDatas.find(key);
    if (it != _meshDatas.end())
        return it->second;
    return nullptr;
}

bool MeshRendererCache::addMeshRendererData(std::string_view key, MeshRendererCache::MeshRendererData* meshdata)
{
    auto it = _meshDatas.find(key);
    if (it == _meshDatas.end())
    {
        _meshDatas.emplace(key, meshdata);
        return true;
    }
    return false;
}

void MeshRendererCache::removeMeshRendererData(std::string_view key)
{
    auto it = _meshDatas.find(key);
    if (it != _meshDatas.end())
    {
        delete it->second;
        _meshDatas.erase(it);
    }
}

void MeshRendererCache::removeAllMeshRendererData()
{
    for (auto& it : _meshDatas)
    {
        delete it.second;
    }
    _meshDatas.clear();
}

MeshRendererCache::MeshRendererCache() {}
MeshRendererCache::~MeshRendererCache()
{
    removeAllMeshRendererData();
}

static MeshMaterial* getMeshRendererMaterialForAttribs(MeshVertexData* meshVertexData, bool usesLight)
{
    bool textured = meshVertexData->hasVertexAttrib(shaderinfos::VertexKey::VERTEX_ATTRIB_TEX_COORD);
    bool hasSkin  = meshVertexData->hasVertexAttrib(shaderinfos::VertexKey::VERTEX_ATTRIB_BLEND_INDEX) &&
                   meshVertexData->hasVertexAttrib(shaderinfos::VertexKey::VERTEX_ATTRIB_BLEND_WEIGHT);
    bool hasNormal       = meshVertexData->hasVertexAttrib(shaderinfos::VertexKey::VERTEX_ATTRIB_NORMAL);
    bool hasTangentSpace = meshVertexData->hasVertexAttrib(shaderinfos::VertexKey::VERTEX_ATTRIB_TANGENT) &&
                           meshVertexData->hasVertexAttrib(shaderinfos::VertexKey::VERTEX_ATTRIB_BINORMAL);
    MeshMaterial::MaterialType type;
    if (textured)
    {
        if (hasTangentSpace)
        {
            type = hasNormal && usesLight ? MeshMaterial::MaterialType::BUMPED_DIFFUSE
                                          : MeshMaterial::MaterialType::UNLIT;
        }
        else
        {
            type = hasNormal && usesLight ? MeshMaterial::MaterialType::DIFFUSE
                                          : MeshMaterial::MaterialType::UNLIT;
        }
    }
    else
    {
        type = hasNormal && usesLight ? MeshMaterial::MaterialType::DIFFUSE_NOTEX
                                      : MeshMaterial::MaterialType::UNLIT_NOTEX;
    }

    return MeshMaterial::createBuiltInMaterial(type, hasSkin);
}

NS_AX_END
