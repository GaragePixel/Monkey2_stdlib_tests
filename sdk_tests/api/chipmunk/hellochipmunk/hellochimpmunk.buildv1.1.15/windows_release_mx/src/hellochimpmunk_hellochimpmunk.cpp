
#include "hellochimpmunk.buildv1.1.15/windows_release_mx/include/hellochimpmunk_hellochimpmunk.h"

#include "hellochimpmunk.buildv1.1.15/windows_release_mx/include/hellochimpmunk_chipmunkdebugger.h"
#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_math.h"
#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_types.h"
#include "sdk/sdk.buildv1.1.15/windows_release_mx/include/sdk_api_2physics_2chipmunk_2arbiter.h"
#include "sdk/sdk.buildv1.1.15/windows_release_mx/include/sdk_api_2physics_2chipmunk_2types.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2app_2app.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2canvas.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_resources_2graphics_2color.h"

void bbMain(){
  static bool done;
  if(done) return;
  done=true;
  void mx2_monkey_main();mx2_monkey_main();
  void mx2_sdk_main();mx2_sdk_main();
  void mx2_sdk_0mojo_main();mx2_sdk_0mojo_main();
  void mx2_stdlib_main();mx2_stdlib_main();
  void mx2_hellochimpmunk_stdlib_collections_2map_init_f();mx2_hellochimpmunk_stdlib_collections_2map_init_f();
  void mx2_hellochimpmunk_chipmunkdebugger_init_f();mx2_hellochimpmunk_chipmunkdebugger_init_f();
  void mx2_hellochimpmunk_hellochimpmunk_init_f();mx2_hellochimpmunk_hellochimpmunk_init_f();
  struct f0_t : public bbGCFrame{
    t_sdk_0mojo_m2_app_AppInstance* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  bbGCNew<t_sdk_0mojo_m2_app_AppInstance>();
  bbGCNew<t_default_HelloChipmunk>();
  (f0.t0=g_sdk_0mojo_m2_app_App.get())->m_Run();
}

void t_default_HelloChipmunk::init(){
  m_debugger=bbGCNew<t_default_ChipmunkDebugger>();
}

void t_default_HelloChipmunk::gcMark(){
  t_sdk_0mojo_m2_app_Window::gcMark();
  bbGCMark(m_debugger);
}

t_default_HelloChipmunk::t_default_HelloChipmunk():t_sdk_0mojo_m2_app_Window(bbString(L"Window",6),640,480,t_sdk_0mojo_m2_app_WindowFlags(0)){
  init();
  struct f0_t : public bbGCFrame{
    bb_cpCollisionHandler* l_handler{};
    bbArray<cpVect> l_verts{};
    void gcMark(){
      bbGCMark(l_handler);
      bbGCMark(l_verts);
    }
  }f0{};
  this->m_ClearColor(g_stdlib_graphics_Color_Grey);
  this->m_space=cpSpaceNew();
  cpSpaceSetGravity(this->m_space,cpv(0.0,100.0));
  this->m_ground=cpSegmentShapeNew(cpSpaceGetStaticBody(this->m_space),cpv(-100.0,15.0),cpv(100.0,-15.0),0.0);
  cpShapeSetFriction(this->m_ground,1.0);
  cpShapeSetCollisionType(this->m_ground,1);
  cpSpaceAddShape(this->m_space,this->m_ground);
  cpShape* l_tshape=cpSpaceAddShape(this->m_space,cpSegmentShapeNew(cpSpaceGetStaticBody(this->m_space),cpv(cpFloat((-this->m_Width()/2)),cpFloat(((this->m_Height()/2)-64))),cpv(0.0,cpFloat((this->m_Height()/2))),0.0));
  cpShapeSetFriction(l_tshape,1.0);
  cpShapeSetCollisionType(l_tshape,1);
  l_tshape=cpSpaceAddShape(this->m_space,cpSegmentShapeNew(cpSpaceGetStaticBody(this->m_space),cpv(0.0,cpFloat((this->m_Height()/2))),cpv(cpFloat((this->m_Width()/2)),cpFloat(((this->m_Height()/2)-64))),0.0));
  cpShapeSetFriction(l_tshape,1.0);
  cpShapeSetCollisionType(l_tshape,1);
  bbFloat l_mass=1.0f;
  bbFloat l_radius=10.0f;
  cpFloat l_moment=cpMomentForCircle(cpFloat(l_mass),0.0,cpFloat(l_radius),cpvzero);
  this->m_ballBody=cpSpaceAddBody(this->m_space,cpBodyNew(cpFloat(l_mass),l_moment));
  cpBodySetPosition(this->m_ballBody,cpv(0.0,-100.0));
  this->m_ballShape=cpSpaceAddShape(this->m_space,cpCircleShapeNew(this->m_ballBody,cpFloat(l_radius),cpvzero));
  cpShapeSetFriction(this->m_ballShape,0.69999999999999996);
  cpShapeSetCollisionType(this->m_ballShape,2);
  this->m_ballBody2=cpSpaceAddBody(this->m_space,cpBodyNew(cpFloat(l_mass),l_moment));
  cpBodySetPosition(this->m_ballBody2,cpv(50.0,-100.0));
  this->m_ballShape2=cpSpaceAddShape(this->m_space,cpCircleShapeNew(this->m_ballBody2,cpFloat(l_radius),cpvzero));
  cpShapeSetFriction(this->m_ballShape2,0.69999999999999996);
  cpShapeSetCollisionType(this->m_ballShape2,2);
  l_mass=0.29999999999999999f;
  l_radius=30.0f;
  bbInt l_NUM_0VERTS=5;
  f0.l_verts=bbArray<cpVect>(l_NUM_0VERTS);
  {
    bbInt l_it=bbInt(0);
    for(;(l_it<l_NUM_0VERTS);l_it+=1){
      bbDouble l_angle=((g_monkey_math_TwoPi*bbDouble(l_it))/bbDouble(l_NUM_0VERTS));
      f0.l_verts[l_it]=cpv((bbDouble(l_radius)*std::cos(l_angle)),(bbDouble(l_radius)*std::sin(l_angle)));
    }
  }
  l_moment=cpMomentForPoly(cpFloat(l_mass),l_NUM_0VERTS,f0.l_verts.data(),cpvzero,0.0);
  this->m_polyBody=cpSpaceAddBody(this->m_space,cpBodyNew(cpFloat(l_mass),l_moment));
  cpBodySetPosition(this->m_polyBody,cpv(50.0,-190.0));
  this->m_polyShape=cpSpaceAddShape(this->m_space,cpPolyShapeNew(this->m_polyBody,l_NUM_0VERTS,f0.l_verts.data(),cpTransformIdentity,0.0));
  cpShapeSetFriction(this->m_polyShape,0.029999999999999999);
  f0.l_handler=bb_cpSpaceAddDefaultCollisionHandler(this->m_space);
  struct lambda0 : public bbFunction<cpBool(cpArbiter*,cpSpace*,cpDataPointer)>::Rep{
    t_default_HelloChipmunk* l_self;
    lambda0(t_default_HelloChipmunk* l_self):l_self(l_self){
    }
    cpBool invoke(cpArbiter* l_arbiter,cpSpace* l_space,cpDataPointer l_data){
      cpShape* l_a{};
      cpShape* l_b{};
      cpArbiterGetShapes(l_arbiter,(&l_a),(&l_b));
      bb_print((((bbString(L"Collision! a=",13)+bbString(cpShapeGetCollisionType(l_a)))+bbString(L", b=",4))+bbString(cpShapeGetCollisionType(l_b))));
      return cpBool(1);
    }
    void gcMark(){
      bbGCMark(l_self);
    }
  };
  f0.l_handler->beginFunc=bbFunction<cpBool(cpArbiter*,cpSpace*,cpDataPointer)>(new lambda0(this));
}
t_default_HelloChipmunk::~t_default_HelloChipmunk(){
}

void t_default_HelloChipmunk::m_OnRender(t_sdk_0mojo_m2_graphics_Canvas* l_canvas){
  struct f0_t : public bbGCFrame{
    t_sdk_0mojo_m2_app_AppInstance* t0{};
    t_default_ChipmunkDebugger* t1{};
    void gcMark(){
      bbGCMark(t0);
      bbGCMark(t1);
    }
  }f0{};
  (f0.t0=g_sdk_0mojo_m2_app_App.get())->m_RequestRender();
  static bbFloat g_timeStep=0.016666666666666666f;
  cpSpaceStep(this->m_space,cpFloat(g_timeStep));
  l_canvas->m_Translate(bbFloat((this->m_Width()/2)),bbFloat((this->m_Height()/2)));
  (f0.t1=this->m_debugger.get())->m_DebugDraw(l_canvas,this->m_space);
}

void t_default_HelloChipmunk::m_Cleanup(){
  cpShapeFree(this->m_ballShape);
  cpBodyFree(this->m_ballBody);
  cpShapeFree(this->m_ground);
  cpSpaceFree(this->m_space);
}

void mx2_hellochimpmunk_hellochimpmunk_init_f(){
}
