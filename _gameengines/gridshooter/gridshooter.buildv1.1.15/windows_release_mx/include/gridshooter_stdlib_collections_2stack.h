
#ifndef MX2_GRIDSHOOTER_STDLIB_COLLECTIONS_2STACK_H
#define MX2_GRIDSHOOTER_STDLIB_COLLECTIONS_2STACK_H

#include <bbmonkey.h>
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_collections_2stack.h"

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_stdlib_collections_2container.h"
#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_types.h"

BB_CLASS(t_default_Actor)
BB_CLASS(t_default_Bullet)
BB_CLASS(t_stdlib_collections_Deque_1Tt_default_Actor_2)
BB_CLASS(t_stdlib_collections_Deque_1Tt_default_Bullet_2)
BB_CLASS(t_stdlib_collections_List_1Tt_default_Actor_2)
BB_CLASS(t_stdlib_collections_List_1Tt_default_Bullet_2)

BB_STRUCT(t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator)
BB_STRUCT(t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator)
BB_CLASS(t_stdlib_collections_Stack_1Tt_default_Bullet_2)
BB_STRUCT(t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator)
BB_STRUCT(t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator)
BB_CLASS(t_stdlib_collections_Stack_1Tt_default_Actor_2)

void g_stdlib_collections_Stack_1Tt_default_Actor_2_AddAll_1Tt_stdlib_collections_List_1Tt_default_Actor_2_2(t_stdlib_collections_Stack_1Tt_default_Actor_2* l_self,t_stdlib_collections_List_1Tt_default_Actor_2* l_values);
void g_stdlib_collections_Stack_1Tt_default_Bullet_2_AddAll_1Tt_stdlib_collections_List_1Tt_default_Bullet_2_2(t_stdlib_collections_Stack_1Tt_default_Bullet_2* l_self,t_stdlib_collections_List_1Tt_default_Bullet_2* l_values);

struct t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator{
  typedef t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator bb_struct_type;
  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator";}

  bbGCVar<t_stdlib_collections_Stack_1Tt_default_Bullet_2> m__0stack{};
  bbInt m__0index{};

  t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator(t_stdlib_collections_Stack_1Tt_default_Bullet_2* l_stack,bbInt l_index);
  ~t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator();

  void m_Insert(t_default_Bullet* l_value);
  void m_Erase();
  void m_Current(t_default_Bullet* l_current);
  t_default_Bullet* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertCurrent();

  t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator(){
  }

  t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator&x,const t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator&y);

void bbGCMark(const t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator&);

struct t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator{
  typedef t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator bb_struct_type;
  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator";}

  bbGCVar<t_stdlib_collections_Stack_1Tt_default_Bullet_2> m__0stack{};
  bbInt m__0index{};

  t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator(t_stdlib_collections_Stack_1Tt_default_Bullet_2* l_stack,bbInt l_index);
  ~t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator();

  void m_Insert(t_default_Bullet* l_value);
  void m_Erase();
  void m_Current(t_default_Bullet* l_current);
  t_default_Bullet* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertCurrent();

  t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator(){
  }

  t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator&x,const t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator&y);

void bbGCMark(const t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator&);

struct t_stdlib_collections_Stack_1Tt_default_Bullet_2 : public bbObject,public virtual t_stdlib_collections_IContainer_1Tt_default_Bullet_2{
  typedef t_stdlib_collections_Stack_1Tt_default_Bullet_2 *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_stdlib_collections_Stack_1Tt_default_Bullet_2";}

  bbArray<bbGCVar<t_default_Bullet>> m__0data{};
  bbInt m__0length{};

  void gcMark();

  t_stdlib_collections_Stack_1Tt_default_Bullet_2(t_stdlib_collections_Stack_1Tt_default_Bullet_2* l_values);
  t_stdlib_collections_Stack_1Tt_default_Bullet_2(t_stdlib_collections_Deque_1Tt_default_Bullet_2* l_values);
  t_stdlib_collections_Stack_1Tt_default_Bullet_2(t_stdlib_collections_List_1Tt_default_Bullet_2* l_values);
  t_stdlib_collections_Stack_1Tt_default_Bullet_2(bbArray<bbGCVar<t_default_Bullet>> l_values);
  t_stdlib_collections_Stack_1Tt_default_Bullet_2(bbInt l_length);
  t_stdlib_collections_Stack_1Tt_default_Bullet_2();
  ~t_stdlib_collections_Stack_1Tt_default_Bullet_2();

  void m__idxeq(bbInt l_index,t_default_Bullet* l_value);
  t_default_Bullet* m__idx(bbInt l_index);
  t_default_Bullet* m_Top();
  bbArray<bbGCVar<t_default_Bullet>> m_ToArray();
  void m_Swap(t_stdlib_collections_Stack_1Tt_default_Bullet_2* l_stack);
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_default_Bullet*,t_default_Bullet*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_default_Bullet*,t_default_Bullet*)> l_compareFunc);
  void m_Sort(bbInt l_ascending);
  t_stdlib_collections_Stack_1Tt_default_Bullet_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_stdlib_collections_Stack_1Tt_default_Bullet_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_default_Bullet* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_default_Bullet* l_value,bbInt l_start);
  bbInt m_RemoveIf(bbFunction<bbBool(t_default_Bullet*)> l_condition);
  bbInt m_RemoveEach(t_default_Bullet* l_value);
  bbBool m_Remove(t_default_Bullet* l_value,bbInt l_start);
  void m_Push(t_default_Bullet* l_value);
  t_default_Bullet* m_Pop();

  bbInt m_Length(){
    return this->m__0length;
  }
  void m_Insert(bbInt l_index,t_default_Bullet* l_value);
  t_default_Bullet* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_default_Bullet* l_value,bbInt l_start);
  bbInt m_FindIndex(t_default_Bullet* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_default_Bullet>> m_Data();
  bbBool m_Contains(t_default_Bullet* l_value);
  void m_Compact();
  void m_Clear();
  bbInt m_Capacity();
  t_stdlib_collections_Stack_1Tt_default_Bullet_2_BackwardsIterator m_Backwards();
  t_stdlib_collections_Stack_1Tt_default_Bullet_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_default_Bullet>> l_values);
  void m_Add(t_default_Bullet* l_value);
};

