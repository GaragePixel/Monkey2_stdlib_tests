
#include <bbmonkey.h>
#include <bbtypeinfo_r.h>
#include <bbdeclinfo_r.h>

#include "_r.h"

#include "sdk/api/physics/box2d/Box2D/Box2D_mx2.h"

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_gamegraphics_2gamegraphics.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_gamegraphics_2src_2background.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_gamegraphics_2src_2sprite.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_gamegraphics_2src_2tilegraphics.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_gridshooter.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_sdk_api_2physics_2box2d_2box2d.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2actor.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2area.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2bullet.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2orb.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2player.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2renderwindow.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_stdlib_collections_2container.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_stdlib_collections_2deque.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_stdlib_collections_2list.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_stdlib_collections_2map.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_stdlib_collections_2stack.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_stdlib_math_2algebraic_2vectorials_2types_2rect.h"
#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_types.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2app_2event.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2canvas.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2font.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2image.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2texture.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_collections_2stack.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_math_2algebraic_2vectorials_2types_2vec2.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_resources_2graphics_2color.h"

BB_CLASS(t_sdk_0mojo_m2_app_Window)
BB_ENUM(t_sdk_0mojo_m2_app_WindowFlags)

#if BB_R_default || BB_R_default__
static struct mx2_gridshooter_gridshooter_typeinfo : public bbClassDecls{
  mx2_gridshooter_gridshooter_typeinfo():bbClassDecls(bbClassTypeInfo::getNamespace("default")){
  }
  bbDeclInfo **initDecls(){
    return bbMembers(bbFunctionDecl<void>("Main",&bbMain));
  }
}_mx2_gridshooter_gridshooter_typeinfo;

struct rt_default_Game : public bbClassTypeInfo{
  static rt_default_Game instance;
  static struct decls_t : public bbClassDecls{
    decls_t():bbClassDecls(&instance){}
    bbDeclInfo **initDecls(){
      return bbMembers(bbCtorDecl<t_default_Game>(),bbFieldDecl("hero",&t_default_Game::m_hero),bbFieldDecl("bg",&t_default_Game::m_bg),bbFieldDecl("bgGrid",&t_default_Game::m_bgGrid),bbFieldDecl("smallFont",&t_default_Game::m_smallFont),bbFieldDecl("colorTint",&t_default_Game::m_colorTint),bbMethodDecl<t_default_Game,void>("OnUpdate",&t_default_Game::m_OnUpdate),bbMethodDecl<t_default_Game,void>("OnStart",&t_default_Game::m_OnStart),bbMethodDecl<t_default_Game,void>("OnDraw",&t_default_Game::m_OnDraw),bbGlobalDecl("cameraSpeed",&g_default_Game_cameraSpeed),bbGlobalDecl("scrollLimitY",&g_default_Game_scrollLimitY),bbGlobalDecl("scrollSpeed",&g_default_Game_scrollSpeed));
    }
  }decls;
  rt_default_Game():bbClassTypeInfo("default.Game","Class"){
  }
  bbTypeInfo *superType(){
    return bbGetType<t_default_RenderWindow*>();
  }
  bbVariant nullValue(){
    return bbVariant((t_default_Game*)0);
  }
  bbVariant newArray( int length ){
    return bbVariant(bbArray<bbGCVar<t_default_Game>>(length));
  }
};
rt_default_Game rt_default_Game::instance;
rt_default_Game::decls_t rt_default_Game::decls;

bbTypeInfo *bbGetType(t_default_Game*const&){
  return &rt_default_Game::instance;
}
bbTypeInfo *t_default_Game::typeof()const{
  return &rt_default_Game::instance;
}

struct rt_default_Orb : public bbClassTypeInfo{
  static rt_default_Orb instance;
  static struct decls_t : public bbClassDecls{
    decls_t():bbClassDecls(&instance){}
    bbDeclInfo **initDecls(){
      return bbMembers(bbCtorDecl<t_default_Orb,t_default_Sprite*>(),bbMethodDecl<t_default_Orb,void>("OnUpdate",&t_default_Orb::m_OnUpdate),bbMethodDecl<t_default_Orb,void>("OnReset",&t_default_Orb::m_OnReset),bbGlobalDecl("cullDistance",&g_default_Orb_cullDistance));
    }
  }decls;
  rt_default_Orb():bbClassTypeInfo("default.Orb","Class"){
  }
  bbTypeInfo *superType(){
    return bbGetType<t_default_Actor*>();
  }
  bbVariant nullValue(){
    return bbVariant((t_default_Orb*)0);
  }
  bbVariant newArray( int length ){
    return bbVariant(bbArray<bbGCVar<t_default_Orb>>(length));
  }
};
rt_default_Orb rt_default_Orb::instance;
rt_default_Orb::decls_t rt_default_Orb::decls;

bbTypeInfo *bbGetType(t_default_Orb*const&){
  return &rt_default_Orb::instance;
}
bbTypeInfo *t_default_Orb::typeof()const{
  return &rt_default_Orb::instance;
}

struct rt_default_Bullet : public bbClassTypeInfo{
  static rt_default_Bullet instance;
  static struct decls_t : public bbClassDecls{
    decls_t():bbClassDecls(&instance){}
    bbDeclInfo **initDecls(){
      return bbMembers(bbCtorDecl<t_default_Bullet,t_default_Sprite*>(),bbMethodDecl<t_default_Bullet,void>("OnUpdate",&t_default_Bullet::m_OnUpdate),bbMethodDecl<t_default_Bullet,void>("OnReset",&t_default_Bullet::m_OnReset));
    }
  }decls;
  rt_default_Bullet():bbClassTypeInfo("default.Bullet","Class"){
  }
  bbTypeInfo *superType(){
    return bbGetType<t_default_Actor*>();
  }
  bbVariant nullValue(){
    return bbVariant((t_default_Bullet*)0);
  }
  bbVariant newArray( int length ){
    return bbVariant(bbArray<bbGCVar<t_default_Bullet>>(length));
  }
};
rt_default_Bullet rt_default_Bullet::instance;
rt_default_Bullet::decls_t rt_default_Bullet::decls;

bbTypeInfo *bbGetType(t_default_Bullet*const&){
  return &rt_default_Bullet::instance;
}
bbTypeInfo *t_default_Bullet::typeof()const{
  return &rt_default_Bullet::instance;
}

struct rt_default_Player : public bbClassTypeInfo{
  static rt_default_Player instance;
  static struct decls_t : public bbClassDecls{
    decls_t():bbClassDecls(&instance){}
    bbDeclInfo **initDecls(){
      return bbMembers(bbCtorDecl<t_default_Player,t_default_Sprite*>(),bbFieldDecl("oldY",&t_default_Player::m_oldY),bbFieldDecl("limitY",&t_default_Player::m_limitY),bbMethodDecl<t_default_Player,void>("OnUpdate",&t_default_Player::m_OnUpdate));
    }
  }decls;
  rt_default_Player():bbClassTypeInfo("default.Player","Class"){
  }
  bbTypeInfo *superType(){
    return bbGetType<t_default_Actor*>();
  }
  bbVariant nullValue(){
    return bbVariant((t_default_Player*)0);
  }
  bbVariant newArray( int length ){
    return bbVariant(bbArray<bbGCVar<t_default_Player>>(length));
  }
};
rt_default_Player rt_default_Player::instance;
rt_default_Player::decls_t rt_default_Player::decls;

