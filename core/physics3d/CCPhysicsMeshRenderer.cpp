/****************************************************************************
 Copyright (c) 2015-2016 Chukong Technologies Inc.
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

#include "physics3d/CCPhysics3D.h"

#if CC_USE_3D_PHYSICS

#    if (CC_ENABLE_BULLET_INTEGRATION)

NS_AX_BEGIN

PhysicsMeshRenderer* PhysicsMeshRenderer::create(std::string_view modelPath,
                                         Physics3DRigidBodyDes* rigidDes,
                                         const axis::Vec3& translateInPhysics,
                                         const axis::Quaternion& rotInPhsyics)
{
    auto ret = new PhysicsMeshRenderer();
    if (ret->initWithFile(modelPath))
    {
        auto obj               = Physics3DRigidBody::create(rigidDes);
        ret->_physicsComponent = Physics3DComponent::create(obj, translateInPhysics, rotInPhsyics);
        ret->addComponent(ret->_physicsComponent);
        ret->_contentSize = ret->getBoundingBox().size;
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return ret;
}

PhysicsMeshRenderer* PhysicsMeshRenderer::createWithCollider(std::string_view modelPath,
                                                     Physics3DColliderDes* colliderDes,
                                                     const axis::Vec3& translateInPhysics,
                                                     const axis::Quaternion& rotInPhsyics)
{
    auto ret = new PhysicsMeshRenderer();
    if (ret->initWithFile(modelPath))
    {
        auto obj               = Physics3DCollider::create(colliderDes);
        ret->_physicsComponent = Physics3DComponent::create(obj, translateInPhysics, rotInPhsyics);
        ret->addComponent(ret->_physicsComponent);
        ret->_contentSize = ret->getBoundingBox().size;
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return ret;
}

Physics3DObject* PhysicsMeshRenderer::getPhysicsObj() const
{
    return _physicsComponent->getPhysics3DObject();
}

void PhysicsMeshRenderer::setSyncFlag(Physics3DComponent::PhysicsSyncFlag syncFlag)
{
    if (_physicsComponent)
        _physicsComponent->setSyncFlag(syncFlag);
}

void PhysicsMeshRenderer::syncNodeToPhysics()
{
    if (_physicsComponent)
        _physicsComponent->syncNodeToPhysics();
}

void PhysicsMeshRenderer::syncPhysicsToNode()
{
    if (_physicsComponent)
        _physicsComponent->syncPhysicsToNode();
}

PhysicsMeshRenderer::PhysicsMeshRenderer() : _physicsComponent(nullptr) {}
PhysicsMeshRenderer::~PhysicsMeshRenderer() {}

NS_AX_END

#    endif  // CC_ENABLE_BULLET_INTEGRATION

#endif  // CC_USE_3D_PHYSICS
