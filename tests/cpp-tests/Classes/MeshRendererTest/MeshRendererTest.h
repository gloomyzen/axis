/****************************************************************************
 Copyright (c) 2013 cocos2d-x.org
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
#pragma once

#include "BaseTest.h"
#include "renderer/backend/ProgramState.h"
#include <string>

NS_AX_BEGIN
class Animate3D;
class MeshRenderer;
class Delay;
class Ray;
class DrawNode3D;
class GLProgramState;
class MotionStreak3D;
NS_AX_END  // namespace axis

DEFINE_TEST_SUITE(MeshRendererTests);

class MeshRendererTestDemo : public TestCase
{
public:
    // overrides
    virtual std::string title() const override;

    virtual ~MeshRendererTestDemo();
};

class MeshRendererForceDepthTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(MeshRendererForceDepthTest);
    MeshRendererForceDepthTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class MeshRendererEmptyTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(MeshRendererEmptyTest);
    MeshRendererEmptyTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class MeshRendererBasicTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(MeshRendererBasicTest);
    MeshRendererBasicTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

    void addNewMeshWithCoords(axis::Vec2 p);
    void onTouchesEnded(const std::vector<axis::Touch*>& touches, axis::Event* event);
};

class MeshRendererUVAnimationTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(MeshRendererUVAnimationTest);
    MeshRendererUVAnimationTest();
    virtual ~MeshRendererUVAnimationTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

protected:
    void cylinderUpdate(float dt);

    float _cylinder_texture_offset;
    float _shining_duration;
    axis::backend::ProgramState* _state = nullptr;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    axis::EventListenerCustom* _backToForegroundListener;
#endif
};

class MeshRendererFakeShadowTest : public MeshRendererTestDemo
{
public:
    enum State
    {
        State_None   = 0,
        State_Idle   = 0x01,
        State_Move   = 0x02,
        State_Rotate = 0x04
    };
    CREATE_FUNC(MeshRendererFakeShadowTest);
    MeshRendererFakeShadowTest();
    virtual ~MeshRendererFakeShadowTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    void Move(axis::Ref* sender, int value);
    void updateCamera(float fDelta);
    void move3D(float elapsedTime);
    void updateState(float elapsedTime);
    bool isState(unsigned int state, unsigned int bit) const;
    void onTouchesBegan(const std::vector<axis::Touch*>& touches, axis::Event* event);
    void onTouchesMoved(const std::vector<axis::Touch*>& touches, axis::Event* event);
    void onTouchesEnded(const std::vector<axis::Touch*>& touches, axis::Event* event);

private:
    axis::Camera* _camera;
    axis::Vec3 _targetPos;
    unsigned int _curState;
    axis::MeshRenderer* _plane;
    axis::MeshRenderer* _orc;
    axis::backend::ProgramState* _state = nullptr;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    axis::EventListenerCustom* _backToForegroundListener;
#endif
};

class MeshRendererLightMapTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(MeshRendererLightMapTest);
    MeshRendererLightMapTest();
    virtual ~MeshRendererLightMapTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    void onTouchesMoved(const std::vector<axis::Touch*>& touches, axis::Event* event);

private:
    axis::Camera* _camera;
};

class MeshRendererBasicToonShaderTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(MeshRendererBasicToonShaderTest);
    MeshRendererBasicToonShaderTest();
    virtual ~MeshRendererBasicToonShaderTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

protected:
    axis::backend::ProgramState* _state;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    axis::EventListenerCustom* _backToForegroundListener;
#endif
};

class MeshRendererHitTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(MeshRendererHitTest);
    MeshRendererHitTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class MeshRendererEffectTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(MeshRendererEffectTest);
    MeshRendererEffectTest();
    virtual ~MeshRendererEffectTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

    void addNewMeshWithCoords(axis::Vec2 p);

    void onTouchesEnded(const std::vector<axis::Touch*>& touches, axis::Event* event);

protected:
    std::vector<axis::MeshRenderer*> _meshes;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    axis::EventListenerCustom* _backToForegroundListener;
#endif
};

class AsyncLoadMeshRendererTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(AsyncLoadMeshRendererTest);
    AsyncLoadMeshRendererTest();
    virtual ~AsyncLoadMeshRendererTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

    void menuCallback_asyncLoadMesh(axis::Ref* sender);

    void asyncLoad_Callback(axis::MeshRenderer* mesh, void* param);

protected:
    std::vector<std::string> _paths;  // model paths to be loaded
};

class MeshRendererWithSkinTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(MeshRendererWithSkinTest);
    MeshRendererWithSkinTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

    void addNewMeshWithCoords(axis::Vec2 p);

    void switchAnimationQualityCallback(axis::Ref* sender);
    void onTouchesEnded(const std::vector<axis::Touch*>& touches, axis::Event* event);

    std::string getAnimationQualityMessage() const;

private:
    std::vector<axis::MeshRenderer*> _meshes;
    int _animateQuality;
    axis::MenuItemFont* _menuItem;
};

class MeshRendererWithSkinOutlineTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(MeshRendererWithSkinOutlineTest);
    MeshRendererWithSkinOutlineTest();
    virtual ~MeshRendererWithSkinOutlineTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

    void addNewMeshWithCoords(axis::Vec2 p);

    void onTouchesEnded(const std::vector<axis::Touch*>& touches, axis::Event* event);

protected:
    std::vector<axis::MeshRenderer*> _meshes;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    axis::EventListenerCustom* _backToForegroundListener;
#endif
};

class Animate3DTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(Animate3DTest);
    Animate3DTest();
    ~Animate3DTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

    void onTouchesEnded(const std::vector<axis::Touch*>& touches, axis::Event* event);

    virtual void update(float dt) override;

protected:
    void addMeshRenderer();

    enum class State
    {
        SWIMMING,
        SWIMMING_TO_HURT,
        HURT,
        HURT_TO_SWIMMING,
    };

    void reachEndCallBack();

    void renewCallBack();

    axis::MeshRenderer* _mesh;

    axis::Action* _swim;
    axis::Animate3D* _hurt;

    float _elapseTransTime;

    State _state;

    axis::MoveTo* _moveAction;
};

class AttachmentTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(AttachmentTest);
    AttachmentTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

    void onTouchesEnded(const std::vector<axis::Touch*>& touches, axis::Event* event);

    void addNewMeshWithCoords(axis::Vec2 p);

protected:
    bool _hasWeapon;
    axis::MeshRenderer* _mesh;
};

class MeshRendererReskinTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(MeshRendererReskinTest);
    MeshRendererReskinTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    void onTouchesEnded(const std::vector<axis::Touch*>& touches, axis::Event* event);
    void addNewMeshWithCoords(axis::Vec2 p);

    void menuCallback_reSkin(axis::Ref* sender);

protected:
    void applyCurSkin();

    enum class SkinType
    {
        UPPER_BODY = 0,
        PANTS,
        SHOES,
        HAIR,
        FACE,
        HAND,
        GLASSES,
        MAX_TYPE,
    };

    std::vector<std::string> _skins[(int)SkinType::MAX_TYPE];  // all skins
    int _curSkin[(int)SkinType::MAX_TYPE];                     // current skin index
    axis::MeshRenderer* _mesh;
};

class MeshRendererWithOBBPerformanceTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(MeshRendererWithOBBPerformanceTest);
    MeshRendererWithOBBPerformanceTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    virtual void update(float dt) override;
    void addNewOBBWithCoords(axis::Vec2 p);
    void addNewMeshWithCoords(axis::Vec2 p);
    void onTouchesBegan(const std::vector<axis::Touch*>& touches, axis::Event* event);
    void onTouchesEnded(const std::vector<axis::Touch*>& touches, axis::Event* event);
    void onTouchesMoved(const std::vector<axis::Touch*>& touches, axis::Event* event);
    void addOBBCallback(axis::Ref* sender);
    void delOBBCallback(axis::Ref* sender);
    void addOBBWithCount(float value);
    void delOBBWithCount(float value);

protected:
    axis::MeshRenderer* _mesh;
    std::vector<axis::OBB> _obb;
    axis::DrawNode3D* _drawOBB;
    axis::Label* _labelCubeCount;
    axis::MoveTo* _moveAction;
    axis::OBB _obbt;
    axis::OBB _obbtOri;  // tortoise origin obb
    axis::DrawNode3D* _drawDebug;
    bool _hasCollider;
    std::set<int> _intersetList;
    void initDrawBox();
    void reachEndCallBack();

    void unproject(const axis::Mat4& viewProjection,
                   const axis::Size* viewport,
                   axis::Vec3* src,
                   axis::Vec3* dst);
    void calculateRayByLocationInView(axis::Ray* ray, const axis::Vec2& location);
};

class MeshRendererMirrorTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(MeshRendererMirrorTest);
    MeshRendererMirrorTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

    void addNewMeshWithCoords(axis::Vec2 p);

protected:
    bool _hasWeapon;
    axis::MeshRenderer* _mesh;
    axis::MeshRenderer* _mirrorMesh;
};

class QuaternionTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(QuaternionTest);
    QuaternionTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

    void addNewMeshWithCoords(axis::Vec2 p);
    virtual void update(float delta) override;

protected:
    axis::MeshRenderer* _mesh;
    float _arcSpeed;
    float _radius;
    float _accAngle;
};

// 3d + 2d use case
class UseCaseMeshRenderer : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(UseCaseMeshRenderer);
    UseCaseMeshRenderer();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

    virtual void update(float delta) override;

    void menuCallback_Message(axis::Ref* sender);

protected:
    void switchCase();

    enum class USECASE
    {
        _3D_WITH_2D,
        _UI_3D_UI,
        MAX_CASE_NUM,
    };
    axis::Label* _label;
    int _caseIdx;  // use case index
    std::string _useCaseTitles[(int)USECASE::MAX_CASE_NUM];
};

// node animation test, cocos2d-x supports both skeletal animation and node animation
class NodeAnimationTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(NodeAnimationTest);
    NodeAnimationTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

    void addNewMeshWithCoords(axis::Vec2 p);

protected:
    std::vector<axis::MeshRenderer*> _meshes;
    int _vectorIndex;
};

NS_AX_BEGIN
class TextureCube;
class Skybox;
NS_AX_END  // namespace axis

class MeshRendererCubeMapTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(MeshRendererCubeMapTest);
    MeshRendererCubeMapTest();
    ~MeshRendererCubeMapTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

    void addNewMeshWithCoords(axis::Vec2);

    void onTouchesMoved(const std::vector<axis::Touch*>& touches, axis::Event* event);

protected:
    axis::TextureCube* _textureCube;
    axis::Skybox* _skyBox;
    axis::MeshRenderer* _teapot;
    axis::Camera* _camera;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    axis::EventListenerCustom* _backToForegroundListener;
#endif
};

/// issue 9767 setGLProgram
class Issue9767 : public MeshRendererTestDemo
{
    enum class ShaderType
    {
        SHADER_TEX,
        SHADER_COLOR,
    };

public:
    CREATE_FUNC(Issue9767);
    Issue9767();
    ~Issue9767();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

    void menuCallback_SwitchShader(axis::Ref* sender);

protected:
    ShaderType _shaderType;
    axis::MeshRenderer* _mesh;
};

/// Clipping MeshRenderer
class MeshRendererClippingTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(MeshRendererClippingTest);
    MeshRendererClippingTest();
    ~MeshRendererClippingTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class Animate3DCallbackTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(Animate3DCallbackTest);
    Animate3DCallbackTest();
    ~Animate3DCallbackTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

protected:
    axis::MeshRenderer* _meshRenderer;
};

class CameraBackgroundClearTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(CameraBackgroundClearTest);
    CameraBackgroundClearTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

    void switch_CameraClearMode(axis::Ref* sender);

protected:
    axis::Camera* _camera;
    axis::Label* _label;
};

class MeshRendererVertexColorTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(MeshRendererVertexColorTest);
    MeshRendererVertexColorTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

    virtual ~MeshRendererVertexColorTest();

protected:
    axis::MeshRenderer* _mesh;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    axis::EventListenerCustom* _backToForegroundListener;
#endif
};

class MotionStreak3DTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(MotionStreak3DTest);
    MotionStreak3DTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    virtual void update(float delta) override;

protected:
    axis::MeshRenderer* _mesh;
    axis::MotionStreak3D* _streak;
};

class MeshRendererNormalMappingTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(MeshRendererNormalMappingTest);
    MeshRendererNormalMappingTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    virtual void update(float dt) override;

    virtual ~MeshRendererNormalMappingTest();
};

class MeshRendererPropertyTest : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(MeshRendererPropertyTest);
    MeshRendererPropertyTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    virtual void update(float delta) override;

    void printMeshName(axis::Ref* sender);
    void removeUsedTexture(axis::Ref* sender);
    void resetTexture(axis::Ref* sender);

    void refreshMeshRender();

protected:
    axis::MeshRenderer* _mesh;
    axis::Texture2D* _meshTex;
    std::string _texFile;
};

class Issue16155Test : public MeshRendererTestDemo
{
public:
    CREATE_FUNC(Issue16155Test);
    Issue16155Test();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};
