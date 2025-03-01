
#ifndef MX2_GRIDSHOOTER_GAMEGRAPHICS_2SRC_2SPRITE_H
#define MX2_GRIDSHOOTER_GAMEGRAPHICS_2SRC_2SPRITE_H

#include <bbmonkey.h>

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_gamegraphics_2gamegraphics.h"
#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_types.h"

BB_CLASS(t_sdk_0mojo_m2_graphics_Canvas)
BB_CLASS(t_stdlib_collections_Map_1sTt_default_AnimationClip_2)

BB_CLASS(t_default_Sprite)
BB_CLASS(t_default_AnimationClip)

struct t_default_Sprite : public t_default_GameGraphics{
  typedef t_default_Sprite *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_default_Sprite";}

  bbFloat m_timeScale{1.0f};
  bbInt m_frameRate{10};
  bbGCVar<t_stdlib_collections_Map_1sTt_default_AnimationClip_2> m_animations{};
  bbInt m__0time{};
  bbInt m__0period{};
  bbInt m__0listFrame{};
  bbInt m__0clampedListFrame{};
  bbInt m__0duration{};
  bbInt m__0frame{};
  bbInt m__0startTime{};
  bbString m__0anim{};

  void init();

  void gcMark();

  t_default_Sprite(bbString l_ImagePath,bbInt l_Totalframes,bbInt l_cellWidth,bbInt l_cellHeight,bbBool l_filter);
  ~t_default_Sprite();

  void m_Reset();

  bbInt m_Frame(){
    return this->m__0frame;
  }
  bbInt m_Duration(bbString l_anim);
  void m_Draw(t_sdk_0mojo_m2_graphics_Canvas* l_canvas,bbString l_anim,bbFloat l_x,bbFloat l_y,bbFloat l_rotation,bbFloat l_scaleX,bbFloat l_scaleY,bbInt l_time);
  void m_AddAnimationClip(bbString l__0id,bbArray<bbInt> l__0frames,bbBool l__0loop);

  t_default_Sprite(){
    init();
  }
};

struct t_default_AnimationClip : public bbObject{
  typedef t_default_AnimationClip *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_default_AnimationClip";}

  bbString m_id{};
  bbArray<bbInt> m_frame{};
  bbBool m_loop{true};

  void gcMark();

  ~t_default_AnimationClip();

  bbInt m_Count();

  t_default_AnimationClip(){
  }
};

#endif
