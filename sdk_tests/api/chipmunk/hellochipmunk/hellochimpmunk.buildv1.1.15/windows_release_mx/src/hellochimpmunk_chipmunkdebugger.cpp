
#include "hellochimpmunk.buildv1.1.15/windows_release_mx/include/hellochimpmunk_chipmunkdebugger.h"

#include "hellochimpmunk.buildv1.1.15/windows_release_mx/include/hellochimpmunk_stdlib_collections_2map.h"
#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_math.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2canvas.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_resources_2graphics_2color.h"

extern bbDouble g_stdlib_math_random_Rnd(bbDouble l_max);
void t_default_ChipmunkDebugger::init(){
  m__0options=bbGCNew<bb_cpSpaceDebugDrawOptions>();
  m__0colors=bbGCNew<t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2>();
}

void t_default_ChipmunkDebugger::gcMark(){
  bbGCMark(m__0options);
  bbGCMark(m__0colors);
  bbGCMark(m__0canvas);
}

t_default_ChipmunkDebugger::t_default_ChipmunkDebugger(){
  init();
  this->m__0options.get()->drawCircle=bbMethod<t_default_ChipmunkDebugger,void,cpVect,cpFloat,cpFloat,cpSpaceDebugColor,cpSpaceDebugColor,cpDataPointer>((t_default_ChipmunkDebugger*)(this),&t_default_ChipmunkDebugger::m_DrawCircle);
  this->m__0options.get()->drawSegment=bbMethod<t_default_ChipmunkDebugger,void,cpVect,cpVect,cpSpaceDebugColor,cpDataPointer>((t_default_ChipmunkDebugger*)(this),&t_default_ChipmunkDebugger::m_DrawSegment);
  this->m__0options.get()->drawFatSegment=bbMethod<t_default_ChipmunkDebugger,void,cpVect,cpVect,cpFloat,cpSpaceDebugColor,cpSpaceDebugColor,cpDataPointer>((t_default_ChipmunkDebugger*)(this),&t_default_ChipmunkDebugger::m_DrawFatSegment);
  this->m__0options.get()->drawPolygon=bbMethod<t_default_ChipmunkDebugger,void,bbInt,cpVect*,cpFloat,cpSpaceDebugColor,cpSpaceDebugColor,cpDataPointer>((t_default_ChipmunkDebugger*)(this),&t_default_ChipmunkDebugger::m_DrawPolygon);
  this->m__0options.get()->drawDot=bbMethod<t_default_ChipmunkDebugger,void,cpFloat,cpVect,cpSpaceDebugColor,cpDataPointer>((t_default_ChipmunkDebugger*)(this),&t_default_ChipmunkDebugger::m_DrawDot);
  this->m__0options.get()->colorForShape=bbMethod<t_default_ChipmunkDebugger,cpSpaceDebugColor,cpShape*,cpDataPointer>((t_default_ChipmunkDebugger*)(this),&t_default_ChipmunkDebugger::m_ColorForShape);
  this->m__0options.get()->flags=CP_SPACE_DEBUG_DRAW_SHAPES;
}
t_default_ChipmunkDebugger::~t_default_ChipmunkDebugger(){
}

void t_default_ChipmunkDebugger::m_DrawSegment(cpVect l_a,cpVect l_b,cpSpaceDebugColor l_color,cpDataPointer l_data){
  struct f0_t : public bbGCFrame{
    t_sdk_0mojo_m2_graphics_Canvas* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  (f0.t0=this->m__0canvas.get())->m_Color(t_stdlib_graphics_Color{l_color.r,l_color.g,l_color.b,1.0f});
  (f0.t0=this->m__0canvas.get())->m_LineWidth(1.0f);
  (f0.t0=this->m__0canvas.get())->m_DrawLine(bbFloat(l_a.x),bbFloat(l_a.y),bbFloat(l_b.x),bbFloat(l_b.y));
}

void t_default_ChipmunkDebugger::m_DrawPolygon(bbInt l_count,cpVect* l_verts,cpFloat l_radius,cpSpaceDebugColor l_outlineColor,cpSpaceDebugColor l_fillColor,cpDataPointer l_data){
  struct f0_t : public bbGCFrame{
    bbArray<bbFloat> l_vs{};
    t_sdk_0mojo_m2_graphics_Canvas* t0{};
    void gcMark(){
      bbGCMark(l_vs);
      bbGCMark(t0);
    }
  }f0{};
  f0.l_vs=bbArray<bbFloat>((l_count*2));
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_count);l_i+=1){
      f0.l_vs[(l_i*2)]=bbFloat(l_verts[l_i].x);
      f0.l_vs[((l_i*2)+1)]=bbFloat(l_verts[l_i].y);
    }
  }
  (f0.t0=this->m__0canvas.get())->m_OutlineColor(t_stdlib_graphics_Color{l_outlineColor.r,l_outlineColor.g,l_outlineColor.b,1.0f});
  (f0.t0=this->m__0canvas.get())->m_Color(t_stdlib_graphics_Color{l_fillColor.r,l_fillColor.g,l_fillColor.b,1.0f});
  (f0.t0=this->m__0canvas.get())->m_DrawPolys(l_count,1,f0.l_vs);
}