bbTypeInfo *bbGetType(t_default_Player*const&){
  return &rt_default_Player::instance;
}
bbTypeInfo *t_default_Player::typeof()const{
  return &rt_default_Player::instance;
}

struct rt_default_Actor : public bbClassTypeInfo{
  static rt_default_Actor instance;
  static struct decls_t : public bbClassDecls{
    decls_t():bbClassDecls(&instance){}
    bbDeclInfo **initDecls(){
      return bbMembers(bbCtorDecl<t_default_Actor,t_default_Sprite*>(),bbFieldDecl("name",&t_default_Actor::m_name),bbFieldDecl("visible",&t_default_Actor::m_visible),bbFieldDecl("speed",&t_default_Actor::m_speed),bbFieldDecl("anim",&t_default_Actor::m_anim),bbFieldDecl("detectCollision",&t_default_Actor::m_detectCollision),bbFieldDecl("sprite",&t_default_Actor::m_sprite),bbFieldDecl("position",&t_default_Actor::m_position),bbFieldDecl("collider",&t_default_Actor::m_collider),bbFieldDecl("_hide",&t_default_Actor::m__0hide),bbFieldDecl("_hideTimer",&t_default_Actor::m__0hideTimer),bbFieldDecl("_hideTimerStart",&t_default_Actor::m__0hideTimerStart),bbFieldDecl("_hideWait",&t_default_Actor::m__0hideWait),bbMethodDecl<t_default_Actor,void>("Reset",&t_default_Actor::m_Reset),bbMethodDecl<t_default_Actor,void>("OnUpdate",&t_default_Actor::m_OnUpdate),bbMethodDecl<t_default_Actor,void>("OnReset",&t_default_Actor::m_OnReset),bbMethodDecl<t_default_Actor,void,t_sdk_0mojo_m2_graphics_Canvas*>("OnDraw",&t_default_Actor::m_OnDraw),bbMethodDecl<t_default_Actor,void,bbInt>("Hide",&t_default_Actor::m_Hide),bbGlobalDecl("bulletPool",&g_default_Actor_bulletPool),bbGlobalDecl("camera",&g_default_Actor_camera),bbGlobalDecl("catalog",&g_default_Actor_catalog),bbGlobalDecl("cullDistance",&g_default_Actor_cullDistance),bbGlobalDecl("currentBullet",&g_default_Actor_currentBullet),bbGlobalDecl("player",&g_default_Actor_player),bbGlobalDecl("scrollSpeed",&g_default_Actor_scrollSpeed),bbFunctionDecl<void>("UpdateAll",&g_default_Actor_UpdateAll),bbFunctionDecl<void,t_sdk_0mojo_m2_graphics_Canvas*>("DrawAll",&g_default_Actor_DrawAll));
    }
  }decls;
  rt_default_Actor():bbClassTypeInfo("default.Actor","Class"){
  }
  bbTypeInfo *superType(){
    return bbGetType<bbObject*>();
  }
  bbVariant nullValue(){
    return bbVariant((t_default_Actor*)0);
  }
  bbVariant newArray( int length ){
    return bbVariant(bbArray<bbGCVar<t_default_Actor>>(length));
  }
};
rt_default_Actor rt_default_Actor::instance;
rt_default_Actor::decls_t rt_default_Actor::decls;

bbTypeInfo *bbGetType(t_default_Actor*const&){
  return &rt_default_Actor::instance;
}
bbTypeInfo *t_default_Actor::typeof()const{
  return &rt_default_Actor::instance;
}

struct rt_default_RenderWindow : public bbClassTypeInfo{
  static rt_default_RenderWindow instance;
  static struct decls_t : public bbClassDecls{
    decls_t():bbClassDecls(&instance){}
    bbDeclInfo **initDecls(){
      return bbMembers(bbCtorDecl<t_default_RenderWindow,bbString,bbInt,bbInt,bbBool,bbBool,t_sdk_0mojo_m2_app_WindowFlags>(),bbFieldDecl("canvas",&t_default_RenderWindow::m_canvas),bbFieldDecl("camera",&t_default_RenderWindow::m_camera),bbFieldDecl("renderToTexture",&t_default_RenderWindow::m_renderToTexture),bbFieldDecl("filterTextures",&t_default_RenderWindow::m_filterTextures),bbFieldDecl("bgColor",&t_default_RenderWindow::m_bgColor),bbFieldDecl("borderColor",&t_default_RenderWindow::m_borderColor),bbFieldDecl("debug",&t_default_RenderWindow::m_debug),bbFieldDecl("_init",&t_default_RenderWindow::m__0init),bbFieldDecl("_flags",&t_default_RenderWindow::m__0flags),bbFieldDecl("_parallax",&t_default_RenderWindow::m__0parallax),bbFieldDecl("_parallaxCam",&t_default_RenderWindow::m__0parallaxCam),bbFieldDecl("_virtualRes",&t_default_RenderWindow::m__0virtualRes),bbFieldDecl("_mouse",&t_default_RenderWindow::m__0mouse),bbFieldDecl("_adjustedMouse",&t_default_RenderWindow::m__0adjustedMouse),bbFieldDecl("_layerInitiated",&t_default_RenderWindow::m__0layerInitiated),bbFieldDecl("_fps",&t_default_RenderWindow::m__0fps),bbFieldDecl("_fpscount",&t_default_RenderWindow::m__0fpscount),bbFieldDecl("_tick",&t_default_RenderWindow::m__0tick),bbFieldDecl("_renderTexture",&t_default_RenderWindow::m__0renderTexture),bbFieldDecl("_renderImage",&t_default_RenderWindow::m__0renderImage),bbFieldDecl("_textureCanvas",&t_default_RenderWindow::m__0textureCanvas),bbFieldDecl("_windowCanvas",&t_default_RenderWindow::m__0windowCanvas),bbMethodDecl<t_default_RenderWindow,void>("WindowStart",&t_default_RenderWindow::m_WindowStart),bbMethodDecl<t_default_RenderWindow,void,bbInt,bbInt>("SetVirtualResolution",&t_default_RenderWindow::m_SetVirtualResolution),bbMethodDecl<t_default_RenderWindow,void>("SelectCanvas",&t_default_RenderWindow::m_SelectCanvas),bbMethodDecl<t_default_RenderWindow,void,t_sdk_0mojo_m2_app_WindowEvent*>("OnWindowEvent",&t_default_RenderWindow::m_OnWindowEvent),bbMethodDecl<t_default_RenderWindow,void>("OnUpdate",&t_default_RenderWindow::m_OnUpdate),bbMethodDecl<t_default_RenderWindow,void>("OnStart",&t_default_RenderWindow::m_OnStart),bbMethodDecl<t_default_RenderWindow,void,t_sdk_0mojo_m2_graphics_Canvas*>("OnRender",&t_default_RenderWindow::m_OnRender),bbMethodDecl<t_default_RenderWindow,t_stdlib_math_types_Vec2_1i>("OnMeasure",&t_default_RenderWindow::m_OnMeasure),bbMethodDecl<t_default_RenderWindow,void>("OnDraw",&t_default_RenderWindow::m_OnDraw),bbMethodDecl<t_default_RenderWindow,void>("FrameUpdate",&t_default_RenderWindow::m_FrameUpdate),bbMethodDecl<t_default_RenderWindow,void>("FrameDraw",&t_default_RenderWindow::m_FrameDraw),bbMethodDecl<t_default_RenderWindow,void>("DebugInfo",&t_default_RenderWindow::m_DebugInfo),bbMethodDecl<t_default_RenderWindow,void>("CycleLayout",&t_default_RenderWindow::m_CycleLayout),bbPropertyDecl<t_default_RenderWindow,bbFloat>("Bottom",&t_default_RenderWindow::m_Bottom,0),bbPropertyDecl<t_default_RenderWindow,t_stdlib_math_types_Rect_1d>("CameraRect",&t_default_RenderWindow::m_CameraRect,0),bbPropertyDecl<t_default_RenderWindow,bbInt>("FPS",&t_default_RenderWindow::m_FPS,0),bbPropertyDecl<t_default_RenderWindow,t_sdk_0mojo_m2_graphics_TextureFlags>("Flags",&t_default_RenderWindow::m_Flags,0),bbPropertyDecl<t_default_RenderWindow,bbFloat>("Left",&t_default_RenderWindow::m_Left,0),bbPropertyDecl<t_default_RenderWindow,t_stdlib_math_types_Vec2_1i>("Mouse",&t_default_RenderWindow::m_Mouse,0),bbPropertyDecl<t_default_RenderWindow,bbFloat>("Parallax",&t_default_RenderWindow::m_Parallax,&t_default_RenderWindow::m_Parallax),bbPropertyDecl<t_default_RenderWindow,bbFloat>("Right",&t_default_RenderWindow::m_Right,0),bbPropertyDecl<t_default_RenderWindow,bbFloat>("Top",&t_default_RenderWindow::m_Top,0),bbGlobalDecl("_echoStack",&g_default_RenderWindow__0echoStack),bbFunctionDecl<void,bbString>("Echo",&g_default_RenderWindow_Echo));
    }
  }decls;
  rt_default_RenderWindow():bbClassTypeInfo("default.RenderWindow","Class"){
  }
  bbTypeInfo *superType(){
    return bbGetType<t_sdk_0mojo_m2_app_Window*>();
  }
  bbVariant nullValue(){
    return bbVariant((t_default_RenderWindow*)0);
  }
  bbVariant newArray( int length ){
    return bbVariant(bbArray<bbGCVar<t_default_RenderWindow>>(length));
  }
};
rt_default_RenderWindow rt_default_RenderWindow::instance;
rt_default_RenderWindow::decls_t rt_default_RenderWindow::decls;

