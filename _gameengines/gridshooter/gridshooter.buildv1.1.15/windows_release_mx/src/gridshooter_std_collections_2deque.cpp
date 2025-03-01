
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_std_collections_2deque.h"

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2actor.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2bullet.h"
#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_debug.h"

extern bbInt g_monkey_math_Max_1i(bbInt l_x,bbInt l_y);
t_std_collections_Deque_1Tt_default_Bullet_2_Iterator::t_std_collections_Deque_1Tt_default_Bullet_2_Iterator(t_std_collections_Deque_1Tt_default_Bullet_2* l_deque,bbInt l_index){
  (*this).m__0deque=l_deque;
  (*this).m__0index=l_index;
}
t_std_collections_Deque_1Tt_default_Bullet_2_Iterator::~t_std_collections_Deque_1Tt_default_Bullet_2_Iterator(){
}

void t_std_collections_Deque_1Tt_default_Bullet_2_Iterator::m_Insert(t_default_Bullet* l_value){
  bbDB::error(bbString(L"Insert not supported for Deques",31));
}

void t_std_collections_Deque_1Tt_default_Bullet_2_Iterator::m_Erase(){
  bbDB::error(bbString(L"Erase not supported for Deques",30));
}

void t_std_collections_Deque_1Tt_default_Bullet_2_Iterator::m_Current(t_default_Bullet* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0deque.get()->m__0data[(*this).m__0index]=l_current;
}

t_default_Bullet* t_std_collections_Deque_1Tt_default_Bullet_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0deque.get()->m__0data[(*this).m__0index].get();
}

void t_std_collections_Deque_1Tt_default_Bullet_2_Iterator::m_Bump(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Deque_1Tt_default_Bullet_2* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
  if(((*this).m__0index==(f0.t0=(*this).m__0deque.get())->m_Capacity())){
    (*this).m__0index=bbInt(0);
  }
}

bbBool t_std_collections_Deque_1Tt_default_Bullet_2_Iterator::m_AtEnd(){
  return ((*this).m__0index==(*this).m__0deque.get()->m__0tail);
}

void t_std_collections_Deque_1Tt_default_Bullet_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(((*this).m__0index!=(*this).m__0deque.get()->m__0tail),bbString(L"Invalid deque iterator",22));
}

int bbCompare(const t_std_collections_Deque_1Tt_default_Bullet_2_Iterator&x,const t_std_collections_Deque_1Tt_default_Bullet_2_Iterator&y){
  if(int t=bbCompare(x.m__0deque,y.m__0deque)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Deque_1Tt_default_Bullet_2_Iterator&t){
  bbGCMark(t.m__0deque);
}

void t_std_collections_Deque_1Tt_default_Bullet_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Deque_1Tt_default_Bullet_2::t_std_collections_Deque_1Tt_default_Bullet_2(bbInt l_length){
  this->m__0tail=l_length;
  this->m__0data=bbArray<bbGCVar<t_default_Bullet>>((this->m__0tail+1));
}

t_std_collections_Deque_1Tt_default_Bullet_2::t_std_collections_Deque_1Tt_default_Bullet_2(){
  this->m__0data=bbArray<bbGCVar<t_default_Bullet>>(10);
}
t_std_collections_Deque_1Tt_default_Bullet_2::~t_std_collections_Deque_1Tt_default_Bullet_2(){
}

void t_std_collections_Deque_1Tt_default_Bullet_2::m__idxeq(bbInt l_index,t_default_Bullet* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m_Length())),bbString(L"Deque index out of range",24));
  this->m__0data[((l_index+this->m__0head)%this->m_Capacity())]=l_value;
}

t_default_Bullet* t_std_collections_Deque_1Tt_default_Bullet_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m_Length())),bbString(L"Deque index out of range",24));
  return this->m__0data[((l_index+this->m__0head)%this->m_Capacity())].get();
}

