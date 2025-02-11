#include "scripting/lua-bindings/auto/lua_cocos2dx_3d_auto.hpp"
#include "cocos2d.h"
#include "3d/CCBundle3D.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_cocos2dx_3d_Animation3D_initWithFile(lua_State* tolua_S)
{
    int argc = 0;
    axis::Animation3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Animation3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Animation3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Animation3D_initWithFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string_view arg0;
        std::string_view arg1;

        ok &= luaval_to_std_string_view(tolua_S, 2,&arg0, "cc.Animation3D:initWithFile");

        ok &= luaval_to_std_string_view(tolua_S, 3,&arg1, "cc.Animation3D:initWithFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Animation3D_initWithFile'", nullptr);
            return 0;
        }
        bool ret = cobj->initWithFile(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Animation3D:initWithFile",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Animation3D_initWithFile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Animation3D_init(lua_State* tolua_S)
{
    int argc = 0;
    axis::Animation3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Animation3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Animation3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Animation3D_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        axis::Animation3DData arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR Animation3DData
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Animation3D_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Animation3D:init",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Animation3D_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Animation3D_getDuration(lua_State* tolua_S)
{
    int argc = 0;
    axis::Animation3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Animation3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Animation3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Animation3D_getDuration'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Animation3D_getDuration'", nullptr);
            return 0;
        }
        double ret = cobj->getDuration();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Animation3D:getDuration",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Animation3D_getDuration'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Animation3D_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.Animation3D",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string_view arg0;
        ok &= luaval_to_std_string_view(tolua_S, 2,&arg0, "cc.Animation3D:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Animation3D_create'", nullptr);
            return 0;
        }
        axis::Animation3D* ret = axis::Animation3D::create(arg0);
        object_to_luaval<axis::Animation3D>(tolua_S, "cc.Animation3D",(axis::Animation3D*)ret);
        return 1;
    }
    if (argc == 2)
    {
        std::string_view arg0;
        std::string_view arg1;
        ok &= luaval_to_std_string_view(tolua_S, 2,&arg0, "cc.Animation3D:create");
        ok &= luaval_to_std_string_view(tolua_S, 3,&arg1, "cc.Animation3D:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Animation3D_create'", nullptr);
            return 0;
        }
        axis::Animation3D* ret = axis::Animation3D::create(arg0, arg1);
        object_to_luaval<axis::Animation3D>(tolua_S, "cc.Animation3D",(axis::Animation3D*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.Animation3D:create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Animation3D_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_3d_Animation3D_constructor(lua_State* tolua_S)
{
    int argc = 0;
    axis::Animation3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Animation3D_constructor'", nullptr);
            return 0;
        }
        cobj = new axis::Animation3D();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.Animation3D");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Animation3D:Animation3D",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Animation3D_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_3d_Animation3D_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Animation3D)");
    return 0;
}

int lua_register_cocos2dx_3d_Animation3D(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.Animation3D");
    tolua_cclass(tolua_S,"Animation3D","cc.Animation3D","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"Animation3D");
        tolua_function(tolua_S,"new",lua_cocos2dx_3d_Animation3D_constructor);
        tolua_function(tolua_S,"initWithFile",lua_cocos2dx_3d_Animation3D_initWithFile);
        tolua_function(tolua_S,"init",lua_cocos2dx_3d_Animation3D_init);
        tolua_function(tolua_S,"getDuration",lua_cocos2dx_3d_Animation3D_getDuration);
        tolua_function(tolua_S,"create", lua_cocos2dx_3d_Animation3D_create);
    tolua_endmodule(tolua_S);
    auto typeName = typeid(axis::Animation3D).name(); // rtti is literal storage
    g_luaType[reinterpret_cast<uintptr_t>(typeName)] = "cc.Animation3D";
    g_typeCast[typeName] = "cc.Animation3D";
    return 1;
}

int lua_cocos2dx_3d_Animate3D_setKeyFrameUserInfo(lua_State* tolua_S)
{
    int argc = 0;
    axis::Animate3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Animate3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Animate3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Animate3D_setKeyFrameUserInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        axis::ValueMap arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.Animate3D:setKeyFrameUserInfo");

        ok &= luaval_to_ccvaluemap(tolua_S, 3, &arg1, "cc.Animate3D:setKeyFrameUserInfo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Animate3D_setKeyFrameUserInfo'", nullptr);
            return 0;
        }
        cobj->setKeyFrameUserInfo(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Animate3D:setKeyFrameUserInfo",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Animate3D_setKeyFrameUserInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Animate3D_getSpeed(lua_State* tolua_S)
{
    int argc = 0;
    axis::Animate3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Animate3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Animate3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Animate3D_getSpeed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Animate3D_getSpeed'", nullptr);
            return 0;
        }
        double ret = cobj->getSpeed();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Animate3D:getSpeed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Animate3D_getSpeed'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Animate3D_setQuality(lua_State* tolua_S)
{
    int argc = 0;
    axis::Animate3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Animate3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Animate3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Animate3D_setQuality'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        axis::Animate3DQuality arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.Animate3D:setQuality");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Animate3D_setQuality'", nullptr);
            return 0;
        }
        cobj->setQuality(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Animate3D:setQuality",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Animate3D_setQuality'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Animate3D_setWeight(lua_State* tolua_S)
{
    int argc = 0;
    axis::Animate3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Animate3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Animate3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Animate3D_setWeight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.Animate3D:setWeight");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Animate3D_setWeight'", nullptr);
            return 0;
        }
        cobj->setWeight(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Animate3D:setWeight",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Animate3D_setWeight'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Animate3D_removeFromMap(lua_State* tolua_S)
{
    int argc = 0;
    axis::Animate3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Animate3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Animate3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Animate3D_removeFromMap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Animate3D_removeFromMap'", nullptr);
            return 0;
        }
        cobj->removeFromMap();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Animate3D:removeFromMap",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Animate3D_removeFromMap'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Animate3D_initWithFrames(lua_State* tolua_S)
{
    int argc = 0;
    axis::Animate3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Animate3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Animate3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Animate3D_initWithFrames'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        axis::Animation3D* arg0;
        int arg1;
        int arg2;
        double arg3;

        ok &= luaval_to_object<axis::Animation3D>(tolua_S, 2, "cc.Animation3D",&arg0, "cc.Animate3D:initWithFrames");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "cc.Animate3D:initWithFrames");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "cc.Animate3D:initWithFrames");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "cc.Animate3D:initWithFrames");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Animate3D_initWithFrames'", nullptr);
            return 0;
        }
        bool ret = cobj->initWithFrames(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Animate3D:initWithFrames",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Animate3D_initWithFrames'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Animate3D_getOriginInterval(lua_State* tolua_S)
{
    int argc = 0;
    axis::Animate3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Animate3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Animate3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Animate3D_getOriginInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Animate3D_getOriginInterval'", nullptr);
            return 0;
        }
        double ret = cobj->getOriginInterval();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Animate3D:getOriginInterval",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Animate3D_getOriginInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Animate3D_setSpeed(lua_State* tolua_S)
{
    int argc = 0;
    axis::Animate3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Animate3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Animate3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Animate3D_setSpeed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.Animate3D:setSpeed");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Animate3D_setSpeed'", nullptr);
            return 0;
        }
        cobj->setSpeed(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Animate3D:setSpeed",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Animate3D_setSpeed'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Animate3D_init(lua_State* tolua_S)
{
    int argc = 0;
    axis::Animate3D* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Animate3D",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (axis::Animate3D*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Animate3D_init'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            axis::Animation3D* arg0;
            ok &= luaval_to_object<axis::Animation3D>(tolua_S, 2, "cc.Animation3D",&arg0, "cc.Animate3D:init");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "cc.Animate3D:init");

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "cc.Animate3D:init");

            if (!ok) { break; }
            bool ret = cobj->init(arg0, arg1, arg2);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            axis::Animation3D* arg0;
            ok &= luaval_to_object<axis::Animation3D>(tolua_S, 2, "cc.Animation3D",&arg0, "cc.Animate3D:init");

            if (!ok) { break; }
            bool ret = cobj->init(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.Animate3D:init",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Animate3D_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Animate3D_setOriginInterval(lua_State* tolua_S)
{
    int argc = 0;
    axis::Animate3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Animate3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Animate3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Animate3D_setOriginInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.Animate3D:setOriginInterval");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Animate3D_setOriginInterval'", nullptr);
            return 0;
        }
        cobj->setOriginInterval(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Animate3D:setOriginInterval",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Animate3D_setOriginInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Animate3D_getWeight(lua_State* tolua_S)
{
    int argc = 0;
    axis::Animate3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Animate3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Animate3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Animate3D_getWeight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Animate3D_getWeight'", nullptr);
            return 0;
        }
        double ret = cobj->getWeight();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Animate3D:getWeight",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Animate3D_getWeight'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Animate3D_getQuality(lua_State* tolua_S)
{
    int argc = 0;
    axis::Animate3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Animate3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Animate3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Animate3D_getQuality'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Animate3D_getQuality'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getQuality();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Animate3D:getQuality",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Animate3D_getQuality'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Animate3D_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.Animate3D",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 3)
        {
            axis::Animation3D* arg0;
            ok &= luaval_to_object<axis::Animation3D>(tolua_S, 2, "cc.Animation3D",&arg0, "cc.Animate3D:create");
            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "cc.Animate3D:create");
            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "cc.Animate3D:create");
            if (!ok) { break; }
            axis::Animate3D* ret = axis::Animate3D::create(arg0, arg1, arg2);
            object_to_luaval<axis::Animate3D>(tolua_S, "cc.Animate3D",(axis::Animate3D*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            axis::Animation3D* arg0;
            ok &= luaval_to_object<axis::Animation3D>(tolua_S, 2, "cc.Animation3D",&arg0, "cc.Animate3D:create");
            if (!ok) { break; }
            axis::Animate3D* ret = axis::Animate3D::create(arg0);
            object_to_luaval<axis::Animate3D>(tolua_S, "cc.Animate3D",(axis::Animate3D*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "cc.Animate3D:create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Animate3D_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_3d_Animate3D_getTransitionTime(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.Animate3D",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Animate3D_getTransitionTime'", nullptr);
            return 0;
        }
        double ret = axis::Animate3D::getTransitionTime();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.Animate3D:getTransitionTime",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Animate3D_getTransitionTime'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_3d_Animate3D_createWithFrames(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.Animate3D",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        axis::Animation3D* arg0;
        int arg1;
        int arg2;
        ok &= luaval_to_object<axis::Animation3D>(tolua_S, 2, "cc.Animation3D",&arg0, "cc.Animate3D:createWithFrames");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "cc.Animate3D:createWithFrames");
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "cc.Animate3D:createWithFrames");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Animate3D_createWithFrames'", nullptr);
            return 0;
        }
        axis::Animate3D* ret = axis::Animate3D::createWithFrames(arg0, arg1, arg2);
        object_to_luaval<axis::Animate3D>(tolua_S, "cc.Animate3D",(axis::Animate3D*)ret);
        return 1;
    }
    if (argc == 4)
    {
        axis::Animation3D* arg0;
        int arg1;
        int arg2;
        double arg3;
        ok &= luaval_to_object<axis::Animation3D>(tolua_S, 2, "cc.Animation3D",&arg0, "cc.Animate3D:createWithFrames");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "cc.Animate3D:createWithFrames");
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "cc.Animate3D:createWithFrames");
        ok &= luaval_to_number(tolua_S, 5,&arg3, "cc.Animate3D:createWithFrames");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Animate3D_createWithFrames'", nullptr);
            return 0;
        }
        axis::Animate3D* ret = axis::Animate3D::createWithFrames(arg0, arg1, arg2, arg3);
        object_to_luaval<axis::Animate3D>(tolua_S, "cc.Animate3D",(axis::Animate3D*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.Animate3D:createWithFrames",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Animate3D_createWithFrames'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_3d_Animate3D_setTransitionTime(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.Animate3D",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.Animate3D:setTransitionTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Animate3D_setTransitionTime'", nullptr);
            return 0;
        }
        axis::Animate3D::setTransitionTime(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.Animate3D:setTransitionTime",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Animate3D_setTransitionTime'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_3d_Animate3D_constructor(lua_State* tolua_S)
{
    int argc = 0;
    axis::Animate3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Animate3D_constructor'", nullptr);
            return 0;
        }
        cobj = new axis::Animate3D();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.Animate3D");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Animate3D:Animate3D",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Animate3D_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_3d_Animate3D_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Animate3D)");
    return 0;
}