bbTypeInfo *bbGetType(t_default_RenderWindow*const&){
  return &rt_default_RenderWindow::instance;
}
bbTypeInfo *t_default_RenderWindow::typeof()const{
  return &rt_default_RenderWindow::instance;
}
static bbUnknownTypeInfo rt_default_Area_1d("default.Area<monkey.types.Double>");
bbTypeInfo *bbGetType(t_default_Area_1d*const&){
  return &rt_default_Area_1d;
}
bbTypeInfo *t_default_Area_1d::typeof()const{
  return &rt_default_Area_1d;
}

struct rt_default_GameGraphics : public bbClassTypeInfo{
  static rt_default_GameGraphics instance;
  static struct decls_t : public bbClassDecls{
    decls_t():bbClassDecls(&instance){}
    bbDeclInfo **initDecls(){
      return bbMembers(bbFieldDecl("images",&t_default_GameGraphics::m_images),bbFieldDecl("debug",&t_default_GameGraphics::m_debug),bbFieldDecl("_handle",&t_default_GameGraphics::m__0handle),bbMethodDecl<t_default_GameGraphics,bbArray<bbGCVar<t_sdk_0mojo_m2_graphics_Image>>,bbString,bbInt,bbInt,bbInt,bbBool,bbBool>("LoadFrames",&t_default_GameGraphics::m_LoadFrames),bbMethodDecl<t_default_GameGraphics,void,t_sdk_0mojo_m2_graphics_Canvas*,bbFloat,bbFloat,bbFloat,bbFloat,bbFloat,bbFloat,bbFloat>("DrawOutline",&t_default_GameGraphics::m_DrawOutline),bbPropertyDecl<t_default_GameGraphics,t_stdlib_math_types_Vec2_1f>("Handle",&t_default_GameGraphics::m_Handle,&t_default_GameGraphics::m_Handle),bbPropertyDecl<t_default_GameGraphics,bbDouble>("Height",&t_default_GameGraphics::m_Height,0),bbPropertyDecl<t_default_GameGraphics,bbDouble>("Width",&t_default_GameGraphics::m_Width,0),bbFunctionDecl<void,t_sdk_0mojo_m2_graphics_Canvas*,bbInt,bbInt,bbInt,bbInt>("DrawRectOutline",&g_default_GameGraphics_DrawRectOutline));
    }
  }decls;
  rt_default_GameGraphics():bbClassTypeInfo("default.GameGraphics","Class"){
  }
  bbTypeInfo *superType(){
    return bbGetType<bbObject*>();
  }
  bbVariant nullValue(){
    return bbVariant((t_default_GameGraphics*)0);
  }
  bbVariant newArray( int length ){
    return bbVariant(bbArray<bbGCVar<t_default_GameGraphics>>(length));
  }
};
rt_default_GameGraphics rt_default_GameGraphics::instance;
rt_default_GameGraphics::decls_t rt_default_GameGraphics::decls;

bbTypeInfo *bbGetType(t_default_GameGraphics*const&){
  return &rt_default_GameGraphics::instance;
}
bbTypeInfo *t_default_GameGraphics::typeof()const{
  return &rt_default_GameGraphics::instance;
}

struct rt_default_Background : public bbClassTypeInfo{
  static rt_default_Background instance;
  static struct decls_t : public bbClassDecls{
    decls_t():bbClassDecls(&instance){}
    bbDeclInfo **initDecls(){
      return bbMembers(bbCtorDecl<t_default_Background,bbString>(),bbFieldDecl("total",&t_default_Background::m_total),bbMethodDecl<t_default_Background,bbString>("ToString",&t_default_Background::m_ToString),bbMethodDecl<t_default_Background,void,t_sdk_0mojo_m2_graphics_Canvas*,bbDouble,bbDouble,bbDouble,t_stdlib_math_types_Rect_1d>("Draw",&t_default_Background::m_Draw));
    }
  }decls;
  rt_default_Background():bbClassTypeInfo("default.Background","Class"){
  }
  bbTypeInfo *superType(){
    return bbGetType<t_default_TileGraphics*>();
  }
  bbVariant nullValue(){
    return bbVariant((t_default_Background*)0);
  }
  bbVariant newArray( int length ){
    return bbVariant(bbArray<bbGCVar<t_default_Background>>(length));
  }
};
rt_default_Background rt_default_Background::instance;
rt_default_Background::decls_t rt_default_Background::decls;

bbTypeInfo *bbGetType(t_default_Background*const&){
  return &rt_default_Background::instance;
}
bbTypeInfo *t_default_Background::typeof()const{
  return &rt_default_Background::instance;
}

