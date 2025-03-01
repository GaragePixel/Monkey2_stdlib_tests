
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2area.h"

void t_default_Area_1d::init(){
  m__0handle=t_stdlib_math_types_Vec2_1f{0.5f,0.5f};
}

t_default_Area_1d::t_default_Area_1d(bbDouble l_x,bbDouble l_y,bbDouble l__0width,bbDouble l__0height){
  init();
  this->m_X(l_x);
  this->m_Y(l_y);
  this->m_Size(l__0width,l__0height);
  this->m__0rect=t_stdlib_math_types_Rect_1d{bbNullCtor};
}
t_default_Area_1d::~t_default_Area_1d(){
}

void t_default_Area_1d::m_Y(bbDouble l_y){
  this->m__0vec.m_Y(l_y);
  this->m__0y0=(l_y-this->m__0pivotY);
  this->m__0y1=(this->m__0y0+this->m__0height);
}

bbDouble t_default_Area_1d::m_Y(){
  return this->m__0vec.m_Y();
}

void t_default_Area_1d::m_X(bbDouble l_x){
  this->m__0vec.m_X(l_x);
  this->m__0x0=(l_x-this->m__0pivotX);
  this->m__0x1=(this->m__0x0+this->m__0width);
}

bbDouble t_default_Area_1d::m_X(){
  return this->m__0vec.m_X();
}

void t_default_Area_1d::m_Width(bbDouble l_w){
  this->m__0width=l_w;
  this->m__0pivotX=(this->m__0width*bbDouble(this->m__0handle.m_x));
  this->m__0x0=(this->m__0vec.m_X()-this->m__0pivotX);
  this->m__0x1=(this->m__0x0+this->m__0width);
}

bbString t_default_Area_1d::m_ToString(){
  return ((((((((bbString(L"Area(",5)+bbString(this->m__0vec.m_X()))+bbString(L",",1))+bbString(this->m__0vec.m_Y()))+bbString(L"; ",2))+bbString(this->m__0width))+bbString(L"x",1))+bbString(this->m__0height))+bbString(L")",1));
}

void t_default_Area_1d::m_Size(bbDouble l__0width,bbDouble l__0height){
  this->m__0width=l__0width;
  this->m__0height=l__0height;
  this->m__0pivotX=(l__0width*bbDouble(this->m__0handle.m_x));
  this->m__0pivotY=(l__0height*bbDouble(this->m__0handle.m_y));
  this->m__0x0=(this->m__0vec.m_X()-this->m__0pivotX);
  this->m__0y0=(this->m__0vec.m_Y()-this->m__0pivotY);
  this->m__0x1=(this->m__0x0+l__0width);
  this->m__0y1=(this->m__0y0+l__0height);
}

void t_default_Area_1d::m_SetHandle(bbFloat l_pX,bbFloat l_pY){
  this->m__0handle.m_X(l_pX);
  this->m__0handle.m_Y(l_pY);
  this->m__0pivotX=(bbDouble(l_pX)*this->m__0width);
  this->m__0pivotY=(bbDouble(l_pY)*this->m__0height);
  this->m__0x0=(this->m__0vec.m_X()-this->m__0pivotX);
  this->m__0y0=(this->m__0vec.m_Y()-this->m__0pivotY);
  this->m__0x1=(this->m__0x0+this->m__0width);
  this->m__0y1=(this->m__0y0+this->m__0height);
}

t_stdlib_math_types_Rect_1d t_default_Area_1d::m_Rect(){
  this->m__0rect.m_Left(this->m__0x0);
  this->m__0rect.m_Top(this->m__0y0);
  this->m__0rect.m_Right(this->m__0x1);
  this->m__0rect.m_Bottom(this->m__0y1);
  return this->m__0rect;
}

void t_default_Area_1d::m_PositionByCorner(bbFloat l__0x0,bbFloat l__0y0){
  this->m_X((bbDouble(l__0x0)+this->m__0pivotX));
  this->m_Y((bbDouble(l__0y0)+this->m__0pivotY));
}

void t_default_Area_1d::m_Position(bbDouble l_x,bbDouble l_y){
  this->m_X(l_x);
  this->m_Y(l_y);
}

bbBool t_default_Area_1d::m_Overlaps(t_default_Area_1d* l_rect){
  if((l_rect->m__0x1>this->m__0x0)){
    if((l_rect->m__0x0<this->m__0x1)){
      if((l_rect->m__0y1>this->m__0y0)){
        if((l_rect->m__0y0<this->m__0y1)){
          return true;
        }
      }
    }
  }
  return false;
}

void t_default_Area_1d::m_Move(bbFloat l_deltaX,bbFloat l_deltaY){
  this->m_Position((this->m__0vec.m_X()+bbDouble(l_deltaX)),(this->m__0vec.m_Y()+bbDouble(l_deltaY)));
}

void t_default_Area_1d::m_Height(bbDouble l_h){
  this->m__0height=l_h;
  this->m__0pivotY=(this->m__0height*bbDouble(this->m__0handle.m_y));
  this->m__0y0=(this->m__0vec.m_Y()-this->m__0pivotY);
  this->m__0y1=(this->m__0y0+this->m__0height);
}

t_stdlib_math_types_Vec2_1f t_default_Area_1d::m_Handle(){
  return this->m__0handle;
}

bbBool t_default_Area_1d::m_Contains(bbFloat l__0x,bbFloat l__0y){
  if((bbDouble(l__0x)>this->m__0x0)){
    if((bbDouble(l__0x)<this->m__0x1)){
      if((bbDouble(l__0y)>this->m__0y0)){
        if((bbDouble(l__0y)<this->m__0y1)){
          return true;
        }
      }
    }
  }
  return false;
}

void mx2_gridshooter_src_2area_init_f(){
}
