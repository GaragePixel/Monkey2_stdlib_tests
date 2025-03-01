
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2bullet.h"

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_gamegraphics_2src_2sprite.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2area.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_stdlib_collections_2stack.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_math_2algebraic_2vectorials_2types_2vec2.h"

t_default_Bullet::t_default_Bullet(t_default_Sprite* l_sprite):t_default_Actor(l_sprite){
  this->m_visible=false;
  this->m_speed=15.0;
  this->m_name=bbString(L"bullet",6);
}
t_default_Bullet::~t_default_Bullet(){
}

void t_default_Bullet::m_OnUpdate(){
  struct f0_t : public bbGCFrame{
    t_default_Area_1d* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  this->m_position.m_X((this->m_position.m_X()+this->m_speed));
  (f0.t0=this->m_collider.get())->m_Position(this->m_position.m_X(),this->m_position.m_Y());
  if((this->m_position.m_X()>(g_default_Actor_player.get()->m_position.m_X()+g_default_Actor_cullDistance))){
    this->m_visible=false;
  }
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
        t_default_Actor* l_other{};
        void gcMark(){
          bbGCMark(l_other);
        }
      }f2{};
      f2.l_other=f1.l_0.m_Current();
      if(this->m_detectCollision){
        if(((f2.l_other->m_visible&&!(f2.l_other->m_name==bbString(L"bullet",6)))&&!(f2.l_other==g_default_Actor_player.get()))){
          struct f4_t : public bbGCFrame{
            t_default_Area_1d* t0{};
            t_default_Area_1d* t1{};
            void gcMark(){
              bbGCMark(t0);
              bbGCMark(t1);
            }
          }f4{};
          if((f4.t1=this->m_collider.get())->m_Overlaps(f4.t0=f2.l_other->m_collider.get())){
            struct f5_t : public bbGCFrame{
              t_default_Sprite* t0{};
              void gcMark(){
                bbGCMark(t0);
              }
            }f5{};
            this->m_speed=0.0;
            this->m_anim=bbString(L"hit",3);
            this->m_detectCollision=false;
            (f5.t0=this->m_sprite.get())->m_Reset();
            this->m_Hide(200);
            f2.l_other->m_Reset();
          }
        }
      }
    }
  }
}

void t_default_Bullet::m_OnReset(){
  struct f0_t : public bbGCFrame{
    t_default_Area_1d* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  (f0.t0=this->m_collider.get())->m_Size(8.0,8.0);
  this->m_speed=8.0;
  this->m_anim=bbString(L"idle",4);
}

void mx2_gridshooter_src_2bullet_init_f(){
}