int lua_register_cocos2dx_3d_Animate3D(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.Animate3D");
    tolua_cclass(tolua_S,"Animate3D","cc.Animate3D","cc.ActionInterval",nullptr);

    tolua_beginmodule(tolua_S,"Animate3D");
        tolua_function(tolua_S,"new",lua_cocos2dx_3d_Animate3D_constructor);
        tolua_function(tolua_S,"setKeyFrameUserInfo",lua_cocos2dx_3d_Animate3D_setKeyFrameUserInfo);
        tolua_function(tolua_S,"getSpeed",lua_cocos2dx_3d_Animate3D_getSpeed);
        tolua_function(tolua_S,"setQuality",lua_cocos2dx_3d_Animate3D_setQuality);
        tolua_function(tolua_S,"setWeight",lua_cocos2dx_3d_Animate3D_setWeight);
        tolua_function(tolua_S,"removeFromMap",lua_cocos2dx_3d_Animate3D_removeFromMap);
        tolua_function(tolua_S,"initWithFrames",lua_cocos2dx_3d_Animate3D_initWithFrames);
        tolua_function(tolua_S,"getOriginInterval",lua_cocos2dx_3d_Animate3D_getOriginInterval);
        tolua_function(tolua_S,"setSpeed",lua_cocos2dx_3d_Animate3D_setSpeed);
        tolua_function(tolua_S,"init",lua_cocos2dx_3d_Animate3D_init);
        tolua_function(tolua_S,"setOriginInterval",lua_cocos2dx_3d_Animate3D_setOriginInterval);
        tolua_function(tolua_S,"getWeight",lua_cocos2dx_3d_Animate3D_getWeight);
        tolua_function(tolua_S,"getQuality",lua_cocos2dx_3d_Animate3D_getQuality);
        tolua_function(tolua_S,"create", lua_cocos2dx_3d_Animate3D_create);
        tolua_function(tolua_S,"getTransitionTime", lua_cocos2dx_3d_Animate3D_getTransitionTime);
        tolua_function(tolua_S,"createWithFrames", lua_cocos2dx_3d_Animate3D_createWithFrames);
        tolua_function(tolua_S,"setTransitionTime", lua_cocos2dx_3d_Animate3D_setTransitionTime);
    tolua_endmodule(tolua_S);
    auto typeName = typeid(axis::Animate3D).name(); // rtti is literal storage
    g_luaType[reinterpret_cast<uintptr_t>(typeName)] = "cc.Animate3D";
    g_typeCast[typeName] = "cc.Animate3D";
    return 1;
}

