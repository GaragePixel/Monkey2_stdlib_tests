
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_std_geom_2rect.h"

extern bbDouble g_monkey_math_Max_1d(bbDouble l_x,bbDouble l_y);
extern bbDouble g_monkey_math_Min_1d(bbDouble l_x,bbDouble l_y);
t_std_geom_Rect_1d::t_std_geom_Rect_1d(t_std_geom_Vec2_1d l_min,bbDouble l_x1,bbDouble l_y1){
  (*this).m_min=l_min;
  (*this).m_max=t_std_geom_Vec2_1d{l_x1,l_y1};
}

t_std_geom_Rect_1d::t_std_geom_Rect_1d(bbDouble l_x0,bbDouble l_y0,t_std_geom_Vec2_1d l_max){
  (*this).m_min=t_std_geom_Vec2_1d{l_x0,l_y0};
  (*this).m_max=l_max;
}

t_std_geom_Rect_1d::t_std_geom_Rect_1d(bbDouble l_x0,bbDouble l_y0,bbDouble l_x1,bbDouble l_y1){
  (*this).m_min=t_std_geom_Vec2_1d{l_x0,l_y0};
  (*this).m_max=t_std_geom_Vec2_1d{l_x1,l_y1};
}

t_std_geom_Rect_1d::t_std_geom_Rect_1d(t_std_geom_Vec2_1d l_min,t_std_geom_Vec2_1d l_max){
  (*this).m_min=l_min;
  (*this).m_max=l_max;
}

t_std_geom_Rect_1d::t_std_geom_Rect_1d(bbNullCtor_t){
}
t_std_geom_Rect_1d::~t_std_geom_Rect_1d(){
}

void t_std_geom_Rect_1d::m__oreq(t_std_geom_Rect_1d l_r){
  (*this).m_min.m_x=g_monkey_math_Min_1d((*this).m_min.m_x,l_r.m_min.m_x);
  (*this).m_min.m_y=g_monkey_math_Min_1d((*this).m_min.m_y,l_r.m_min.m_y);
  (*this).m_max.m_x=g_monkey_math_Max_1d((*this).m_max.m_x,l_r.m_max.m_x);
  (*this).m_max.m_y=g_monkey_math_Max_1d((*this).m_max.m_y,l_r.m_max.m_y);
}

t_std_geom_Rect_1d t_std_geom_Rect_1d::m__or(t_std_geom_Rect_1d l_r){
  bbDouble l_x0=g_monkey_math_Min_1d((*this).m_min.m_x,l_r.m_min.m_x);
  bbDouble l_y0=g_monkey_math_Min_1d((*this).m_min.m_y,l_r.m_min.m_y);
  bbDouble l_x1=g_monkey_math_Max_1d((*this).m_max.m_x,l_r.m_max.m_x);
  bbDouble l_y1=g_monkey_math_Max_1d((*this).m_max.m_y,l_r.m_max.m_y);
  return t_std_geom_Rect_1d{l_x0,l_y0,l_x1,l_y1};
}

bbString t_std_geom_Rect_1d::m_to_s(){
  return ((((((((bbString(L"Rect(",5)+bbString((*this).m_min.m_x))+bbString(L",",1))+bbString((*this).m_min.m_y))+bbString(L",",1))+bbString((*this).m_max.m_x))+bbString(L",",1))+bbString((*this).m_max.m_y))+bbString(L")",1));
}

void t_std_geom_Rect_1d::m_Y(bbDouble l_y){
  (*this).m_min.m_y=l_y;
}

bbDouble t_std_geom_Rect_1d::m_Y(){
  return (*this).m_min.m_y;
}

void t_std_geom_Rect_1d::m_X(bbDouble l_x){
  (*this).m_min.m_x=l_x;
}

bbDouble t_std_geom_Rect_1d::m_X(){
  return (*this).m_min.m_x;
}

bbDouble t_std_geom_Rect_1d::m_Width(){
  return ((*this).m_max.m_x-(*this).m_min.m_x);
}

void t_std_geom_Rect_1d::m_TopRight(t_std_geom_Vec2_1d l_v){
  (*this).m_max.m_x=l_v.m_x;
  (*this).m_min.m_y=l_v.m_y;
}

t_std_geom_Vec2_1d t_std_geom_Rect_1d::m_TopRight(){
  return t_std_geom_Vec2_1d{(*this).m_max.m_x,(*this).m_min.m_y};
}

void t_std_geom_Rect_1d::m_TopLeft(t_std_geom_Vec2_1d l_v){
  (*this).m_min=l_v;
}

t_std_geom_Vec2_1d t_std_geom_Rect_1d::m_TopLeft(){
  return (*this).m_min;
}