struct rt_default_TileGraphics : public bbClassTypeInfo{
  static rt_default_TileGraphics instance;
  static struct decls_t : public bbClassDecls{
    decls_t():bbClassDecls(&instance){}
    bbDeclInfo **initDecls(){
      return bbMembers(bbFieldDecl("tileWidth",&t_default_TileGraphics::m_tileWidth),bbFieldDecl("tileHeight",&t_default_TileGraphics::m_tileHeight),bbFieldDecl("drawScaleX",&t_default_TileGraphics::m_drawScaleX),bbFieldDecl("drawScaleY",&t_default_TileGraphics::m_drawScaleY),bbFieldDecl("viewLeft",&t_default_TileGraphics::m_viewLeft),bbFieldDecl("viewTop",&t_default_TileGraphics::m_viewTop),bbFieldDecl("viewRight",&t_default_TileGraphics::m_viewRight),bbFieldDecl("viewBottom",&t_default_TileGraphics::m_viewBottom),bbFieldDecl("tileStartX",&t_default_TileGraphics::m_tileStartX),bbFieldDecl("tileStartY",&t_default_TileGraphics::m_tileStartY),bbFieldDecl("tileEndX",&t_default_TileGraphics::m_tileEndX),bbFieldDecl("tileEndY",&t_default_TileGraphics::m_tileEndY),bbMethodDecl<t_default_TileGraphics,void,bbDouble,bbDouble,bbDouble,t_stdlib_math_types_Rect_1d>("GetVisibleTiles",&t_default_TileGraphics::m_GetVisibleTiles));
    }
  }decls;
  rt_default_TileGraphics():bbClassTypeInfo("default.TileGraphics","Class"){
  }
  bbTypeInfo *superType(){
    return bbGetType<t_default_GameGraphics*>();
  }
  bbVariant nullValue(){
    return bbVariant((t_default_TileGraphics*)0);
  }
  bbVariant newArray( int length ){
    return bbVariant(bbArray<bbGCVar<t_default_TileGraphics>>(length));
  }
};
rt_default_TileGraphics rt_default_TileGraphics::instance;
rt_default_TileGraphics::decls_t rt_default_TileGraphics::decls;

bbTypeInfo *bbGetType(t_default_TileGraphics*const&){
  return &rt_default_TileGraphics::instance;
}
bbTypeInfo *t_default_TileGraphics::typeof()const{
  return &rt_default_TileGraphics::instance;
}

struct rt_default_Sprite : public bbClassTypeInfo{
  static rt_default_Sprite instance;
  static struct decls_t : public bbClassDecls{
    decls_t():bbClassDecls(&instance){}
    bbDeclInfo **initDecls(){
      return bbMembers(bbCtorDecl<t_default_Sprite,bbString,bbInt,bbInt,bbInt,bbBool>(),bbFieldDecl("timeScale",&t_default_Sprite::m_timeScale),bbFieldDecl("frameRate",&t_default_Sprite::m_frameRate),bbFieldDecl("animations",&t_default_Sprite::m_animations),bbFieldDecl("_time",&t_default_Sprite::m__0time),bbFieldDecl("_period",&t_default_Sprite::m__0period),bbFieldDecl("_listFrame",&t_default_Sprite::m__0listFrame),bbFieldDecl("_clampedListFrame",&t_default_Sprite::m__0clampedListFrame),bbFieldDecl("_duration",&t_default_Sprite::m__0duration),bbFieldDecl("_frame",&t_default_Sprite::m__0frame),bbFieldDecl("_startTime",&t_default_Sprite::m__0startTime),bbFieldDecl("_anim",&t_default_Sprite::m__0anim),bbMethodDecl<t_default_Sprite,void>("Reset",&t_default_Sprite::m_Reset),bbMethodDecl<t_default_Sprite,void,t_sdk_0mojo_m2_graphics_Canvas*,bbString,bbFloat,bbFloat,bbFloat,bbFloat,bbFloat,bbInt>("Draw",&t_default_Sprite::m_Draw),bbMethodDecl<t_default_Sprite,void,bbString,bbArray<bbInt>,bbBool>("AddAnimationClip",&t_default_Sprite::m_AddAnimationClip),bbPropertyDecl<t_default_Sprite,bbString>("Duration",0,&t_default_Sprite::m_Duration),bbPropertyDecl<t_default_Sprite,bbInt>("Frame",&t_default_Sprite::m_Frame,0));
    }
  }decls;
  rt_default_Sprite():bbClassTypeInfo("default.Sprite","Class"){
  }
  bbTypeInfo *superType(){
    return bbGetType<t_default_GameGraphics*>();
  }
  bbVariant nullValue(){
    return bbVariant((t_default_Sprite*)0);
  }
  bbVariant newArray( int length ){
    return bbVariant(bbArray<bbGCVar<t_default_Sprite>>(length));
  }
};
rt_default_Sprite rt_default_Sprite::instance;
rt_default_Sprite::decls_t rt_default_Sprite::decls;

bbTypeInfo *bbGetType(t_default_Sprite*const&){
  return &rt_default_Sprite::instance;
}
bbTypeInfo *t_default_Sprite::typeof()const{
  return &rt_default_Sprite::instance;
}

struct rt_default_AnimationClip : public bbClassTypeInfo{
  static rt_default_AnimationClip instance;
  static struct decls_t : public bbClassDecls{
    decls_t():bbClassDecls(&instance){}
    bbDeclInfo **initDecls(){
      return bbMembers(bbCtorDecl<t_default_AnimationClip>(),bbFieldDecl("id",&t_default_AnimationClip::m_id),bbFieldDecl("frame",&t_default_AnimationClip::m_frame),bbFieldDecl("loop",&t_default_AnimationClip::m_loop),bbMethodDecl<t_default_AnimationClip,bbInt>("Count",&t_default_AnimationClip::m_Count));
    }
  }decls;
  rt_default_AnimationClip():bbClassTypeInfo("default.AnimationClip","Class"){
  }
  bbTypeInfo *superType(){
    return bbGetType<bbObject*>();
  }
  bbVariant nullValue(){
    return bbVariant((t_default_AnimationClip*)0);
  }
  bbVariant newArray( int length ){
    return bbVariant(bbArray<bbGCVar<t_default_AnimationClip>>(length));
  }
};
rt_default_AnimationClip rt_default_AnimationClip::instance;
rt_default_AnimationClip::decls_t rt_default_AnimationClip::decls;

