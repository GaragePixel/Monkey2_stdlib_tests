
#ifndef MX2_GRIDSHOOTER_STDLIB_MATH_2ALGEBRAIC_2VECTORIALS_2TYPES_2RECT_H
#define MX2_GRIDSHOOTER_STDLIB_MATH_2ALGEBRAIC_2VECTORIALS_2TYPES_2RECT_H

#include <bbmonkey.h>
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_math_2algebraic_2vectorials_2types_2rect.h"

#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_math_2algebraic_2vectorials_2types_2vec2.h"

BB_STRUCT(t_stdlib_math_types_Rect_1d)

struct t_stdlib_math_types_Rect_1d{
  typedef t_stdlib_math_types_Rect_1d bb_struct_type;
  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_stdlib_math_types_Rect_1d";}

  t_stdlib_math_types_Vec2_1d m_min{};
  t_stdlib_math_types_Vec2_1d m_max{};

  t_stdlib_math_types_Rect_1d(t_stdlib_math_types_Vec2_1d l_min,bbDouble l_x1,bbDouble l_y1);
  t_stdlib_math_types_Rect_1d(bbDouble l_x0,bbDouble l_y0,t_stdlib_math_types_Vec2_1d l_max);
  t_stdlib_math_types_Rect_1d(bbDouble l_x0,bbDouble l_y0,bbDouble l_x1,bbDouble l_y1);
  t_stdlib_math_types_Rect_1d(t_stdlib_math_types_Vec2_1d l_min,t_stdlib_math_types_Vec2_1d l_max);
  t_stdlib_math_types_Rect_1d(bbNullCtor_t);
  ~t_stdlib_math_types_Rect_1d();

  void m__oreq(t_stdlib_math_types_Rect_1d l_r);
  t_stdlib_math_types_Rect_1d m__or(t_stdlib_math_types_Rect_1d l_r);
  bbString m_to_s();
  void m_Y(bbDouble l_y);
  bbDouble m_Y();
  void m_X(bbDouble l_x);
  bbDouble m_X();
  bbDouble m_Width();
  void m_TopRight(t_stdlib_math_types_Vec2_1d l_v);
  t_stdlib_math_types_Vec2_1d m_TopRight();
  void m_TopLeft(t_stdlib_math_types_Vec2_1d l_v);
  t_stdlib_math_types_Vec2_1d m_TopLeft();
  void m_Top(bbDouble l_top);
  bbDouble m_Top();
  bbString m_ToString();
  void m_Size(t_stdlib_math_types_Vec2_1d l_size);
  t_stdlib_math_types_Vec2_1d m_Size();
  void m_Right(bbDouble l_right);
  bbDouble m_Right();
  void m_Origin(t_stdlib_math_types_Vec2_1d l_origin);
  t_stdlib_math_types_Vec2_1d m_Origin();
  void m_Left(bbDouble l_left);
  bbDouble m_Left();
  bbBool m_Intersects(t_stdlib_math_types_Rect_1d l_r);
  bbDouble m_Height();
  bbBool m_Empty();
  bbBool m_Contains(t_stdlib_math_types_Rect_1d l_r);
  bbBool m_Contains(t_stdlib_math_types_Vec2_1d l_v);
  t_stdlib_math_types_Rect_1d m_Centered(t_stdlib_math_types_Rect_1d l_r);
  t_stdlib_math_types_Vec2_1d m_Center();
  void m_BottomRight(t_stdlib_math_types_Vec2_1d l_v);
  t_stdlib_math_types_Vec2_1d m_BottomRight();
  void m_BottomLeft(t_stdlib_math_types_Vec2_1d l_v);
  t_stdlib_math_types_Vec2_1d m_BottomLeft();
  void m_Bottom(bbDouble l_bottom);
  bbDouble m_Bottom();
  void m__diveq(t_stdlib_math_types_Vec2_1d l_v);
  t_stdlib_math_types_Rect_1d m__div(t_stdlib_math_types_Vec2_1d l_v);
  void m__subeq(t_stdlib_math_types_Vec2_1d l_v);
  void m__subeq(t_stdlib_math_types_Rect_1d l_r);
  t_stdlib_math_types_Rect_1d m__sub(t_stdlib_math_types_Vec2_1d l_v);
  t_stdlib_math_types_Rect_1d m__sub(t_stdlib_math_types_Rect_1d l_r);
  void m__addeq(t_stdlib_math_types_Vec2_1d l_v);
  void m__addeq(t_stdlib_math_types_Rect_1d l_r);
  t_stdlib_math_types_Rect_1d m__add(t_stdlib_math_types_Vec2_1d l_v);
  t_stdlib_math_types_Rect_1d m__add(t_stdlib_math_types_Rect_1d l_r);
  void m__muleq(t_stdlib_math_types_Vec2_1d l_v);
  t_stdlib_math_types_Rect_1d m__mul(t_stdlib_math_types_Vec2_1d l_v);
  void m__andeq(t_stdlib_math_types_Rect_1d l_r);
  t_stdlib_math_types_Rect_1d m__and(t_stdlib_math_types_Rect_1d l_r);

  t_stdlib_math_types_Rect_1d(){
  }
};

int bbCompare(const t_stdlib_math_types_Rect_1d&x,const t_stdlib_math_types_Rect_1d&y);

#endif