void t_std_geom_Rect_1d::m_Top(bbDouble l_top){
  (*this).m_min.m_y=l_top;
}

bbDouble t_std_geom_Rect_1d::m_Top(){
  return (*this).m_min.m_y;
}

bbString t_std_geom_Rect_1d::m_ToString(){
  return (*this).m_to_s();
}

void t_std_geom_Rect_1d::m_Size(t_std_geom_Vec2_1d l_size){
  (*this).m_max=(*this).m_min.m__add(l_size);
}

t_std_geom_Vec2_1d t_std_geom_Rect_1d::m_Size(){
  return (*this).m_max.m__sub((*this).m_min);
}

void t_std_geom_Rect_1d::m_Right(bbDouble l_right){
  (*this).m_max.m_x=l_right;
}

bbDouble t_std_geom_Rect_1d::m_Right(){
  return (*this).m_max.m_x;
}

void t_std_geom_Rect_1d::m_Origin(t_std_geom_Vec2_1d l_origin){
  (*this).m_min=l_origin;
}

t_std_geom_Vec2_1d t_std_geom_Rect_1d::m_Origin(){
  return (*this).m_min;
}

void t_std_geom_Rect_1d::m_Left(bbDouble l_left){
  (*this).m_min.m_x=l_left;
}

bbDouble t_std_geom_Rect_1d::m_Left(){
  return (*this).m_min.m_x;
}

bbBool t_std_geom_Rect_1d::m_Intersects(t_std_geom_Rect_1d l_r){
  return ((((l_r.m_max.m_x>(*this).m_min.m_x)&&(l_r.m_min.m_x<(*this).m_max.m_x))&&(l_r.m_max.m_y>(*this).m_min.m_y))&&(l_r.m_min.m_y<(*this).m_max.m_y));
}

bbDouble t_std_geom_Rect_1d::m_Height(){
  return ((*this).m_max.m_y-(*this).m_min.m_y);
}

bbBool t_std_geom_Rect_1d::m_Empty(){
  return (((*this).m_max.m_x<=(*this).m_min.m_x)||((*this).m_max.m_y<=(*this).m_min.m_y));
}

bbBool t_std_geom_Rect_1d::m_Contains(t_std_geom_Rect_1d l_r){
  return (((((*this).m_min.m_x<=l_r.m_min.m_x)&&((*this).m_max.m_x>=l_r.m_max.m_x))&&((*this).m_min.m_y<=l_r.m_min.m_y))&&((*this).m_max.m_y>=l_r.m_max.m_y));
}

bbBool t_std_geom_Rect_1d::m_Contains(t_std_geom_Vec2_1d l_v){
  return ((((l_v.m_x>=(*this).m_min.m_x)&&(l_v.m_x<(*this).m_max.m_x))&&(l_v.m_y>=(*this).m_min.m_y))&&(l_v.m_y<(*this).m_max.m_y));
}

t_std_geom_Rect_1d t_std_geom_Rect_1d::m_Centered(t_std_geom_Rect_1d l_r){
  bbDouble l_x=(((l_r.m_Width()-(*this).m_Width())/2.0)+l_r.m_min.m_x);
  bbDouble l_y=(((l_r.m_Height()-(*this).m_Height())/2.0)+l_r.m_min.m_y);
  return t_std_geom_Rect_1d{l_x,l_y,(l_x+(*this).m_Width()),(l_y+(*this).m_Height())};
}

t_std_geom_Vec2_1d t_std_geom_Rect_1d::m_Center(){
  return (*this).m_min.m__add((*this).m_max).m__div(2.0);
}

void t_std_geom_Rect_1d::m_BottomRight(t_std_geom_Vec2_1d l_v){
  (*this).m_max=l_v;
}

t_std_geom_Vec2_1d t_std_geom_Rect_1d::m_BottomRight(){
  return (*this).m_max;
}

void t_std_geom_Rect_1d::m_BottomLeft(t_std_geom_Vec2_1d l_v){
  (*this).m_min.m_x=l_v.m_x;
  (*this).m_max.m_y=l_v.m_y;
}

t_std_geom_Vec2_1d t_std_geom_Rect_1d::m_BottomLeft(){
  return t_std_geom_Vec2_1d{(*this).m_min.m_x,(*this).m_max.m_y};
}

void t_std_geom_Rect_1d::m_Bottom(bbDouble l_bottom){
  (*this).m_max.m_y=l_bottom;
}

bbDouble t_std_geom_Rect_1d::m_Bottom(){
  return (*this).m_max.m_y;
}

void t_std_geom_Rect_1d::m__diveq(t_std_geom_Vec2_1d l_v){
  (*this).m_min=(*this).m_min.m__div(l_v);
  (*this).m_max=(*this).m_max.m__div(l_v);
}