bbArray<bbGCVar<t_default_Bullet>> t_std_collections_Deque_1Tt_default_Bullet_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Bullet>> l_data{};
    void gcMark(){
      bbGCMark(l_data);
    }
  }f0{};
  f0.l_data=bbArray<bbGCVar<t_default_Bullet>>(this->m_Length());
  if((this->m__0head<=this->m__0tail)){
    struct f1_t : public bbGCFrame{
      bbArray<bbGCVar<t_default_Bullet>> t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    (f1.t0=this->m__0data).copyTo(f0.l_data,this->m__0head,bbInt(0),this->m_Length());
  }else{
    struct f1_t : public bbGCFrame{
      bbArray<bbGCVar<t_default_Bullet>> t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    bbInt l_n=(this->m_Capacity()-this->m__0head);
    (f1.t0=this->m__0data).copyTo(f0.l_data,this->m__0head,bbInt(0),l_n);
    (f1.t0=this->m__0data).copyTo(f0.l_data,bbInt(0),l_n,this->m__0tail);
  }
  return f0.l_data;
}

void t_std_collections_Deque_1Tt_default_Bullet_2::m_Set(bbInt l_index,t_default_Bullet* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m_Length())),bbString(L"Deque index out of range",24));
  this->m__0data[((l_index+this->m__0head)%this->m_Capacity())]=l_value;
}

void t_std_collections_Deque_1Tt_default_Bullet_2::m_Reserve(bbInt l_capacity){
  bbDebugAssert((l_capacity>=bbInt(0)),bbString(L"Debug assert failed",19));
  if((this->m_Capacity()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m_Length()*2)+this->m_Length()),l_capacity);
  this->m_Normalize(l_capacity);
}

t_default_Bullet* t_std_collections_Deque_1Tt_default_Bullet_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_default_Bullet* l_value{};
    void gcMark(){
      bbGCMark(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),bbString(L"Illegal operation on empty deque",32));
  this->m__0tail-=1;
  if((this->m__0tail==-1)){
    this->m__0tail=(this->m_Capacity()-1);
  }
  f0.l_value=this->m__0data[this->m__0tail].get();
  this->m__0data[this->m__0tail]=((t_default_Bullet*)0);
  return f0.l_value;
}

t_default_Bullet* t_std_collections_Deque_1Tt_default_Bullet_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_default_Bullet* l_value{};
    void gcMark(){
      bbGCMark(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),bbString(L"Illegal operation on empty deque",32));
  f0.l_value=this->m__0data[this->m__0head].get();
  this->m__0data[this->m__0head]=((t_default_Bullet*)0);
  this->m__0head+=1;
  if((this->m__0head==this->m_Capacity())){
    this->m__0head=bbInt(0);
  }
  return f0.l_value;
}

void t_std_collections_Deque_1Tt_default_Bullet_2::m_PushLast(t_default_Bullet* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_Deque_1Tt_default_Bullet_2::m_PushFirst(t_default_Bullet* l_value){
  this->m_AddFirst(l_value);
}

t_default_Bullet* t_std_collections_Deque_1Tt_default_Bullet_2::m_PopLast(){
  return this->m_RemoveLast();
}

t_default_Bullet* t_std_collections_Deque_1Tt_default_Bullet_2::m_PopFirst(){
  return this->m_RemoveFirst();
}

void t_std_collections_Deque_1Tt_default_Bullet_2::m_Normalize(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Bullet>> l_data{};
    void gcMark(){
      bbGCMark(l_data);
    }
  }f0{};
  bbInt l_length=this->m_Length();
  f0.l_data=bbArray<bbGCVar<t_default_Bullet>>(l_capacity);
  if((this->m__0head<=this->m__0tail)){
    struct f1_t : public bbGCFrame{
      bbArray<bbGCVar<t_default_Bullet>> t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    (f1.t0=this->m__0data).copyTo(f0.l_data,this->m__0head,bbInt(0),l_length);
  }else{
    struct f1_t : public bbGCFrame{
      bbArray<bbGCVar<t_default_Bullet>> t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    bbInt l_n=(this->m_Capacity()-this->m__0head);
    (f1.t0=this->m__0data).copyTo(f0.l_data,this->m__0head,bbInt(0),l_n);
    (f1.t0=this->m__0data).copyTo(f0.l_data,bbInt(0),l_n,this->m__0tail);
  }
  this->m__0data=f0.l_data;
  this->m__0tail=l_length;
  this->m__0head=bbInt(0);
}

bbInt t_std_collections_Deque_1Tt_default_Bullet_2::m_Length(){
  if((this->m__0head<=this->m__0tail)){
    return (this->m__0tail-this->m__0head);
  }
  return ((this->m_Capacity()-this->m__0head)+this->m__0tail);
}

t_default_Bullet* t_std_collections_Deque_1Tt_default_Bullet_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),bbString(L"Illegal operation on empty deque",32));
  return this->m__0data[((this->m__0tail>bbInt(0)) ? (this->m__0tail-1) : (this->m_Capacity()-1))].get();
}

