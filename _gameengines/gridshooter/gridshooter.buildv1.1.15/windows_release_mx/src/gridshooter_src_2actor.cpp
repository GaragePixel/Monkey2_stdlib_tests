
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2actor.h"

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_gamegraphics_2src_2sprite.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2area.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_stdlib_collections_2stack.h"

extern bbInt g_stdlib_system_time_Millisecs();
bbGCVar<t_stdlib_collections_Stack_1Tt_default_Bullet_2> g_default_Actor_bulletPool;
bbGCVar<t_default_Area_1d> g_default_Actor_camera;
bbGCVar<t_stdlib_collections_Stack_1Tt_default_Actor_2> g_default_Actor_catalog;
bbDouble g_default_Actor_cullDistance;
bbInt g_default_Actor_currentBullet;
bbGCVar<t_default_Actor> g_default_Actor_player;
bbFloat g_default_Actor_scrollSpeed;

void g_default_Actor_UpdateAll(){
  {
    struct f1_t : public bbGCFrame{
      t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator l_0{};
      t_stdlib_collections_Stack_1Tt_default_Actor_2* t0{};
      void gcMark(){
        bbGCMark(l_0);
        bbGCMark(t0);
      }
    }f1{};
    f1.l_0=(f1.t0=g_default_Actor_catalog.get())->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_default_Actor* l_a{};
        void gcMark(){
          bbGCMark(l_a);
        }
      }f2{};
      f2.l_a=f1.l_0.m_Current();
      if(f2.l_a->m_visible){
        struct f3_t : public bbGCFrame{
          t_default_Area_1d* t0{};
          void gcMark(){
            bbGCMark(t0);
          }
        }f3{};
        if(f2.l_a->m__0hide){
          f2.l_a->m__0hideTimer=(g_stdlib_system_time_Millisecs()-f2.l_a->m__0hideTimerStart);
          if((f2.l_a->m__0hideTimer>f2.l_a->m__0hideWait)){
            f2.l_a->m_visible=false;
            f2.l_a->m__0hide=false;
          }
        }
        f2.l_a->m_position.m_X((f2.l_a->m_position.m_X()+bbDouble(g_default_Actor_scrollSpeed)));
        f2.l_a->m_OnUpdate();
        (f3.t0=f2.l_a->m_collider.get())->m_Position(f2.l_a->m_position.m_X(),f2.l_a->m_position.m_Y());
      }
    }
  }
}

void g_default_Actor_DrawAll(t_sdk_0mojo_m2_graphics_Canvas* l_canvas){
  {
    struct f1_t : public bbGCFrame{
      t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator l_0{};
      t_stdlib_collections_Stack_1Tt_default_Actor_2* t0{};
      void gcMark(){
        bbGCMark(l_0);
        bbGCMark(t0);
      }
    }f1{};
    f1.l_0=(f1.t0=g_default_Actor_catalog.get())->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_default_Actor* l_a{};
        void gcMark(){
          bbGCMark(l_a);
        }
      }f2{};
      f2.l_a=f1.l_0.m_Current();
      if(f2.l_a->m_visible){
        struct f3_t : public bbGCFrame{
          t_default_Sprite* t0{};
          void gcMark(){
            bbGCMark(t0);
          }
        }f3{};
        (f3.t0=f2.l_a->m_sprite.get())->m_Draw(l_canvas,f2.l_a->m_anim,bbFloat(f2.l_a->m_position.m_X()),bbFloat(f2.l_a->m_position.m_Y()),0.0f,1.0f,1.0f,-1);
        f2.l_a->m_OnDraw(l_canvas);
      }
    }
  }
}

void t_default_Actor::init(){
  m_name=bbString{};
  m_anim=bbString(L"idle",4);
  m_position=t_stdlib_math_types_Vec2_1d{bbNullCtor};
}

void t_default_Actor::gcMark(){
  bbGCMark(m_sprite);
  bbGCMark(m_collider);
}

t_default_Actor::t_default_Actor(t_default_Sprite* l_sprite){
  init();
  struct f0_t : public bbGCFrame{
    t_stdlib_collections_Stack_1Tt_default_Actor_2* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  this->m_sprite=l_sprite;
  (f0.t0=g_default_Actor_catalog.get())->m_Push(this);
  this->m_collider=bbGCNew<t_default_Area_1d>(0.0,0.0,l_sprite->m_Width(),l_sprite->m_Height());
  this->m_Reset();
}
t_default_Actor::~t_default_Actor(){
}

void t_default_Actor::m_Reset(){
  struct f0_t : public bbGCFrame{
    t_default_Sprite* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  (f0.t0=this->m_sprite.get())->m_Reset();
  this->m__0hide=false;
  this->m_detectCollision=true;
  this->m_OnReset();
}

void t_default_Actor::m_OnUpdate(){
}

void t_default_Actor::m_OnReset(){
}

void t_default_Actor::m_OnDraw(t_sdk_0mojo_m2_graphics_Canvas* l_canvas){
}

void t_default_Actor::m_Hide(bbInt l_time){
  this->m__0hide=true;
  this->m__0hideTimerStart=g_stdlib_system_time_Millisecs();
  this->m__0hideWait=l_time;
}

void mx2_gridshooter_src_2actor_init_f(){
  g_default_Actor_bulletPool=bbGCNew<t_stdlib_collections_Stack_1Tt_default_Bullet_2>();
  g_default_Actor_catalog=bbGCNew<t_stdlib_collections_Stack_1Tt_default_Actor_2>();
  g_default_Actor_currentBullet=bbInt(0);
  g_default_Actor_scrollSpeed=5.0f;
}

struct mx2_gridshooter_src_2actor_roots_t : bbGCRoot{
  void gcMark(){
    bbGCMark(g_default_Actor_bulletPool.get());
    bbGCMark(g_default_Actor_camera.get());
    bbGCMark(g_default_Actor_catalog.get());
    bbGCMark(g_default_Actor_player.get());
  }
}mx2_gridshooter_src_2actor_roots;