bbTypeInfo *bbGetType(t_default_AnimationClip*const&){
  return &rt_default_AnimationClip::instance;
}
bbTypeInfo *t_default_AnimationClip::typeof()const{
  return &rt_default_AnimationClip::instance;
}
#else
static bbUnknownTypeInfo rt_default_Game("default.Game");
bbTypeInfo *bbGetType(t_default_Game*const&){
  return &rt_default_Game;
}
bbTypeInfo *t_default_Game::typeof()const{
  return &rt_default_Game;
}
static bbUnknownTypeInfo rt_default_Orb("default.Orb");
bbTypeInfo *bbGetType(t_default_Orb*const&){
  return &rt_default_Orb;
}
bbTypeInfo *t_default_Orb::typeof()const{
  return &rt_default_Orb;
}
static bbUnknownTypeInfo rt_default_Bullet("default.Bullet");
bbTypeInfo *bbGetType(t_default_Bullet*const&){
  return &rt_default_Bullet;
}
bbTypeInfo *t_default_Bullet::typeof()const{
  return &rt_default_Bullet;
}
static bbUnknownTypeInfo rt_default_Player("default.Player");
bbTypeInfo *bbGetType(t_default_Player*const&){
  return &rt_default_Player;
}
bbTypeInfo *t_default_Player::typeof()const{
  return &rt_default_Player;
}
static bbUnknownTypeInfo rt_default_Actor("default.Actor");
bbTypeInfo *bbGetType(t_default_Actor*const&){
  return &rt_default_Actor;
}
bbTypeInfo *t_default_Actor::typeof()const{
  return &rt_default_Actor;
}
static bbUnknownTypeInfo rt_default_RenderWindow("default.RenderWindow");
bbTypeInfo *bbGetType(t_default_RenderWindow*const&){
  return &rt_default_RenderWindow;
}
bbTypeInfo *t_default_RenderWindow::typeof()const{
  return &rt_default_RenderWindow;
}
static bbUnknownTypeInfo rt_default_Area_1d("default.Area<monkey.types.Double>");
bbTypeInfo *bbGetType(t_default_Area_1d*const&){
  return &rt_default_Area_1d;
}
bbTypeInfo *t_default_Area_1d::typeof()const{
  return &rt_default_Area_1d;
}
static bbUnknownTypeInfo rt_default_GameGraphics("default.GameGraphics");
bbTypeInfo *bbGetType(t_default_GameGraphics*const&){
  return &rt_default_GameGraphics;
}
bbTypeInfo *t_default_GameGraphics::typeof()const{
  return &rt_default_GameGraphics;
}
static bbUnknownTypeInfo rt_default_Background("default.Background");
bbTypeInfo *bbGetType(t_default_Background*const&){
  return &rt_default_Background;
}
bbTypeInfo *t_default_Background::typeof()const{
  return &rt_default_Background;
}
static bbUnknownTypeInfo rt_default_TileGraphics("default.TileGraphics");
bbTypeInfo *bbGetType(t_default_TileGraphics*const&){
  return &rt_default_TileGraphics;
}
bbTypeInfo *t_default_TileGraphics::typeof()const{
  return &rt_default_TileGraphics;
}
static bbUnknownTypeInfo rt_default_Sprite("default.Sprite");
bbTypeInfo *bbGetType(t_default_Sprite*const&){
  return &rt_default_Sprite;
}
bbTypeInfo *t_default_Sprite::typeof()const{
  return &rt_default_Sprite;
}
static bbUnknownTypeInfo rt_default_AnimationClip("default.AnimationClip");
bbTypeInfo *bbGetType(t_default_AnimationClip*const&){
  return &rt_default_AnimationClip;
}
bbTypeInfo *t_default_AnimationClip::typeof()const{
  return &rt_default_AnimationClip;
}
#endif

#if BB_R_monkey_math || BB_R_monkey_math__ || BB_R_monkey__
#else
#endif

#if BB_R_sdk_api_box2d || BB_R_sdk_api_box2d__ || BB_R_sdk_api__ || BB_R_sdk__
static bbUnknownTypeInfo rx_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d("sdk.api.box2d.Vec2<monkey.types.Double>");
bbTypeInfo *bbGetType(x_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d const&){
  return &rx_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d;
}
bbTypeInfo *x_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d::typeof()const{
  return &rx_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d;
}
#else
static bbUnknownTypeInfo rx_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d("sdk.api.box2d.Vec2<monkey.types.Double>");
bbTypeInfo *bbGetType(x_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d const&){
  return &rx_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d;
}
bbTypeInfo *x_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d::typeof()const{
  return &rx_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d;
}
#endif

