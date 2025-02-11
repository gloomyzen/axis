/****************************************************************************
 Copyright (c) 2013-2016 Chukong Technologies Inc.
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

#ifndef _CPPTESTS_BASETEST_H__
#define _CPPTESTS_BASETEST_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "GUI/CCControlExtension/CCControlExtensions.h"
#include "GUI/CCScrollView/CCScrollView.h"
#include "GUI/CCScrollView/CCTableView.h"
#include "VisibleRect.h"

class TestSuite;

/**
 * Each test case should inherit from TestCase, and add to a TestSuite object.
 */
class TestCase : public axis::Scene
{
public:
    /** TestCase test type.*/
    enum class Type
    {
        /** For testing whether test case not crash.*/
        ROBUSTNESS,
        /**
         * For check the correctness of regular test cases.
         * A test case passes only if the actual output equal to the expected output.
         */
        UNIT,
        /** @warning The test type is not achieved.*/
        GRAPHICAL_STATIC,
        /** @note It's mean the test case need test manually.*/
        MANUAL
    };
    TestCase();
    ~TestCase();

    virtual std::string title() const { return ""; }
    virtual std::string subtitle() const { return ""; }

    /** Returns the test type, the default type is Type::ROBUSTNESS.*/
    virtual Type getTestType() const;
    /** Returns the time the test case needs.*/
    virtual float getDuration() const;

    /** Returns the expected output.*/
    virtual std::string getExpectedOutput() const { return ""; }
    /** Returns the actual output.*/
    virtual std::string getActualOutput() const { return ""; }

    /** Callback functions.*/
    virtual void restartTestCallback(axis::Ref* sender);
    virtual void nextTestCallback(axis::Ref* sender);
    virtual void priorTestCallback(axis::Ref* sender);
    virtual void onBackCallback(axis::Ref* sender);

    /**
     * You should NEVER call this method, unless you know what you are doing.
     */
    void setTestSuite(TestSuite* testSuite);
    TestSuite* getTestSuite() const { return _testSuite; }

    /** Returns the run time of test case.*/
    float getRunTime() const { return _runTime; }

    /**
     * You should NEVER call this method, unless you know what you are doing.
     */
    void setTestCaseName(std::string_view name) { _testCaseName = name; }
    std::string getTestCaseName() const { return _testCaseName; }

    const axis::Label* getSubtitleLable() const { return _subtitleLabel; }
    const axis::MenuItemImage* getRestartTestItem() const { return _restartTestItem; }

    virtual void onEnter() override;
    virtual bool init() override;

protected:
    axis::MenuItemImage* _priorTestItem;
    axis::MenuItemImage* _restartTestItem;
    axis::MenuItemImage* _nextTestItem;

    axis::Label* _titleLabel;
    axis::Label* _subtitleLabel;

private:
    TestSuite* _testSuite;
    float _runTime;
    std::string _testCaseName;
};

/**
 * A TestBase object stores the following information about a test:
 * - A pointer to the parent test(TestList or TestSuite).
 * - Array of children test names.
 * - A flag to indicate whether the test is a TestList object.
 *
 * @note You should not inherit from TestBase directly.
 */
class TestBase : public axis::Ref
{
public:
    virtual ~TestBase();

    /** Backs up one level. */
    void backsUpOneLevel();

    virtual void runThisTest() {}

    bool isTestList() { return _isTestList; }

    ssize_t getChildTestCount() { return _childTestNames.size(); }

    /**
     * You should NEVER call this method.
     */
    void setTestParent(TestBase* parent) { _parentTest = parent; }
    TestBase* getTestParent() { return _parentTest; }

    void setTestName(std::string_view testName) { _testName = testName; }
    std::string getTestName() const { return _testName; }

protected:
    TestBase();

    std::string _testName;
    TestBase* _parentTest;
    bool _isTestList;
    std::vector<std::string> _childTestNames;
};

class TestController;

/**
 * TestSuite correspond to a group of test cases.
 * @note Each test case should add to a TestSuite object.
 */
class TestSuite : public TestBase
{
public:
    void addTestCase(std::string_view testName, std::function<axis::Scene*()> callback);

    virtual void restartCurrTest();
    virtual void enterNextTest();
    virtual void enterPreviousTest();

    int getCurrTestIndex() { return _currTestIndex; }
    virtual void runThisTest() override;

private:
    std::vector<std::function<axis::Scene*()>> _testCallbacks;

    int _currTestIndex;
    friend class TestController;
};

class TestCustomTableView;

/**
 * An instance of TestList is a means for displaying hierarchical lists of TestSuite.
 */
class TestList : public TestBase,
                 public axis::extension::TableViewDataSource,
                 public axis::extension::TableViewDelegate
{
public:
    TestList();
    ~TestList();

    void addTest(std::string_view testName, std::function<TestBase*()> callback);

    virtual void runThisTest() override;

    virtual void tableCellTouched(axis::extension::TableView* table,
                                  axis::extension::TableViewCell* cell) override;
    virtual axis::extension::TableViewCell* tableCellAtIndex(axis::extension::TableView* table,
                                                                ssize_t idx) override;
    virtual axis::Size tableCellSizeForIndex(axis::extension::TableView* table, ssize_t idx) override;
    virtual ssize_t numberOfCellsInTableView(axis::extension::TableView* table) override;

    virtual void scrollViewDidScroll(axis::extension::ScrollView* view) override {}
    virtual void scrollViewDidZoom(axis::extension::ScrollView* view) override {}

    void deatchTableView();

private:
    std::vector<std::function<TestBase*()>> _testCallbacks;
    bool _cellTouchEnabled;
    bool _shouldRestoreTableOffset;
    axis::Vec2 _tableOffset;
    friend class TestController;
    TestCustomTableView* _tableView{};
};

#define ADD_TEST(__className__) addTest(#__className__, []() { return new __className__; });

#define ADD_TEST_CASE(__className__) addTestCase(#__className__, []() { return __className__::create(); });

#define DEFINE_TEST_LIST(__className__)   \
    class __className__ : public TestList \
    {                                     \
    public:                               \
        __className__();                  \
    }

#define DEFINE_TEST_SUITE(__className__)   \
    class __className__ : public TestSuite \
    {                                      \
    public:                                \
        __className__();                   \
    }

/**
 * BaseTest is retained for compatibility with older versions.
 * @warning It should soon be removed.
 */
class BaseTest : public axis::Layer
{
public:
    virtual std::string title() const { return ""; }
    virtual std::string subtitle() const { return ""; }

    virtual void restartCallback(axis::Ref* sender) {}
    virtual void nextCallback(axis::Ref* sender) {}
    virtual void backCallback(axis::Ref* sender) {}

    virtual void onEnter() override {}
    virtual void onExit() override {}
};

#endif /* defined(_CPPTESTS_BASETEST_H__) */
