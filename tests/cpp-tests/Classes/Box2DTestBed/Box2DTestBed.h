/****************************************************************************
 * Copyright (c) 2021 @aismann; Peter Eismann, Germany; dreifrankensoft

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

#ifndef _BOX2D_TESTBED_H_
#define _BOX2D_TESTBED_H_

#include "cocos2d.h"
#include "box2d/box2d.h"
#include "../BaseTest.h"

DEFINE_TEST_SUITE(Box2DTestBedTests);

class Test;
typedef Test* TestCreateFcn();

struct TestEntry
{
    const char* category;
    const char* name;
    TestCreateFcn* createFcn;
};

#define MAX_TESTS 256
extern TestEntry g_testEntries[MAX_TESTS];

int RegisterTest(const char* category, const char* name, TestCreateFcn* fcn);

class Box2DTestBed : public TestCase, axis::Layer
{
public:
    static Box2DTestBed* createWithEntryID(int entryId);

    Box2DTestBed();
    virtual ~Box2DTestBed();

    void onEnter() override;
    void onExit() override;

    void onDrawImGui();

    void initPhysics();
    void update(float dt) override;

    void createResetButton();

    bool initWithEntryID(int entryId);

    bool onTouchBegan(axis::Touch* touch, axis::Event* event);
    void onTouchMoved(axis::Touch* touch, axis::Event* event);
    void onTouchEnded(axis::Touch* touch, axis::Event* event);

    void onKeyPressed(axis::EventKeyboard::KeyCode code, axis::Event* event);
    void onKeyReleased(axis::EventKeyboard::KeyCode code, axis::Event* event);

    void onMouseDown(axis::Event* event);
    void onMouseUp(axis::Event* event);
    void onMouseMove(axis::Event* event);
    void onMouseScroll(axis::Event* event);

    axis::EventListenerTouchOneByOne* _touchListener;
    axis::EventListenerKeyboard* _keyboardListener;

    TestEntry* m_entry;
    Test* m_test;
    int m_entryID;

private:
    b2World* world;
    axis::Texture2D* _spriteTexture;

    b2Vec2 pos;
    b2Vec2 oldPos;
    bool button[2];

    // Debug stuff
    axis::DrawNode* debugDrawNode;
    axis::extension::PhysicsDebugNodeBox2D g_debugDraw;
};

#endif
