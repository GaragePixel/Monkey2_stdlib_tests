
#ifndef MX2_GRIDSHOOTER_STDLIB_COLLECTIONS_2LIST_H
#define MX2_GRIDSHOOTER_STDLIB_COLLECTIONS_2LIST_H

#include <bbmonkey.h>
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_collections_2list.h"

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_stdlib_collections_2container.h"
#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_types.h"

BB_CLASS(t_default_Actor)
BB_CLASS(t_default_Bullet)
BB_CLASS(t_stdlib_collections_Stack_1Tt_default_Actor_2)
BB_CLASS(t_stdlib_collections_Stack_1Tt_default_Bullet_2)

BB_CLASS(t_stdlib_collections_List_1Tt_default_Bullet_2_Node)
BB_STRUCT(t_stdlib_collections_List_1Tt_default_Bullet_2_Iterator)
BB_STRUCT(t_stdlib_collections_List_1Tt_default_Bullet_2_BackwardsIterator)
BB_CLASS(t_stdlib_collections_List_1Tt_default_Bullet_2)
BB_CLASS(t_stdlib_collections_List_1Tt_default_Actor_2_Node)
BB_STRUCT(t_stdlib_collections_List_1Tt_default_Actor_2_Iterator)
BB_STRUCT(t_stdlib_collections_List_1Tt_default_Actor_2_BackwardsIterator)
BB_CLASS(t_stdlib_collections_List_1Tt_default_Actor_2)

void g_stdlib_collections_List_1Tt_default_Actor_2_AddAll_1Tt_stdlib_collections_List_1Tt_default_Actor_2_2(t_stdlib_collections_List_1Tt_default_Actor_2* l_self,t_stdlib_collections_List_1Tt_default_Actor_2* l_values);
void g_stdlib_collections_List_1Tt_default_Actor_2_AddAll_1Tt_stdlib_collections_Stack_1Tt_default_Actor_2_2(t_stdlib_collections_List_1Tt_default_Actor_2* l_self,t_stdlib_collections_Stack_1Tt_default_Actor_2* l_values);
void g_stdlib_collections_List_1Tt_default_Bullet_2_AddAll_1Tt_stdlib_collections_List_1Tt_default_Bullet_2_2(t_stdlib_collections_List_1Tt_default_Bullet_2* l_self,t_stdlib_collections_List_1Tt_default_Bullet_2* l_values);
void g_stdlib_collections_List_1Tt_default_Bullet_2_AddAll_1Tt_stdlib_collections_Stack_1Tt_default_Bullet_2_2(t_stdlib_collections_List_1Tt_default_Bullet_2* l_self,t_stdlib_collections_Stack_1Tt_default_Bullet_2* l_values);

struct t_stdlib_collections_List_1Tt_default_Bullet_2_Node : public bbObject{
  typedef t_stdlib_collections_List_1Tt_default_Bullet_2_Node *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_stdlib_collections_List_1Tt_default_Bullet_2_Node";}

  bbGCVar<t_stdlib_collections_List_1Tt_default_Bullet_2_Node> m__0succ{};
  bbGCVar<t_stdlib_collections_List_1Tt_default_Bullet_2_Node> m__0pred{};
  bbGCVar<t_default_Bullet> m__0value{};

  void gcMark();

  t_stdlib_collections_List_1Tt_default_Bullet_2_Node(t_default_Bullet* l_value,t_stdlib_collections_List_1Tt_default_Bullet_2_Node* l_succ);
  t_stdlib_collections_List_1Tt_default_Bullet_2_Node(t_default_Bullet* l_value);
  ~t_stdlib_collections_List_1Tt_default_Bullet_2_Node();

  void m_Value(t_default_Bullet* l_value);
  t_default_Bullet* m_Value();
  t_stdlib_collections_List_1Tt_default_Bullet_2_Node* m_Succ();
  void m_Remove();
  t_stdlib_collections_List_1Tt_default_Bullet_2_Node* m_Pred();
  void m_InsertBefore(t_stdlib_collections_List_1Tt_default_Bullet_2_Node* l_node);
  void m_InsertAfter(t_stdlib_collections_List_1Tt_default_Bullet_2_Node* l_node);

  t_stdlib_collections_List_1Tt_default_Bullet_2_Node(){
  }
};

