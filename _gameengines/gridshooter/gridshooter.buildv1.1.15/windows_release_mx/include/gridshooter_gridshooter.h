
#ifndef MX2_GRIDSHOOTER_GRIDSHOOTER_H
#define MX2_GRIDSHOOTER_GRIDSHOOTER_H

#include <bbmonkey.h>

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2renderwindow.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_resources_2graphics_2color.h"

BB_CLASS(t_default_Background)
BB_CLASS(t_default_Player)
BB_CLASS(t_sdk_0mojo_m2_graphics_Font)

BB_CLASS(t_default_Game)

extern bbFloat g_default_Game_cameraSpeed;
extern bbDouble g_default_Game_scrollLimitY;
extern bbFloat g_default_Game_scrollSpeed;

void bbMain();

struct t_default_Game : public t_default_RenderWindow{
  typedef t_default_Game *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_default_Game";}

  bbGCVar<t_default_Player> m_hero{};
  bbGCVar<t_default_Background> m_bg{};
  bbGCVar<t_default_Background> m_bgGrid{};
  bbGCVar<t_sdk_0mojo_m2_graphics_Font> m_smallFont{};
  t_stdlib_graphics_Color m_colorTint{};

  void init();

  void gcMark();

  t_default_Game();
  ~t_default_Game();

  void m_OnUpdate();
  void m_OnStart();
  void m_OnDraw();
};

#endif
