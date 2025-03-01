
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_std_collections_2list.h"

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2actor.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2bullet.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_std_collections_2stack.h"
#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_debug.h"

extern bbInt invoke(t_default_Bullet* l_x,t_default_Bullet* l_y);
extern bbInt invoke(t_default_Actor* l_x,t_default_Actor* l_y);
extern bbInt invoke(t_default_Actor* l_x,t_default_Actor* l_y);
extern bbInt invoke(t_default_Bullet* l_x,t_default_Bullet* l_y);
void g_std_collections_List_1Tt_default_Actor_2_AddAll_1Tt_std_collections_List_1Tt_default_Actor_2_2(t_std_collections_List_1Tt_default_Actor_2* l_self,t_std_collections_List_1Tt_default_Actor_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_default_Actor_2_Iterator l_0{};
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
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_default_Actor_2_AddAll_1Tt_std_collections_Stack_1Tt_default_Actor_2_2(t_std_collections_List_1Tt_default_Actor_2* l_self,t_std_collections_Stack_1Tt_default_Actor_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_default_Actor_2_Iterator l_0{};
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
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_default_Bullet_2_AddAll_1Tt_std_collections_List_1Tt_default_Bullet_2_2(t_std_collections_List_1Tt_default_Bullet_2* l_self,t_std_collections_List_1Tt_default_Bullet_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_default_Bullet_2_Iterator l_0{};
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
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void g_std_collections_List_1Tt_default_Bullet_2_AddAll_1Tt_std_collections_Stack_1Tt_default_Bullet_2_2(t_std_collections_List_1Tt_default_Bullet_2* l_self,t_std_collections_Stack_1Tt_default_Bullet_2* l_values){
  {
    struct f1_t : public bbGCFrame{
      t_std_collections_Stack_1Tt_default_Bullet_2_Iterator l_0{};
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
      l_self->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_default_Bullet_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_default_Bullet_2_Node::t_std_collections_List_1Tt_default_Bullet_2_Node(t_default_Bullet* l_value,t_std_collections_List_1Tt_default_Bullet_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred.get();
  this->m__0pred.get()->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_default_Bullet_2_Node::t_std_collections_List_1Tt_default_Bullet_2_Node(t_default_Bullet* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}
t_std_collections_List_1Tt_default_Bullet_2_Node::~t_std_collections_List_1Tt_default_Bullet_2_Node(){
}

void t_std_collections_List_1Tt_default_Bullet_2_Node::m_Value(t_default_Bullet* l_value){
  this->m__0value=l_value;
}

t_default_Bullet* t_std_collections_List_1Tt_default_Bullet_2_Node::m_Value(){
  return this->m__0value.get();
}

t_std_collections_List_1Tt_default_Bullet_2_Node* t_std_collections_List_1Tt_default_Bullet_2_Node::m_Succ(){
  return this->m__0succ.get();
}

void t_std_collections_List_1Tt_default_Bullet_2_Node::m_Remove(){
  if(((this->m__0succ.get()->m__0pred.get()!=this)||(this->m__0pred.get()->m__0succ.get()!=this))){
    return;
  }
  this->m__0succ.get()->m__0pred=this->m__0pred.get();
  this->m__0pred.get()->m__0succ=this->m__0succ.get();
}

t_std_collections_List_1Tt_default_Bullet_2_Node* t_std_collections_List_1Tt_default_Bullet_2_Node::m_Pred(){
  return this->m__0pred.get();
}

void t_std_collections_List_1Tt_default_Bullet_2_Node::m_InsertBefore(t_std_collections_List_1Tt_default_Bullet_2_Node* l_node){
  this->m_Remove();
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred.get();
  this->m__0pred.get()->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_default_Bullet_2_Node::m_InsertAfter(t_std_collections_List_1Tt_default_Bullet_2_Node* l_node){
  this->m_Remove();
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ.get();
  this->m__0succ.get()->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_default_Bullet_2_Iterator::t_std_collections_List_1Tt_default_Bullet_2_Iterator(t_std_collections_List_1Tt_default_Bullet_2* l_list,t_std_collections_List_1Tt_default_Bullet_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
}
t_std_collections_List_1Tt_default_Bullet_2_Iterator::~t_std_collections_List_1Tt_default_Bullet_2_Iterator(){
}

void t_std_collections_List_1Tt_default_Bullet_2_Iterator::m_Insert(t_default_Bullet* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Bullet_2_Node* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_default_Bullet_2_Node>(l_value,f0.t0=(*this).m__0node.get());
}

void t_std_collections_List_1Tt_default_Bullet_2_Iterator::m_Erase(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Bullet_2_Node* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node.get()->m__0succ.get();
  (f0.t0=(*this).m__0node.get()->m__0pred.get())->m_Remove();
}

void t_std_collections_List_1Tt_default_Bullet_2_Iterator::m_Current(t_default_Bullet* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node.get()->m__0value=l_current;
}

t_default_Bullet* t_std_collections_List_1Tt_default_Bullet_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node.get()->m__0value.get();
}

void t_std_collections_List_1Tt_default_Bullet_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node.get()->m__0succ.get();
}

bbBool t_std_collections_List_1Tt_default_Bullet_2_Iterator::m_AtEnd(){
  return ((*this).m__0node.get()==(*this).m__0list.get()->m__0head.get());
}

void t_std_collections_List_1Tt_default_Bullet_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(((*this).m__0node.get()!=(*this).m__0list.get()->m__0head.get()),bbString(L"Invalid list iterator",21));
}

int bbCompare(const t_std_collections_List_1Tt_default_Bullet_2_Iterator&x,const t_std_collections_List_1Tt_default_Bullet_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_default_Bullet_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_default_Bullet_2_BackwardsIterator::t_std_collections_List_1Tt_default_Bullet_2_BackwardsIterator(t_std_collections_List_1Tt_default_Bullet_2* l_list,t_std_collections_List_1Tt_default_Bullet_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
}
t_std_collections_List_1Tt_default_Bullet_2_BackwardsIterator::~t_std_collections_List_1Tt_default_Bullet_2_BackwardsIterator(){
}

void t_std_collections_List_1Tt_default_Bullet_2_BackwardsIterator::m_Insert(t_default_Bullet* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Bullet_2_Node* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_default_Bullet_2_Node>(l_value,f0.t0=(*this).m__0node.get()->m__0succ.get());
}

void t_std_collections_List_1Tt_default_Bullet_2_BackwardsIterator::m_Erase(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Bullet_2_Node* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node.get()->m__0pred.get();
  (f0.t0=(*this).m__0node.get()->m__0succ.get())->m_Remove();
}

void t_std_collections_List_1Tt_default_Bullet_2_BackwardsIterator::m_Current(t_default_Bullet* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node.get()->m__0value=l_current;
}

t_default_Bullet* t_std_collections_List_1Tt_default_Bullet_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node.get()->m__0value.get();
}

void t_std_collections_List_1Tt_default_Bullet_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node.get()->m__0pred.get();
}

bbBool t_std_collections_List_1Tt_default_Bullet_2_BackwardsIterator::m_AtEnd(){
  return ((*this).m__0node.get()==(*this).m__0list.get()->m__0head.get());
}

void t_std_collections_List_1Tt_default_Bullet_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(((*this).m__0node.get()!=(*this).m__0list.get()->m__0head.get()),bbString(L"Invalid list iterator",21));
}

int bbCompare(const t_std_collections_List_1Tt_default_Bullet_2_BackwardsIterator&x,const t_std_collections_List_1Tt_default_Bullet_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_default_Bullet_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_default_Bullet_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_default_Bullet_2::t_std_collections_List_1Tt_default_Bullet_2(t_std_collections_List_1Tt_default_Bullet_2* l_values):t_std_collections_List_1Tt_default_Bullet_2(){
  g_std_collections_List_1Tt_default_Bullet_2_AddAll_1Tt_std_collections_List_1Tt_default_Bullet_2_2(this,l_values);
}

t_std_collections_List_1Tt_default_Bullet_2::t_std_collections_List_1Tt_default_Bullet_2(t_std_collections_Stack_1Tt_default_Bullet_2* l_values):t_std_collections_List_1Tt_default_Bullet_2(){
  g_std_collections_List_1Tt_default_Bullet_2_AddAll_1Tt_std_collections_Stack_1Tt_default_Bullet_2_2(this,l_values);
}

t_std_collections_List_1Tt_default_Bullet_2::t_std_collections_List_1Tt_default_Bullet_2(bbArray<bbGCVar<t_default_Bullet>> l_values):t_std_collections_List_1Tt_default_Bullet_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_default_Bullet_2::t_std_collections_List_1Tt_default_Bullet_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_default_Bullet_2_Node>(((t_default_Bullet*)0));
}
t_std_collections_List_1Tt_default_Bullet_2::~t_std_collections_List_1Tt_default_Bullet_2(){
}

bbArray<bbGCVar<t_default_Bullet>> t_std_collections_List_1Tt_default_Bullet_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Bullet>> l_data{};
    t_std_collections_List_1Tt_default_Bullet_2_Node* l_node{};
    void gcMark(){
      bbGCMark(l_data);
      bbGCMark(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_default_Bullet>>(l_n);
  f0.l_node=this->m__0head.get()->m__0succ.get();
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data[l_i]=f0.l_node->m__0value.get();
      f0.l_node=f0.l_node->m__0succ.get();
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_default_Bullet_2::m_Sort(bbFunction<bbInt(t_default_Bullet*,t_default_Bullet*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_default_Bullet_2_Node* l_p{};
      t_std_collections_List_1Tt_default_Bullet_2_Node* l_tail{};
      void gcMark(){
        bbGCMark(l_p);
        bbGCMark(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head.get();
    f1.l_p=this->m__0head.get()->m__0succ.get();
    while((f1.l_p!=this->m__0head.get())){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_default_Bullet_2_Node* l_q{};
        void gcMark(){
          bbGCMark(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ.get();
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head.get()))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ.get();
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_default_Bullet_2_Node* l_t{};
          void gcMark(){
            bbGCMark(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head.get()))){
          struct f4_t : public bbGCFrame{
            t_default_Bullet* t0{};
            t_default_Bullet* t1{};
            void gcMark(){
              bbGCMark(t0);
              bbGCMark(t1);
            }
          }f4{};
          bbInt l_cc=l_compareFunc(f4.t0=f1.l_p->m__0value.get(),f4.t1=f2.l_q->m__0value.get());
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ.get();
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ.get();
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ.get();
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head.get()))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ.get();
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head.get();
    this->m__0head.get()->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_default_Bullet_2::m_Sort(bbInt l_ascending){
  if(bbBool(l_ascending)){
    struct f1_t : public bbGCFrame{
      bbFunction<bbInt(t_default_Bullet*,t_default_Bullet*)> t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    struct lambda0 : public bbFunction<bbInt(t_default_Bullet*,t_default_Bullet*)>::Rep{
      t_std_collections_List_1Tt_default_Bullet_2* l_self;
      lambda0(t_std_collections_List_1Tt_default_Bullet_2* l_self):l_self(l_self){
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
      t_std_collections_List_1Tt_default_Bullet_2* l_self;
      lambda1(t_std_collections_List_1Tt_default_Bullet_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_default_Bullet* l_x,t_default_Bullet* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMark(l_self);
      }
    };
    this->m_Sort(f1.t0=bbFunction<bbInt(t_default_Bullet*,t_default_Bullet*)>(new lambda1(this)));
  }
}

t_default_Bullet* t_std_collections_List_1Tt_default_Bullet_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_default_Bullet* l_value{};
    t_std_collections_List_1Tt_default_Bullet_2_Node* t0{};
    void gcMark(){
      bbGCMark(l_value);
      bbGCMark(t0);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),bbString(L"Debug assert failed",19));
  f0.l_value=this->m__0head.get()->m__0pred.get()->m__0value.get();
  (f0.t0=this->m__0head.get()->m__0pred.get())->m_Remove();
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_default_Bullet_2::m_RemoveLast(t_default_Bullet* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Bullet_2_Node* l_node{};
    void gcMark(){
      bbGCMark(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  return true;
}

bbInt t_std_collections_List_1Tt_default_Bullet_2::m_RemoveIf(bbFunction<bbBool(t_default_Bullet*)> l_condition){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Bullet_2_Node* l_node{};
    void gcMark(){
      bbGCMark(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head.get()->m__0succ.get();
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head.get())){
    struct f1_t : public bbGCFrame{
      t_default_Bullet* t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    if(l_condition(f1.t0=f0.l_node->m__0value.get())){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_default_Bullet_2_Node* t0{};
        void gcMark(){
          bbGCMark(t0);
        }
      }f2{};
      f0.l_node=f0.l_node->m__0succ.get();
      (f2.t0=f0.l_node->m__0pred.get())->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ.get();
    }
  }
  return l_n;
}

t_default_Bullet* t_std_collections_List_1Tt_default_Bullet_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_default_Bullet* l_value{};
    t_std_collections_List_1Tt_default_Bullet_2_Node* t0{};
    void gcMark(){
      bbGCMark(l_value);
      bbGCMark(t0);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),bbString(L"Debug assert failed",19));
  f0.l_value=this->m__0head.get()->m__0succ.get()->m__0value.get();
  (f0.t0=this->m__0head.get()->m__0succ.get())->m_Remove();
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_default_Bullet_2::m_RemoveEach(t_default_Bullet* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Bullet_2_Node* l_node{};
    void gcMark(){
      bbGCMark(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head.get()->m__0succ.get();
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head.get())){
    if((f0.l_node->m__0value.get()==l_value)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_default_Bullet_2_Node* t0{};
        void gcMark(){
          bbGCMark(t0);
        }
      }f2{};
      f0.l_node=f0.l_node->m__0succ.get();
      (f2.t0=f0.l_node->m__0pred.get())->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ.get();
    }
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_default_Bullet_2::m_Remove(t_default_Bullet* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Bullet_2_Node* l_node{};
    void gcMark(){
      bbGCMark(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  return true;
}

t_std_collections_List_1Tt_default_Bullet_2_Node* t_std_collections_List_1Tt_default_Bullet_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head.get()->m__0pred.get();
  }
  return ((t_std_collections_List_1Tt_default_Bullet_2_Node*)0);
}

t_default_Bullet* t_std_collections_List_1Tt_default_Bullet_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),bbString(L"Debug assert failed",19));
  return this->m__0head.get()->m__0pred.get()->m__0value.get();
}

t_std_collections_List_1Tt_default_Bullet_2_Node* t_std_collections_List_1Tt_default_Bullet_2::m_HeadNode(){
  return this->m__0head.get();
}

t_std_collections_List_1Tt_default_Bullet_2_Node* t_std_collections_List_1Tt_default_Bullet_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head.get()->m__0succ.get();
  }
  return ((t_std_collections_List_1Tt_default_Bullet_2_Node*)0);
}

t_default_Bullet* t_std_collections_List_1Tt_default_Bullet_2::m_First(){
  bbDebugAssert(!this->m_Empty(),bbString(L"Debug assert failed",19));
  return this->m__0head.get()->m__0succ.get()->m__0value.get();
}

t_std_collections_List_1Tt_default_Bullet_2_Node* t_std_collections_List_1Tt_default_Bullet_2::m_FindNode(t_default_Bullet* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Bullet_2_Node* l_node{};
    void gcMark(){
      bbGCMark(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head.get()->m__0succ.get();
  while((f0.l_node!=this->m__0head.get())){
    if((f0.l_node->m__0value.get()==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ.get();
  }
  return ((t_std_collections_List_1Tt_default_Bullet_2_Node*)0);
}

t_std_collections_List_1Tt_default_Bullet_2_Node* t_std_collections_List_1Tt_default_Bullet_2::m_FindLastNode(t_default_Bullet* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Bullet_2_Node* l_node{};
    void gcMark(){
      bbGCMark(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head.get()->m__0pred.get();
  while((f0.l_node!=this->m__0head.get())){
    if((f0.l_node->m__0value.get()==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred.get();
  }
  return ((t_std_collections_List_1Tt_default_Bullet_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_default_Bullet_2::m_Empty(){
  return (this->m__0head.get()->m__0succ.get()==this->m__0head.get());
}

bbInt t_std_collections_List_1Tt_default_Bullet_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Bullet_2_Node* l_node{};
    void gcMark(){
      bbGCMark(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head.get()->m__0succ.get();
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head.get())){
    f0.l_node=f0.l_node->m__0succ.get();
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_default_Bullet_2::m_Clear(){
  this->m__0head.get()->m__0succ=this->m__0head.get();
  this->m__0head.get()->m__0pred=this->m__0head.get();
}

t_std_collections_List_1Tt_default_Bullet_2_BackwardsIterator t_std_collections_List_1Tt_default_Bullet_2::m_Backwards(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Bullet_2_Node* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  return t_std_collections_List_1Tt_default_Bullet_2_BackwardsIterator{this,f0.t0=this->m__0head.get()->m__0pred.get()};
}

t_std_collections_List_1Tt_default_Bullet_2_Iterator t_std_collections_List_1Tt_default_Bullet_2::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Bullet_2_Node* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  return t_std_collections_List_1Tt_default_Bullet_2_Iterator{this,f0.t0=this->m__0head.get()->m__0succ.get()};
}

t_std_collections_List_1Tt_default_Bullet_2_Node* t_std_collections_List_1Tt_default_Bullet_2::m_AddLast(t_default_Bullet* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Bullet_2_Node* l_node{};
    t_std_collections_List_1Tt_default_Bullet_2_Node* t0{};
    void gcMark(){
      bbGCMark(l_node);
      bbGCMark(t0);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_default_Bullet_2_Node>(l_value,f0.t0=this->m__0head.get());
  return f0.l_node;
}

t_std_collections_List_1Tt_default_Bullet_2_Node* t_std_collections_List_1Tt_default_Bullet_2::m_AddFirst(t_default_Bullet* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Bullet_2_Node* l_node{};
    t_std_collections_List_1Tt_default_Bullet_2_Node* t0{};
    void gcMark(){
      bbGCMark(l_node);
      bbGCMark(t0);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_default_Bullet_2_Node>(l_value,f0.t0=this->m__0head.get()->m__0succ.get());
  return f0.l_node;
}

void t_std_collections_List_1Tt_default_Bullet_2::m_AddAll(bbArray<bbGCVar<t_default_Bullet>> l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values.length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_default_Bullet* l_value{};
        void gcMark(){
          bbGCMark(l_value);
        }
      }f2{};
      f2.l_value=l_values[l_0].get();
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_default_Bullet_2::m_Add(t_default_Bullet* l_value){
  this->m_AddLast(l_value);
}

void t_std_collections_List_1Tt_default_Actor_2_Node::gcMark(){
  bbGCMark(m__0succ);
  bbGCMark(m__0pred);
  bbGCMark(m__0value);
}

t_std_collections_List_1Tt_default_Actor_2_Node::t_std_collections_List_1Tt_default_Actor_2_Node(t_default_Actor* l_value,t_std_collections_List_1Tt_default_Actor_2_Node* l_succ){
  this->m__0value=l_value;
  this->m__0succ=l_succ;
  this->m__0pred=l_succ->m__0pred.get();
  this->m__0pred.get()->m__0succ=this;
  l_succ->m__0pred=this;
}

t_std_collections_List_1Tt_default_Actor_2_Node::t_std_collections_List_1Tt_default_Actor_2_Node(t_default_Actor* l_value){
  this->m__0value=l_value;
  this->m__0succ=this;
  this->m__0pred=this;
}
t_std_collections_List_1Tt_default_Actor_2_Node::~t_std_collections_List_1Tt_default_Actor_2_Node(){
}

void t_std_collections_List_1Tt_default_Actor_2_Node::m_Value(t_default_Actor* l_value){
  this->m__0value=l_value;
}

t_default_Actor* t_std_collections_List_1Tt_default_Actor_2_Node::m_Value(){
  return this->m__0value.get();
}

t_std_collections_List_1Tt_default_Actor_2_Node* t_std_collections_List_1Tt_default_Actor_2_Node::m_Succ(){
  return this->m__0succ.get();
}

void t_std_collections_List_1Tt_default_Actor_2_Node::m_Remove(){
  if(((this->m__0succ.get()->m__0pred.get()!=this)||(this->m__0pred.get()->m__0succ.get()!=this))){
    return;
  }
  this->m__0succ.get()->m__0pred=this->m__0pred.get();
  this->m__0pred.get()->m__0succ=this->m__0succ.get();
}

t_std_collections_List_1Tt_default_Actor_2_Node* t_std_collections_List_1Tt_default_Actor_2_Node::m_Pred(){
  return this->m__0pred.get();
}

void t_std_collections_List_1Tt_default_Actor_2_Node::m_InsertBefore(t_std_collections_List_1Tt_default_Actor_2_Node* l_node){
  this->m_Remove();
  this->m__0succ=l_node;
  this->m__0pred=l_node->m__0pred.get();
  this->m__0pred.get()->m__0succ=this;
  l_node->m__0pred=this;
}

void t_std_collections_List_1Tt_default_Actor_2_Node::m_InsertAfter(t_std_collections_List_1Tt_default_Actor_2_Node* l_node){
  this->m_Remove();
  this->m__0pred=l_node;
  this->m__0succ=l_node->m__0succ.get();
  this->m__0succ.get()->m__0pred=this;
  l_node->m__0succ=this;
}

t_std_collections_List_1Tt_default_Actor_2_Iterator::t_std_collections_List_1Tt_default_Actor_2_Iterator(t_std_collections_List_1Tt_default_Actor_2* l_list,t_std_collections_List_1Tt_default_Actor_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
}
t_std_collections_List_1Tt_default_Actor_2_Iterator::~t_std_collections_List_1Tt_default_Actor_2_Iterator(){
}

void t_std_collections_List_1Tt_default_Actor_2_Iterator::m_Insert(t_default_Actor* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Actor_2_Node* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_default_Actor_2_Node>(l_value,f0.t0=(*this).m__0node.get());
}

void t_std_collections_List_1Tt_default_Actor_2_Iterator::m_Erase(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Actor_2_Node* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node.get()->m__0succ.get();
  (f0.t0=(*this).m__0node.get()->m__0pred.get())->m_Remove();
}

void t_std_collections_List_1Tt_default_Actor_2_Iterator::m_Current(t_default_Actor* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node.get()->m__0value=l_current;
}

t_default_Actor* t_std_collections_List_1Tt_default_Actor_2_Iterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node.get()->m__0value.get();
}

void t_std_collections_List_1Tt_default_Actor_2_Iterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node.get()->m__0succ.get();
}

bbBool t_std_collections_List_1Tt_default_Actor_2_Iterator::m_AtEnd(){
  return ((*this).m__0node.get()==(*this).m__0list.get()->m__0head.get());
}

void t_std_collections_List_1Tt_default_Actor_2_Iterator::m_AssertCurrent(){
  bbDebugAssert(((*this).m__0node.get()!=(*this).m__0list.get()->m__0head.get()),bbString(L"Invalid list iterator",21));
}

int bbCompare(const t_std_collections_List_1Tt_default_Actor_2_Iterator&x,const t_std_collections_List_1Tt_default_Actor_2_Iterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_default_Actor_2_Iterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

t_std_collections_List_1Tt_default_Actor_2_BackwardsIterator::t_std_collections_List_1Tt_default_Actor_2_BackwardsIterator(t_std_collections_List_1Tt_default_Actor_2* l_list,t_std_collections_List_1Tt_default_Actor_2_Node* l_node){
  (*this).m__0list=l_list;
  (*this).m__0node=l_node;
}
t_std_collections_List_1Tt_default_Actor_2_BackwardsIterator::~t_std_collections_List_1Tt_default_Actor_2_BackwardsIterator(){
}

void t_std_collections_List_1Tt_default_Actor_2_BackwardsIterator::m_Insert(t_default_Actor* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Actor_2_Node* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  (*this).m__0node=bbGCNew<t_std_collections_List_1Tt_default_Actor_2_Node>(l_value,f0.t0=(*this).m__0node.get()->m__0succ.get());
}

void t_std_collections_List_1Tt_default_Actor_2_BackwardsIterator::m_Erase(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Actor_2_Node* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node.get()->m__0pred.get();
  (f0.t0=(*this).m__0node.get()->m__0succ.get())->m_Remove();
}

void t_std_collections_List_1Tt_default_Actor_2_BackwardsIterator::m_Current(t_default_Actor* l_current){
  (*this).m_AssertCurrent();
  (*this).m__0node.get()->m__0value=l_current;
}

t_default_Actor* t_std_collections_List_1Tt_default_Actor_2_BackwardsIterator::m_Current(){
  (*this).m_AssertCurrent();
  return (*this).m__0node.get()->m__0value.get();
}

void t_std_collections_List_1Tt_default_Actor_2_BackwardsIterator::m_Bump(){
  (*this).m_AssertCurrent();
  (*this).m__0node=(*this).m__0node.get()->m__0pred.get();
}

bbBool t_std_collections_List_1Tt_default_Actor_2_BackwardsIterator::m_AtEnd(){
  return ((*this).m__0node.get()==(*this).m__0list.get()->m__0head.get());
}

void t_std_collections_List_1Tt_default_Actor_2_BackwardsIterator::m_AssertCurrent(){
  bbDebugAssert(((*this).m__0node.get()!=(*this).m__0list.get()->m__0head.get()),bbString(L"Invalid list iterator",21));
}

int bbCompare(const t_std_collections_List_1Tt_default_Actor_2_BackwardsIterator&x,const t_std_collections_List_1Tt_default_Actor_2_BackwardsIterator&y){
  if(int t=bbCompare(x.m__0list,y.m__0list)) return t;
  if(int t=bbCompare(x.m__0node,y.m__0node)) return t;
  return 0;
}

void bbGCMark(const t_std_collections_List_1Tt_default_Actor_2_BackwardsIterator&t){
  bbGCMark(t.m__0list);
  bbGCMark(t.m__0node);
}

void t_std_collections_List_1Tt_default_Actor_2::gcMark(){
  bbGCMark(m__0head);
}

t_std_collections_List_1Tt_default_Actor_2::t_std_collections_List_1Tt_default_Actor_2(t_std_collections_List_1Tt_default_Actor_2* l_values):t_std_collections_List_1Tt_default_Actor_2(){
  g_std_collections_List_1Tt_default_Actor_2_AddAll_1Tt_std_collections_List_1Tt_default_Actor_2_2(this,l_values);
}

t_std_collections_List_1Tt_default_Actor_2::t_std_collections_List_1Tt_default_Actor_2(t_std_collections_Stack_1Tt_default_Actor_2* l_values):t_std_collections_List_1Tt_default_Actor_2(){
  g_std_collections_List_1Tt_default_Actor_2_AddAll_1Tt_std_collections_Stack_1Tt_default_Actor_2_2(this,l_values);
}

t_std_collections_List_1Tt_default_Actor_2::t_std_collections_List_1Tt_default_Actor_2(bbArray<bbGCVar<t_default_Actor>> l_values):t_std_collections_List_1Tt_default_Actor_2(){
  this->m_AddAll(l_values);
}

t_std_collections_List_1Tt_default_Actor_2::t_std_collections_List_1Tt_default_Actor_2(){
  this->m__0head=bbGCNew<t_std_collections_List_1Tt_default_Actor_2_Node>(((t_default_Actor*)0));
}
t_std_collections_List_1Tt_default_Actor_2::~t_std_collections_List_1Tt_default_Actor_2(){
}

bbArray<bbGCVar<t_default_Actor>> t_std_collections_List_1Tt_default_Actor_2::m_ToArray(){
  struct f0_t : public bbGCFrame{
    bbArray<bbGCVar<t_default_Actor>> l_data{};
    t_std_collections_List_1Tt_default_Actor_2_Node* l_node{};
    void gcMark(){
      bbGCMark(l_data);
      bbGCMark(l_node);
    }
  }f0{};
  bbInt l_n=this->m_Count();
  f0.l_data=bbArray<bbGCVar<t_default_Actor>>(l_n);
  f0.l_node=this->m__0head.get()->m__0succ.get();
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<l_n);l_i+=1){
      f0.l_data[l_i]=f0.l_node->m__0value.get();
      f0.l_node=f0.l_node->m__0succ.get();
    }
  }
  return f0.l_data;
}

void t_std_collections_List_1Tt_default_Actor_2::m_Sort(bbFunction<bbInt(t_default_Actor*,t_default_Actor*)> l_compareFunc){
  bbInt l_insize=1;
  for(;;){
    struct f1_t : public bbGCFrame{
      t_std_collections_List_1Tt_default_Actor_2_Node* l_p{};
      t_std_collections_List_1Tt_default_Actor_2_Node* l_tail{};
      void gcMark(){
        bbGCMark(l_p);
        bbGCMark(l_tail);
      }
    }f1{};
    bbInt l_merges=bbInt(0);
    f1.l_tail=this->m__0head.get();
    f1.l_p=this->m__0head.get()->m__0succ.get();
    while((f1.l_p!=this->m__0head.get())){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_default_Actor_2_Node* l_q{};
        void gcMark(){
          bbGCMark(l_q);
        }
      }f2{};
      l_merges+=1;
      f2.l_q=f1.l_p->m__0succ.get();
      bbInt l_qsize=l_insize;
      bbInt l_psize=1;
      while(((l_psize<l_insize)&&(f2.l_q!=this->m__0head.get()))){
        l_psize+=1;
        f2.l_q=f2.l_q->m__0succ.get();
      }
      for(;;){
        struct f3_t : public bbGCFrame{
          t_std_collections_List_1Tt_default_Actor_2_Node* l_t{};
          void gcMark(){
            bbGCMark(l_t);
          }
        }f3{};
        if(((bbBool(l_psize)&&bbBool(l_qsize))&&(f2.l_q!=this->m__0head.get()))){
          struct f4_t : public bbGCFrame{
            t_default_Actor* t0{};
            t_default_Actor* t1{};
            void gcMark(){
              bbGCMark(t0);
              bbGCMark(t1);
            }
          }f4{};
          bbInt l_cc=l_compareFunc(f4.t0=f1.l_p->m__0value.get(),f4.t1=f2.l_q->m__0value.get());
          if((l_cc<=bbInt(0))){
            f3.l_t=f1.l_p;
            f1.l_p=f1.l_p->m__0succ.get();
            l_psize-=1;
          }else{
            f3.l_t=f2.l_q;
            f2.l_q=f2.l_q->m__0succ.get();
            l_qsize-=1;
          }
        }else if(bbBool(l_psize)){
          f3.l_t=f1.l_p;
          f1.l_p=f1.l_p->m__0succ.get();
          l_psize-=1;
        }else if((bbBool(l_qsize)&&(f2.l_q!=this->m__0head.get()))){
          f3.l_t=f2.l_q;
          f2.l_q=f2.l_q->m__0succ.get();
          l_qsize-=1;
        }else{
          break;
        }
        f3.l_t->m__0pred=f1.l_tail;
        f1.l_tail->m__0succ=f3.l_t;
        f1.l_tail=f3.l_t;
      }
      f1.l_p=f2.l_q;
    }
    f1.l_tail->m__0succ=this->m__0head.get();
    this->m__0head.get()->m__0pred=f1.l_tail;
    if((l_merges<=1)){
      return;
    }
    l_insize*=2;
  }
}

void t_std_collections_List_1Tt_default_Actor_2::m_Sort(bbInt l_ascending){
  if(bbBool(l_ascending)){
    struct f1_t : public bbGCFrame{
      bbFunction<bbInt(t_default_Actor*,t_default_Actor*)> t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    struct lambda2 : public bbFunction<bbInt(t_default_Actor*,t_default_Actor*)>::Rep{
      t_std_collections_List_1Tt_default_Actor_2* l_self;
      lambda2(t_std_collections_List_1Tt_default_Actor_2* l_self):l_self(l_self){
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
      t_std_collections_List_1Tt_default_Actor_2* l_self;
      lambda3(t_std_collections_List_1Tt_default_Actor_2* l_self):l_self(l_self){
      }
      bbInt invoke(t_default_Actor* l_x,t_default_Actor* l_y){
        return -bbCompare(l_x,l_y);
      }
      void gcMark(){
        bbGCMark(l_self);
      }
    };
    this->m_Sort(f1.t0=bbFunction<bbInt(t_default_Actor*,t_default_Actor*)>(new lambda3(this)));
  }
}

t_default_Actor* t_std_collections_List_1Tt_default_Actor_2::m_RemoveLast(){
  struct f0_t : public bbGCFrame{
    t_default_Actor* l_value{};
    t_std_collections_List_1Tt_default_Actor_2_Node* t0{};
    void gcMark(){
      bbGCMark(l_value);
      bbGCMark(t0);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),bbString(L"Debug assert failed",19));
  f0.l_value=this->m__0head.get()->m__0pred.get()->m__0value.get();
  (f0.t0=this->m__0head.get()->m__0pred.get())->m_Remove();
  return f0.l_value;
}

bbBool t_std_collections_List_1Tt_default_Actor_2::m_RemoveLast(t_default_Actor* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Actor_2_Node* l_node{};
    void gcMark(){
      bbGCMark(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindLastNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  return true;
}

bbInt t_std_collections_List_1Tt_default_Actor_2::m_RemoveIf(bbFunction<bbBool(t_default_Actor*)> l_condition){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Actor_2_Node* l_node{};
    void gcMark(){
      bbGCMark(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head.get()->m__0succ.get();
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head.get())){
    struct f1_t : public bbGCFrame{
      t_default_Actor* t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    if(l_condition(f1.t0=f0.l_node->m__0value.get())){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_default_Actor_2_Node* t0{};
        void gcMark(){
          bbGCMark(t0);
        }
      }f2{};
      f0.l_node=f0.l_node->m__0succ.get();
      (f2.t0=f0.l_node->m__0pred.get())->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ.get();
    }
  }
  return l_n;
}

t_default_Actor* t_std_collections_List_1Tt_default_Actor_2::m_RemoveFirst(){
  struct f0_t : public bbGCFrame{
    t_default_Actor* l_value{};
    t_std_collections_List_1Tt_default_Actor_2_Node* t0{};
    void gcMark(){
      bbGCMark(l_value);
      bbGCMark(t0);
    }
  }f0{};
  bbDebugAssert(!this->m_Empty(),bbString(L"Debug assert failed",19));
  f0.l_value=this->m__0head.get()->m__0succ.get()->m__0value.get();
  (f0.t0=this->m__0head.get()->m__0succ.get())->m_Remove();
  return f0.l_value;
}

bbInt t_std_collections_List_1Tt_default_Actor_2::m_RemoveEach(t_default_Actor* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Actor_2_Node* l_node{};
    void gcMark(){
      bbGCMark(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head.get()->m__0succ.get();
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head.get())){
    if((f0.l_node->m__0value.get()==l_value)){
      struct f2_t : public bbGCFrame{
        t_std_collections_List_1Tt_default_Actor_2_Node* t0{};
        void gcMark(){
          bbGCMark(t0);
        }
      }f2{};
      f0.l_node=f0.l_node->m__0succ.get();
      (f2.t0=f0.l_node->m__0pred.get())->m_Remove();
      l_n+=1;
    }else{
      f0.l_node=f0.l_node->m__0succ.get();
    }
  }
  return l_n;
}

bbBool t_std_collections_List_1Tt_default_Actor_2::m_Remove(t_default_Actor* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Actor_2_Node* l_node{};
    void gcMark(){
      bbGCMark(l_node);
    }
  }f0{};
  f0.l_node=this->m_FindNode(l_value);
  if(!bbBool(f0.l_node)){
    return false;
  }
  f0.l_node->m_Remove();
  return true;
}

t_std_collections_List_1Tt_default_Actor_2_Node* t_std_collections_List_1Tt_default_Actor_2::m_LastNode(){
  if(!this->m_Empty()){
    return this->m__0head.get()->m__0pred.get();
  }
  return ((t_std_collections_List_1Tt_default_Actor_2_Node*)0);
}

t_default_Actor* t_std_collections_List_1Tt_default_Actor_2::m_Last(){
  bbDebugAssert(!this->m_Empty(),bbString(L"Debug assert failed",19));
  return this->m__0head.get()->m__0pred.get()->m__0value.get();
}

t_std_collections_List_1Tt_default_Actor_2_Node* t_std_collections_List_1Tt_default_Actor_2::m_HeadNode(){
  return this->m__0head.get();
}

t_std_collections_List_1Tt_default_Actor_2_Node* t_std_collections_List_1Tt_default_Actor_2::m_FirstNode(){
  if(!this->m_Empty()){
    return this->m__0head.get()->m__0succ.get();
  }
  return ((t_std_collections_List_1Tt_default_Actor_2_Node*)0);
}

t_default_Actor* t_std_collections_List_1Tt_default_Actor_2::m_First(){
  bbDebugAssert(!this->m_Empty(),bbString(L"Debug assert failed",19));
  return this->m__0head.get()->m__0succ.get()->m__0value.get();
}

t_std_collections_List_1Tt_default_Actor_2_Node* t_std_collections_List_1Tt_default_Actor_2::m_FindNode(t_default_Actor* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Actor_2_Node* l_node{};
    void gcMark(){
      bbGCMark(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head.get()->m__0succ.get();
  while((f0.l_node!=this->m__0head.get())){
    if((f0.l_node->m__0value.get()==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0succ.get();
  }
  return ((t_std_collections_List_1Tt_default_Actor_2_Node*)0);
}

t_std_collections_List_1Tt_default_Actor_2_Node* t_std_collections_List_1Tt_default_Actor_2::m_FindLastNode(t_default_Actor* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Actor_2_Node* l_node{};
    void gcMark(){
      bbGCMark(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head.get()->m__0pred.get();
  while((f0.l_node!=this->m__0head.get())){
    if((f0.l_node->m__0value.get()==l_value)){
      return f0.l_node;
    }
    f0.l_node=f0.l_node->m__0pred.get();
  }
  return ((t_std_collections_List_1Tt_default_Actor_2_Node*)0);
}

bbBool t_std_collections_List_1Tt_default_Actor_2::m_Empty(){
  return (this->m__0head.get()->m__0succ.get()==this->m__0head.get());
}

bbInt t_std_collections_List_1Tt_default_Actor_2::m_Count(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Actor_2_Node* l_node{};
    void gcMark(){
      bbGCMark(l_node);
    }
  }f0{};
  f0.l_node=this->m__0head.get()->m__0succ.get();
  bbInt l_n=bbInt(0);
  while((f0.l_node!=this->m__0head.get())){
    f0.l_node=f0.l_node->m__0succ.get();
    l_n+=1;
  }
  return l_n;
}

void t_std_collections_List_1Tt_default_Actor_2::m_Clear(){
  this->m__0head.get()->m__0succ=this->m__0head.get();
  this->m__0head.get()->m__0pred=this->m__0head.get();
}

t_std_collections_List_1Tt_default_Actor_2_BackwardsIterator t_std_collections_List_1Tt_default_Actor_2::m_Backwards(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Actor_2_Node* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  return t_std_collections_List_1Tt_default_Actor_2_BackwardsIterator{this,f0.t0=this->m__0head.get()->m__0pred.get()};
}

t_std_collections_List_1Tt_default_Actor_2_Iterator t_std_collections_List_1Tt_default_Actor_2::m_All(){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Actor_2_Node* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  return t_std_collections_List_1Tt_default_Actor_2_Iterator{this,f0.t0=this->m__0head.get()->m__0succ.get()};
}

t_std_collections_List_1Tt_default_Actor_2_Node* t_std_collections_List_1Tt_default_Actor_2::m_AddLast(t_default_Actor* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Actor_2_Node* l_node{};
    t_std_collections_List_1Tt_default_Actor_2_Node* t0{};
    void gcMark(){
      bbGCMark(l_node);
      bbGCMark(t0);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_default_Actor_2_Node>(l_value,f0.t0=this->m__0head.get());
  return f0.l_node;
}

t_std_collections_List_1Tt_default_Actor_2_Node* t_std_collections_List_1Tt_default_Actor_2::m_AddFirst(t_default_Actor* l_value){
  struct f0_t : public bbGCFrame{
    t_std_collections_List_1Tt_default_Actor_2_Node* l_node{};
    t_std_collections_List_1Tt_default_Actor_2_Node* t0{};
    void gcMark(){
      bbGCMark(l_node);
      bbGCMark(t0);
    }
  }f0{};
  f0.l_node=bbGCNew<t_std_collections_List_1Tt_default_Actor_2_Node>(l_value,f0.t0=this->m__0head.get()->m__0succ.get());
  return f0.l_node;
}

void t_std_collections_List_1Tt_default_Actor_2::m_AddAll(bbArray<bbGCVar<t_default_Actor>> l_values){
  {
    bbInt l_0=bbInt(0);
    bbInt l_1=l_values.length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_default_Actor* l_value{};
        void gcMark(){
          bbGCMark(l_value);
        }
      }f2{};
      f2.l_value=l_values[l_0].get();
      this->m_AddLast(f2.l_value);
    }
  }
}

void t_std_collections_List_1Tt_default_Actor_2::m_Add(t_default_Actor* l_value){
  this->m_AddLast(l_value);
}

void mx2_gridshooter_std_collections_2list_init_f(){
}