struct t_stdlib_collections_List_1Tt_default_Bullet_2_Iterator{
  typedef t_stdlib_collections_List_1Tt_default_Bullet_2_Iterator bb_struct_type;
  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_stdlib_collections_List_1Tt_default_Bullet_2_Iterator";}

  bbGCVar<t_stdlib_collections_List_1Tt_default_Bullet_2> m__0list{};
  bbGCVar<t_stdlib_collections_List_1Tt_default_Bullet_2_Node> m__0node{};

  t_stdlib_collections_List_1Tt_default_Bullet_2_Iterator(t_stdlib_collections_List_1Tt_default_Bullet_2* l_list,t_stdlib_collections_List_1Tt_default_Bullet_2_Node* l_node);
  ~t_stdlib_collections_List_1Tt_default_Bullet_2_Iterator();

  void m_Insert(t_default_Bullet* l_value);
  void m_Erase();
  void m_Current(t_default_Bullet* l_current);
  t_default_Bullet* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertCurrent();

  t_stdlib_collections_List_1Tt_default_Bullet_2_Iterator(){
  }

  t_stdlib_collections_List_1Tt_default_Bullet_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_stdlib_collections_List_1Tt_default_Bullet_2_Iterator&x,const t_stdlib_collections_List_1Tt_default_Bullet_2_Iterator&y);

void bbGCMark(const t_stdlib_collections_List_1Tt_default_Bullet_2_Iterator&);

struct t_stdlib_collections_List_1Tt_default_Bullet_2_BackwardsIterator{
  typedef t_stdlib_collections_List_1Tt_default_Bullet_2_BackwardsIterator bb_struct_type;
  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_stdlib_collections_List_1Tt_default_Bullet_2_BackwardsIterator";}

  bbGCVar<t_stdlib_collections_List_1Tt_default_Bullet_2> m__0list{};
  bbGCVar<t_stdlib_collections_List_1Tt_default_Bullet_2_Node> m__0node{};

  t_stdlib_collections_List_1Tt_default_Bullet_2_BackwardsIterator(t_stdlib_collections_List_1Tt_default_Bullet_2* l_list,t_stdlib_collections_List_1Tt_default_Bullet_2_Node* l_node);
  ~t_stdlib_collections_List_1Tt_default_Bullet_2_BackwardsIterator();

  void m_Insert(t_default_Bullet* l_value);
  void m_Erase();
  void m_Current(t_default_Bullet* l_current);
  t_default_Bullet* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertCurrent();

  t_stdlib_collections_List_1Tt_default_Bullet_2_BackwardsIterator(){
  }

  t_stdlib_collections_List_1Tt_default_Bullet_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_stdlib_collections_List_1Tt_default_Bullet_2_BackwardsIterator&x,const t_stdlib_collections_List_1Tt_default_Bullet_2_BackwardsIterator&y);

void bbGCMark(const t_stdlib_collections_List_1Tt_default_Bullet_2_BackwardsIterator&);

struct t_stdlib_collections_List_1Tt_default_Bullet_2 : public bbObject,public virtual t_stdlib_collections_IContainer_1Tt_default_Bullet_2{
  typedef t_stdlib_collections_List_1Tt_default_Bullet_2 *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_stdlib_collections_List_1Tt_default_Bullet_2";}

  bbGCVar<t_stdlib_collections_List_1Tt_default_Bullet_2_Node> m__0head{};

  void gcMark();

  t_stdlib_collections_List_1Tt_default_Bullet_2(t_stdlib_collections_List_1Tt_default_Bullet_2* l_values);
  t_stdlib_collections_List_1Tt_default_Bullet_2(t_stdlib_collections_Stack_1Tt_default_Bullet_2* l_values);
  t_stdlib_collections_List_1Tt_default_Bullet_2(bbArray<bbGCVar<t_default_Bullet>> l_values);
  t_stdlib_collections_List_1Tt_default_Bullet_2();
  ~t_stdlib_collections_List_1Tt_default_Bullet_2();

