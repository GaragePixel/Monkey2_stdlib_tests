
#ifndef MX2_HELLOCHIMPMUNK_CHIPMUNKDEBUGGER_H
#define MX2_HELLOCHIMPMUNK_CHIPMUNKDEBUGGER_H

#include <bbmonkey.h>

#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_types.h"
#include "sdk/sdk.buildv1.1.15/windows_release_mx/include/sdk_api_2physics_2chipmunk_2shape.h"
#include "sdk/sdk.buildv1.1.15/windows_release_mx/include/sdk_api_2physics_2chipmunk_2space.h"
#include "sdk/sdk.buildv1.1.15/windows_release_mx/include/sdk_api_2physics_2chipmunk_2types.h"

BB_CLASS(t_sdk_0mojo_m2_graphics_Canvas)
BB_CLASS(t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2)

BB_CLASS(t_default_ChipmunkDebugger)

struct t_default_ChipmunkDebugger : public bbObject{
  typedef t_default_ChipmunkDebugger *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_default_ChipmunkDebugger";}

  bbGCVar<bb_cpSpaceDebugDrawOptions> m__0options{};
  bbGCVar<t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2> m__0colors{};
  bbGCVar<t_sdk_0mojo_m2_graphics_Canvas> m__0canvas{};

  void init();

  void gcMark();

  t_default_ChipmunkDebugger();
  ~t_default_ChipmunkDebugger();

  void m_DrawSegment(cpVect l_a,cpVect l_b,cpSpaceDebugColor l_color,cpDataPointer l_data);
  void m_DrawPolygon(bbInt l_count,cpVect* l_verts,cpFloat l_radius,cpSpaceDebugColor l_outlineColor,cpSpaceDebugColor l_fillColor,cpDataPointer l_data);
  void m_DrawFatSegment(cpVect l_a,cpVect l_b,cpFloat l_radius,cpSpaceDebugColor l_outlineColor,cpSpaceDebugColor l_fillColor,cpDataPointer l_data);
  void m_DrawDot(cpFloat l_size,cpVect l_pos,cpSpaceDebugColor l_color,cpDataPointer l_data);
  void m_DrawCircle(cpVect l_pos,cpFloat l_angle,cpFloat l_radius,cpSpaceDebugColor l_outlineColor,cpSpaceDebugColor l_fillColor,cpDataPointer l_data);
  void m_DebugDraw(t_sdk_0mojo_m2_graphics_Canvas* l_canvas,cpSpace* l_space);
  cpSpaceDebugColor m_ColorForShape(cpShape* l_shape,cpDataPointer l_data);
};

#endif
