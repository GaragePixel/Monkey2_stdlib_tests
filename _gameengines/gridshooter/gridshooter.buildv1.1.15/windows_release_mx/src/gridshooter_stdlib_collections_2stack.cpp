
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_stdlib_collections_2stack.h"

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2actor.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2bullet.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_stdlib_collections_2deque.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_stdlib_collections_2list.h"
#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_debug.h"

extern bbInt invoke(t_default_Actor* l_x,t_default_Actor* l_y);
extern bbInt invoke(t_default_Actor* l_x,t_default_Actor* l_y);
extern bbInt invoke(t_default_Bullet* l_x,t_default_Bullet* l_y);
extern bbInt invoke(t_default_Bullet* l_x,t_default_Bullet* l_y);
extern bbInt g_monkey_math_Max_1i(bbInt l_x,bbInt l_y);
void g_stdlib_collections_Stack_1Tt_default_Actor_2_AddAll_1Tt_stdlib_collections_List_1Tt_default_Actor_2_2(t_stdlib_collections_Stack_1Tt_default_Actor_2* l_self,t_stdlib_collections_List_1Tt_default_Actor_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_stdlib_collections_List_1Tt_default_Actor_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_default_Actor* l_value{};
        void gcMark(){
          bbGCMark(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_Add(f2.l_value);
    }
  }
}

void g_stdlib_collections_Stack_1Tt_default_Bullet_2_AddAll_1Tt_stdlib_collections_List_1Tt_default_Bullet_2_2(t_stdlib_collections_Stack_1Tt_default_Bullet_2* l_self,t_stdlib_collections_List_1Tt_default_Bullet_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_stdlib_collections_List_1Tt_default_Bullet_2_Iterator l_0{};
      void gcMark(){
        bbGCMark(l_0);
      }
    }f1{};
    f1.l_0=l_values->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_default_Bullet* l_value{};
        void gcMark(){
          bbGCMark(l_value);
        }
      }f2{};
      f2.l_value=f1.l_0.m_Current();
      l_self->m_Add(f2.l_value);
    }
  }
}