void t_default_ChipmunkDebugger::m_DrawFatSegment(cpVect l_a,cpVect l_b,cpFloat l_radius,cpSpaceDebugColor l_outlineColor,cpSpaceDebugColor l_fillColor,cpDataPointer l_data){
  struct f0_t : public bbGCFrame{
    t_sdk_0mojo_m2_graphics_Canvas* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  (f0.t0=this->m__0canvas.get())->m_OutlineColor(t_stdlib_graphics_Color{l_outlineColor.r,l_outlineColor.g,l_outlineColor.b,1.0f});
  (f0.t0=this->m__0canvas.get())->m_Color(t_stdlib_graphics_Color{l_fillColor.r,l_fillColor.g,l_fillColor.b,1.0f});
  (f0.t0=this->m__0canvas.get())->m_LineWidth(bbFloat(l_radius));
  (f0.t0=this->m__0canvas.get())->m_DrawLine(bbFloat(l_a.x),bbFloat(l_a.y),bbFloat(l_b.x),bbFloat(l_b.y));
}

void t_default_ChipmunkDebugger::m_DrawDot(cpFloat l_size,cpVect l_pos,cpSpaceDebugColor l_color,cpDataPointer l_data){
  struct f0_t : public bbGCFrame{
    t_sdk_0mojo_m2_graphics_Canvas* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  (f0.t0=this->m__0canvas.get())->m_Color(t_stdlib_graphics_Color{l_color.r,l_color.g,l_color.b,1.0f});
  (f0.t0=this->m__0canvas.get())->m_PointSize(bbFloat(l_size));
  (f0.t0=this->m__0canvas.get())->m_DrawPoint(bbFloat(l_pos.x),bbFloat(l_pos.y));
}

void t_default_ChipmunkDebugger::m_DrawCircle(cpVect l_pos,cpFloat l_angle,cpFloat l_radius,cpSpaceDebugColor l_outlineColor,cpSpaceDebugColor l_fillColor,cpDataPointer l_data){
  struct f0_t : public bbGCFrame{
    t_sdk_0mojo_m2_graphics_Canvas* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  (f0.t0=this->m__0canvas.get())->m_OutlineColor(t_stdlib_graphics_Color{l_outlineColor.r,l_outlineColor.g,l_outlineColor.b,1.0f});
  (f0.t0=this->m__0canvas.get())->m_Color(t_stdlib_graphics_Color{l_fillColor.r,l_fillColor.g,l_fillColor.b,1.0f});
  (f0.t0=this->m__0canvas.get())->m_DrawCircle(bbFloat(l_pos.x),bbFloat(l_pos.y),bbFloat(l_radius));
  (f0.t0=this->m__0canvas.get())->m_Color(g_stdlib_graphics_Color_Black);
  (f0.t0=this->m__0canvas.get())->m_DrawLine(bbFloat(l_pos.x),bbFloat(l_pos.y),bbFloat((l_pos.x+(std::cos(l_angle)*l_radius))),bbFloat((l_pos.y+(std::sin(l_angle)*l_radius))));
}

void t_default_ChipmunkDebugger::m_DebugDraw(t_sdk_0mojo_m2_graphics_Canvas* l_canvas,cpSpace* l_space){
  struct f0_t : public bbGCFrame{
    bb_cpSpaceDebugDrawOptions* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  this->m__0canvas=l_canvas;
  l_canvas->m_OutlineMode(t_sdk_0mojo_m2_graphics_OutlineMode(2));
  l_canvas->m_OutlineWidth(3.0f);
  bb_cpSpaceDebugDraw(l_space,f0.t0=this->m__0options.get());
}

cpSpaceDebugColor t_default_ChipmunkDebugger::m_ColorForShape(cpShape* l_shape,cpDataPointer l_data){
  struct f0_t : public bbGCFrame{
    t_stdlib_collections_Map_1TcpShape_2TcpSpaceDebugColor_2* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  cpSpaceDebugColor l_color=(f0.t0=this->m__0colors.get())->m__idx(l_shape);
  if(bbBool(l_color.a)){
    return l_color;
  }
  l_color.r=bbFloat(g_stdlib_math_random_Rnd(1.0));
  l_color.g=bbFloat(g_stdlib_math_random_Rnd(bbDouble((1.0f-l_color.r))));
  l_color.b=bbFloat(g_stdlib_math_random_Rnd(bbDouble(((1.0f-l_color.r)-l_color.g))));
  l_color.a=1.0f;
  (f0.t0=this->m__0colors.get())->m__idxeq(l_shape,l_color);
  return l_color;
}

void mx2_hellochimpmunk_chipmunkdebugger_init_f(){
}
