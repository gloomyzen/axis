#ifndef __INPUTPROCESSOR_H__
#define __INPUTPROCESSOR_H__

#include "FairyGUIMacros.h"
#include "cocos2d.h"
#include "UIEventDispatcher.h"
#include "InputEvent.h"

NS_FGUI_BEGIN

class GComponent;
class TouchInfo;

class InputProcessor
{
public:
    typedef std::function<void(int eventType)> CaptureEventCallback;

    InputEvent* getRecentInput() { return &_recentInput; }
    static bool isTouchOnUI();

    InputProcessor(GComponent* owner);
    ~InputProcessor();

    axis::Vec2 getTouchPosition(int touchId);

    void addTouchMonitor(int touchId, GObject* target);
    void removeTouchMonitor(GObject* target);

    void cancelClick(int touchId);
    void simulateClick(GObject* target, int touchId = -1);

    void setCaptureCallback(CaptureEventCallback value) { _captureCallback = value; }
    
    void disableDefaultTouchEvent();
    bool touchDown(axis::Touch *touch, axis::Event *event);
    void touchMove(axis::Touch *touch, axis::Event *event);
    void touchUp(axis::Touch *touch, axis::Event *event);
    
private:
    bool onTouchBegan(axis::Touch * touch, axis::Event *);
    void onTouchMoved(axis::Touch * touch, axis::Event *);
    void onTouchEnded(axis::Touch * touch, axis::Event *);
    void onTouchCancelled(axis::Touch * touch, axis::Event *);

    void onMouseDown(axis::EventMouse* event);
    void onMouseUp(axis::EventMouse* event);
    void onMouseMove(axis::EventMouse* event);
    void onMouseScroll(axis::EventMouse* event);

    void onKeyDown(axis::EventKeyboard::KeyCode keyCode, axis::Event*);
    void onKeyUp(axis::EventKeyboard::KeyCode keyCode, axis::Event*);

    TouchInfo* getTouch(int touchId, bool createIfNotExisits = true);
    void updateRecentInput(TouchInfo* touch, GObject* target);
    void handleRollOver(TouchInfo* touch, GObject* target);
    void setBegin(TouchInfo* touch, GObject* target);
    void setEnd(TouchInfo* touch, GObject* target);
    GObject* clickTest(TouchInfo* touch, GObject* target);

    axis::EventListenerTouchOneByOne* _touchListener;
    axis::EventListenerMouse* _mouseListener;
    axis::EventListenerKeyboard* _keyboardListener;
    std::vector<TouchInfo*> _touches;
    GComponent* _owner;
    CaptureEventCallback _captureCallback;
    InputEvent _recentInput;
    uint16_t _keyModifiers;

    static bool _touchOnUI;
    static unsigned int _touchOnUIFlagFrameId;
    static InputProcessor* _activeProcessor;

    friend class UIEventDispatcher;
};

NS_FGUI_END

#endif