t_default_Bullet* t_std_collections_Deque_1Tt_default_Bullet_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m_Length())),bbString(L"Deque index out of range",24));
  return this->m__0data[((l_index+this->m__0head)%this->m_Capacity())].get();
}

t_default_Bullet* t_std_collections_Deque_1Tt_default_Bullet_2::m_First(){
  bbDebugAssert(!this->m_Empty(),bbString(L"Illegal operation on empty deque",32));
  return this->m__0data[this->m__0head].get();
}

bbBool t_std_collections_Deque_1Tt_default_Bullet_2::m_Empty(){
  return (this->m__0head==this->m__0tail);
}

bbArray<bbGCVar<t_default_Bullet>> t_std_collections_Deque_1Tt_default_Bullet_2::m_Data(){
  if(!bbBool(this->m__0head)){
    return this->m__0data;
  }
  this->m_Normalize(this->m_Capacity());
  return this->m__0data;
}

void t_std_collections_Deque_1Tt_default_Bullet_2::m_Clear(){
  if((this->m__0head<=this->m__0tail)){
    {
      bbInt l_i=this->m__0head;
      for(;(l_i<this->m__0tail);l_i+=1){
        this->m__0data[l_i]=((t_default_Bullet*)0);
      }
    }
  }else{
    {
      bbInt l_i=bbInt(0);
      for(;(l_i<this->m__0tail);l_i+=1){
        this->m__0data[l_i]=((t_default_Bullet*)0);
      }
    }
    {
      bbInt l_i=this->m__0head;
      for(;(l_i<this->m_Capacity());l_i+=1){
        this->m__0data[l_i]=((t_default_Bullet*)0);
      }
    }
  }
  this->m__0head=bbInt(0);
  this->m__0tail=bbInt(0);
}

bbInt t_std_collections_Deque_1Tt_default_Bullet_2::m_Capacity(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Bullet>> t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  return (f0.t0=this->m__0data).length();
}

t_std_collections_Deque_1Tt_default_Bullet_2_Iterator t_std_collections_Deque_1Tt_default_Bullet_2::m_All(){
  return t_std_collections_Deque_1Tt_default_Bullet_2_Iterator{this,this->m__0head};
}

void t_std_collections_Deque_1Tt_default_Bullet_2::m_AddLast(t_default_Bullet* l_value){
  if(((this->m_Length()+1)==this->m_Capacity())){
    this->m_Reserve((this->m_Capacity()+1));
  }
  this->m__0data[this->m__0tail]=l_value;
  this->m__0tail+=1;
  if((this->m__0tail==this->m_Capacity())){
    this->m__0tail=bbInt(0);
  }
}

void t_std_collections_Deque_1Tt_default_Bullet_2::m_AddFirst(t_default_Bullet* l_value){
  if(((this->m_Length()+1)==this->m_Capacity())){
    this->m_Reserve((this->m_Capacity()+1));
  }
  this->m__0head-=1;
  if((this->m__0head==-1)){
    this->m__0head=(this->m_Capacity()-1);
  }
  this->m__0data[this->m__0head]=l_value;
}

