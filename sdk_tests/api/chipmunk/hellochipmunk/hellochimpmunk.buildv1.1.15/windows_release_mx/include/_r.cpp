
#include <bbmonkey.h>
#include <bbtypeinfo_r.h>
#include <bbdeclinfo_r.h>

#include "_r.h"

#include "hellochimpmunk.buildv1.1.15/windows_release_mx/include/hellochimpmunk_chipmunkdebugger.h"
#include "hellochimpmunk.buildv1.1.15/windows_release_mx/include/hellochimpmunk_hellochimpmunk.h"
#include "hellochimpmunk.buildv1.1.15/windows_release_mx/include/hellochimpmunk_stdlib_collections_2map.h"
#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_types.h"
#include "sdk/sdk.buildv1.1.15/windows_release_mx/include/sdk_api_2physics_2chipmunk_2body.h"
#include "sdk/sdk.buildv1.1.15/windows_release_mx/include/sdk_api_2physics_2chipmunk_2shape.h"
#include "sdk/sdk.buildv1.1.15/windows_release_mx/include/sdk_api_2physics_2chipmunk_2space.h"
#include "sdk/sdk.buildv1.1.15/windows_release_mx/include/sdk_api_2physics_2chipmunk_2types.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2canvas.h"

BB_CLASS(t_sdk_0mojo_m2_app_Window)

#if BB_R_default || BB_R_default__
static struct mx2_hellochimpmunk_hellochimpmunk_typeinfo : public bbClassDecls{
  mx2_hellochimpmunk_hellochimpmunk_typeinfo():bbClassDecls(bbClassTypeInfo::getNamespace("default")){
  }
  bbDeclInfo **initDecls(){
    return bbMembers(bbFunctionDecl<void>("Main",&bbMain));
  }
}_mx2_hellochimpmunk_hellochimpmunk_typeinfo;

struct rt_default_HelloChipmunk : public bbClassTypeInfo{
  static rt_default_HelloChipmunk instance;
  static struct decls_t : public bbClassDecls{
    decls_t():bbClassDecls(&instance){}
    bbDeclInfo **initDecls(){
      return bbMembers(bbCtorDecl<t_default_HelloChipmunk>(),bbFieldDecl("space",&t_default_HelloChipmunk::m_space),bbFieldDecl("ground",&t_default_HelloChipmunk::m_ground),bbFieldDecl("ballBody",&t_default_HelloChipmunk::m_ballBody),bbFieldDecl("ballShape",&t_default_HelloChipmunk::m_ballShape),bbFieldDecl("ballBody2",&t_default_HelloChipmunk::m_ballBody2),bbFieldDecl("ballShape2",&t_default_HelloChipmunk::m_ballShape2),bbFieldDecl("polyBody",&t_default_HelloChipmunk::m_polyBody),bbFieldDecl("polyShape",&t_default_HelloChipmunk::m_polyShape),bbFieldDecl("debugger",&t_default_HelloChipmunk::m_debugger),bbMethodDecl<t_default_HelloChipmunk,void,t_sdk_0mojo_m2_graphics_Canvas*>("OnRender",&t_default_HelloChipmunk::m_OnRender),bbMethodDecl<t_default_HelloChipmunk,void>("Cleanup",&t_default_HelloChipmunk::m_Cleanup));
    }
  }decls;
  rt_default_HelloChipmunk():bbClassTypeInfo("default.HelloChipmunk","Class"){
  }
  bbTypeInfo *superType(){
    return bbGetType<t_sdk_0mojo_m2_app_Window*>();
  }
  bbVariant nullValue(){
    return bbVariant((t_default_HelloChipmunk*)0);
  }
  bbVariant newArray( int length ){
    return bbVariant(bbArray<bbGCVar<t_default_HelloChipmunk>>(length));
  }
};
rt_default_HelloChipmunk rt_default_HelloChipmunk::instance;
rt_default_HelloChipmunk::decls_t rt_default_HelloChipmunk::decls;

bbTypeInfo *bbGetType(t_default_HelloChipmunk*const&){
  return &rt_default_HelloChipmunk::instance;
}
bbTypeInfo *t_default_HelloChipmunk::typeof()const{
  return &rt_default_HelloChipmunk::instance;
}

