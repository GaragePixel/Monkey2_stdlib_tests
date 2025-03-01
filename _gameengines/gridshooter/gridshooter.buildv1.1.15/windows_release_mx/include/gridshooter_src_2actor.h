
#ifndef MX2_GRIDSHOOTER_SRC_2ACTOR_H
#define MX2_GRIDSHOOTER_SRC_2ACTOR_H

#include <bbmonkey.h>

#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_types.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_math_2algebraic_2vectorials_2types_2vec2.h"

BB_CLASS(t_default_Area_1d)
BB_CLASS(t_default_Sprite)
BB_CLASS(t_sdk_0mojo_m2_graphics_Canvas)
BB_CLASS(t_stdlib_collections_Stack_1Tt_default_Actor_2)
BB_CLASS(t_stdlib_collections_Stack_1Tt_default_Bullet_2)

BB_CLASS(t_default_Actor)

extern bbGCVar<t_stdlib_collections_Stack_1Tt_default_Bullet_2> g_default_Actor_bulletPool;
extern bbGCVar<t_default_Area_1d> g_default_Actor_camera;
extern bbGCVar<t_stdlib_collections_Stack_1Tt_default_Actor_2> g_default_Actor_catalog;
extern bbDouble g_default_Actor_cullDistance;
extern bbInt g_default_Actor_currentBullet;
extern bbGCVar<t_default_Actor> g_default_Actor_player;
extern bbFloat g_default_Actor_scrollSpeed;

void g_default_Actor_UpdateAll();
void g_default_Actor_DrawAll(t_sdk_0mojo_m2_graphics_Canvas* l_canvas);

struct t_default_Actor : public bbObject{
  typedef t_default_Actor *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_default_Actor";}

  bbString m_name{};
  bbBool m_visible{true};
  bbDouble m_speed{3.0};
  bbString m_anim{};
  bbBool m_detectCollision{true};
  bbGCVar<t_default_Sprite> m_sprite{};
  t_stdlib_math_types_Vec2_1d m_position{};
  bbGCVar<t_default_Area_1d> m_collider{};
  bbBool m__0hide{false};
  bbInt m__0hideTimer{bbInt(0)};
  bbInt m__0hideTimerStart{bbInt(0)};
  bbInt m__0hideWait{bbInt(0)};

  void init();

  void gcMark();

  t_default_Actor(t_default_Sprite* l_sprite);
  ~t_default_Actor();

  void m_Reset();
  virtual void m_OnUpdate();
  virtual void m_OnReset();
  virtual void m_OnDraw(t_sdk_0mojo_m2_graphics_Canvas* l_canvas);
  void m_Hide(bbInt l_time);

  t_default_Actor(){
    init();
  }
};

#endif