t_std_collections_Deque_1Tt_default_Actor_2_Iterator::t_std_collections_Deque_1Tt_default_Actor_2_Iterator(t_std_collections_Deque_1Tt_default_Actor_2* l_deque,bbInt l_index){
  (*this).m__0deque=l_deque;
  (*this).m__0index=l_index;
}
t_std_collections_Deque_1Tt_default_Actor_2_Iterator::~t_std_collections_Deque_1Tt_default_Actor_2_Iterator(){
}

void t_std_collections_Deque_1Tt_default_Actor_2_Iterator::m_Insert(t_default_Actor* l_value){
  bbDB::error(bbString(L"Insert not supported for Deques",31));
}

void t_std_collections_Deque_1Tt_default_Actor_2_Iterator::m_Erase(){
  bbDB::error(bbString(L"Erase not supported for Deques",30));
}

void t_std_collections_Deque_1Tt_default_Actor_2_Iterator::m_Current(t_default_Actor* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0deque.get()->m__0data[(*this).m__0index]=l_current;
}

t_default_Actor* t_std_collections_Deque_1Tt_default_Actor_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0deque.get()->m__0data[(*this).m__0index].get();
}

void t_std_collections_Deque_1Tt_default_Actor_2_Iterator::m_Bump(){
  struct f0_t : public bbGCFrame{
    t_std_collections_Deque_1Tt_default_Actor_2* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  (*this).m_AssertCurrent();
  (*this).m__0index+=1;
  if(((*this).m__0index==(f0.t0=(*this).m__0deque.get())->m_Capacity())){
    (*this).m__0index=bbInt(0);
  }
}

bbBool t_std_collections_Deque_1Tt_default_Actor_2_Iterator::m_AtEnd(){
  return ((*this).m__0index==(*this).m__0deque.get()->m__0tail);
}

void t_std_collections_Deque_1Tt_default_Actor_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(((*this).m__0index!=(*this).m__0deque.get()->m__0tail),bbString(L"Invalid deque iterator",22));
}

int bbCompare(const t_std_collections_Deque_1Tt_default_Actor_2_Iterator&x,const t_std_collections_Deque_1Tt_default_Actor_2_Iterator&y){
  if(int t=bbCompare(x.m__0deque,y.m__0deque)) return t;
  if(int t=bbCompare(x.m__0index,y.m__0index)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_Deque_1Tt_default_Actor_2_Iterator&t){
  bbGCMark(t.m__0deque);
}

void t_std_collections_Deque_1Tt_default_Actor_2::gcMark(){
  bbGCMark(m__0data);
}

t_std_collections_Deque_1Tt_default_Actor_2::t_std_collections_Deque_1Tt_default_Actor_2(bbInt l_length){
  this->m__0tail=l_length;
  this->m__0data=bbArray<bbGCVar<t_default_Actor>>((this->m__0tail+1));
}

t_std_collections_Deque_1Tt_default_Actor_2::t_std_collections_Deque_1Tt_default_Actor_2(){
  this->m__0data=bbArray<bbGCVar<t_default_Actor>>(10);
}
t_std_collections_Deque_1Tt_default_Actor_2::~t_std_collections_Deque_1Tt_default_Actor_2(){
}

void t_std_collections_Deque_1Tt_default_Actor_2::m__idxeq(bbInt l_index,t_default_Actor* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m_Length())),bbString(L"Deque index out of range",24));
  this->m__0data[((l_index+this->m__0head)%this->m_Capacity())]=l_value;
}

t_default_Actor* t_std_collections_Deque_1Tt_default_Actor_2::m__idx(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m_Length())),bbString(L"Deque index out of range",24));
  return this->m__0data[((l_index+this->m__0head)%this->m_Capacity())].get();
}

