
#ifndef MX2_GRIDSHOOTER_GAMEGRAPHICS_2GAMEGRAPHICS_H
#define MX2_GRIDSHOOTER_GAMEGRAPHICS_2GAMEGRAPHICS_H

#include <bbmonkey.h>

#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_types.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_math_2algebraic_2vectorials_2types_2vec2.h"

BB_CLASS(t_sdk_0mojo_m2_graphics_Canvas)
BB_CLASS(t_sdk_0mojo_m2_graphics_Image)

BB_CLASS(t_default_GameGraphics)

void g_default_GameGraphics_DrawRectOutline(t_sdk_0mojo_m2_graphics_Canvas* l_canvas,bbInt l_left,bbInt l_top,bbInt l_width,bbInt l_height);

struct t_default_GameGraphics : public bbObject{
  typedef t_default_GameGraphics *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_default_GameGraphics";}

  bbArray<bbGCVar<t_sdk_0mojo_m2_graphics_Image>> m_images{};
  bbBool m_debug{false};
  t_stdlib_math_types_Vec2_1f m__0handle{};

  void init();

  void gcMark();

  ~t_default_GameGraphics();

  bbDouble m_Width();
  bbArray<bbGCVar<t_sdk_0mojo_m2_graphics_Image>> m_LoadFrames(bbString l_path,bbInt l_numFrames,bbInt l_cellWidth,bbInt l_cellHeight,bbBool l_filter,bbBool l_padded);
  bbDouble m_Height();
  void m_Handle(t_stdlib_math_types_Vec2_1f l_handle);
  t_stdlib_math_types_Vec2_1f m_Handle();
  void m_DrawOutline(t_sdk_0mojo_m2_graphics_Canvas* l_canvas,bbFloat l_x,bbFloat l_y,bbFloat l_width,bbFloat l_height,bbFloat l_rz,bbFloat l_sx,bbFloat l_sy);

  t_default_GameGraphics(){
    init();
  }
};

#endif
