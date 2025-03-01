
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2orb.h"

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_gamegraphics_2src_2sprite.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2area.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_math_2algebraic_2vectorials_2types_2vec2.h"

extern bbDouble g_stdlib_math_random_Rnd();
bbDouble g_default_Orb_cullDistance;

t_default_Orb::t_default_Orb(t_default_Sprite* l_sprite):t_default_Actor(l_sprite){
  this->m_name=bbString(L"orb",3);
}
t_default_Orb::~t_default_Orb(){
}

void t_default_Orb::m_OnUpdate(){
  struct f0_t : public bbGCFrame{
    t_default_Sprite* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  this->m_position.m_X((this->m_position.m_X()-1.0));
  if((this->m_position.m_X()<(g_default_Actor_camera.get()->m_Left()-(f0.t0=this->m_sprite.get())->m_Width()))){
    this->m_Reset();
  }
}

void t_default_Orb::m_OnReset(){
  struct f0_t : public bbGCFrame{
    t_default_Sprite* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  this->m_position.m_X((g_default_Actor_camera.get()->m_Right()+(f0.t0=this->m_sprite.get())->m_Width()));
  bbDouble l_n=((g_stdlib_math_random_Rnd()*240.0)-120.0);
  this->m_position.m_Y(l_n);
}

void mx2_gridshooter_src_2orb_init_f(){
}