bbArray<bbGCVar<t_default_Actor>> t_std_collections_Deque_1Tt_default_Actor_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Actor>> l_data{};
    void gcMark(){
      bbGCMark(l_data);
    }
  }f0{};
  f0.l_data=bbArray<bbGCVar<t_default_Actor>>(this->m_Length());
  if((this->m__0head<=this->m__0tail)){
    struct f1_t : public bbGCFrame{
      bbArray<bbGCVar<t_default_Actor>> t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    (f1.t0=this->m__0data).copyTo(f0.l_data,this->m__0head,bbInt(0),this->m_Length());
  }else{
    struct f1_t : public bbGCFrame{
      bbArray<bbGCVar<t_default_Actor>> t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    bbInt l_n=(this->m_Capacity()-this->m__0head);
    (f1.t0=this->m__0data).copyTo(f0.l_data,this->m__0head,bbInt(0),l_n);
    (f1.t0=this->m__0data).copyTo(f0.l_data,bbInt(0),l_n,this->m__0tail);
  }
  return f0.l_data;
}

void t_std_collections_Deque_1Tt_default_Actor_2::m_Set(bbInt l_index,t_default_Actor* l_value){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m_Length())),bbString(L"Deque index out of range",24));
  this->m__0data[((l_index+this->m__0head)%this->m_Capacity())]=l_value;
}

void t_std_collections_Deque_1Tt_default_Actor_2::m_Reserve(bbInt l_capacity){
  bbDebugAssert((l_capacity>=bbInt(0)),bbString(L"Debug assert failed",19));
  if((this->m_Capacity()>=l_capacity)){
    return;
  }
  l_capacity=g_monkey_math_Max_1i(((this->m_Length()*2)+this->m_Length()),l_capacity);
  this->m_Normalize(l_capacity);
}

t_default_Actor* t_std_collections_Deque_1Tt_default_Actor_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_default_Actor* l_value{};
    void gcMark(){
      bbGCMark(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),bbString(L"Illegal operation on empty deque",32));
  this->m__0tail-=1;
  if((this->m__0tail==-1)){
    this->m__0tail=(this->m_Capacity()-1);
  }
  f0.l_value=this->m__0data[this->m__0tail].get();
  this->m__0data[this->m__0tail]=((t_default_Actor*)0);
  return f0.l_value;
}

t_default_Actor* t_std_collections_Deque_1Tt_default_Actor_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_default_Actor* l_value{};
    void gcMark(){
      bbGCMark(l_value);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),bbString(L"Illegal operation on empty deque",32));
  f0.l_value=this->m__0data[this->m__0head].get();
  this->m__0data[this->m__0head]=((t_default_Actor*)0);
  this->m__0head+=1;
  if((this->m__0head==this->m_Capacity())){
    this->m__0head=bbInt(0);
  }
  return f0.l_value;
}

void t_std_collections_Deque_1Tt_default_Actor_2::m_PushLast(t_default_Actor* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_Deque_1Tt_default_Actor_2::m_PushFirst(t_default_Actor* l_value){
  this->m_AddFirst(l_value);
}

t_default_Actor* t_std_collections_Deque_1Tt_default_Actor_2::m_PopLast(){
  return this->m_RemoveLast();
}

t_default_Actor* t_std_collections_Deque_1Tt_default_Actor_2::m_PopFirst(){
  return this->m_RemoveFirst();
}

void t_std_collections_Deque_1Tt_default_Actor_2::m_Normalize(bbInt l_capacity){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Actor>> l_data{};
    void gcMark(){
      bbGCMark(l_data);
    }
  }f0{};
  bbInt l_length=this->m_Length();
  f0.l_data=bbArray<bbGCVar<t_default_Actor>>(l_capacity);
  if((this->m__0head<=this->m__0tail)){
    struct f1_t : public bbGCFrame{
      bbArray<bbGCVar<t_default_Actor>> t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    (f1.t0=this->m__0data).copyTo(f0.l_data,this->m__0head,bbInt(0),l_length);
  }else{
    struct f1_t : public bbGCFrame{
      bbArray<bbGCVar<t_default_Actor>> t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    bbInt l_n=(this->m_Capacity()-this->m__0head);
    (f1.t0=this->m__0data).copyTo(f0.l_data,this->m__0head,bbInt(0),l_n);
    (f1.t0=this->m__0data).copyTo(f0.l_data,bbInt(0),l_n,this->m__0tail);
  }
  this->m__0data=f0.l_data;
  this->m__0tail=l_length;
  this->m__0head=bbInt(0);
}

bbInt t_std_collections_Deque_1Tt_default_Actor_2::m_Length(){
  if((this->m__0head<=this->m__0tail)){
    return (this->m__0tail-this->m__0head);
  }
  return ((this->m_Capacity()-this->m__0head)+this->m__0tail);
}

t_default_Actor* t_std_collections_Deque_1Tt_default_Actor_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),bbString(L"Illegal operation on empty deque",32));
  return this->m__0data[((this->m__0tail>bbInt(0)) ? (this->m__0tail-1) : (this->m_Capacity()-1))].get();
}