  bbArray<bbGCVar<t_default_Bullet>> m_ToArray();
  void m_Sort(bbFunction<bbInt(t_default_Bullet*,t_default_Bullet*)> l_compareFunc);
  void m_Sort(bbInt l_ascending);
  t_default_Bullet* m_RemoveLast();
  bbBool m_RemoveLast(t_default_Bullet* l_value);
  bbInt m_RemoveIf(bbFunction<bbBool(t_default_Bullet*)> l_condition);
  t_default_Bullet* m_RemoveFirst();
  bbInt m_RemoveEach(t_default_Bullet* l_value);
  bbBool m_Remove(t_default_Bullet* l_value);
  t_stdlib_collections_List_1Tt_default_Bullet_2_Node* m_LastNode();
  t_default_Bullet* m_Last();
  t_stdlib_collections_List_1Tt_default_Bullet_2_Node* m_HeadNode();
  t_stdlib_collections_List_1Tt_default_Bullet_2_Node* m_FirstNode();
  t_default_Bullet* m_First();
  t_stdlib_collections_List_1Tt_default_Bullet_2_Node* m_FindNode(t_default_Bullet* l_value);
  t_stdlib_collections_List_1Tt_default_Bullet_2_Node* m_FindLastNode(t_default_Bullet* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_stdlib_collections_List_1Tt_default_Bullet_2_BackwardsIterator m_Backwards();
  t_stdlib_collections_List_1Tt_default_Bullet_2_Iterator m_All();
  t_stdlib_collections_List_1Tt_default_Bullet_2_Node* m_AddLast(t_default_Bullet* l_value);
  t_stdlib_collections_List_1Tt_default_Bullet_2_Node* m_AddFirst(t_default_Bullet* l_value);
  void m_AddAll(bbArray<bbGCVar<t_default_Bullet>> l_values);
  void m_Add(t_default_Bullet* l_value);
};

struct t_stdlib_collections_List_1Tt_default_Actor_2_Node : public bbObject{
  typedef t_stdlib_collections_List_1Tt_default_Actor_2_Node *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_stdlib_collections_List_1Tt_default_Actor_2_Node";}

  bbGCVar<t_stdlib_collections_List_1Tt_default_Actor_2_Node> m__0succ{};
  bbGCVar<t_stdlib_collections_List_1Tt_default_Actor_2_Node> m__0pred{};
  bbGCVar<t_default_Actor> m__0value{};

  void gcMark();

  t_stdlib_collections_List_1Tt_default_Actor_2_Node(t_default_Actor* l_value,t_stdlib_collections_List_1Tt_default_Actor_2_Node* l_succ);
  t_stdlib_collections_List_1Tt_default_Actor_2_Node(t_default_Actor* l_value);
  ~t_stdlib_collections_List_1Tt_default_Actor_2_Node();

  void m_Value(t_default_Actor* l_value);
  t_default_Actor* m_Value();
  t_stdlib_collections_List_1Tt_default_Actor_2_Node* m_Succ();
  void m_Remove();
  t_stdlib_collections_List_1Tt_default_Actor_2_Node* m_Pred();
  void m_InsertBefore(t_stdlib_collections_List_1Tt_default_Actor_2_Node* l_node);
  void m_InsertAfter(t_stdlib_collections_List_1Tt_default_Actor_2_Node* l_node);

  t_stdlib_collections_List_1Tt_default_Actor_2_Node(){
  }
};

struct t_stdlib_collections_List_1Tt_default_Actor_2_Iterator{
  typedef t_stdlib_collections_List_1Tt_default_Actor_2_Iterator bb_struct_type;
  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_stdlib_collections_List_1Tt_default_Actor_2_Iterator";}

  bbGCVar<t_stdlib_collections_List_1Tt_default_Actor_2> m__0list{};
  bbGCVar<t_stdlib_collections_List_1Tt_default_Actor_2_Node> m__0node{};

  t_stdlib_collections_List_1Tt_default_Actor_2_Iterator(t_stdlib_collections_List_1Tt_default_Actor_2* l_list,t_stdlib_collections_List_1Tt_default_Actor_2_Node* l_node);
  ~t_stdlib_collections_List_1Tt_default_Actor_2_Iterator();

  void m_Insert(t_default_Actor* l_value);
  void m_Erase();
  void m_Current(t_default_Actor* l_current);
  t_default_Actor* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertCurrent();

  t_stdlib_collections_List_1Tt_default_Actor_2_Iterator(){
  }

  t_stdlib_collections_List_1Tt_default_Actor_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_stdlib_collections_List_1Tt_default_Actor_2_Iterator&x,const t_stdlib_collections_List_1Tt_default_Actor_2_Iterator&y);

void bbGCMark(const t_stdlib_collections_List_1Tt_default_Actor_2_Iterator&);

struct t_stdlib_collections_List_1Tt_default_Actor_2_BackwardsIterator{
  typedef t_stdlib_collections_List_1Tt_default_Actor_2_BackwardsIterator bb_struct_type;
  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_stdlib_collections_List_1Tt_default_Actor_2_BackwardsIterator";}

