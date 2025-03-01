
#include <bbmonkey.h>
#include <bbtypeinfo_r.h>
#include <bbdeclinfo_r.h>

#include "_r.h"

#include "commanche.buildv1.1.15/windows_release_mx/include/commanche_commanche.h"
#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_types.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2canvas.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2image.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_resources_2graphics_2pixmap.h"

BB_CLASS(t_sdk_0mojo_m2_app_Window)
BB_ENUM(t_sdk_0mojo_m2_app_WindowFlags)

#if BB_R_default || BB_R_default__
static struct mx2_commanche_commanche_typeinfo : public bbClassDecls{
  mx2_commanche_commanche_typeinfo():bbClassDecls(bbClassTypeInfo::getNamespace("default")){
  }
  bbDeclInfo **initDecls(){
    return bbMembers(bbConstDecl("WIDTH",&g_default_WIDTH),bbConstDecl("HEIGHT",&g_default_HEIGHT),bbConstDecl("MAPW",&g_default_MAPW),bbConstDecl("MAPH",&g_default_MAPH),bbGlobalDecl("Cmap",&g_default_Cmap),bbGlobalDecl("Dmap",&g_default_Dmap),bbGlobalDecl("PmapDest",&g_default_PmapDest),bbGlobalDecl("image",&g_default_image),bbGlobalDecl("depth",&g_default_depth),bbGlobalDecl("Camera",&g_default_Camera),bbFunctionDecl<void>("Main",&bbMain));
  }
}_mx2_commanche_commanche_typeinfo;

struct rt_default_tCamera : public bbClassTypeInfo{
  static rt_default_tCamera instance;
  static struct decls_t : public bbClassDecls{
    decls_t():bbClassDecls(&instance){}
    bbDeclInfo **initDecls(){
      return bbMembers(bbCtorDecl<t_default_tCamera>(),bbFieldDecl("x",&t_default_tCamera::m_x),bbFieldDecl("y",&t_default_tCamera::m_y),bbFieldDecl("height",&t_default_tCamera::m_height),bbFieldDecl("angle",&t_default_tCamera::m_angle),bbFieldDecl("v",&t_default_tCamera::m_v));
    }
  }decls;
  rt_default_tCamera():bbClassTypeInfo("default.tCamera","Class"){
  }
  bbTypeInfo *superType(){
    return bbGetType<bbObject*>();
  }
  bbVariant nullValue(){
    return bbVariant((t_default_tCamera*)0);
  }
  bbVariant newArray( int length ){
    return bbVariant(bbArray<bbGCVar<t_default_tCamera>>(length));
  }
};
rt_default_tCamera rt_default_tCamera::instance;
rt_default_tCamera::decls_t rt_default_tCamera::decls;

bbTypeInfo *bbGetType(t_default_tCamera*const&){
  return &rt_default_tCamera::instance;
}
bbTypeInfo *t_default_tCamera::typeof()const{
  return &rt_default_tCamera::instance;
}

struct rt_default_MyWindow : public bbClassTypeInfo{
  static rt_default_MyWindow instance;
  static struct decls_t : public bbClassDecls{
    decls_t():bbClassDecls(&instance){}
    bbDeclInfo **initDecls(){
      return bbMembers(bbCtorDecl<t_default_MyWindow,bbString,bbInt,bbInt,t_sdk_0mojo_m2_app_WindowFlags>(),bbFieldDecl("pm",&t_default_MyWindow::m_pm),bbFieldDecl("img",&t_default_MyWindow::m_img),bbMethodDecl<t_default_MyWindow,void>("UpdateSim",&t_default_MyWindow::m_UpdateSim),bbMethodDecl<t_default_MyWindow,void>("UpdateCamera",&t_default_MyWindow::m_UpdateCamera),bbMethodDecl<t_default_MyWindow,void,bbInt,bbFloat,bbFloat,bbFloat,bbFloat,bbFloat>("Raycast",&t_default_MyWindow::m_Raycast),bbMethodDecl<t_default_MyWindow,void,t_sdk_0mojo_m2_graphics_Canvas*>("OnRender",&t_default_MyWindow::m_OnRender),bbMethodDecl<t_default_MyWindow,void>("LoadMap",&t_default_MyWindow::m_LoadMap));
    }
  }decls;
  rt_default_MyWindow():bbClassTypeInfo("default.MyWindow","Class"){
  }
  bbTypeInfo *superType(){
    return bbGetType<t_sdk_0mojo_m2_app_Window*>();
  }
  bbVariant nullValue(){
    return bbVariant((t_default_MyWindow*)0);
  }
  bbVariant newArray( int length ){
    return bbVariant(bbArray<bbGCVar<t_default_MyWindow>>(length));
  }
};
rt_default_MyWindow rt_default_MyWindow::instance;
rt_default_MyWindow::decls_t rt_default_MyWindow::decls;

bbTypeInfo *bbGetType(t_default_MyWindow*const&){
  return &rt_default_MyWindow::instance;
}
bbTypeInfo *t_default_MyWindow::typeof()const{
  return &rt_default_MyWindow::instance;
}
#else
static bbUnknownTypeInfo rt_default_tCamera("default.tCamera");
bbTypeInfo *bbGetType(t_default_tCamera*const&){
  return &rt_default_tCamera;
}
bbTypeInfo *t_default_tCamera::typeof()const{
  return &rt_default_tCamera;
}
static bbUnknownTypeInfo rt_default_MyWindow("default.MyWindow");
bbTypeInfo *bbGetType(t_default_MyWindow*const&){
  return &rt_default_MyWindow;
}
bbTypeInfo *t_default_MyWindow::typeof()const{
  return &rt_default_MyWindow;
}
#endif