t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator::t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator(t_stdlib_collections_Stack_1Tt_default_Bullet_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
}
t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator::~t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator(){
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator::m_Insert(t_default_Bullet* l_value){
  struct f0_t : public bbGCFrame{
    t_stdlib_collections_Stack_1Tt_default_Bullet_2* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  bbDebugAssert(((*this).m__0index<=(*this).m__0stack.get()->m__0length),bbString(L"Invalid stack iterator",22));
  (f0.t0=(*this).m__0stack.get())->m_Insert((*this).m__0index,l_value);
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator::m_Erase(){
  struct f0_t : public bbGCFrame{
    t_stdlib_collections_Stack_1Tt_default_Bullet_2* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  (*this).m_AssertCurrent();
  (f0.t0=(*this).m__0stack.get())->m_Erase((*this).m__0index);
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator::m_Current(t_default_Bullet* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack.get()->m__0data[(*this).m__0index]=l_current;
}

t_default_Bullet* t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack.get()->m__0data[(*this).m__0index].get();
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator::m_AtEnd(){
  return ((*this).m__0index>=(*this).m__0stack.get()->m__0length);
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(((*this).m__0index<(*this).m__0stack.get()->m__0length),bbString(L"Invalid stack iterator",22));
}

int bbCompare(const t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator&x,const t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  return 0;
}

void bbGCMark(const t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator::t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator(t_stdlib_collections_Stack_1Tt_default_Bullet_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
}
t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator::~t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator(){
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator::m_Insert(t_default_Bullet* l_value){
  struct f0_t : public bbGCFrame{
    t_stdlib_collections_Stack_1Tt_default_Bullet_2* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  bbDebugAssert(((*this).m__0index<(*this).m__0stack.get()->m__0length),bbString(L"Invalid stack iterator",22));
  (*this).m__0index+=1;
  (f0.t0=(*this).m__0stack.get())->m_Insert((*this).m__0index,l_value);
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator::m_Erase(){
  struct f0_t : public bbGCFrame{
    t_stdlib_collections_Stack_1Tt_default_Bullet_2* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  (*this).m_AssertCurrent();
  (f0.t0=(*this).m__0stack.get())->m_Erase((*this).m__0index);
  (*this).m__0index-=1;
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator::m_Current(t_default_Bullet* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack.get()->m__0data[(*this).m__0index]=l_current;
}

t_default_Bullet* t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack.get()->m__0data[(*this).m__0index].get();
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator::m_AtEnd(){
  return ((*this).m__0index==-1);
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(((*this).m__0index>=bbInt(0)),bbString(L"Invalid stack iterator",22));
}

int bbCompare(const t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator&x,const t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  return 0;
}

void bbGCMark(const t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2::gcMark(){
  bbGCMark(m__0data);
}

t_stdlib_collections_Stack_1Tt_default_Bullet_2::t_stdlib_collections_Stack_1Tt_default_Bullet_2(t_stdlib_collections_Stack_1Tt_default_Bullet_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Bullet>> t0{};
    bbArray<bbGCVar<t_default_Bullet>> t1{};
    void gcMark(){
      bbGCMark(t0);
      bbGCMark(t1);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_default_Bullet>>(this->m__0length);
  (f0.t1=l_values->m_Data()).copyTo(f0.t0=this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_stdlib_collections_Stack_1Tt_default_Bullet_2::t_stdlib_collections_Stack_1Tt_default_Bullet_2(t_stdlib_collections_Deque_1Tt_default_Bullet_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Bullet>> t0{};
    bbArray<bbGCVar<t_default_Bullet>> t1{};
    void gcMark(){
      bbGCMark(t0);
      bbGCMark(t1);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_default_Bullet>>(this->m__0length);
  (f0.t1=l_values->m_Data()).copyTo(f0.t0=this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_stdlib_collections_Stack_1Tt_default_Bullet_2::t_stdlib_collections_Stack_1Tt_default_Bullet_2(t_stdlib_collections_List_1Tt_default_Bullet_2* l_values){
  g_stdlib_collections_Stack_1Tt_default_Bullet_2_AddAll_1Tt_stdlib_collections_List_1Tt_default_Bullet_2_2(this,l_values);
}

t_stdlib_collections_Stack_1Tt_default_Bullet_2::t_stdlib_collections_Stack_1Tt_default_Bullet_2(bbArray<bbGCVar<t_default_Bullet>> l_values){
  this->m_AddAll(l_values);
}

t_stdlib_collections_Stack_1Tt_default_Bullet_2::t_stdlib_collections_Stack_1Tt_default_Bullet_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_default_Bullet>>(this->m__0length);
}

t_stdlib_collections_Stack_1Tt_default_Bullet_2::t_stdlib_collections_Stack_1Tt_default_Bullet_2(){
  this->m__0data=bbArray<bbGCVar<t_default_Bullet>>(10);
}
t_stdlib_collections_Stack_1Tt_default_Bullet_2::~t_stdlib_collections_Stack_1Tt_default_Bullet_2(){
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2::m__idxeq(bbInt l_index,t_default_Bullet* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),bbString(L"Stack index out of range",24));
  this->m__0data[l_index]=l_value;
}

t_default_Bullet* t_stdlib_collections_Stack_1Tt_default_Bullet_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),bbString(L"Stack index out of range",24));
  return this->m__0data[l_index].get();
}

t_default_Bullet* t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),bbString(L"Stack is empty",14));
  return this->m__0data[(this->m__0length-1)].get();
}

bbArray<bbGCVar<t_default_Bullet>> t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Bullet>> t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  return (f0.t0=this->m__0data).slice(bbInt(0),this->m__0length);
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Swap(t_stdlib_collections_Stack_1Tt_default_Bullet_2* l_stack){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Bullet>> l_data{};
    void gcMark(){
      bbGCMark(l_data);
    }
  }f0{};
  f0.l_data=this->m__0data;
  bbInt l_length=this->m__0length;
  this->m__0data=l_stack->m__0data;
  this->m__0length=l_stack->m__0length;
  l_stack->m__0data=f0.l_data;
  l_stack->m__0length=l_length;
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_default_Bullet* l_t{};
    void gcMark(){
      bbGCMark(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),bbString(L"Stack index out of range",24));
  f0.l_t=this->m__0data[l_index1].get();
  this->m__0data[l_index1]=this->m__0data[l_index2].get();
  this->m__0data[l_index2]=f0.l_t;
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Sort(bbFunction<bbInt(t_default_Bullet*,t_default_Bullet*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  struct f0_t : public bbGCFrame{
    t_default_Bullet* t0{};
    t_default_Bullet* t1{};
    void gcMark(){
      bbGCMark(t0);
      bbGCMark(t1);
    }
  }f0{};
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    struct f1_t : public bbGCFrame{
      t_default_Bullet* t0{};
      t_default_Bullet* t1{};
      void gcMark(){
        bbGCMark(t0);
        bbGCMark(t1);
      }
    }f1{};
    if((l_compareFunc(f1.t0=this->m__0data[l_hi].get(),f1.t1=this->m__0data[l_lo].get())<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(f0.t0=this->m__0data[l_i].get(),f0.t1=this->m__0data[l_lo].get())<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(f0.t0=this->m__0data[l_hi].get(),f0.t1=this->m__0data[l_i].get())<bbInt(0))){
    struct f1_t : public bbGCFrame{
      t_default_Bullet* t0{};
      t_default_Bullet* t1{};
      void gcMark(){
        bbGCMark(t0);
        bbGCMark(t1);
      }
    }f1{};
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(f1.t0=this->m__0data[l_i].get(),f1.t1=this->m__0data[l_lo].get())<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_default_Bullet* l_p{};
      t_default_Bullet* t0{};
      void gcMark(){
        bbGCMark(l_p);
        bbGCMark(t0);
      }
    }f1{};
    f1.l_p=this->m__0data[l_i].get();
    while((l_compareFunc(f1.t0=this->m__0data[l_x].get(),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,f1.t0=this->m__0data[l_y].get())<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Sort(bbFunction<bbInt(t_default_Bullet*,t_default_Bullet*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Sort(bbInt l_ascending){
  if(bbBool(l_ascending)){
    struct f1_t : public bbGCFrame{
      bbFunction<bbInt(t_default_Bullet*,t_default_Bullet*)> t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    struct lambda0 : public bbFunction<bbInt(t_default_Bullet*,t_default_Bullet*)>::Rep{
      t_stdlib_collections_Stack_1Tt_default_Bullet_2* l_self;
      lambda0(t_stdlib_collections_Stack_1Tt_default_Bullet_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_default_Bullet* l_x,t_default_Bullet* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMark(l_self);
      }
    };
    this->m_Sort(f1.t0=bbFunction<bbInt(t_default_Bullet*,t_default_Bullet*)>(new lambda0(this)));
  }else{
    struct f1_t : public bbGCFrame{
      bbFunction<bbInt(t_default_Bullet*,t_default_Bullet*)> t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    struct lambda1 : public bbFunction<bbInt(t_default_Bullet*,t_default_Bullet*)>::Rep{
      t_stdlib_collections_Stack_1Tt_default_Bullet_2* l_self;
      lambda1(t_stdlib_collections_Stack_1Tt_default_Bullet_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_default_Bullet* l_x,t_default_Bullet* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMark(l_self);
      }
    };
    this->m_Sort(f1.t0=bbFunction<bbInt(t_default_Bullet*,t_default_Bullet*)>(new lambda1(this)));
  }
}

t_stdlib_collections_Stack_1Tt_default_Bullet_2* t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Bullet>> t0{};
    bbArray<bbGCVar<t_default_Bullet>> t1{};
    void gcMark(){
      bbGCMark(t0);
      bbGCMark(t1);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_stdlib_collections_Stack_1Tt_default_Bullet_2>(f0.t1=(f0.t0=this->m__0data).slice(l_index1,l_index2));
}

t_stdlib_collections_Stack_1Tt_default_Bullet_2* t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Set(bbInt l_index,t_default_Bullet* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),bbString(L"Stack index out of range",24));
  this->m__0data[l_index]=l_value;
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),bbString(L"Debug assert failed",19));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data[l_i]=((t_default_Bullet*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Bullet>> l_data{};
    bbArray<bbGCVar<t_default_Bullet>> t0{};
    void gcMark(){
      bbGCMark(l_data);
      bbGCMark(t0);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),bbString(L"Debug assert failed",19));
  if(((f0.t0=this->m__0data).length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i((this->m__0length*2),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_default_Bullet>>(l_capacity);
  (f0.t0=this->m__0data).copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_RemoveLast(t_default_Bullet* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_RemoveIf(bbFunction<bbBool(t_default_Bullet*)> l_condition){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      struct f2_t : public bbGCFrame{
        t_default_Bullet* t0{};
        void gcMark(){
          bbGCMark(t0);
        }
      }f2{};
      if(l_condition(f2.t0=this->m__0data[l_get].get())){
        l_n+=1;
        continue;
      }
      this->m__0data[l_put]=this->m__0data[l_get].get();
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbInt t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_RemoveEach(t_default_Bullet* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data[l_get].get()==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data[l_put]=this->m__0data[l_get].get();
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Remove(t_default_Bullet* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Push(t_default_Bullet* l_value){
  this->m_Add(l_value);
}

t_default_Bullet* t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_default_Bullet* l_value{};
    void gcMark(){
      bbGCMark(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),bbString(L"Stack is empty",14));
  this->m__0length-=1;
  f0.l_value=this->m__0data[this->m__0length].get();
  this->m__0data[this->m__0length]=((t_default_Bullet*)0);
  return f0.l_value;
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Insert(bbInt l_index,t_default_Bullet* l_value){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Bullet>> t0{};
    bbArray<bbGCVar<t_default_Bullet>> t1{};
    void gcMark(){
      bbGCMark(t0);
      bbGCMark(t1);
    }
  }f0{};
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),bbString(L"Debug assert failed",19));
  this->m_Reserve((this->m__0length+1));
  (f0.t1=this->m__0data).copyTo(f0.t0=this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data[l_index]=l_value;
  this->m__0length+=1;
}

t_default_Bullet* t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),bbString(L"Stack index out of range",24));
  return this->m__0data[l_index].get();
}

bbInt t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_FindLastIndex(t_default_Bullet* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),bbString(L"Debug assert failed",19));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data[l_i].get()==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_FindIndex(t_default_Bullet* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),bbString(L"Debug assert failed",19));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data[l_i].get()==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Erase(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Bullet>> t0{};
    bbArray<bbGCVar<t_default_Bullet>> t1{};
    void gcMark(){
      bbGCMark(t0);
      bbGCMark(t1);
    }
  }f0{};
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),bbString(L"Debug assert failed",19));
  if((l_index1==this->m__0length)){
    return;
  }
  (f0.t1=this->m__0data).copyTo(f0.t0=this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Erase(bbInt l_index){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Bullet>> t0{};
    bbArray<bbGCVar<t_default_Bullet>> t1{};
    void gcMark(){
      bbGCMark(t0);
      bbGCMark(t1);
    }
  }f0{};
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),bbString(L"Debug assert failed",19));
  if((l_index==this->m__0length)){
    return;
  }
  (f0.t1=this->m__0data).copyTo(f0.t0=this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_default_Bullet>> t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Data(){
  return this->m__0data;
}

bbBool t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Contains(t_default_Bullet* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Compact(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Bullet>> t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  if((this->m__0length!=(f0.t0=this->m__0data).length())){
    struct f1_t : public bbGCFrame{
      bbArray<bbGCVar<t_default_Bullet>> t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    this->m__0data=(f1.t0=this->m__0data).slice(bbInt(0),this->m__0length);
  }
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Capacity(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Bullet>> t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  return (f0.t0=this->m__0data).length();
}

t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Backwards(){
  return t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator{this,(this->m__0length-1)};
}

t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_All(){
  return t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator{this,bbInt(0)};
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_AddAll(bbArray<bbGCVar<t_default_Bullet>> l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Bullet>> t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  this->m_Reserve((this->m__0length+l_values.length()));
  l_values.copyTo(f0.t0=this->m__0data,bbInt(0),this->m__0length,l_values.length());
  this->m_Resize((this->m__0length+l_values.length()));
}

void t_stdlib_collections_Stack_1Tt_default_Bullet_2::m_Add(t_default_Bullet* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data[this->m__0length]=l_value;
  this->m__0length+=1;
}

t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator::t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator(t_stdlib_collections_Stack_1Tt_default_Actor_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
}
t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator::~t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator(){
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator::m_Insert(t_default_Actor* l_value){
  struct f0_t : public bbGCFrame{
    t_stdlib_collections_Stack_1Tt_default_Actor_2* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  bbDebugAssert(((*this).m__0index<=(*this).m__0stack.get()->m__0length),bbString(L"Invalid stack iterator",22));
  (f0.t0=(*this).m__0stack.get())->m_Insert((*this).m__0index,l_value);
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator::m_Erase(){
  struct f0_t : public bbGCFrame{
    t_stdlib_collections_Stack_1Tt_default_Actor_2* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  (*this).m_AssertCurrent();
  (f0.t0=(*this).m__0stack.get())->m_Erase((*this).m__0index);
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator::m_Current(t_default_Actor* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack.get()->m__0data[(*this).m__0index]=l_current;
}

t_default_Actor* t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack.get()->m__0data[(*this).m__0index].get();
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
}

bbBool t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator::m_AtEnd(){
  return ((*this).m__0index>=(*this).m__0stack.get()->m__0length);
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(((*this).m__0index<(*this).m__0stack.get()->m__0length),bbString(L"Invalid stack iterator",22));
}

int bbCompare(const t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator&x,const t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  return 0;
}

void bbGCMark(const t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator&t){
  bbGCMark(t.m__0stack);
}

t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator::t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator(t_stdlib_collections_Stack_1Tt_default_Actor_2* l_stack,bbInt l_index){
  (*this).m__0stack=l_stack;
  (*this).m__0index=l_index;
}
t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator::~t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator(){
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator::m_Insert(t_default_Actor* l_value){
  struct f0_t : public bbGCFrame{
    t_stdlib_collections_Stack_1Tt_default_Actor_2* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  bbDebugAssert(((*this).m__0index<(*this).m__0stack.get()->m__0length),bbString(L"Invalid stack iterator",22));
  (*this).m__0index+=1;
  (f0.t0=(*this).m__0stack.get())->m_Insert((*this).m__0index,l_value);
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator::m_Erase(){
  struct f0_t : public bbGCFrame{
    t_stdlib_collections_Stack_1Tt_default_Actor_2* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  (*this).m_AssertCurrent();
  (f0.t0=(*this).m__0stack.get())->m_Erase((*this).m__0index);
  (*this).m__0index-=1;
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator::m_Current(t_default_Actor* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0stack.get()->m__0data[(*this).m__0index]=l_current;
}

t_default_Actor* t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0stack.get()->m__0data[(*this).m__0index].get();
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0index-=1;
}

bbBool t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator::m_AtEnd(){
  return ((*this).m__0index==-1);
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(((*this).m__0index>=bbInt(0)),bbString(L"Invalid stack iterator",22));
}

int bbCompare(const t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator&x,const t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0stack,y.m__0stack)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  return 0;
}

void bbGCMark(const t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator&t){
  bbGCMark(t.m__0stack);
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2::gcMark(){
  bbGCMark(m__0data);
}

t_stdlib_collections_Stack_1Tt_default_Actor_2::t_stdlib_collections_Stack_1Tt_default_Actor_2(t_stdlib_collections_Stack_1Tt_default_Actor_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Actor>> t0{};
    bbArray<bbGCVar<t_default_Actor>> t1{};
    void gcMark(){
      bbGCMark(t0);
      bbGCMark(t1);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_default_Actor>>(this->m__0length);
  (f0.t1=l_values->m_Data()).copyTo(f0.t0=this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_stdlib_collections_Stack_1Tt_default_Actor_2::t_stdlib_collections_Stack_1Tt_default_Actor_2(t_stdlib_collections_Deque_1Tt_default_Actor_2* l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Actor>> t0{};
    bbArray<bbGCVar<t_default_Actor>> t1{};
    void gcMark(){
      bbGCMark(t0);
      bbGCMark(t1);
    }
  }f0{};
  this->m__0length=l_values->m_Length();
  this->m__0data=bbArray<bbGCVar<t_default_Actor>>(this->m__0length);
  (f0.t1=l_values->m_Data()).copyTo(f0.t0=this->m__0data,bbInt(0),bbInt(0),this->m__0length);
}

t_stdlib_collections_Stack_1Tt_default_Actor_2::t_stdlib_collections_Stack_1Tt_default_Actor_2(t_stdlib_collections_List_1Tt_default_Actor_2* l_values){
  g_stdlib_collections_Stack_1Tt_default_Actor_2_AddAll_1Tt_stdlib_collections_List_1Tt_default_Actor_2_2(this,l_values);
}

t_stdlib_collections_Stack_1Tt_default_Actor_2::t_stdlib_collections_Stack_1Tt_default_Actor_2(bbArray<bbGCVar<t_default_Actor>> l_values){
  this->m_AddAll(l_values);
}

t_stdlib_collections_Stack_1Tt_default_Actor_2::t_stdlib_collections_Stack_1Tt_default_Actor_2(bbInt l_length){
  this->m__0length=l_length;
  this->m__0data=bbArray<bbGCVar<t_default_Actor>>(this->m__0length);
}

t_stdlib_collections_Stack_1Tt_default_Actor_2::t_stdlib_collections_Stack_1Tt_default_Actor_2(){
  this->m__0data=bbArray<bbGCVar<t_default_Actor>>(10);
}
t_stdlib_collections_Stack_1Tt_default_Actor_2::~t_stdlib_collections_Stack_1Tt_default_Actor_2(){
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2::m__idxeq(bbInt l_index,t_default_Actor* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),bbString(L"Stack index out of range",24));
  this->m__0data[l_index]=l_value;
}

t_default_Actor* t_stdlib_collections_Stack_1Tt_default_Actor_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),bbString(L"Stack index out of range",24));
  return this->m__0data[l_index].get();
}

t_default_Actor* t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Top(){
  bbDebugAssert(bbBool(this->m__0length),bbString(L"Stack is empty",14));
  return this->m__0data[(this->m__0length-1)].get();
}

bbArray<bbGCVar<t_default_Actor>> t_stdlib_collections_Stack_1Tt_default_Actor_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Actor>> t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  return (f0.t0=this->m__0data).slice(bbInt(0),this->m__0length);
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Swap(t_stdlib_collections_Stack_1Tt_default_Actor_2* l_stack){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Actor>> l_data{};
    void gcMark(){
      bbGCMark(l_data);
    }
  }f0{};
  f0.l_data=this->m__0data;
  bbInt l_length=this->m__0length;
  this->m__0data=l_stack->m__0data;
  this->m__0length=l_stack->m__0length;
  l_stack->m__0data=f0.l_data;
  l_stack->m__0length=l_length;
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Swap(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    t_default_Actor* l_t{};
    void gcMark(){
      bbGCMark(l_t);
    }
  }f0{};
  bbDebugAssert(((((l_index1>=bbInt(0))&&(l_index1<this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<this->m__0length)),bbString(L"Stack index out of range",24));
  f0.l_t=this->m__0data[l_index1].get();
  this->m__0data[l_index1]=this->m__0data[l_index2].get();
  this->m__0data[l_index2]=f0.l_t;
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Sort(bbFunction<bbInt(t_default_Actor*,t_default_Actor*)> l_compareFunc,bbInt l_lo,bbInt l_hi){
  struct f0_t : public bbGCFrame{
    t_default_Actor* t0{};
    t_default_Actor* t1{};
    void gcMark(){
      bbGCMark(t0);
      bbGCMark(t1);
    }
  }f0{};
  if((l_hi<=l_lo)){
    return;
  }
  if(((l_lo+1)==l_hi)){
    struct f1_t : public bbGCFrame{
      t_default_Actor* t0{};
      t_default_Actor* t1{};
      void gcMark(){
        bbGCMark(t0);
        bbGCMark(t1);
      }
    }f1{};
    if((l_compareFunc(f1.t0=this->m__0data[l_hi].get(),f1.t1=this->m__0data[l_lo].get())<bbInt(0))){
      this->m_Swap(l_hi,l_lo);
    }
    return;
  }
  bbInt l_i=((l_lo+l_hi)/2);
  if((l_compareFunc(f0.t0=this->m__0data[l_i].get(),f0.t1=this->m__0data[l_lo].get())<bbInt(0))){
    this->m_Swap(l_i,l_lo);
  }
  if((l_compareFunc(f0.t0=this->m__0data[l_hi].get(),f0.t1=this->m__0data[l_i].get())<bbInt(0))){
    struct f1_t : public bbGCFrame{
      t_default_Actor* t0{};
      t_default_Actor* t1{};
      void gcMark(){
        bbGCMark(t0);
        bbGCMark(t1);
      }
    }f1{};
    this->m_Swap(l_hi,l_i);
    if((l_compareFunc(f1.t0=this->m__0data[l_i].get(),f1.t1=this->m__0data[l_lo].get())<bbInt(0))){
      this->m_Swap(l_i,l_lo);
    }
  }
  bbInt l_x=(l_lo+1);
  bbInt l_y=(l_hi-1);
  do{
    struct f1_t : public bbGCFrame{
      t_default_Actor* l_p{};
      t_default_Actor* t0{};
      void gcMark(){
        bbGCMark(l_p);
        bbGCMark(t0);
      }
    }f1{};
    f1.l_p=this->m__0data[l_i].get();
    while((l_compareFunc(f1.t0=this->m__0data[l_x].get(),f1.l_p)<bbInt(0))){
      l_x+=1;
    }
    while((l_compareFunc(f1.l_p,f1.t0=this->m__0data[l_y].get())<bbInt(0))){
      l_y-=1;
    }
    if((l_x>l_y)){
      break;
    }
    if((l_x<l_y)){
      this->m_Swap(l_x,l_y);
      if((l_i==l_x)){
        l_i=l_y;
      }else if((l_i==l_y)){
        l_i=l_x;
      }
    }
    l_x+=1;
    l_y-=1;
  }while(!((l_x>l_y)));
  this->m_Sort(l_compareFunc,l_lo,l_y);
  this->m_Sort(l_compareFunc,l_x,l_hi);
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Sort(bbFunction<bbInt(t_default_Actor*,t_default_Actor*)> l_compareFunc){
  this->m_Sort(l_compareFunc,bbInt(0),(this->m__0length-1));
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Sort(bbInt l_ascending){
  if(bbBool(l_ascending)){
    struct f1_t : public bbGCFrame{
      bbFunction<bbInt(t_default_Actor*,t_default_Actor*)> t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    struct lambda2 : public bbFunction<bbInt(t_default_Actor*,t_default_Actor*)>::Rep{
      t_stdlib_collections_Stack_1Tt_default_Actor_2* l_self;
      lambda2(t_stdlib_collections_Stack_1Tt_default_Actor_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_default_Actor* l_x,t_default_Actor* l_y){
        return bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMark(l_self);
      }
    };
    this->m_Sort(f1.t0=bbFunction<bbInt(t_default_Actor*,t_default_Actor*)>(new lambda2(this)));
  }else{
    struct f1_t : public bbGCFrame{
      bbFunction<bbInt(t_default_Actor*,t_default_Actor*)> t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    struct lambda3 : public bbFunction<bbInt(t_default_Actor*,t_default_Actor*)>::Rep{
      t_stdlib_collections_Stack_1Tt_default_Actor_2* l_self;
      lambda3(t_stdlib_collections_Stack_1Tt_default_Actor_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_default_Actor* l_x,t_default_Actor* l_y){
        return bbCompare(l_y,l_x);
      }
      void gcMark(){
        bbGCMark(l_self);
      }
    };
    this->m_Sort(f1.t0=bbFunction<bbInt(t_default_Actor*,t_default_Actor*)>(new lambda3(this)));
  }
}

t_stdlib_collections_Stack_1Tt_default_Actor_2* t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Slice(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Actor>> t0{};
    bbArray<bbGCVar<t_default_Actor>> t1{};
    void gcMark(){
      bbGCMark(t0);
      bbGCMark(t1);
    }
  }f0{};
  if((l_index1<bbInt(0))){
    l_index1=g_monkey_math_Max_1i((l_index1+this->m__0length),bbInt(0));
  }else if((l_index1>this->m__0length)){
    l_index1=this->m__0length;
  }
  if((l_index2<bbInt(0))){
    l_index2=g_monkey_math_Max_1i((l_index2+this->m__0length),l_index1);
  }else if((l_index2>this->m__0length)){
    l_index2=this->m__0length;
  }else if((l_index2<l_index1)){
    l_index2=l_index1;
  }
  return bbGCNew<t_stdlib_collections_Stack_1Tt_default_Actor_2>(f0.t1=(f0.t0=this->m__0data).slice(l_index1,l_index2));
}

t_stdlib_collections_Stack_1Tt_default_Actor_2* t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Slice(bbInt l_index){
  return this->m_Slice(l_index,this->m__0length);
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Set(bbInt l_index,t_default_Actor* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),bbString(L"Stack index out of range",24));
  this->m__0data[l_index]=l_value;
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Resize(bbInt l_length){
  bbDebugAssert((l_length>=bbInt(0)),bbString(L"Debug assert failed",19));
  {
    bbInt l_i=l_length;
    for(;(l_i<this->m__0length);l_i+=1){
      this->m__0data[l_i]=((t_default_Actor*)0);
    }
  }
  this->m_Reserve(l_length);
  this->m__0length=l_length;
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Reserve(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Actor>> l_data{};
    bbArray<bbGCVar<t_default_Actor>> t0{};
    void gcMark(){
      bbGCMark(l_data);
      bbGCMark(t0);
    }
  }f0{};
  bbDebugAssert((l_capacity>=bbInt(0)),bbString(L"Debug assert failed",19));
  if(((f0.t0=this->m__0data).length()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i((this->m__0length*2),l_capacity);
  f0.l_data=bbArray<bbGCVar<t_default_Actor>>(l_capacity);
  (f0.t0=this->m__0data).copyTo(f0.l_data,bbInt(0),bbInt(0),this->m__0length);
  this->m__0data=f0.l_data;
}

bbBool t_stdlib_collections_Stack_1Tt_default_Actor_2::m_RemoveLast(t_default_Actor* l_value,bbInt l_start){
  bbInt l_i=this->m_FindLastIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

bbInt t_stdlib_collections_Stack_1Tt_default_Actor_2::m_RemoveIf(bbFunction<bbBool(t_default_Actor*)> l_condition){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      struct f2_t : public bbGCFrame{
        t_default_Actor* t0{};
        void gcMark(){
          bbGCMark(t0);
        }
      }f2{};
      if(l_condition(f2.t0=this->m__0data[l_get].get())){
        l_n+=1;
        continue;
      }
      this->m__0data[l_put]=this->m__0data[l_get].get();
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbInt t_stdlib_collections_Stack_1Tt_default_Actor_2::m_RemoveEach(t_default_Actor* l_value){
  bbInt l_put=bbInt(0);
  bbInt l_n=bbInt(0);
  {
    bbInt l_get=bbInt(0);
    for(;(l_get<this->m__0length);l_get+=1){
      if((this->m__0data[l_get].get()==l_value)){
        l_n+=1;
        continue;
      }
      this->m__0data[l_put]=this->m__0data[l_get].get();
      l_put+=1;
    }
  }
  this->m_Resize(l_put);
  return l_n;
}

bbBool t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Remove(t_default_Actor* l_value,bbInt l_start){
  bbInt l_i=this->m_FindIndex(l_value,l_start);
  if((l_i==-1)){
    return false;
  }
  this->m_Erase(l_i);
  return true;
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Push(t_default_Actor* l_value){
  this->m_Add(l_value);
}

t_default_Actor* t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Pop(){
  struct f0_t : public bbGCFrame{
    t_default_Actor* l_value{};
    void gcMark(){
      bbGCMark(l_value);
    }
  }f0{};
  bbDebugAssert(bbBool(this->m__0length),bbString(L"Stack is empty",14));
  this->m__0length-=1;
  f0.l_value=this->m__0data[this->m__0length].get();
  this->m__0data[this->m__0length]=((t_default_Actor*)0);
  return f0.l_value;
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Insert(bbInt l_index,t_default_Actor* l_value){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Actor>> t0{};
    bbArray<bbGCVar<t_default_Actor>> t1{};
    void gcMark(){
      bbGCMark(t0);
      bbGCMark(t1);
    }
  }f0{};
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),bbString(L"Debug assert failed",19));
  this->m_Reserve((this->m__0length+1));
  (f0.t1=this->m__0data).copyTo(f0.t0=this->m__0data,l_index,(l_index+1),(this->m__0length-l_index));
  this->m__0data[l_index]=l_value;
  this->m__0length+=1;
}

t_default_Actor* t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m__0length)),bbString(L"Stack index out of range",24));
  return this->m__0data[l_index].get();
}

bbInt t_stdlib_collections_Stack_1Tt_default_Actor_2::m_FindLastIndex(t_default_Actor* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),bbString(L"Debug assert failed",19));
  bbInt l_i=this->m__0length;
  while((l_i>l_start)){
    l_i-=1;
    if((this->m__0data[l_i].get()==l_value)){
      return l_i;
    }
  }
  return -1;
}

bbInt t_stdlib_collections_Stack_1Tt_default_Actor_2::m_FindIndex(t_default_Actor* l_value,bbInt l_start){
  bbDebugAssert(((l_start>=bbInt(0))&&(l_start<=this->m__0length)),bbString(L"Debug assert failed",19));
  bbInt l_i=l_start;
  while((l_i<this->m__0length)){
    if((this->m__0data[l_i].get()==l_value)){
      return l_i;
    }
    l_i+=1;
  }
  return -1;
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Erase(bbInt l_index1,bbInt l_index2){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Actor>> t0{};
    bbArray<bbGCVar<t_default_Actor>> t1{};
    void gcMark(){
      bbGCMark(t0);
      bbGCMark(t1);
    }
  }f0{};
  bbDebugAssert((((((l_index1>=bbInt(0))&&(l_index1<=this->m__0length))&&(l_index2>=bbInt(0)))&&(l_index2<=this->m__0length))&&(l_index1<=l_index2)),bbString(L"Debug assert failed",19));
  if((l_index1==this->m__0length)){
    return;
  }
  (f0.t1=this->m__0data).copyTo(f0.t0=this->m__0data,l_index2,l_index1,(this->m__0length-l_index2));
  this->m_Resize(((this->m__0length-l_index2)+l_index1));
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Erase(bbInt l_index){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Actor>> t0{};
    bbArray<bbGCVar<t_default_Actor>> t1{};
    void gcMark(){
      bbGCMark(t0);
      bbGCMark(t1);
    }
  }f0{};
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<=this->m__0length)),bbString(L"Debug assert failed",19));
  if((l_index==this->m__0length)){
    return;
  }
  (f0.t1=this->m__0data).copyTo(f0.t0=this->m__0data,(l_index+1),l_index,((this->m__0length-l_index)-1));
  this->m_Resize((this->m__0length-1));
}

bbBool t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Empty(){
  return (this->m__0length==bbInt(0));
}

bbArray<bbGCVar<t_default_Actor>> t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Data(){
  return this->m__0data;
}

bbBool t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Contains(t_default_Actor* l_value){
  return (this->m_FindIndex(l_value,bbInt(0))!=-1);
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Compact(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Actor>> t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  if((this->m__0length!=(f0.t0=this->m__0data).length())){
    struct f1_t : public bbGCFrame{
      bbArray<bbGCVar<t_default_Actor>> t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    this->m__0data=(f1.t0=this->m__0data).slice(bbInt(0),this->m__0length);
  }
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Clear(){
  this->m_Resize(bbInt(0));
}

bbInt t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Capacity(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Actor>> t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  return (f0.t0=this->m__0data).length();
}

t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Backwards(){
  return t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator{this,(this->m__0length-1)};
}

t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator t_stdlib_collections_Stack_1Tt_default_Actor_2::m_All(){
  return t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator{this,bbInt(0)};
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2::m_AddAll(bbArray<bbGCVar<t_default_Actor>> l_values){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Actor>> t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  this->m_Reserve((this->m__0length+l_values.length()));
  l_values.copyTo(f0.t0=this->m__0data,bbInt(0),this->m__0length,l_values.length());
  this->m_Resize((this->m__0length+l_values.length()));
}

void t_stdlib_collections_Stack_1Tt_default_Actor_2::m_Add(t_default_Actor* l_value){
  this->m_Reserve((this->m__0length+1));
  this->m__0data[this->m__0length]=l_value;
  this->m__0length+=1;
}

void mx2_gridshooter_stdlib_collections_2stack_init_f(){
}