  bbGCVar<t_stdlib_collections_List_1Tt_default_Actor_2> m__0list{};
  bbGCVar<t_stdlib_collections_List_1Tt_default_Actor_2_Node> m__0node{};

  t_stdlib_collections_List_1Tt_default_Actor_2_BackwardsIterator(t_stdlib_collections_List_1Tt_default_Actor_2* l_list,t_stdlib_collections_List_1Tt_default_Actor_2_Node* l_node);
  ~t_stdlib_collections_List_1Tt_default_Actor_2_BackwardsIterator();

  void m_Insert(t_default_Actor* l_value);
  void m_Erase();
  void m_Current(t_default_Actor* l_current);
  t_default_Actor* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertCurrent();

  t_stdlib_collections_List_1Tt_default_Actor_2_BackwardsIterator(){
  }

  t_stdlib_collections_List_1Tt_default_Actor_2_BackwardsIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_stdlib_collections_List_1Tt_default_Actor_2_BackwardsIterator&x,const t_stdlib_collections_List_1Tt_default_Actor_2_BackwardsIterator&y);

void bbGCMark(const t_stdlib_collections_List_1Tt_default_Actor_2_BackwardsIterator&);

struct t_stdlib_collections_List_1Tt_default_Actor_2 : public bbObject,public virtual t_stdlib_collections_IContainer_1Tt_default_Actor_2{
  typedef t_stdlib_collections_List_1Tt_default_Actor_2 *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_stdlib_collections_List_1Tt_default_Actor_2";}

  bbGCVar<t_stdlib_collections_List_1Tt_default_Actor_2_Node> m__0head{};

  void gcMark();

  t_stdlib_collections_List_1Tt_default_Actor_2(t_stdlib_collections_List_1Tt_default_Actor_2* l_values);
  t_stdlib_collections_List_1Tt_default_Actor_2(t_stdlib_collections_Stack_1Tt_default_Actor_2* l_values);
  t_stdlib_collections_List_1Tt_default_Actor_2(bbArray<bbGCVar<t_default_Actor>> l_values);
  t_stdlib_collections_List_1Tt_default_Actor_2();
  ~t_stdlib_collections_List_1Tt_default_Actor_2();

  bbArray<bbGCVar<t_default_Actor>> m_ToArray();
  void m_Sort(bbFunction<bbInt(t_default_Actor*,t_default_Actor*)> l_compareFunc);
  void m_Sort(bbInt l_ascending);
  t_default_Actor* m_RemoveLast();
  bbBool m_RemoveLast(t_default_Actor* l_value);
  bbInt m_RemoveIf(bbFunction<bbBool(t_default_Actor*)> l_condition);
  t_default_Actor* m_RemoveFirst();
  bbInt m_RemoveEach(t_default_Actor* l_value);
  bbBool m_Remove(t_default_Actor* l_value);
  t_stdlib_collections_List_1Tt_default_Actor_2_Node* m_LastNode();
  t_default_Actor* m_Last();
  t_stdlib_collections_List_1Tt_default_Actor_2_Node* m_HeadNode();
  t_stdlib_collections_List_1Tt_default_Actor_2_Node* m_FirstNode();
  t_default_Actor* m_First();
  t_stdlib_collections_List_1Tt_default_Actor_2_Node* m_FindNode(t_default_Actor* l_value);
  t_stdlib_collections_List_1Tt_default_Actor_2_Node* m_FindLastNode(t_default_Actor* l_value);
  bbBool m_Empty();
  bbInt m_Count();
  void m_Clear();
  t_stdlib_collections_List_1Tt_default_Actor_2_BackwardsIterator m_Backwards();
  t_stdlib_collections_List_1Tt_default_Actor_2_Iterator m_All();
  t_stdlib_collections_List_1Tt_default_Actor_2_Node* m_AddLast(t_default_Actor* l_value);
  t_stdlib_collections_List_1Tt_default_Actor_2_Node* m_AddFirst(t_default_Actor* l_value);
  void m_AddAll(bbArray<bbGCVar<t_default_Actor>> l_values);
  void m_Add(t_default_Actor* l_value);
};

#endif