int lua_cocos2dx_3d_TextureCube_getImagePaths(lua_State* tolua_S)
{
    int argc = 0;
    axis::TextureCube* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TextureCube",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::TextureCube*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_TextureCube_getImagePaths'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_TextureCube_getImagePaths'", nullptr);
            return 0;
        }
        const std::vector<std::string>& ret = cobj->getImagePaths();
        ccvector_std_string_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TextureCube:getImagePaths",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_TextureCube_getImagePaths'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_TextureCube_getBackendTexture(lua_State* tolua_S)
{
    int argc = 0;
    axis::TextureCube* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TextureCube",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::TextureCube*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_TextureCube_getBackendTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_TextureCube_getBackendTexture'", nullptr);
            return 0;
        }
        axis::backend::TextureBackend* ret = cobj->getBackendTexture();
        object_to_luaval<axis::backend::TextureBackend>(tolua_S, "ccb.TextureBackend",(axis::backend::TextureBackend*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TextureCube:getBackendTexture",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_TextureCube_getBackendTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_TextureCube_reloadTexture(lua_State* tolua_S)
{
    int argc = 0;
    axis::TextureCube* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TextureCube",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::TextureCube*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_TextureCube_reloadTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_TextureCube_reloadTexture'", nullptr);
            return 0;
        }
        bool ret = cobj->reloadTexture();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TextureCube:reloadTexture",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_TextureCube_reloadTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_TextureCube_setTexParameters(lua_State* tolua_S)
{
    int argc = 0;
    axis::TextureCube* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TextureCube",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::TextureCube*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_TextureCube_setTexParameters'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        axis::Texture2D::TexParams arg0;

        ok &= luaval_to_texparams(tolua_S, 2, &arg0, "cc.TextureCube:setTexParameters");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_TextureCube_setTexParameters'", nullptr);
            return 0;
        }
        cobj->setTexParameters(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TextureCube:setTexParameters",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_TextureCube_setTexParameters'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_TextureCube_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.TextureCube",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 6)
    {
        std::string_view arg0;
        std::string_view arg1;
        std::string_view arg2;
        std::string_view arg3;
        std::string_view arg4;
        std::string_view arg5;
        ok &= luaval_to_std_string_view(tolua_S, 2,&arg0, "cc.TextureCube:create");
        ok &= luaval_to_std_string_view(tolua_S, 3,&arg1, "cc.TextureCube:create");
        ok &= luaval_to_std_string_view(tolua_S, 4,&arg2, "cc.TextureCube:create");
        ok &= luaval_to_std_string_view(tolua_S, 5,&arg3, "cc.TextureCube:create");
        ok &= luaval_to_std_string_view(tolua_S, 6,&arg4, "cc.TextureCube:create");
        ok &= luaval_to_std_string_view(tolua_S, 7,&arg5, "cc.TextureCube:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_TextureCube_create'", nullptr);
            return 0;
        }
        axis::TextureCube* ret = axis::TextureCube::create(arg0, arg1, arg2, arg3, arg4, arg5);
        object_to_luaval<axis::TextureCube>(tolua_S, "cc.TextureCube",(axis::TextureCube*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.TextureCube:create",argc, 6);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_TextureCube_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_3d_TextureCube_constructor(lua_State* tolua_S)
{
    int argc = 0;
    axis::TextureCube* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_TextureCube_constructor'", nullptr);
            return 0;
        }
        cobj = new axis::TextureCube();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.TextureCube");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TextureCube:TextureCube",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_TextureCube_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_3d_TextureCube_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TextureCube)");
    return 0;
}

int lua_register_cocos2dx_3d_TextureCube(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.TextureCube");
    tolua_cclass(tolua_S,"TextureCube","cc.TextureCube","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"TextureCube");
        tolua_function(tolua_S,"new",lua_cocos2dx_3d_TextureCube_constructor);
        tolua_function(tolua_S,"getImagePaths",lua_cocos2dx_3d_TextureCube_getImagePaths);
        tolua_function(tolua_S,"getBackendTexture",lua_cocos2dx_3d_TextureCube_getBackendTexture);
        tolua_function(tolua_S,"reloadTexture",lua_cocos2dx_3d_TextureCube_reloadTexture);
        tolua_function(tolua_S,"setTexParameters",lua_cocos2dx_3d_TextureCube_setTexParameters);
        tolua_function(tolua_S,"create", lua_cocos2dx_3d_TextureCube_create);
    tolua_endmodule(tolua_S);
    auto typeName = typeid(axis::TextureCube).name(); // rtti is literal storage
    g_luaType[reinterpret_cast<uintptr_t>(typeName)] = "cc.TextureCube";
    g_typeCast[typeName] = "cc.TextureCube";
    return 1;
}

int lua_cocos2dx_3d_AttachNode_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.AttachNode",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        axis::Bone3D* arg0;
        ok &= luaval_to_object<axis::Bone3D>(tolua_S, 2, "cc.Bone3D",&arg0, "cc.AttachNode:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_AttachNode_create'", nullptr);
            return 0;
        }
        axis::AttachNode* ret = axis::AttachNode::create(arg0);
        object_to_luaval<axis::AttachNode>(tolua_S, "cc.AttachNode",(axis::AttachNode*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.AttachNode:create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_AttachNode_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_3d_AttachNode_constructor(lua_State* tolua_S)
{
    int argc = 0;
    axis::AttachNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_AttachNode_constructor'", nullptr);
            return 0;
        }
        cobj = new axis::AttachNode();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.AttachNode");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.AttachNode:AttachNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_AttachNode_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_3d_AttachNode_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (AttachNode)");
    return 0;
}

int lua_register_cocos2dx_3d_AttachNode(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.AttachNode");
    tolua_cclass(tolua_S,"AttachNode","cc.AttachNode","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"AttachNode");
        tolua_function(tolua_S,"new",lua_cocos2dx_3d_AttachNode_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_3d_AttachNode_create);
    tolua_endmodule(tolua_S);
    auto typeName = typeid(axis::AttachNode).name(); // rtti is literal storage
    g_luaType[reinterpret_cast<uintptr_t>(typeName)] = "cc.AttachNode";
    g_typeCast[typeName] = "cc.AttachNode";
    return 1;
}

int lua_cocos2dx_3d_BillBoard_getMode(lua_State* tolua_S)
{
    int argc = 0;
    axis::BillBoard* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.BillBoard",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::BillBoard*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_BillBoard_getMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_BillBoard_getMode'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getMode();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.BillBoard:getMode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_BillBoard_getMode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_BillBoard_setMode(lua_State* tolua_S)
{
    int argc = 0;
    axis::BillBoard* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.BillBoard",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::BillBoard*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_BillBoard_setMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        axis::BillBoard::Mode arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.BillBoard:setMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_BillBoard_setMode'", nullptr);
            return 0;
        }
        cobj->setMode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.BillBoard:setMode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_BillBoard_setMode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_BillBoard_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.BillBoard",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            std::string_view arg0;
            ok &= luaval_to_std_string_view(tolua_S, 2,&arg0, "cc.BillBoard:create");
            if (!ok) { break; }
            axis::BillBoard* ret = axis::BillBoard::create(arg0);
            object_to_luaval<axis::BillBoard>(tolua_S, "cc.BillBoard",(axis::BillBoard*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            std::string_view arg0;
            ok &= luaval_to_std_string_view(tolua_S, 2,&arg0, "cc.BillBoard:create");
            if (!ok) { break; }
            axis::BillBoard::Mode arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "cc.BillBoard:create");
            if (!ok) { break; }
            axis::BillBoard* ret = axis::BillBoard::create(arg0, arg1);
            object_to_luaval<axis::BillBoard>(tolua_S, "cc.BillBoard",(axis::BillBoard*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            axis::BillBoard* ret = axis::BillBoard::create();
            object_to_luaval<axis::BillBoard>(tolua_S, "cc.BillBoard",(axis::BillBoard*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            axis::BillBoard::Mode arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.BillBoard:create");
            if (!ok) { break; }
            axis::BillBoard* ret = axis::BillBoard::create(arg0);
            object_to_luaval<axis::BillBoard>(tolua_S, "cc.BillBoard",(axis::BillBoard*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            std::string_view arg0;
            ok &= luaval_to_std_string_view(tolua_S, 2,&arg0, "cc.BillBoard:create");
            if (!ok) { break; }
            axis::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1, "cc.BillBoard:create");
            if (!ok) { break; }
            axis::BillBoard* ret = axis::BillBoard::create(arg0, arg1);
            object_to_luaval<axis::BillBoard>(tolua_S, "cc.BillBoard",(axis::BillBoard*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            std::string_view arg0;
            ok &= luaval_to_std_string_view(tolua_S, 2,&arg0, "cc.BillBoard:create");
            if (!ok) { break; }
            axis::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1, "cc.BillBoard:create");
            if (!ok) { break; }
            axis::BillBoard::Mode arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "cc.BillBoard:create");
            if (!ok) { break; }
            axis::BillBoard* ret = axis::BillBoard::create(arg0, arg1, arg2);
            object_to_luaval<axis::BillBoard>(tolua_S, "cc.BillBoard",(axis::BillBoard*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "cc.BillBoard:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_BillBoard_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_3d_BillBoard_createWithTexture(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.BillBoard",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        axis::Texture2D* arg0;
        ok &= luaval_to_object<axis::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0, "cc.BillBoard:createWithTexture");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_BillBoard_createWithTexture'", nullptr);
            return 0;
        }
        axis::BillBoard* ret = axis::BillBoard::createWithTexture(arg0);
        object_to_luaval<axis::BillBoard>(tolua_S, "cc.BillBoard",(axis::BillBoard*)ret);
        return 1;
    }
    if (argc == 2)
    {
        axis::Texture2D* arg0;
        axis::BillBoard::Mode arg1;
        ok &= luaval_to_object<axis::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0, "cc.BillBoard:createWithTexture");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "cc.BillBoard:createWithTexture");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_BillBoard_createWithTexture'", nullptr);
            return 0;
        }
        axis::BillBoard* ret = axis::BillBoard::createWithTexture(arg0, arg1);
        object_to_luaval<axis::BillBoard>(tolua_S, "cc.BillBoard",(axis::BillBoard*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.BillBoard:createWithTexture",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_BillBoard_createWithTexture'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_3d_BillBoard_constructor(lua_State* tolua_S)
{
    int argc = 0;
    axis::BillBoard* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_BillBoard_constructor'", nullptr);
            return 0;
        }
        cobj = new axis::BillBoard();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.BillBoard");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.BillBoard:BillBoard",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_BillBoard_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_3d_BillBoard_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (BillBoard)");
    return 0;
}

int lua_register_cocos2dx_3d_BillBoard(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.BillBoard");
    tolua_cclass(tolua_S,"BillBoard","cc.BillBoard","cc.Sprite",nullptr);

    tolua_beginmodule(tolua_S,"BillBoard");
        tolua_function(tolua_S,"new",lua_cocos2dx_3d_BillBoard_constructor);
        tolua_function(tolua_S,"getMode",lua_cocos2dx_3d_BillBoard_getMode);
        tolua_function(tolua_S,"setMode",lua_cocos2dx_3d_BillBoard_setMode);
        tolua_function(tolua_S,"create", lua_cocos2dx_3d_BillBoard_create);
        tolua_function(tolua_S,"createWithTexture", lua_cocos2dx_3d_BillBoard_createWithTexture);
    tolua_endmodule(tolua_S);
    auto typeName = typeid(axis::BillBoard).name(); // rtti is literal storage
    g_luaType[reinterpret_cast<uintptr_t>(typeName)] = "cc.BillBoard";
    g_typeCast[typeName] = "cc.BillBoard";
    return 1;
}

int lua_cocos2dx_3d_Mesh_getMaterial(lua_State* tolua_S)
{
    int argc = 0;
    axis::Mesh* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Mesh",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Mesh*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Mesh_getMaterial'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Mesh_getMaterial'", nullptr);
            return 0;
        }
        axis::Material* ret = cobj->getMaterial();
        object_to_luaval<axis::Material>(tolua_S, "cc.Material",(axis::Material*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Mesh:getMaterial",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Mesh_getMaterial'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Mesh_getVertexSizeInBytes(lua_State* tolua_S)
{
    int argc = 0;
    axis::Mesh* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Mesh",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Mesh*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Mesh_getVertexSizeInBytes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Mesh_getVertexSizeInBytes'", nullptr);
            return 0;
        }
        int ret = cobj->getVertexSizeInBytes();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Mesh:getVertexSizeInBytes",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Mesh_getVertexSizeInBytes'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Mesh_setProgramState(lua_State* tolua_S)
{
    int argc = 0;
    axis::Mesh* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Mesh",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Mesh*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Mesh_setProgramState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        axis::backend::ProgramState* arg0;

        ok &= luaval_to_object<axis::backend::ProgramState>(tolua_S, 2, "ccb.ProgramState",&arg0, "cc.Mesh:setProgramState");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Mesh_setProgramState'", nullptr);
            return 0;
        }
        cobj->setProgramState(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Mesh:setProgramState",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Mesh_setProgramState'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Mesh_setIndexFormat(lua_State* tolua_S)
{
    int argc = 0;
    axis::Mesh* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Mesh",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Mesh*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Mesh_setIndexFormat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        axis::backend::IndexFormat arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.Mesh:setIndexFormat");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Mesh_setIndexFormat'", nullptr);
            return 0;
        }
        cobj->setIndexFormat(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Mesh:setIndexFormat",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Mesh_setIndexFormat'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Mesh_setMaterial(lua_State* tolua_S)
{
    int argc = 0;
    axis::Mesh* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Mesh",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Mesh*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Mesh_setMaterial'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        axis::Material* arg0;

        ok &= luaval_to_object<axis::Material>(tolua_S, 2, "cc.Material",&arg0, "cc.Mesh:setMaterial");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Mesh_setMaterial'", nullptr);
            return 0;
        }
        cobj->setMaterial(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Mesh:setMaterial",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Mesh_setMaterial'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Mesh_getName(lua_State* tolua_S)
{
    int argc = 0;
    axis::Mesh* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Mesh",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Mesh*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Mesh_getName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Mesh_getName'", nullptr);
            return 0;
        }
        std::string_view ret = cobj->getName();
        lua_pushlstring(tolua_S,ret.data(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Mesh:getName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Mesh_getName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Mesh_getMeshVertexAttribute(lua_State* tolua_S)
{
    int argc = 0;
    axis::Mesh* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Mesh",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Mesh*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Mesh_getMeshVertexAttribute'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.Mesh:getMeshVertexAttribute");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Mesh_getMeshVertexAttribute'", nullptr);
            return 0;
        }
        const axis::MeshVertexAttrib& ret = cobj->getMeshVertexAttribute(arg0);
        mesh_vertex_attrib_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Mesh:getMeshVertexAttribute",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Mesh_getMeshVertexAttribute'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Mesh_calculateAABB(lua_State* tolua_S)
{
    int argc = 0;
    axis::Mesh* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Mesh",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Mesh*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Mesh_calculateAABB'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Mesh_calculateAABB'", nullptr);
            return 0;
        }
        cobj->calculateAABB();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Mesh:calculateAABB",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Mesh_calculateAABB'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Mesh_draw(lua_State* tolua_S)
{
    int argc = 0;
    axis::Mesh* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Mesh",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Mesh*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Mesh_draw'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 7) 
    {
        axis::Renderer* arg0;
        double arg1;
        axis::Mat4 arg2;
        unsigned int arg3;
        unsigned int arg4;
        axis::Vec4 arg5;
        bool arg6;

        ok &= luaval_to_object<axis::Renderer>(tolua_S, 2, "cc.Renderer",&arg0, "cc.Mesh:draw");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "cc.Mesh:draw");

        ok &= luaval_to_mat4(tolua_S, 4, &arg2, "cc.Mesh:draw");

        ok &= luaval_to_uint32(tolua_S, 5,&arg3, "cc.Mesh:draw");

        ok &= luaval_to_uint32(tolua_S, 6,&arg4, "cc.Mesh:draw");

        ok &= luaval_to_vec4(tolua_S, 7, &arg5, "cc.Mesh:draw");

        ok &= luaval_to_boolean(tolua_S, 8,&arg6, "cc.Mesh:draw");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Mesh_draw'", nullptr);
            return 0;
        }
        cobj->draw(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Mesh:draw",argc, 7);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Mesh_draw'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Mesh_getBlendFunc(lua_State* tolua_S)
{
    int argc = 0;
    axis::Mesh* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Mesh",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Mesh*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Mesh_getBlendFunc'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Mesh_getBlendFunc'", nullptr);
            return 0;
        }
        const axis::BlendFunc& ret = cobj->getBlendFunc();
        blendfunc_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Mesh:getBlendFunc",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Mesh_getBlendFunc'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Mesh_setName(lua_State* tolua_S)
{
    int argc = 0;
    axis::Mesh* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Mesh",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Mesh*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Mesh_setName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string_view arg0;

        ok &= luaval_to_std_string_view(tolua_S, 2,&arg0, "cc.Mesh:setName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Mesh_setName'", nullptr);
            return 0;
        }
        cobj->setName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Mesh:setName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Mesh_setName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Mesh_setMeshIndexData(lua_State* tolua_S)
{
    int argc = 0;
    axis::Mesh* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Mesh",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Mesh*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Mesh_setMeshIndexData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        axis::MeshIndexData* arg0;

        ok &= luaval_to_object<axis::MeshIndexData>(tolua_S, 2, "cc.MeshIndexData",&arg0, "cc.Mesh:setMeshIndexData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Mesh_setMeshIndexData'", nullptr);
            return 0;
        }
        cobj->setMeshIndexData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Mesh:setMeshIndexData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Mesh_setMeshIndexData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Mesh_getProgramState(lua_State* tolua_S)
{
    int argc = 0;
    axis::Mesh* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Mesh",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Mesh*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Mesh_getProgramState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Mesh_getProgramState'", nullptr);
            return 0;
        }
        axis::backend::ProgramState* ret = cobj->getProgramState();
        object_to_luaval<axis::backend::ProgramState>(tolua_S, "ccb.ProgramState",(axis::backend::ProgramState*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Mesh:getProgramState",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Mesh_getProgramState'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Mesh_getMeshVertexAttribCount(lua_State* tolua_S)
{
    int argc = 0;
    axis::Mesh* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Mesh",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Mesh*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Mesh_getMeshVertexAttribCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Mesh_getMeshVertexAttribCount'", nullptr);
            return 0;
        }
        ssize_t ret = cobj->getMeshVertexAttribCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Mesh:getMeshVertexAttribCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Mesh_getMeshVertexAttribCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Mesh_setBlendFunc(lua_State* tolua_S)
{
    int argc = 0;
    axis::Mesh* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Mesh",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Mesh*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Mesh_setBlendFunc'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        axis::BlendFunc arg0;

        ok &= luaval_to_blendfunc(tolua_S, 2, &arg0, "cc.Mesh:setBlendFunc");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Mesh_setBlendFunc'", nullptr);
            return 0;
        }
        cobj->setBlendFunc(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Mesh:setBlendFunc",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Mesh_setBlendFunc'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Mesh_setForce2DQueue(lua_State* tolua_S)
{
    int argc = 0;
    axis::Mesh* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Mesh",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Mesh*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Mesh_setForce2DQueue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.Mesh:setForce2DQueue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Mesh_setForce2DQueue'", nullptr);
            return 0;
        }
        cobj->setForce2DQueue(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Mesh:setForce2DQueue",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Mesh_setForce2DQueue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Mesh_setSkin(lua_State* tolua_S)
{
    int argc = 0;
    axis::Mesh* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Mesh",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Mesh*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Mesh_setSkin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        axis::MeshSkin* arg0;

        ok &= luaval_to_object<axis::MeshSkin>(tolua_S, 2, "cc.MeshSkin",&arg0, "cc.Mesh:setSkin");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Mesh_setSkin'", nullptr);
            return 0;
        }
        cobj->setSkin(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Mesh:setSkin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Mesh_setSkin'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Mesh_isVisible(lua_State* tolua_S)
{
    int argc = 0;
    axis::Mesh* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Mesh",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Mesh*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Mesh_isVisible'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Mesh_isVisible'", nullptr);
            return 0;
        }
        bool ret = cobj->isVisible();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Mesh:isVisible",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Mesh_isVisible'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Mesh_setVisible(lua_State* tolua_S)
{
    int argc = 0;
    axis::Mesh* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Mesh",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Mesh*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Mesh_setVisible'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.Mesh:setVisible");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Mesh_setVisible'", nullptr);
            return 0;
        }
        cobj->setVisible(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Mesh:setVisible",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Mesh_setVisible'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Mesh_constructor(lua_State* tolua_S)
{
    int argc = 0;
    axis::Mesh* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Mesh_constructor'", nullptr);
            return 0;
        }
        cobj = new axis::Mesh();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.Mesh");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Mesh:Mesh",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Mesh_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_3d_Mesh_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Mesh)");
    return 0;
}

int lua_register_cocos2dx_3d_Mesh(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.Mesh");
    tolua_cclass(tolua_S,"Mesh","cc.Mesh","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"Mesh");
        tolua_function(tolua_S,"new",lua_cocos2dx_3d_Mesh_constructor);
        tolua_function(tolua_S,"getMaterial",lua_cocos2dx_3d_Mesh_getMaterial);
        tolua_function(tolua_S,"getVertexSizeInBytes",lua_cocos2dx_3d_Mesh_getVertexSizeInBytes);
        tolua_function(tolua_S,"setProgramState",lua_cocos2dx_3d_Mesh_setProgramState);
        tolua_function(tolua_S,"setIndexFormat",lua_cocos2dx_3d_Mesh_setIndexFormat);
        tolua_function(tolua_S,"setMaterial",lua_cocos2dx_3d_Mesh_setMaterial);
        tolua_function(tolua_S,"getName",lua_cocos2dx_3d_Mesh_getName);
        tolua_function(tolua_S,"getMeshVertexAttribute",lua_cocos2dx_3d_Mesh_getMeshVertexAttribute);
        tolua_function(tolua_S,"calculateAABB",lua_cocos2dx_3d_Mesh_calculateAABB);
        tolua_function(tolua_S,"draw",lua_cocos2dx_3d_Mesh_draw);
        tolua_function(tolua_S,"getBlendFunc",lua_cocos2dx_3d_Mesh_getBlendFunc);
        tolua_function(tolua_S,"setName",lua_cocos2dx_3d_Mesh_setName);
        tolua_function(tolua_S,"setMeshIndexData",lua_cocos2dx_3d_Mesh_setMeshIndexData);
        tolua_function(tolua_S,"getProgramState",lua_cocos2dx_3d_Mesh_getProgramState);
        tolua_function(tolua_S,"getMeshVertexAttribCount",lua_cocos2dx_3d_Mesh_getMeshVertexAttribCount);
        tolua_function(tolua_S,"setBlendFunc",lua_cocos2dx_3d_Mesh_setBlendFunc);
        tolua_function(tolua_S,"setForce2DQueue",lua_cocos2dx_3d_Mesh_setForce2DQueue);
        tolua_function(tolua_S,"setSkin",lua_cocos2dx_3d_Mesh_setSkin);
        tolua_function(tolua_S,"isVisible",lua_cocos2dx_3d_Mesh_isVisible);
        tolua_function(tolua_S,"setVisible",lua_cocos2dx_3d_Mesh_setVisible);
    tolua_endmodule(tolua_S);
    auto typeName = typeid(axis::Mesh).name(); // rtti is literal storage
    g_luaType[reinterpret_cast<uintptr_t>(typeName)] = "cc.Mesh";
    g_typeCast[typeName] = "cc.Mesh";
    return 1;
}

int lua_cocos2dx_3d_Skeleton3D_removeAllBones(lua_State* tolua_S)
{
    int argc = 0;
    axis::Skeleton3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Skeleton3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Skeleton3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Skeleton3D_removeAllBones'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Skeleton3D_removeAllBones'", nullptr);
            return 0;
        }
        cobj->removeAllBones();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Skeleton3D:removeAllBones",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Skeleton3D_removeAllBones'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Skeleton3D_addBone(lua_State* tolua_S)
{
    int argc = 0;
    axis::Skeleton3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Skeleton3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Skeleton3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Skeleton3D_addBone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        axis::Bone3D* arg0;

        ok &= luaval_to_object<axis::Bone3D>(tolua_S, 2, "cc.Bone3D",&arg0, "cc.Skeleton3D:addBone");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Skeleton3D_addBone'", nullptr);
            return 0;
        }
        cobj->addBone(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Skeleton3D:addBone",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Skeleton3D_addBone'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Skeleton3D_getBoneByName(lua_State* tolua_S)
{
    int argc = 0;
    axis::Skeleton3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Skeleton3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Skeleton3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Skeleton3D_getBoneByName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string_view arg0;

        ok &= luaval_to_std_string_view(tolua_S, 2,&arg0, "cc.Skeleton3D:getBoneByName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Skeleton3D_getBoneByName'", nullptr);
            return 0;
        }
        axis::Bone3D* ret = cobj->getBoneByName(arg0);
        object_to_luaval<axis::Bone3D>(tolua_S, "cc.Bone3D",(axis::Bone3D*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Skeleton3D:getBoneByName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Skeleton3D_getBoneByName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Skeleton3D_getRootBone(lua_State* tolua_S)
{
    int argc = 0;
    axis::Skeleton3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Skeleton3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Skeleton3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Skeleton3D_getRootBone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.Skeleton3D:getRootBone");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Skeleton3D_getRootBone'", nullptr);
            return 0;
        }
        axis::Bone3D* ret = cobj->getRootBone(arg0);
        object_to_luaval<axis::Bone3D>(tolua_S, "cc.Bone3D",(axis::Bone3D*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Skeleton3D:getRootBone",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Skeleton3D_getRootBone'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Skeleton3D_updateBoneMatrix(lua_State* tolua_S)
{
    int argc = 0;
    axis::Skeleton3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Skeleton3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Skeleton3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Skeleton3D_updateBoneMatrix'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Skeleton3D_updateBoneMatrix'", nullptr);
            return 0;
        }
        cobj->updateBoneMatrix();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Skeleton3D:updateBoneMatrix",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Skeleton3D_updateBoneMatrix'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Skeleton3D_getBoneByIndex(lua_State* tolua_S)
{
    int argc = 0;
    axis::Skeleton3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Skeleton3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Skeleton3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Skeleton3D_getBoneByIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "cc.Skeleton3D:getBoneByIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Skeleton3D_getBoneByIndex'", nullptr);
            return 0;
        }
        axis::Bone3D* ret = cobj->getBoneByIndex(arg0);
        object_to_luaval<axis::Bone3D>(tolua_S, "cc.Bone3D",(axis::Bone3D*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Skeleton3D:getBoneByIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Skeleton3D_getBoneByIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Skeleton3D_getRootCount(lua_State* tolua_S)
{
    int argc = 0;
    axis::Skeleton3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Skeleton3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Skeleton3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Skeleton3D_getRootCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Skeleton3D_getRootCount'", nullptr);
            return 0;
        }
        ssize_t ret = cobj->getRootCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Skeleton3D:getRootCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Skeleton3D_getRootCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Skeleton3D_getBoneIndex(lua_State* tolua_S)
{
    int argc = 0;
    axis::Skeleton3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Skeleton3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Skeleton3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Skeleton3D_getBoneIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        axis::Bone3D* arg0;

        ok &= luaval_to_object<axis::Bone3D>(tolua_S, 2, "cc.Bone3D",&arg0, "cc.Skeleton3D:getBoneIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Skeleton3D_getBoneIndex'", nullptr);
            return 0;
        }
        int ret = cobj->getBoneIndex(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Skeleton3D:getBoneIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Skeleton3D_getBoneIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Skeleton3D_getBoneCount(lua_State* tolua_S)
{
    int argc = 0;
    axis::Skeleton3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Skeleton3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Skeleton3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Skeleton3D_getBoneCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Skeleton3D_getBoneCount'", nullptr);
            return 0;
        }
        ssize_t ret = cobj->getBoneCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Skeleton3D:getBoneCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Skeleton3D_getBoneCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Skeleton3D_constructor(lua_State* tolua_S)
{
    int argc = 0;
    axis::Skeleton3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Skeleton3D_constructor'", nullptr);
            return 0;
        }
        cobj = new axis::Skeleton3D();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.Skeleton3D");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Skeleton3D:Skeleton3D",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Skeleton3D_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_3d_Skeleton3D_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Skeleton3D)");
    return 0;
}

int lua_register_cocos2dx_3d_Skeleton3D(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.Skeleton3D");
    tolua_cclass(tolua_S,"Skeleton3D","cc.Skeleton3D","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"Skeleton3D");
        tolua_function(tolua_S,"new",lua_cocos2dx_3d_Skeleton3D_constructor);
        tolua_function(tolua_S,"removeAllBones",lua_cocos2dx_3d_Skeleton3D_removeAllBones);
        tolua_function(tolua_S,"addBone",lua_cocos2dx_3d_Skeleton3D_addBone);
        tolua_function(tolua_S,"getBoneByName",lua_cocos2dx_3d_Skeleton3D_getBoneByName);
        tolua_function(tolua_S,"getRootBone",lua_cocos2dx_3d_Skeleton3D_getRootBone);
        tolua_function(tolua_S,"updateBoneMatrix",lua_cocos2dx_3d_Skeleton3D_updateBoneMatrix);
        tolua_function(tolua_S,"getBoneByIndex",lua_cocos2dx_3d_Skeleton3D_getBoneByIndex);
        tolua_function(tolua_S,"getRootCount",lua_cocos2dx_3d_Skeleton3D_getRootCount);
        tolua_function(tolua_S,"getBoneIndex",lua_cocos2dx_3d_Skeleton3D_getBoneIndex);
        tolua_function(tolua_S,"getBoneCount",lua_cocos2dx_3d_Skeleton3D_getBoneCount);
    tolua_endmodule(tolua_S);
    auto typeName = typeid(axis::Skeleton3D).name(); // rtti is literal storage
    g_luaType[reinterpret_cast<uintptr_t>(typeName)] = "cc.Skeleton3D";
    g_typeCast[typeName] = "cc.Skeleton3D";
    return 1;
}

int lua_cocos2dx_3d_Skybox_reload(lua_State* tolua_S)
{
    int argc = 0;
    axis::Skybox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Skybox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Skybox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Skybox_reload'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Skybox_reload'", nullptr);
            return 0;
        }
        cobj->reload();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Skybox:reload",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Skybox_reload'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Skybox_init(lua_State* tolua_S)
{
    int argc = 0;
    axis::Skybox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Skybox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Skybox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Skybox_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 6) 
    {
        std::string_view arg0;
        std::string_view arg1;
        std::string_view arg2;
        std::string_view arg3;
        std::string_view arg4;
        std::string_view arg5;

        ok &= luaval_to_std_string_view(tolua_S, 2,&arg0, "cc.Skybox:init");

        ok &= luaval_to_std_string_view(tolua_S, 3,&arg1, "cc.Skybox:init");

        ok &= luaval_to_std_string_view(tolua_S, 4,&arg2, "cc.Skybox:init");

        ok &= luaval_to_std_string_view(tolua_S, 5,&arg3, "cc.Skybox:init");

        ok &= luaval_to_std_string_view(tolua_S, 6,&arg4, "cc.Skybox:init");

        ok &= luaval_to_std_string_view(tolua_S, 7,&arg5, "cc.Skybox:init");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Skybox_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init(arg0, arg1, arg2, arg3, arg4, arg5);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Skybox:init",argc, 6);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Skybox_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Skybox_setTexture(lua_State* tolua_S)
{
    int argc = 0;
    axis::Skybox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Skybox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Skybox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Skybox_setTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        axis::TextureCube* arg0;

        ok &= luaval_to_object<axis::TextureCube>(tolua_S, 2, "cc.TextureCube",&arg0, "cc.Skybox:setTexture");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Skybox_setTexture'", nullptr);
            return 0;
        }
        cobj->setTexture(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Skybox:setTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Skybox_setTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Skybox_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.Skybox",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 6)
        {
            std::string_view arg0;
            ok &= luaval_to_std_string_view(tolua_S, 2,&arg0, "cc.Skybox:create");
            if (!ok) { break; }
            std::string_view arg1;
            ok &= luaval_to_std_string_view(tolua_S, 3,&arg1, "cc.Skybox:create");
            if (!ok) { break; }
            std::string_view arg2;
            ok &= luaval_to_std_string_view(tolua_S, 4,&arg2, "cc.Skybox:create");
            if (!ok) { break; }
            std::string_view arg3;
            ok &= luaval_to_std_string_view(tolua_S, 5,&arg3, "cc.Skybox:create");
            if (!ok) { break; }
            std::string_view arg4;
            ok &= luaval_to_std_string_view(tolua_S, 6,&arg4, "cc.Skybox:create");
            if (!ok) { break; }
            std::string_view arg5;
            ok &= luaval_to_std_string_view(tolua_S, 7,&arg5, "cc.Skybox:create");
            if (!ok) { break; }
            axis::Skybox* ret = axis::Skybox::create(arg0, arg1, arg2, arg3, arg4, arg5);
            object_to_luaval<axis::Skybox>(tolua_S, "cc.Skybox",(axis::Skybox*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            axis::Skybox* ret = axis::Skybox::create();
            object_to_luaval<axis::Skybox>(tolua_S, "cc.Skybox",(axis::Skybox*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "cc.Skybox:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Skybox_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_3d_Skybox_constructor(lua_State* tolua_S)
{
    int argc = 0;
    axis::Skybox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Skybox_constructor'", nullptr);
            return 0;
        }
        cobj = new axis::Skybox();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.Skybox");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Skybox:Skybox",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Skybox_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_3d_Skybox_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Skybox)");
    return 0;
}

int lua_register_cocos2dx_3d_Skybox(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.Skybox");
    tolua_cclass(tolua_S,"Skybox","cc.Skybox","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"Skybox");
        tolua_function(tolua_S,"new",lua_cocos2dx_3d_Skybox_constructor);
        tolua_function(tolua_S,"reload",lua_cocos2dx_3d_Skybox_reload);
        tolua_function(tolua_S,"init",lua_cocos2dx_3d_Skybox_init);
        tolua_function(tolua_S,"setTexture",lua_cocos2dx_3d_Skybox_setTexture);
        tolua_function(tolua_S,"create", lua_cocos2dx_3d_Skybox_create);
    tolua_endmodule(tolua_S);
    auto typeName = typeid(axis::Skybox).name(); // rtti is literal storage
    g_luaType[reinterpret_cast<uintptr_t>(typeName)] = "cc.Skybox";
    g_typeCast[typeName] = "cc.Skybox";
    return 1;
}

int lua_cocos2dx_3d_Terrain_initHeightMap(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Terrain",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Terrain*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Terrain_initHeightMap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string_view arg0;

        ok &= luaval_to_std_string_view(tolua_S, 2,&arg0, "cc.Terrain:initHeightMap");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_initHeightMap'", nullptr);
            return 0;
        }
        bool ret = cobj->initHeightMap(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:initHeightMap",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_initHeightMap'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Terrain_setMaxDetailMapAmount(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Terrain",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Terrain*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Terrain_setMaxDetailMapAmount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.Terrain:setMaxDetailMapAmount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_setMaxDetailMapAmount'", nullptr);
            return 0;
        }
        cobj->setMaxDetailMapAmount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:setMaxDetailMapAmount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_setMaxDetailMapAmount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Terrain_setDrawWire(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Terrain",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Terrain*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Terrain_setDrawWire'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.Terrain:setDrawWire");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_setDrawWire'", nullptr);
            return 0;
        }
        cobj->setDrawWire(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:setDrawWire",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_setDrawWire'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Terrain_getHeightData(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Terrain",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Terrain*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Terrain_getHeightData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_getHeightData'", nullptr);
            return 0;
        }
        std::vector<float> ret = cobj->getHeightData();
        ccvector_float_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:getHeightData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_getHeightData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Terrain_setDetailMap(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Terrain",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Terrain*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Terrain_setDetailMap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned int arg0;
        axis::Terrain::DetailMap arg1;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "cc.Terrain:setDetailMap");

        #pragma warning NO CONVERSION TO NATIVE FOR DetailMap
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_setDetailMap'", nullptr);
            return 0;
        }
        cobj->setDetailMap(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:setDetailMap",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_setDetailMap'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Terrain_resetHeightMap(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Terrain",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Terrain*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Terrain_resetHeightMap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string_view arg0;

        ok &= luaval_to_std_string_view(tolua_S, 2,&arg0, "cc.Terrain:resetHeightMap");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_resetHeightMap'", nullptr);
            return 0;
        }
        cobj->resetHeightMap(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:resetHeightMap",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_resetHeightMap'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Terrain_setLightDir(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Terrain",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Terrain*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Terrain_setLightDir'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        axis::Vec3 arg0;

        ok &= luaval_to_vec3(tolua_S, 2, &arg0, "cc.Terrain:setLightDir");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_setLightDir'", nullptr);
            return 0;
        }
        cobj->setLightDir(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:setLightDir",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_setLightDir'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Terrain_setAlphaMap(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Terrain",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Terrain*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Terrain_setAlphaMap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        axis::Texture2D* arg0;

        ok &= luaval_to_object<axis::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0, "cc.Terrain:setAlphaMap");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_setAlphaMap'", nullptr);
            return 0;
        }
        cobj->setAlphaMap(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:setAlphaMap",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_setAlphaMap'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Terrain_setSkirtHeightRatio(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Terrain",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Terrain*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Terrain_setSkirtHeightRatio'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.Terrain:setSkirtHeightRatio");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_setSkirtHeightRatio'", nullptr);
            return 0;
        }
        cobj->setSkirtHeightRatio(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:setSkirtHeightRatio",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_setSkirtHeightRatio'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Terrain_convertToTerrainSpace(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Terrain",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Terrain*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Terrain_convertToTerrainSpace'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        axis::Vec2 arg0;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "cc.Terrain:convertToTerrainSpace");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_convertToTerrainSpace'", nullptr);
            return 0;
        }
        axis::Vec2 ret = cobj->convertToTerrainSpace(arg0);
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:convertToTerrainSpace",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_convertToTerrainSpace'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Terrain_initTextures(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Terrain",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Terrain*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Terrain_initTextures'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_initTextures'", nullptr);
            return 0;
        }
        bool ret = cobj->initTextures();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:initTextures",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_initTextures'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Terrain_initProperties(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Terrain",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Terrain*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Terrain_initProperties'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_initProperties'", nullptr);
            return 0;
        }
        bool ret = cobj->initProperties();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:initProperties",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_initProperties'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Terrain_initWithTerrainData(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Terrain",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Terrain*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Terrain_initWithTerrainData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        axis::Terrain::TerrainData arg0;
        axis::Terrain::CrackFixedType arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR TerrainData
		ok = false;

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "cc.Terrain:initWithTerrainData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_initWithTerrainData'", nullptr);
            return 0;
        }
        bool ret = cobj->initWithTerrainData(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:initWithTerrainData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_initWithTerrainData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Terrain_setLODDistance(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Terrain",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Terrain*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Terrain_setLODDistance'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        double arg1;
        double arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "cc.Terrain:setLODDistance");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "cc.Terrain:setLODDistance");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "cc.Terrain:setLODDistance");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_setLODDistance'", nullptr);
            return 0;
        }
        cobj->setLODDistance(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:setLODDistance",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_setLODDistance'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Terrain_getTerrainSize(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Terrain",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Terrain*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Terrain_getTerrainSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_getTerrainSize'", nullptr);
            return 0;
        }
        axis::Vec2 ret = cobj->getTerrainSize();
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:getTerrainSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_getTerrainSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Terrain_getNormal(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Terrain",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Terrain*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Terrain_getNormal'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.Terrain:getNormal");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "cc.Terrain:getNormal");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_getNormal'", nullptr);
            return 0;
        }
        axis::Vec3 ret = cobj->getNormal(arg0, arg1);
        vec3_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:getNormal",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_getNormal'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Terrain_reload(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Terrain",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Terrain*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Terrain_reload'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_reload'", nullptr);
            return 0;
        }
        cobj->reload();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:reload",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_reload'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Terrain_getImageHeight(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Terrain",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Terrain*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Terrain_getImageHeight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.Terrain:getImageHeight");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "cc.Terrain:getImageHeight");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_getImageHeight'", nullptr);
            return 0;
        }
        double ret = cobj->getImageHeight(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:getImageHeight",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_getImageHeight'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Terrain_setLightMap(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Terrain",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Terrain*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Terrain_setLightMap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string_view arg0;

        ok &= luaval_to_std_string_view(tolua_S, 2,&arg0, "cc.Terrain:setLightMap");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_setLightMap'", nullptr);
            return 0;
        }
        cobj->setLightMap(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:setLightMap",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_setLightMap'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Terrain_setIsEnableFrustumCull(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Terrain",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Terrain*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Terrain_setIsEnableFrustumCull'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "cc.Terrain:setIsEnableFrustumCull");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_setIsEnableFrustumCull'", nullptr);
            return 0;
        }
        cobj->setIsEnableFrustumCull(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:setIsEnableFrustumCull",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_setIsEnableFrustumCull'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Terrain_getMinHeight(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Terrain",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Terrain*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Terrain_getMinHeight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_getMinHeight'", nullptr);
            return 0;
        }
        double ret = cobj->getMinHeight();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:getMinHeight",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_getMinHeight'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Terrain_getMaxHeight(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Terrain",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Terrain*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Terrain_getMaxHeight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_getMaxHeight'", nullptr);
            return 0;
        }
        double ret = cobj->getMaxHeight();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:getMaxHeight",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_getMaxHeight'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Terrain_constructor(lua_State* tolua_S)
{
    int argc = 0;
    axis::Terrain* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Terrain_constructor'", nullptr);
            return 0;
        }
        cobj = new axis::Terrain();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.Terrain");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Terrain:Terrain",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Terrain_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_3d_Terrain_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Terrain)");
    return 0;
}

int lua_register_cocos2dx_3d_Terrain(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.Terrain");
    tolua_cclass(tolua_S,"Terrain","cc.Terrain","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"Terrain");
        tolua_function(tolua_S,"new",lua_cocos2dx_3d_Terrain_constructor);
        tolua_function(tolua_S,"initHeightMap",lua_cocos2dx_3d_Terrain_initHeightMap);
        tolua_function(tolua_S,"setMaxDetailMapAmount",lua_cocos2dx_3d_Terrain_setMaxDetailMapAmount);
        tolua_function(tolua_S,"setDrawWire",lua_cocos2dx_3d_Terrain_setDrawWire);
        tolua_function(tolua_S,"getHeightData",lua_cocos2dx_3d_Terrain_getHeightData);
        tolua_function(tolua_S,"setDetailMap",lua_cocos2dx_3d_Terrain_setDetailMap);
        tolua_function(tolua_S,"resetHeightMap",lua_cocos2dx_3d_Terrain_resetHeightMap);
        tolua_function(tolua_S,"setLightDir",lua_cocos2dx_3d_Terrain_setLightDir);
        tolua_function(tolua_S,"setAlphaMap",lua_cocos2dx_3d_Terrain_setAlphaMap);
        tolua_function(tolua_S,"setSkirtHeightRatio",lua_cocos2dx_3d_Terrain_setSkirtHeightRatio);
        tolua_function(tolua_S,"convertToTerrainSpace",lua_cocos2dx_3d_Terrain_convertToTerrainSpace);
        tolua_function(tolua_S,"initTextures",lua_cocos2dx_3d_Terrain_initTextures);
        tolua_function(tolua_S,"initProperties",lua_cocos2dx_3d_Terrain_initProperties);
        tolua_function(tolua_S,"initWithTerrainData",lua_cocos2dx_3d_Terrain_initWithTerrainData);
        tolua_function(tolua_S,"setLODDistance",lua_cocos2dx_3d_Terrain_setLODDistance);
        tolua_function(tolua_S,"getTerrainSize",lua_cocos2dx_3d_Terrain_getTerrainSize);
        tolua_function(tolua_S,"getNormal",lua_cocos2dx_3d_Terrain_getNormal);
        tolua_function(tolua_S,"reload",lua_cocos2dx_3d_Terrain_reload);
        tolua_function(tolua_S,"getImageHeight",lua_cocos2dx_3d_Terrain_getImageHeight);
        tolua_function(tolua_S,"setLightMap",lua_cocos2dx_3d_Terrain_setLightMap);
        tolua_function(tolua_S,"setIsEnableFrustumCull",lua_cocos2dx_3d_Terrain_setIsEnableFrustumCull);
        tolua_function(tolua_S,"getMinHeight",lua_cocos2dx_3d_Terrain_getMinHeight);
        tolua_function(tolua_S,"getMaxHeight",lua_cocos2dx_3d_Terrain_getMaxHeight);
    tolua_endmodule(tolua_S);
    auto typeName = typeid(axis::Terrain).name(); // rtti is literal storage
    g_luaType[reinterpret_cast<uintptr_t>(typeName)] = "cc.Terrain";
    g_typeCast[typeName] = "cc.Terrain";
    return 1;
}

int lua_cocos2dx_3d_Bundle3D_load(lua_State* tolua_S)
{
    int argc = 0;
    axis::Bundle3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Bundle3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Bundle3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Bundle3D_load'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string_view arg0;

        ok &= luaval_to_std_string_view(tolua_S, 2,&arg0, "cc.Bundle3D:load");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Bundle3D_load'", nullptr);
            return 0;
        }
        bool ret = cobj->load(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Bundle3D:load",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Bundle3D_load'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Bundle3D_loadSkinData(lua_State* tolua_S)
{
    int argc = 0;
    axis::Bundle3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Bundle3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Bundle3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Bundle3D_loadSkinData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string_view arg0;
        axis::SkinData* arg1;

        ok &= luaval_to_std_string_view(tolua_S, 2,&arg0, "cc.Bundle3D:loadSkinData");

        #pragma warning NO CONVERSION TO NATIVE FOR SkinData*
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Bundle3D_loadSkinData'", nullptr);
            return 0;
        }
        bool ret = cobj->loadSkinData(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Bundle3D:loadSkinData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Bundle3D_loadSkinData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Bundle3D_clear(lua_State* tolua_S)
{
    int argc = 0;
    axis::Bundle3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Bundle3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Bundle3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Bundle3D_clear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Bundle3D_clear'", nullptr);
            return 0;
        }
        cobj->clear();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Bundle3D:clear",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Bundle3D_clear'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Bundle3D_loadMaterials(lua_State* tolua_S)
{
    int argc = 0;
    axis::Bundle3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Bundle3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Bundle3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Bundle3D_loadMaterials'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        axis::MaterialDatas arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR MaterialDatas
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Bundle3D_loadMaterials'", nullptr);
            return 0;
        }
        bool ret = cobj->loadMaterials(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Bundle3D:loadMaterials",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Bundle3D_loadMaterials'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Bundle3D_loadNodes(lua_State* tolua_S)
{
    int argc = 0;
    axis::Bundle3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Bundle3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Bundle3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Bundle3D_loadNodes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        axis::NodeDatas arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR NodeDatas
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Bundle3D_loadNodes'", nullptr);
            return 0;
        }
        bool ret = cobj->loadNodes(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Bundle3D:loadNodes",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Bundle3D_loadNodes'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Bundle3D_loadAnimationData(lua_State* tolua_S)
{
    int argc = 0;
    axis::Bundle3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Bundle3D",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (axis::Bundle3D*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Bundle3D_loadAnimationData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string_view arg0;
        axis::Animation3DData* arg1;

        ok &= luaval_to_std_string_view(tolua_S, 2,&arg0, "cc.Bundle3D:loadAnimationData");

        #pragma warning NO CONVERSION TO NATIVE FOR Animation3DData*
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Bundle3D_loadAnimationData'", nullptr);
            return 0;
        }
        bool ret = cobj->loadAnimationData(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Bundle3D:loadAnimationData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Bundle3D_loadAnimationData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_3d_Bundle3D_parseSamplerAddressMode(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.Bundle3D",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string_view arg0;
        ok &= luaval_to_std_string_view(tolua_S, 2,&arg0, "cc.Bundle3D:parseSamplerAddressMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Bundle3D_parseSamplerAddressMode'", nullptr);
            return 0;
        }
        int ret = (int)axis::Bundle3D::parseSamplerAddressMode(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.Bundle3D:parseSamplerAddressMode",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Bundle3D_parseSamplerAddressMode'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_3d_Bundle3D_destroyBundle(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.Bundle3D",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        axis::Bundle3D* arg0;
        ok &= luaval_to_object<axis::Bundle3D>(tolua_S, 2, "cc.Bundle3D",&arg0, "cc.Bundle3D:destroyBundle");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Bundle3D_destroyBundle'", nullptr);
            return 0;
        }
        axis::Bundle3D::destroyBundle(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.Bundle3D:destroyBundle",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Bundle3D_destroyBundle'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_3d_Bundle3D_createBundle(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.Bundle3D",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Bundle3D_createBundle'", nullptr);
            return 0;
        }
        axis::Bundle3D* ret = axis::Bundle3D::createBundle();
        object_to_luaval<axis::Bundle3D>(tolua_S, "cc.Bundle3D",(axis::Bundle3D*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.Bundle3D:createBundle",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Bundle3D_createBundle'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_3d_Bundle3D_parseGLDataType(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.Bundle3D",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string_view arg0;
        int arg1;
        ok &= luaval_to_std_string_view(tolua_S, 2,&arg0, "cc.Bundle3D:parseGLDataType");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "cc.Bundle3D:parseGLDataType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Bundle3D_parseGLDataType'", nullptr);
            return 0;
        }
        int ret = (int)axis::Bundle3D::parseGLDataType(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.Bundle3D:parseGLDataType",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Bundle3D_parseGLDataType'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_3d_Bundle3D_constructor(lua_State* tolua_S)
{
    int argc = 0;
    axis::Bundle3D* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_3d_Bundle3D_constructor'", nullptr);
            return 0;
        }
        cobj = new axis::Bundle3D();
        tolua_pushusertype(tolua_S,(void*)cobj,"cc.Bundle3D");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Bundle3D:Bundle3D",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Bundle3D_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_3d_Bundle3D_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Bundle3D)");
    return 0;
}

int lua_register_cocos2dx_3d_Bundle3D(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.Bundle3D");
    tolua_cclass(tolua_S,"Bundle3D","cc.Bundle3D","",nullptr);

    tolua_beginmodule(tolua_S,"Bundle3D");
        tolua_function(tolua_S,"new",lua_cocos2dx_3d_Bundle3D_constructor);
        tolua_function(tolua_S,"load",lua_cocos2dx_3d_Bundle3D_load);
        tolua_function(tolua_S,"loadSkinData",lua_cocos2dx_3d_Bundle3D_loadSkinData);
        tolua_function(tolua_S,"clear",lua_cocos2dx_3d_Bundle3D_clear);
        tolua_function(tolua_S,"loadMaterials",lua_cocos2dx_3d_Bundle3D_loadMaterials);
        tolua_function(tolua_S,"loadNodes",lua_cocos2dx_3d_Bundle3D_loadNodes);
        tolua_function(tolua_S,"loadAnimationData",lua_cocos2dx_3d_Bundle3D_loadAnimationData);
        tolua_function(tolua_S,"parseSamplerAddressMode", lua_cocos2dx_3d_Bundle3D_parseSamplerAddressMode);
        tolua_function(tolua_S,"destroyBundle", lua_cocos2dx_3d_Bundle3D_destroyBundle);
        tolua_function(tolua_S,"createBundle", lua_cocos2dx_3d_Bundle3D_createBundle);
        tolua_function(tolua_S,"parseGLDataType", lua_cocos2dx_3d_Bundle3D_parseGLDataType);
    tolua_endmodule(tolua_S);
    auto typeName = typeid(axis::Bundle3D).name(); // rtti is literal storage
    g_luaType[reinterpret_cast<uintptr_t>(typeName)] = "cc.Bundle3D";
    g_typeCast[typeName] = "cc.Bundle3D";
    return 1;
}
TOLUA_API int register_all_cocos2dx_3d(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"cc",0);
	tolua_beginmodule(tolua_S,"cc");

	lua_register_cocos2dx_3d_Animate3D(tolua_S);
	lua_register_cocos2dx_3d_AttachNode(tolua_S);
	lua_register_cocos2dx_3d_TextureCube(tolua_S);
	lua_register_cocos2dx_3d_Terrain(tolua_S);
	lua_register_cocos2dx_3d_Skybox(tolua_S);
	lua_register_cocos2dx_3d_Bundle3D(tolua_S);
	lua_register_cocos2dx_3d_Skeleton3D(tolua_S);
	lua_register_cocos2dx_3d_BillBoard(tolua_S);
	lua_register_cocos2dx_3d_Animation3D(tolua_S);
	lua_register_cocos2dx_3d_Mesh(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

