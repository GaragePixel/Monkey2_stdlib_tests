
#ifndef MX2_GRIDSHOOTER_SRC_2AREA_H
#define MX2_GRIDSHOOTER_SRC_2AREA_H

#include <bbmonkey.h>

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_stdlib_math_2algebraic_2vectorials_2types_2rect.h"
#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_types.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_math_2algebraic_2vectorials_2types_2vec2.h"

BB_CLASS(t_default_Area_1d)

struct t_default_Area_1d : public bbObject{
  typedef t_default_Area_1d *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_default_Area_1d";}

  t_stdlib_math_types_Vec2_1d m__0vec{};
  bbDouble m__0width{};
  bbDouble m__0height{};
  t_stdlib_math_types_Vec2_1f m__0handle{};
  bbDouble m__0x0{};
  bbDouble m__0y0{};
  bbDouble m__0x1{};
  bbDouble m__0y1{};
  bbDouble m__0pivotX{};
  bbDouble m__0pivotY{};
  t_stdlib_math_types_Rect_1d m__0rect{};

  void init();

  t_default_Area_1d(bbDouble l_x,bbDouble l_y,bbDouble l__0width,bbDouble l__0height);
  ~t_default_Area_1d();

  void m_Y(bbDouble l_y);
  bbDouble m_Y();
  void m_X(bbDouble l_x);
  bbDouble m_X();
  void m_Width(bbDouble l_w);

  bbDouble m_Width(){
    return this->m__0width;
  }

  bbDouble m_Top(){
    return this->m__0y0;
  }
  bbString m_ToString();
  void m_Size(bbDouble l__0width,bbDouble l__0height);
  void m_SetHandle(bbFloat l_pX,bbFloat l_pY);

  bbDouble m_Right(){
    return this->m__0x1;
  }
  t_stdlib_math_types_Rect_1d m_Rect();
  void m_PositionByCorner(bbFloat l__0x0,bbFloat l__0y0);
  void m_Position(bbDouble l_x,bbDouble l_y);
  bbBool m_Overlaps(t_default_Area_1d* l_rect);
  void m_Move(bbFloat l_deltaX,bbFloat l_deltaY);

  bbDouble m_Left(){
    return this->m__0x0;
  }
  void m_Height(bbDouble l_h);

  bbDouble m_Height(){
    return this->m__0height;
  }
  t_stdlib_math_types_Vec2_1f m_Handle();
  bbBool m_Contains(bbFloat l__0x,bbFloat l__0y);

  bbDouble m_Bottom(){
    return this->m__0y1;
  }

  t_default_Area_1d(){
    init();
  }
};

#endif