struct t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator{
  typedef t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator bb_struct_type;
  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator";}

  bbGCVar<t_stdlib_collections_Stack_1Tt_default_Actor_2> m__0stack{};
  bbInt m__0index{};

  t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator(t_stdlib_collections_Stack_1Tt_default_Actor_2* l_stack,bbInt l_index);
  ~t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator();

  void m_Insert(t_default_Actor* l_value);
  void m_Erase();
  void m_Current(t_default_Actor* l_current);
  t_default_Actor* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertCurrent();

  t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator(){
  }

  t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator&x,const t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator&y);

void bbGCMark(const t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator&);

struct t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator{
  typedef t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator bb_struct_type;
  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator";}

  bbGCVar<t_stdlib_collections_Stack_1Tt_default_Actor_2> m__0stack{};
  bbInt m__0index{};

  t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator(t_stdlib_collections_Stack_1Tt_default_Actor_2* l_stack,bbInt l_index);
  ~t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator();

  void m_Insert(t_default_Actor* l_value);
  void m_Erase();
  void m_Current(t_default_Actor* l_current);
  t_default_Actor* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertCurrent();

  t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator(){
  }

  t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator&x,const t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator&y);

void bbGCMark(const t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator&);

struct t_stdlib_collections_Stack_1Tt_default_Actor_2 : public bbObject,public virtual t_stdlib_collections_IContainer_1Tt_default_Actor_2{
  typedef t_stdlib_collections_Stack_1Tt_default_Actor_2 *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_stdlib_collections_Stack_1Tt_default_Actor_2";}

  bbArray<bbGCVar<t_default_Actor>> m__0data{};
  bbInt m__0length{};

  void gcMark();

  t_stdlib_collections_Stack_1Tt_default_Actor_2(t_stdlib_collections_Stack_1Tt_default_Actor_2* l_values);
  t_stdlib_collections_Stack_1Tt_default_Actor_2(t_stdlib_collections_Deque_1Tt_default_Actor_2* l_values);
  t_stdlib_collections_Stack_1Tt_default_Actor_2(t_stdlib_collections_List_1Tt_default_Actor_2* l_values);
  t_stdlib_collections_Stack_1Tt_default_Actor_2(bbArray<bbGCVar<t_default_Actor>> l_values);
  t_stdlib_collections_Stack_1Tt_default_Actor_2(bbInt l_length);
  t_stdlib_collections_Stack_1Tt_default_Actor_2();
  ~t_stdlib_collections_Stack_1Tt_default_Actor_2();

  void m__idxeq(bbInt l_index,t_default_Actor* l_value);
  t_default_Actor* m__idx(bbInt l_index);
  t_default_Actor* m_Top();
  bbArray<bbGCVar<t_default_Actor>> m_ToArray();
  void m_Swap(t_stdlib_collections_Stack_1Tt_default_Actor_2* l_stack);
  void m_Swap(bbInt l_index1,bbInt l_index2);
  void m_Sort(bbFunction<bbInt(t_default_Actor*,t_default_Actor*)> l_compareFunc,bbInt l_lo,bbInt l_hi);
  void m_Sort(bbFunction<bbInt(t_default_Actor*,t_default_Actor*)> l_compareFunc);
  void m_Sort(bbInt l_ascending);
  t_stdlib_collections_Stack_1Tt_default_Actor_2* m_Slice(bbInt l_index1,bbInt l_index2);
  t_stdlib_collections_Stack_1Tt_default_Actor_2* m_Slice(bbInt l_index);
  void m_Set(bbInt l_index,t_default_Actor* l_value);
  void m_Resize(bbInt l_length);
  void m_Reserve(bbInt l_capacity);
  bbBool m_RemoveLast(t_default_Actor* l_value,bbInt l_start);
  bbInt m_RemoveIf(bbFunction<bbBool(t_default_Actor*)> l_condition);
  bbInt m_RemoveEach(t_default_Actor* l_value);
  bbBool m_Remove(t_default_Actor* l_value,bbInt l_start);
  void m_Push(t_default_Actor* l_value);
  t_default_Actor* m_Pop();

  bbInt m_Length(){
    return this->m__0length;
  }
  void m_Insert(bbInt l_index,t_default_Actor* l_value);
  t_default_Actor* m_Get(bbInt l_index);
  bbInt m_FindLastIndex(t_default_Actor* l_value,bbInt l_start);
  bbInt m_FindIndex(t_default_Actor* l_value,bbInt l_start);
  void m_Erase(bbInt l_index1,bbInt l_index2);
  void m_Erase(bbInt l_index);
  bbBool m_Empty();
  bbArray<bbGCVar<t_default_Actor>> m_Data();
  bbBool m_Contains(t_default_Actor* l_value);
  void m_Compact();
  void m_Clear();
  bbInt m_Capacity();
  t_stdlib_collections_Stack_1Tt_default_Actor_2_BackwardsIterator m_Backwards();
  t_stdlib_collections_Stack_1Tt_default_Actor_2_Iterator m_All();
  void m_AddAll(bbArray<bbGCVar<t_default_Actor>> l_values);
  void m_Add(t_default_Actor* l_value);
};

#endif