struct rt_default_ChipmunkDebugger : public bbClassTypeInfo{
  static rt_default_ChipmunkDebugger instance;
  static struct decls_t : public bbClassDecls{
    decls_t():bbClassDecls(&instance){}
    bbDeclInfo **initDecls(){
      return bbMembers(bbCtorDecl<t_default_ChipmunkDebugger>(),bbFieldDecl("_options",&t_default_ChipmunkDebugger::m__0options),bbFieldDecl("_colors",&t_default_ChipmunkDebugger::m__0colors),bbFieldDecl("_canvas",&t_default_ChipmunkDebugger::m__0canvas),bbMethodDecl<t_default_ChipmunkDebugger,void,cpVect,cpVect,cpSpaceDebugColor,cpDataPointer>("DrawSegment",&t_default_ChipmunkDebugger::m_DrawSegment),bbMethodDecl<t_default_ChipmunkDebugger,void,bbInt,cpVect*,cpFloat,cpSpaceDebugColor,cpSpaceDebugColor,cpDataPointer>("DrawPolygon",&t_default_ChipmunkDebugger::m_DrawPolygon),bbMethodDecl<t_default_ChipmunkDebugger,void,cpVect,cpVect,cpFloat,cpSpaceDebugColor,cpSpaceDebugColor,cpDataPointer>("DrawFatSegment",&t_default_ChipmunkDebugger::m_DrawFatSegment),bbMethodDecl<t_default_ChipmunkDebugger,void,cpFloat,cpVect,cpSpaceDebugColor,cpDataPointer>("DrawDot",&t_default_ChipmunkDebugger::m_DrawDot),bbMethodDecl<t_default_ChipmunkDebugger,void,cpVect,cpFloat,cpFloat,cpSpaceDebugColor,cpSpaceDebugColor,cpDataPointer>("DrawCircle",&t_default_ChipmunkDebugger::m_DrawCircle),bbMethodDecl<t_default_ChipmunkDebugger,void,t_sdk_0mojo_m2_graphics_Canvas*,cpSpace*>("DebugDraw",&t_default_ChipmunkDebugger::m_DebugDraw),bbMethodDecl<t_default_ChipmunkDebugger,cpSpaceDebugColor,cpShape*,cpDataPointer>("ColorForShape",&t_default_ChipmunkDebugger::m_ColorForShape));
    }
  }decls;
  rt_default_ChipmunkDebugger():bbClassTypeInfo("default.ChipmunkDebugger","Class"){
  }
  bbTypeInfo *superType(){
    return bbGetType<bbObject*>();
  }
  bbVariant nullValue(){
    return bbVariant((t_default_ChipmunkDebugger*)0);
  }
  bbVariant newArray( int length ){
    return bbVariant(bbArray<bbGCVar<t_default_ChipmunkDebugger>>(length));
  }
};
rt_default_ChipmunkDebugger rt_default_ChipmunkDebugger::instance;
rt_default_ChipmunkDebugger::decls_t rt_default_ChipmunkDebugger::decls;

bbTypeInfo *bbGetType(t_default_ChipmunkDebugger*const&){
  return &rt_default_ChipmunkDebugger::instance;
}
bbTypeInfo *t_default_ChipmunkDebugger::typeof()const{
  return &rt_default_ChipmunkDebugger::instance;
}
#else
static bbUnknownTypeInfo rt_default_HelloChipmunk("default.HelloChipmunk");
bbTypeInfo *bbGetType(t_default_HelloChipmunk*const&){
  return &rt_default_HelloChipmunk;
}
bbTypeInfo *t_default_HelloChipmunk::typeof()const{
  return &rt_default_HelloChipmunk;
}
static bbUnknownTypeInfo rt_default_ChipmunkDebugger("default.ChipmunkDebugger");
bbTypeInfo *bbGetType(t_default_ChipmunkDebugger*const&){
  return &rt_default_ChipmunkDebugger;
}
bbTypeInfo *t_default_ChipmunkDebugger::typeof()const{
  return &rt_default_ChipmunkDebugger;
}
#endif

