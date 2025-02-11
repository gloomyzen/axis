/****************************************************************************
 Copyright (C) 2013 Henry van Merode. All rights reserved.
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

#include "CCPUJetAffector.h"
#include "extensions/Particle3D/PU/CCPUParticleSystem3D.h"

NS_AX_BEGIN

// Constants
const float PUJetAffector::DEFAULT_ACCELERATION = 1.0f;

//-----------------------------------------------------------------------
PUJetAffector::PUJetAffector() : PUAffector(), _scaled(0.0f)
{
    _dynAcceleration = new PUDynamicAttributeFixed();
    (static_cast<PUDynamicAttributeFixed*>(_dynAcceleration))->setValue(DEFAULT_ACCELERATION);
}
//-----------------------------------------------------------------------
PUJetAffector::~PUJetAffector()
{
    if (!_dynAcceleration)
        return;

    CC_SAFE_DELETE(_dynAcceleration);
    _dynAcceleration = 0;
}
//-----------------------------------------------------------------------
void PUJetAffector::setDynAcceleration(PUDynamicAttribute* dynAcceleration)
{
    if (_dynAcceleration)
        CC_SAFE_DELETE(_dynAcceleration);

    _dynAcceleration = dynAcceleration;
}

void PUJetAffector::updatePUAffector(PUParticle3D* particle, float deltaTime)
{
    // for (auto iter : _particleSystem->getParticles())
    {
        // PUParticle3D *particle = iter;
        _scaled = deltaTime * (_dynAcceleration->getValue(particle->timeFraction));
        if (particle->direction == Vec3::ZERO)
        {
            // Existing direction is zero, so use original direction
            particle->direction += (particle->originalDirection * _scaled);
        }
        else
        {
            particle->direction += (particle->direction * _scaled);
        }
    }
}

PUJetAffector* PUJetAffector::create()
{
    auto pja = new PUJetAffector();
    pja->autorelease();
    return pja;
}

void PUJetAffector::copyAttributesTo(PUAffector* affector)
{
    PUAffector::copyAttributesTo(affector);

    PUJetAffector* jetAffector = static_cast<PUJetAffector*>(affector);
    jetAffector->setDynAcceleration(getDynAcceleration()->clone());
}

NS_AX_END
