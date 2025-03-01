
#ifndef MX2_GRIDSHOOTER_SRC_2PLAYER_H
#define MX2_GRIDSHOOTER_SRC_2PLAYER_H

#include <bbmonkey.h>

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2actor.h"

BB_CLASS(t_default_Sprite)

BB_CLASS(t_default_Player)

struct t_default_Player : public t_default_Actor{
  typedef t_default_Player *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_default_Player";}

  bbDouble m_oldY{};
  bbDouble m_limitY{180.0};

  t_default_Player(t_default_Sprite* l_sprite);
  ~t_default_Player();

  void m_OnUpdate();

  t_default_Player(){
  }
};

#endif