#if BB_R_stdlib_collections || BB_R_stdlib_collections__ || BB_R_stdlib__
static bbUnknownTypeInfo rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node_Color("stdlib.collections.Map<sdk.api.chipmunk.cpShape,sdk.api.chipmunk.cpSpaceDebugColor>.Node.Color");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node_Color const&){
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node_Color;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node("stdlib.collections.Map<sdk.api.chipmunk.cpShape,sdk.api.chipmunk.cpSpaceDebugColor>.Node");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node*const&){
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node;
}
bbTypeInfo *t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node::typeof()const{
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Iterator("stdlib.collections.Map<sdk.api.chipmunk.cpShape,sdk.api.chipmunk.cpSpaceDebugColor>.Iterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Iterator const&){
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Iterator;
}
bbTypeInfo *t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Iterator::typeof()const{
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Iterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_KeyIterator("stdlib.collections.Map<sdk.api.chipmunk.cpShape,sdk.api.chipmunk.cpSpaceDebugColor>.KeyIterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_KeyIterator const&){
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_KeyIterator;
}
bbTypeInfo *t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_KeyIterator::typeof()const{
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_KeyIterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapKeys("stdlib.collections.Map<sdk.api.chipmunk.cpShape,sdk.api.chipmunk.cpSpaceDebugColor>.MapKeys");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapKeys const&){
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapKeys;
}
bbTypeInfo *t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapKeys::typeof()const{
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapKeys;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_ValueIterator("stdlib.collections.Map<sdk.api.chipmunk.cpShape,sdk.api.chipmunk.cpSpaceDebugColor>.ValueIterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_ValueIterator const&){
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_ValueIterator;
}
bbTypeInfo *t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_ValueIterator::typeof()const{
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_ValueIterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapValues("stdlib.collections.Map<sdk.api.chipmunk.cpShape,sdk.api.chipmunk.cpSpaceDebugColor>.MapValues");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapValues const&){
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapValues;
}
bbTypeInfo *t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapValues::typeof()const{
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapValues;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2("stdlib.collections.Map<sdk.api.chipmunk.cpShape,sdk.api.chipmunk.cpSpaceDebugColor>");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2*const&){
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2;
}
bbTypeInfo *t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2::typeof()const{
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2;
}
#else
static bbUnknownTypeInfo rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node_Color("stdlib.collections.Map<sdk.api.chipmunk.cpShape,sdk.api.chipmunk.cpSpaceDebugColor>.Node.Color");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node_Color const&){
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node_Color;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node("stdlib.collections.Map<sdk.api.chipmunk.cpShape,sdk.api.chipmunk.cpSpaceDebugColor>.Node");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node*const&){
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node;
}
bbTypeInfo *t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node::typeof()const{
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Iterator("stdlib.collections.Map<sdk.api.chipmunk.cpShape,sdk.api.chipmunk.cpSpaceDebugColor>.Iterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Iterator const&){
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Iterator;
}
bbTypeInfo *t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Iterator::typeof()const{
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Iterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_KeyIterator("stdlib.collections.Map<sdk.api.chipmunk.cpShape,sdk.api.chipmunk.cpSpaceDebugColor>.KeyIterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_KeyIterator const&){
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_KeyIterator;
}
bbTypeInfo *t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_KeyIterator::typeof()const{
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_KeyIterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapKeys("stdlib.collections.Map<sdk.api.chipmunk.cpShape,sdk.api.chipmunk.cpSpaceDebugColor>.MapKeys");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapKeys const&){
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapKeys;
}
bbTypeInfo *t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapKeys::typeof()const{
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapKeys;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_ValueIterator("stdlib.collections.Map<sdk.api.chipmunk.cpShape,sdk.api.chipmunk.cpSpaceDebugColor>.ValueIterator");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_ValueIterator const&){
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_ValueIterator;
}
bbTypeInfo *t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_ValueIterator::typeof()const{
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_ValueIterator;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapValues("stdlib.collections.Map<sdk.api.chipmunk.cpShape,sdk.api.chipmunk.cpSpaceDebugColor>.MapValues");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapValues const&){
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapValues;
}
bbTypeInfo *t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapValues::typeof()const{
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapValues;
}
static bbUnknownTypeInfo rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2("stdlib.collections.Map<sdk.api.chipmunk.cpShape,sdk.api.chipmunk.cpSpaceDebugColor>");
bbTypeInfo *bbGetType(t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2*const&){
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2;
}
bbTypeInfo *t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2::typeof()const{
  return &rt_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2;
}
#endif