#ifndef __TWEENMANAGER_H__
#define __TWEENMANAGER_H__

#include "FairyGUIMacros.h"
#include "TweenPropType.h"
#include "cocos2d.h"

NS_FGUI_BEGIN

class GTweener;

class TweenManager
{
public:
    static GTweener* createTween();
    static bool isTweening(axis::Ref* target, TweenPropType propType);
    static bool killTweens(axis::Ref* target, TweenPropType propType, bool completed);
    static GTweener* getTween(axis::Ref* target, TweenPropType propType);
    static void update(float dt);
    static void clean();
    static void init();

private:
    static void reset(axis::EventCustom*);

    static GTweener** _activeTweens;
    static std::vector<GTweener*> _tweenerPool;
    static int _totalActiveTweens;
    static int _arrayLength;
    static bool _inited;
};

NS_FGUI_END

#endif