#if BB_R_stdlib_collections || BB_R_stdlib_collections__ || BB_R_stdlib__
static bbUnknownTypeInfo rt_stdlib_collections_IContainer_1Tt_default_Bullet_2("stdlib.collections.IContainer<default.Bullet>");
bbTypeInfo *bbGetType(t_stdlib_collections_IContainer_1Tt_default_Bullet_2*const&){
  return &rt_stdlib_collections_IContainer_1Tt_default_Bullet_2;
}
bbTypeInfo *t_stdlib_collections_IContainer_1Tt_default_Bullet_2::typeof()const{
  return &rt_stdlib_collections_IContainer_1Tt_default_Bullet_2;
}
static bbUnknownTypeInfo rt_stdlib_collections_IIterator_1Tt_default_Bullet_2("stdlib.collections.IIterator<default.Bullet>");
bbTypeInfo *bbGetType(t_stdlib_collections_IIterator_1Tt_default_Bullet_2*const&){
  return &rt_stdlib_collections_IIterator_1Tt_default_Bullet_2;
}
bbTypeInfo *t_stdlib_collections_IIterator_1Tt_default_Bullet_2::typeof()const{
  return &rt_stdlib_collections_IIterator_1Tt_default_Bullet_2;
}
static bbUnknownTypeInfo rt_stdlib_collections_IContainer_1Tt_default_Actor_2("stdlib.collections.IContainer<default.Actor>");
bbTypeInfo *bbGetType(t_stdlib_collections_IContainer_1Tt_default_Actor_2*const&){
  return &rt_stdlib_collections_IContainer_1Tt_default_Actor_2;
}
bbTypeInfo *t_stdlib_collections_IContainer_1Tt_default_Actor_2::typeof()const{
  return &rt_stdlib_collections_IContainer_1Tt_default_Actor_2;
}
static bbUnknownTypeInfo rt_stdlib_collections_IIterator_1Tt_default_Actor_2("stdlib.collections.IIterator<default.Actor>");
bbTypeInfo *bbGetType(t_stdlib_collections_IIterator_1Tt_default_Actor_2*const&){
  return &rt_stdlib_collections_IIterator_1Tt_default_Actor_2;
}
bbTypeInfo *t_stdlib_collections_IIterator_1Tt_default_Actor_2::typeof()const{
  return &rt_stdlib_collections_IIterator_1Tt_default_Actor_2;
}
static bbUnknownTypeInfo rt_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator("stdlib.collections.Stack<default.Bullet>.Iterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator const&){
  return &rt_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator;
}
bbTypeInfo *t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator::typeof()const{
  return &rt_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator("stdlib.collections.Stack<default.Bullet>.BackwardsIterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator const&){
  return &rt_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator;
}
bbTypeInfo *t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator::typeof()const{
  return &rt_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Stack_1Tt_default_Bullet_2("stdlib.collections.Stack<default.Bullet>");
bbTypeInfo *bbGetType(t_stdlib_collections_Stack_1Tt_default_Bullet_2*const&){
  return &rt_stdlib_collections_Stack_1Tt_default_Bullet_2;
}
bbTypeInfo *t_stdlib_collections_Stack_1Tt_default_Bullet_2::typeof()const{
  return &rt_stdlib_collections_Stack_1Tt_default_Bullet_2;
}
static bbUnknownTypeInfo rt_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator("stdlib.collections.Stack<default.Actor>.Iterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator const&){
  return &rt_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator;
}
bbTypeInfo *t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator::typeof()const{
  return &rt_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator("stdlib.collections.Stack<default.Actor>.BackwardsIterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator const&){
  return &rt_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator;
}
bbTypeInfo *t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator::typeof()const{
  return &rt_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Stack_1Tt_default_Actor_2("stdlib.collections.Stack<default.Actor>");
bbTypeInfo *bbGetType(t_stdlib_collections_Stack_1Tt_default_Actor_2*const&){
  return &rt_stdlib_collections_Stack_1Tt_default_Actor_2;
}
bbTypeInfo *t_stdlib_collections_Stack_1Tt_default_Actor_2::typeof()const{
  return &rt_stdlib_collections_Stack_1Tt_default_Actor_2;
}
static bbUnknownTypeInfo rt_stdlib_collections_List_1Tt_default_Bullet_2_Node("stdlib.collections.List<default.Bullet>.Node");
bbTypeInfo *bbGetType(t_stdlib_collections_List_1Tt_default_Bullet_2_Node*const&){
  return &rt_stdlib_collections_List_1Tt_default_Bullet_2_Node;
}
bbTypeInfo *t_stdlib_collections_List_1Tt_default_Bullet_2_Node::typeof()const{
  return &rt_stdlib_collections_List_1Tt_default_Bullet_2_Node;
}
static bbUnknownTypeInfo rt_stdlib_collections_List_1Tt_default_Bullet_2_Iterator("stdlib.collections.List<default.Bullet>.Iterator");
bbTypeInfo *bbGetType(t_stdlib_collections_List_1Tt_default_Bullet_2_Iterator const&){
  return &rt_stdlib_collections_List_1Tt_default_Bullet_2_Iterator;
}
bbTypeInfo *t_stdlib_collections_List_1Tt_default_Bullet_2_Iterator::typeof()const{
  return &rt_stdlib_collections_List_1Tt_default_Bullet_2_Iterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_List_1Tt_default_Bullet_2_BackwardsIterator("stdlib.collections.List<default.Bullet>.BackwardsIterator");
bbTypeInfo *bbGetType(t_stdlib_collections_List_1Tt_default_Bullet_2_BackwardsIterator const&){
  return &rt_stdlib_collections_List_1Tt_default_Bullet_2_BackwardsIterator;
}
bbTypeInfo *t_stdlib_collections_List_1Tt_default_Bullet_2_BackwardsIterator::typeof()const{
  return &rt_stdlib_collections_List_1Tt_default_Bullet_2_BackwardsIterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_List_1Tt_default_Bullet_2("stdlib.collections.List<default.Bullet>");
bbTypeInfo *bbGetType(t_stdlib_collections_List_1Tt_default_Bullet_2*const&){
  return &rt_stdlib_collections_List_1Tt_default_Bullet_2;
}
bbTypeInfo *t_stdlib_collections_List_1Tt_default_Bullet_2::typeof()const{
  return &rt_stdlib_collections_List_1Tt_default_Bullet_2;
}
static bbUnknownTypeInfo rt_stdlib_collections_List_1Tt_default_Actor_2_Node("stdlib.collections.List<default.Actor>.Node");
bbTypeInfo *bbGetType(t_stdlib_collections_List_1Tt_default_Actor_2_Node*const&){
  return &rt_stdlib_collections_List_1Tt_default_Actor_2_Node;
}
bbTypeInfo *t_stdlib_collections_List_1Tt_default_Actor_2_Node::typeof()const{
  return &rt_stdlib_collections_List_1Tt_default_Actor_2_Node;
}
static bbUnknownTypeInfo rt_stdlib_collections_List_1Tt_default_Actor_2_Iterator("stdlib.collections.List<default.Actor>.Iterator");
bbTypeInfo *bbGetType(t_stdlib_collections_List_1Tt_default_Actor_2_Iterator const&){
  return &rt_stdlib_collections_List_1Tt_default_Actor_2_Iterator;
}
bbTypeInfo *t_stdlib_collections_List_1Tt_default_Actor_2_Iterator::typeof()const{
  return &rt_stdlib_collections_List_1Tt_default_Actor_2_Iterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_List_1Tt_default_Actor_2_BackwardsIterator("stdlib.collections.List<default.Actor>.BackwardsIterator");
bbTypeInfo *bbGetType(t_stdlib_collections_List_1Tt_default_Actor_2_BackwardsIterator const&){
  return &rt_stdlib_collections_List_1Tt_default_Actor_2_BackwardsIterator;
}
bbTypeInfo *t_stdlib_collections_List_1Tt_default_Actor_2_BackwardsIterator::typeof()const{
  return &rt_stdlib_collections_List_1Tt_default_Actor_2_BackwardsIterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_List_1Tt_default_Actor_2("stdlib.collections.List<default.Actor>");
bbTypeInfo *bbGetType(t_stdlib_collections_List_1Tt_default_Actor_2*const&){
  return &rt_stdlib_collections_List_1Tt_default_Actor_2;
}
bbTypeInfo *t_stdlib_collections_List_1Tt_default_Actor_2::typeof()const{
  return &rt_stdlib_collections_List_1Tt_default_Actor_2;
}
static bbUnknownTypeInfo rt_stdlib_collections_Deque_1Tt_default_Bullet_2_Iterator("stdlib.collections.Deque<default.Bullet>.Iterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Deque_1Tt_default_Bullet_2_Iterator const&){
  return &rt_stdlib_collections_Deque_1Tt_default_Bullet_2_Iterator;
}
bbTypeInfo *t_stdlib_collections_Deque_1Tt_default_Bullet_2_Iterator::typeof()const{
  return &rt_stdlib_collections_Deque_1Tt_default_Bullet_2_Iterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Deque_1Tt_default_Bullet_2("stdlib.collections.Deque<default.Bullet>");
bbTypeInfo *bbGetType(t_stdlib_collections_Deque_1Tt_default_Bullet_2*const&){
  return &rt_stdlib_collections_Deque_1Tt_default_Bullet_2;
}
bbTypeInfo *t_stdlib_collections_Deque_1Tt_default_Bullet_2::typeof()const{
  return &rt_stdlib_collections_Deque_1Tt_default_Bullet_2;
}
static bbUnknownTypeInfo rt_stdlib_collections_Deque_1Tt_default_Actor_2_Iterator("stdlib.collections.Deque<default.Actor>.Iterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Deque_1Tt_default_Actor_2_Iterator const&){
  return &rt_stdlib_collections_Deque_1Tt_default_Actor_2_Iterator;
}
bbTypeInfo *t_stdlib_collections_Deque_1Tt_default_Actor_2_Iterator::typeof()const{
  return &rt_stdlib_collections_Deque_1Tt_default_Actor_2_Iterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Deque_1Tt_default_Actor_2("stdlib.collections.Deque<default.Actor>");
bbTypeInfo *bbGetType(t_stdlib_collections_Deque_1Tt_default_Actor_2*const&){
  return &rt_stdlib_collections_Deque_1Tt_default_Actor_2;
}
bbTypeInfo *t_stdlib_collections_Deque_1Tt_default_Actor_2::typeof()const{
  return &rt_stdlib_collections_Deque_1Tt_default_Actor_2;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node_Color("stdlib.collections.Map<monkey.types.String,default.AnimationClip>.Node.Color");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node_Color const&){
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node_Color;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node("stdlib.collections.Map<monkey.types.String,default.AnimationClip>.Node");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node*const&){
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node;
}
bbTypeInfo *t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node::typeof()const{
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_Iterator("stdlib.collections.Map<monkey.types.String,default.AnimationClip>.Iterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Iterator const&){
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_Iterator;
}
bbTypeInfo *t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Iterator::typeof()const{
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_Iterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_KeyIterator("stdlib.collections.Map<monkey.types.String,default.AnimationClip>.KeyIterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_KeyIterator const&){
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_KeyIterator;
}
bbTypeInfo *t_stdlib_collections_Map_1sTt_default_AnimationClip_2_KeyIterator::typeof()const{
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_KeyIterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapKeys("stdlib.collections.Map<monkey.types.String,default.AnimationClip>.MapKeys");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapKeys const&){
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapKeys;
}
bbTypeInfo *t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapKeys::typeof()const{
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapKeys;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_ValueIterator("stdlib.collections.Map<monkey.types.String,default.AnimationClip>.ValueIterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_ValueIterator const&){
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_ValueIterator;
}
bbTypeInfo *t_stdlib_collections_Map_1sTt_default_AnimationClip_2_ValueIterator::typeof()const{
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_ValueIterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapValues("stdlib.collections.Map<monkey.types.String,default.AnimationClip>.MapValues");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapValues const&){
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapValues;
}
bbTypeInfo *t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapValues::typeof()const{
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapValues;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1sTt_default_AnimationClip_2("stdlib.collections.Map<monkey.types.String,default.AnimationClip>");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1sTt_default_AnimationClip_2*const&){
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2;
}
bbTypeInfo *t_stdlib_collections_Map_1sTt_default_AnimationClip_2::typeof()const{
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2;
}
#else
static bbUnknownTypeInfo rt_stdlib_collections_IContainer_1Tt_default_Bullet_2("stdlib.collections.IContainer<default.Bullet>");
bbTypeInfo *bbGetType(t_stdlib_collections_IContainer_1Tt_default_Bullet_2*const&){
  return &rt_stdlib_collections_IContainer_1Tt_default_Bullet_2;
}
bbTypeInfo *t_stdlib_collections_IContainer_1Tt_default_Bullet_2::typeof()const{
  return &rt_stdlib_collections_IContainer_1Tt_default_Bullet_2;
}
static bbUnknownTypeInfo rt_stdlib_collections_IIterator_1Tt_default_Bullet_2("stdlib.collections.IIterator<default.Bullet>");
bbTypeInfo *bbGetType(t_stdlib_collections_IIterator_1Tt_default_Bullet_2*const&){
  return &rt_stdlib_collections_IIterator_1Tt_default_Bullet_2;
}
bbTypeInfo *t_stdlib_collections_IIterator_1Tt_default_Bullet_2::typeof()const{
  return &rt_stdlib_collections_IIterator_1Tt_default_Bullet_2;
}
static bbUnknownTypeInfo rt_stdlib_collections_IContainer_1Tt_default_Actor_2("stdlib.collections.IContainer<default.Actor>");
bbTypeInfo *bbGetType(t_stdlib_collections_IContainer_1Tt_default_Actor_2*const&){
  return &rt_stdlib_collections_IContainer_1Tt_default_Actor_2;
}
bbTypeInfo *t_stdlib_collections_IContainer_1Tt_default_Actor_2::typeof()const{
  return &rt_stdlib_collections_IContainer_1Tt_default_Actor_2;
}
static bbUnknownTypeInfo rt_stdlib_collections_IIterator_1Tt_default_Actor_2("stdlib.collections.IIterator<default.Actor>");
bbTypeInfo *bbGetType(t_stdlib_collections_IIterator_1Tt_default_Actor_2*const&){
  return &rt_stdlib_collections_IIterator_1Tt_default_Actor_2;
}
bbTypeInfo *t_stdlib_collections_IIterator_1Tt_default_Actor_2::typeof()const{
  return &rt_stdlib_collections_IIterator_1Tt_default_Actor_2;
}
static bbUnknownTypeInfo rt_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator("stdlib.collections.Stack<default.Bullet>.Iterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator const&){
  return &rt_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator;
}
bbTypeInfo *t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator::typeof()const{
  return &rt_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator("stdlib.collections.Stack<default.Bullet>.BackwardsIterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator const&){
  return &rt_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator;
}
bbTypeInfo *t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator::typeof()const{
  return &rt_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Stack_1Tt_default_Bullet_2("stdlib.collections.Stack<default.Bullet>");
bbTypeInfo *bbGetType(t_stdlib_collections_Stack_1Tt_default_Bullet_2*const&){
  return &rt_stdlib_collections_Stack_1Tt_default_Bullet_2;
}
bbTypeInfo *t_stdlib_collections_Stack_1Tt_default_Bullet_2::typeof()const{
  return &rt_stdlib_collections_Stack_1Tt_default_Bullet_2;
}
static bbUnknownTypeInfo rt_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator("stdlib.collections.Stack<default.Actor>.Iterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator const&){
  return &rt_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator;
}
bbTypeInfo *t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator::typeof()const{
  return &rt_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator("stdlib.collections.Stack<default.Actor>.BackwardsIterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator const&){
  return &rt_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator;
}
bbTypeInfo *t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator::typeof()const{
  return &rt_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Stack_1Tt_default_Actor_2("stdlib.collections.Stack<default.Actor>");
bbTypeInfo *bbGetType(t_stdlib_collections_Stack_1Tt_default_Actor_2*const&){
  return &rt_stdlib_collections_Stack_1Tt_default_Actor_2;
}
bbTypeInfo *t_stdlib_collections_Stack_1Tt_default_Actor_2::typeof()const{
  return &rt_stdlib_collections_Stack_1Tt_default_Actor_2;
}
static bbUnknownTypeInfo rt_stdlib_collections_List_1Tt_default_Bullet_2_Node("stdlib.collections.List<default.Bullet>.Node");
bbTypeInfo *bbGetType(t_stdlib_collections_List_1Tt_default_Bullet_2_Node*const&){
  return &rt_stdlib_collections_List_1Tt_default_Bullet_2_Node;
}
bbTypeInfo *t_stdlib_collections_List_1Tt_default_Bullet_2_Node::typeof()const{
  return &rt_stdlib_collections_List_1Tt_default_Bullet_2_Node;
}
static bbUnknownTypeInfo rt_stdlib_collections_List_1Tt_default_Bullet_2_Iterator("stdlib.collections.List<default.Bullet>.Iterator");
bbTypeInfo *bbGetType(t_stdlib_collections_List_1Tt_default_Bullet_2_Iterator const&){
  return &rt_stdlib_collections_List_1Tt_default_Bullet_2_Iterator;
}
bbTypeInfo *t_stdlib_collections_List_1Tt_default_Bullet_2_Iterator::typeof()const{
  return &rt_stdlib_collections_List_1Tt_default_Bullet_2_Iterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_List_1Tt_default_Bullet_2_BackwardsIterator("stdlib.collections.List<default.Bullet>.BackwardsIterator");
bbTypeInfo *bbGetType(t_stdlib_collections_List_1Tt_default_Bullet_2_BackwardsIterator const&){
  return &rt_stdlib_collections_List_1Tt_default_Bullet_2_BackwardsIterator;
}
bbTypeInfo *t_stdlib_collections_List_1Tt_default_Bullet_2_BackwardsIterator::typeof()const{
  return &rt_stdlib_collections_List_1Tt_default_Bullet_2_BackwardsIterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_List_1Tt_default_Bullet_2("stdlib.collections.List<default.Bullet>");
bbTypeInfo *bbGetType(t_stdlib_collections_List_1Tt_default_Bullet_2*const&){
  return &rt_stdlib_collections_List_1Tt_default_Bullet_2;
}
bbTypeInfo *t_stdlib_collections_List_1Tt_default_Bullet_2::typeof()const{
  return &rt_stdlib_collections_List_1Tt_default_Bullet_2;
}
static bbUnknownTypeInfo rt_stdlib_collections_List_1Tt_default_Actor_2_Node("stdlib.collections.List<default.Actor>.Node");
bbTypeInfo *bbGetType(t_stdlib_collections_List_1Tt_default_Actor_2_Node*const&){
  return &rt_stdlib_collections_List_1Tt_default_Actor_2_Node;
}
bbTypeInfo *t_stdlib_collections_List_1Tt_default_Actor_2_Node::typeof()const{
  return &rt_stdlib_collections_List_1Tt_default_Actor_2_Node;
}
static bbUnknownTypeInfo rt_stdlib_collections_List_1Tt_default_Actor_2_Iterator("stdlib.collections.List<default.Actor>.Iterator");
bbTypeInfo *bbGetType(t_stdlib_collections_List_1Tt_default_Actor_2_Iterator const&){
  return &rt_stdlib_collections_List_1Tt_default_Actor_2_Iterator;
}
bbTypeInfo *t_stdlib_collections_List_1Tt_default_Actor_2_Iterator::typeof()const{
  return &rt_stdlib_collections_List_1Tt_default_Actor_2_Iterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_List_1Tt_default_Actor_2_BackwardsIterator("stdlib.collections.List<default.Actor>.BackwardsIterator");
bbTypeInfo *bbGetType(t_stdlib_collections_List_1Tt_default_Actor_2_BackwardsIterator const&){
  return &rt_stdlib_collections_List_1Tt_default_Actor_2_BackwardsIterator;
}
bbTypeInfo *t_stdlib_collections_List_1Tt_default_Actor_2_BackwardsIterator::typeof()const{
  return &rt_stdlib_collections_List_1Tt_default_Actor_2_BackwardsIterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_List_1Tt_default_Actor_2("stdlib.collections.List<default.Actor>");
bbTypeInfo *bbGetType(t_stdlib_collections_List_1Tt_default_Actor_2*const&){
  return &rt_stdlib_collections_List_1Tt_default_Actor_2;
}
bbTypeInfo *t_stdlib_collections_List_1Tt_default_Actor_2::typeof()const{
  return &rt_stdlib_collections_List_1Tt_default_Actor_2;
}
static bbUnknownTypeInfo rt_stdlib_collections_Deque_1Tt_default_Bullet_2_Iterator("stdlib.collections.Deque<default.Bullet>.Iterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Deque_1Tt_default_Bullet_2_Iterator const&){
  return &rt_stdlib_collections_Deque_1Tt_default_Bullet_2_Iterator;
}
bbTypeInfo *t_stdlib_collections_Deque_1Tt_default_Bullet_2_Iterator::typeof()const{
  return &rt_stdlib_collections_Deque_1Tt_default_Bullet_2_Iterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Deque_1Tt_default_Bullet_2("stdlib.collections.Deque<default.Bullet>");
bbTypeInfo *bbGetType(t_stdlib_collections_Deque_1Tt_default_Bullet_2*const&){
  return &rt_stdlib_collections_Deque_1Tt_default_Bullet_2;
}
bbTypeInfo *t_stdlib_collections_Deque_1Tt_default_Bullet_2::typeof()const{
  return &rt_stdlib_collections_Deque_1Tt_default_Bullet_2;
}
static bbUnknownTypeInfo rt_stdlib_collections_Deque_1Tt_default_Actor_2_Iterator("stdlib.collections.Deque<default.Actor>.Iterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Deque_1Tt_default_Actor_2_Iterator const&){
  return &rt_stdlib_collections_Deque_1Tt_default_Actor_2_Iterator;
}
bbTypeInfo *t_stdlib_collections_Deque_1Tt_default_Actor_2_Iterator::typeof()const{
  return &rt_stdlib_collections_Deque_1Tt_default_Actor_2_Iterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Deque_1Tt_default_Actor_2("stdlib.collections.Deque<default.Actor>");
bbTypeInfo *bbGetType(t_stdlib_collections_Deque_1Tt_default_Actor_2*const&){
  return &rt_stdlib_collections_Deque_1Tt_default_Actor_2;
}
bbTypeInfo *t_stdlib_collections_Deque_1Tt_default_Actor_2::typeof()const{
  return &rt_stdlib_collections_Deque_1Tt_default_Actor_2;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node_Color("stdlib.collections.Map<monkey.types.String,default.AnimationClip>.Node.Color");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node_Color const&){
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node_Color;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node("stdlib.collections.Map<monkey.types.String,default.AnimationClip>.Node");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node*const&){
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node;
}
bbTypeInfo *t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node::typeof()const{
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_Iterator("stdlib.collections.Map<monkey.types.String,default.AnimationClip>.Iterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Iterator const&){
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_Iterator;
}
bbTypeInfo *t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Iterator::typeof()const{
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_Iterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_KeyIterator("stdlib.collections.Map<monkey.types.String,default.AnimationClip>.KeyIterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_KeyIterator const&){
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_KeyIterator;
}
bbTypeInfo *t_stdlib_collections_Map_1sTt_default_AnimationClip_2_KeyIterator::typeof()const{
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_KeyIterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapKeys("stdlib.collections.Map<monkey.types.String,default.AnimationClip>.MapKeys");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapKeys const&){
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapKeys;
}
bbTypeInfo *t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapKeys::typeof()const{
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapKeys;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_ValueIterator("stdlib.collections.Map<monkey.types.String,default.AnimationClip>.ValueIterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_ValueIterator const&){
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_ValueIterator;
}
bbTypeInfo *t_stdlib_collections_Map_1sTt_default_AnimationClip_2_ValueIterator::typeof()const{
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_ValueIterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapValues("stdlib.collections.Map<monkey.types.String,default.AnimationClip>.MapValues");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapValues const&){
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapValues;
}
bbTypeInfo *t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapValues::typeof()const{
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapValues;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1sTt_default_AnimationClip_2("stdlib.collections.Map<monkey.types.String,default.AnimationClip>");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1sTt_default_AnimationClip_2*const&){
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2;
}
bbTypeInfo *t_stdlib_collections_Map_1sTt_default_AnimationClip_2::typeof()const{
  return &rt_stdlib_collections_Map_1sTt_default_AnimationClip_2;
}
#endif

#if BB_R_stdlib_math_types || BB_R_stdlib_math_types__ || BB_R_stdlib_math__ || BB_R_stdlib__
static bbUnknownTypeInfo rt_stdlib_math_types_Rect_1d("stdlib.math.types.Rect<monkey.types.Double>");
bbTypeInfo *bbGetType(t_stdlib_math_types_Rect_1d const&){
  return &rt_stdlib_math_types_Rect_1d;
}
bbTypeInfo *t_stdlib_math_types_Rect_1d::typeof()const{
  return &rt_stdlib_math_types_Rect_1d;
}
#else
static bbUnknownTypeInfo rt_stdlib_math_types_Rect_1d("stdlib.math.types.Rect<monkey.types.Double>");
bbTypeInfo *bbGetType(t_stdlib_math_types_Rect_1d const&){
  return &rt_stdlib_math_types_Rect_1d;
}
bbTypeInfo *t_stdlib_math_types_Rect_1d::typeof()const{
  return &rt_stdlib_math_types_Rect_1d;
}
#endif