/****************************************************************************
Copyright (c) 2013-2017 Chukong Technologies Inc.

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

#ifndef __CC_EXTENTIONS_CCCOMBASE_H__
#define __CC_EXTENTIONS_CCCOMBASE_H__

#include <string>
#include "DictionaryHelper.h"
#include "CocosStudioExport.h"
#include "base/ObjectFactory.h"
#include "CocoLoader.h"

#define DECLARE_CLASS_COMPONENT_INFO           \
public:                                        \
    static axis::ObjectFactory::TInfo Type; \
    static axis::Ref* createInstance(void);

#define IMPLEMENT_CLASS_COMPONENT_INFO(className)                                 \
    axis::Ref* className::createInstance(void) { return className::create(); } \
    axis::ObjectFactory::TInfo className::Type(#className, &className::createInstance);

#define CREATE_CLASS_COMPONENT_INFO(className) axis::ObjectFactory::TInfo(#className, &className::createInstance)

struct CCS_DLL SerData
{
    const rapidjson::Value* _rData;
    cocostudio::stExpCocoNode* _cocoNode;
    cocostudio::CocoLoader* _cocoLoader;
    SerData()
    {
        _rData      = NULL;
        _cocoNode   = NULL;
        _cocoLoader = NULL;
    }
};

#endif
