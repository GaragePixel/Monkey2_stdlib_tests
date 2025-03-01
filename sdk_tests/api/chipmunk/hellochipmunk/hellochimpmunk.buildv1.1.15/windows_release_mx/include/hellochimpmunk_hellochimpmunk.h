
#ifndef MX2_HELLOCHIMPMUNK_HELLOCHIMPMUNK_H
#define MX2_HELLOCHIMPMUNK_HELLOCHIMPMUNK_H

#include <bbmonkey.h>

#include "sdk/sdk.buildv1.1.15/windows_release_mx/include/sdk_api_2physics_2chipmunk_2body.h"
#include "sdk/sdk.buildv1.1.15/windows_release_mx/include/sdk_api_2physics_2chipmunk_2shape.h"
#include "sdk/sdk.buildv1.1.15/windows_release_mx/include/sdk_api_2physics_2chipmunk_2space.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2app_2window.h"

BB_CLASS(t_default_ChipmunkDebugger)
BB_CLASS(t_sdk_0mojo_m2_graphics_Canvas)

BB_CLASS(t_default_HelloChipmunk)

void bbMain();

struct t_default_HelloChipmunk : public t_sdk_0mojo_m2_app_Window{
  typedef t_default_HelloChipmunk *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_default_HelloChipmunk";}

  cpSpace* m_space{};
  cpShape* m_ground{};
  cpBody* m_ballBody{};
  cpShape* m_ballShape{};
  cpBody* m_ballBody2{};
  cpShape* m_ballShape2{};
  cpBody* m_polyBody{};
  cpShape* m_polyShape{};
  bbGCVar<t_default_ChipmunkDebugger> m_debugger{};

  void init();

  void gcMark();

  t_default_HelloChipmunk();
  ~t_default_HelloChipmunk();

  void m_OnRender(t_sdk_0mojo_m2_graphics_Canvas* l_canvas);
  void m_Cleanup();
};

#endif