t_std_geom_Rect_1d t_std_geom_Rect_1d::m__div(t_std_geom_Vec2_1d l_v){
  return t_std_geom_Rect_1d{((*this).m_min.m_x/l_v.m_x),((*this).m_min.m_y/l_v.m_y),((*this).m_max.m_x/l_v.m_x),((*this).m_max.m_y/l_v.m_y)};
}

void t_std_geom_Rect_1d::m__subeq(t_std_geom_Vec2_1d l_v){
  (*this).m_min=(*this).m_min.m__sub(l_v);
  (*this).m_max=(*this).m_max.m__sub(l_v);
}

void t_std_geom_Rect_1d::m__subeq(t_std_geom_Rect_1d l_r){
  (*this).m_min=(*this).m_min.m__sub(l_r.m_min);
  (*this).m_max=(*this).m_max.m__sub(l_r.m_max);
}

t_std_geom_Rect_1d t_std_geom_Rect_1d::m__sub(t_std_geom_Vec2_1d l_v){
  return t_std_geom_Rect_1d{(*this).m_min.m__sub(l_v),(*this).m_max.m__sub(l_v)};
}

t_std_geom_Rect_1d t_std_geom_Rect_1d::m__sub(t_std_geom_Rect_1d l_r){
  return t_std_geom_Rect_1d{(*this).m_min.m__sub(l_r.m_min),(*this).m_max.m__sub(l_r.m_max)};
}

void t_std_geom_Rect_1d::m__addeq(t_std_geom_Vec2_1d l_v){
  (*this).m_min=(*this).m_min.m__add(l_v);
  (*this).m_max=(*this).m_max.m__add(l_v);
}

void t_std_geom_Rect_1d::m__addeq(t_std_geom_Rect_1d l_r){
  (*this).m_min=(*this).m_min.m__add(l_r.m_min);
  (*this).m_max=(*this).m_max.m__add(l_r.m_max);
}

t_std_geom_Rect_1d t_std_geom_Rect_1d::m__add(t_std_geom_Vec2_1d l_v){
  return t_std_geom_Rect_1d{(*this).m_min.m__add(l_v),(*this).m_max.m__add(l_v)};
}

t_std_geom_Rect_1d t_std_geom_Rect_1d::m__add(t_std_geom_Rect_1d l_r){
  return t_std_geom_Rect_1d{(*this).m_min.m__add(l_r.m_min),(*this).m_max.m__add(l_r.m_max)};
}

void t_std_geom_Rect_1d::m__muleq(t_std_geom_Vec2_1d l_v){
  (*this).m_min=(*this).m_min.m__mul(l_v);
  (*this).m_max=(*this).m_max.m__mul(l_v);
}

t_std_geom_Rect_1d t_std_geom_Rect_1d::m__mul(t_std_geom_Vec2_1d l_v){
  return t_std_geom_Rect_1d{((*this).m_min.m_x*l_v.m_x),((*this).m_min.m_y*l_v.m_y),((*this).m_max.m_x*l_v.m_x),((*this).m_max.m_y*l_v.m_y)};
}

void t_std_geom_Rect_1d::m__andeq(t_std_geom_Rect_1d l_r){
  (*this).m_min.m_x=g_monkey_math_Max_1d((*this).m_min.m_x,l_r.m_min.m_x);
  (*this).m_min.m_y=g_monkey_math_Max_1d((*this).m_min.m_y,l_r.m_min.m_y);
  (*this).m_max.m_x=g_monkey_math_Min_1d((*this).m_max.m_x,l_r.m_max.m_x);
  (*this).m_max.m_y=g_monkey_math_Min_1d((*this).m_max.m_y,l_r.m_max.m_y);
}

t_std_geom_Rect_1d t_std_geom_Rect_1d::m__and(t_std_geom_Rect_1d l_r){
  bbDouble l_x0=g_monkey_math_Max_1d((*this).m_min.m_x,l_r.m_min.m_x);
  bbDouble l_y0=g_monkey_math_Max_1d((*this).m_min.m_y,l_r.m_min.m_y);
  bbDouble l_x1=g_monkey_math_Min_1d((*this).m_max.m_x,l_r.m_max.m_x);
  bbDouble l_y1=g_monkey_math_Min_1d((*this).m_max.m_y,l_r.m_max.m_y);
  return t_std_geom_Rect_1d{l_x0,l_y0,l_x1,l_y1};
}

int bbCompare(const t_std_geom_Rect_1d&x,const t_std_geom_Rect_1d&y){
  if(int t=bbCompare(x.m_min,y.m_min)) return t;
  if(int t=bbCompare(x.m_max,y.m_max)) return t;
  return 0;
}

void mx2_gridshooter_std_geom_2rect_init_f(){
}