t_default_Actor* t_std_collections_Deque_1Tt_default_Actor_2::m_Get(bbInt l_index){
  bbDebugAssert(((l_index>=bbInt(0))&&(l_index<this->m_Length())),bbString(L"Deque index out of range",24));
  return this->m__0data[((l_index+this->m__0head)%this->m_Capacity())].get();
}

t_default_Actor* t_std_collections_Deque_1Tt_default_Actor_2::m_First(){
  bbDebugAssert(!this->m_Empty(),bbString(L"Illegal operation on empty deque",32));
  return this->m__0data[this->m__0head].get();
}

bbBool t_std_collections_Deque_1Tt_default_Actor_2::m_Empty(){
  return (this->m__0head==this->m__0tail);
}

bbArray<bbGCVar<t_default_Actor>> t_std_collections_Deque_1Tt_default_Actor_2::m_Data(){
  if(!bbBool(this->m__0head)){
    return this->m__0data;
  }
  this->m_Normalize(this->m_Capacity());
  return this->m__0data;
}

void t_std_collections_Deque_1Tt_default_Actor_2::m_Clear(){
  if((this->m__0head<=this->m__0tail)){
    {
      bbInt l_i=this->m__0head;
      for(;(l_i<this->m__0tail);l_i+=1){
        this->m__0data[l_i]=((t_default_Actor*)0);
      }
    }
  }else{
    {
      bbInt l_i=bbInt(0);
      for(;(l_i<this->m__0tail);l_i+=1){
        this->m__0data[l_i]=((t_default_Actor*)0);
      }
    }
    {
      bbInt l_i=this->m__0head;
      for(;(l_i<this->m_Capacity());l_i+=1){
        this->m__0data[l_i]=((t_default_Actor*)0);
      }
    }
  }
  this->m__0head=bbInt(0);
  this->m__0tail=bbInt(0);
}

bbInt t_std_collections_Deque_1Tt_default_Actor_2::m_Capacity(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Actor>> t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  return (f0.t0=this->m__0data).length();
}

t_std_collections_Deque_1Tt_default_Actor_2_Iterator t_std_collections_Deque_1Tt_default_Actor_2::m_All(){
  return t_std_collections_Deque_1Tt_default_Actor_2_Iterator{this,this->m__0head};
}

void t_std_collections_Deque_1Tt_default_Actor_2::m_AddLast(t_default_Actor* l_value){
  if(((this->m_Length()+1)==this->m_Capacity())){
    this->m_Reserve((this->m_Capacity()+1));
  }
  this->m__0data[this->m__0tail]=l_value;
  this->m__0tail+=1;
  if((this->m__0tail==this->m_Capacity())){
    this->m__0tail=bbInt(0);
  }
}

void t_std_collections_Deque_1Tt_default_Actor_2::m_AddFirst(t_default_Actor* l_value){
  if(((this->m_Length()+1)==this->m_Capacity())){
    this->m_Reserve((this->m_Capacity()+1));
  }
  this->m__0head-=1;
  if((this->m__0head==-1)){
    this->m__0head=(this->m_Capacity()-1);
  }
  this->m__0data[this->m__0head]=l_value;
}

void mx2_gridshooter_std_collections_2deque_init_f(){
}
