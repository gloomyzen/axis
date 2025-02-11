/****************************************************************************
Copyright (c) 2015-2017 Chukong Technologies Inc.

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

#ifndef __CCSKELETONNODE_H__
#define __CCSKELETONNODE_H__

#include "ActionTimeline/CCTimelineMacro.h"
#include "renderer/CCRenderer.h"
#include "CocosStudioExport.h"
#include "base/CCMap.h"

#include "ActionTimeline/CCBoneNode.h"

NS_TIMELINE_BEGIN

class CCS_DLL SkeletonNode : public BoneNode
{
    friend class BoneNode;

public:
    static SkeletonNode* create();

    /**
     *get bonenode in skeleton node by bone name
     */
    BoneNode* getBoneNode(std::string_view boneName);

    /**
     *get All bones in this skeleton, <bone's name, BoneNode>
     */
    const axis::StringMap<BoneNode*>& getAllSubBonesMap() const;

    /**
     *@brief: change displays
     *@param: boneSkinNameMap, map <name of bone, name of skin to display which added to bone>
     */
    void changeSkins(const hlookup::string_map<std::string>& boneSkinNameMap);

    /**
     *@brief: change displays
     *@param: skinGroupName have
     */
    void changeSkins(std::string_view skinGroupName);

    /**
     *@brief: add a boneSkinNameMap as a SkinGroup named groupName
     *@param: groupName, key
     *@param: boneSkinNameMap, map <name of bone, name of skin to display which added to bone>
     */
    void addSkinGroup(std::string groupName, hlookup::string_map<std::string> boneSkinNameMap);

    axis::Rect getBoundingBox() const override;

    SkeletonNode();
    virtual ~SkeletonNode();
    virtual bool init() override;

protected:
    virtual void updateVertices() override;
    virtual void updateColor() override;

    virtual void visit(axis::Renderer* renderer,
                       const axis::Mat4& parentTransform,
                       uint32_t parentFlags) override;
    virtual void draw(axis::Renderer* renderer, const axis::Mat4& transform, uint32_t flags) override;

protected:
    axis::StringMap<BoneNode*> _subBonesMap;

private:
    struct VertexData
    {
        axis::Vec3 vertex;
        axis::Color4F color;
    };

    axis::Vec2 _squareVertices[8];
    VertexData _vertexData[8];

    hlookup::string_map<hlookup::string_map<std::string>>
        _skinGroupMap;  // map< suit name, map< bone name, skin name> >
    CC_DISALLOW_COPY_AND_ASSIGN(SkeletonNode);

    void checkSubBonesDirty();
    // for draw skins as ordered bones' local z
    axis::Vector<BoneNode*> _subOrderedAllBones;
    void updateOrderedAllbones();
    void sortOrderedAllBones();
    // for batch draw sub bones
    bool _subBonesDirty;
    bool _subBonesOrderDirty;
    std::vector<VertexData> _batchedBoneVertexData;
    int _batchedVeticesCount;
    axis::CustomCommand _batchBoneCommand;

    void batchDrawAllSubBones();
};

NS_TIMELINE_END

#endif  //__CCSKELETONNODE_H__
