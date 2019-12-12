//
// Created by xylee on 2019/12/11.
//
#include <iostream>
#include <stdio.h>
#define  ElementType int
typedef struct LNode *List;
struct LNode{
    ElementType Data;
    List Next;
};
struct LNode L;
List Ptrl;
int Length(List Ptrl)
{
    List p = Ptrl;
    int j = 0;
    while (p){
        p = p->Next;
        j++;
    }
    return j;
}
List FindKth(int K,List Ptrl)
{
    List p = Ptrl;
    int i =1;
    while (p!=NULL && i<K){
        p = p->Next;
        i++;
    }
    if (i==K)return NULL;
}
List Find(ElementType X,List Ptrl)
{
    List p = Ptrl;
    while( p!=NULL && p->Data !=X)
        p = p->Next;
    return p;
}
List  Insert(ElementType X,int i,List Ptrl)
{
    List p,s;
    if(i == 1){
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = Ptrl;
        return s;
    }
    p = FindKth(i-1,Ptrl);
    if(p == NULL){
        printf("参数i错误。");
        return NULL;
    }
    else{
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
        return Ptrl;
    }

}
List Delete(int i,List Ptrl)
{
    List p,s;
    if(i ==1){
        s = Ptrl;
        if(Ptrl!=NULL)Ptrl = Ptrl->Next;
        else return NULL;
        free(s);
        return Ptrl;
    }
    p = FindKth(i-1,Ptrl);
    if(p == NULL ||p->Next ==NULL)
        printf("节点不存在,无法插入");
    else {
        s = p->Next;
        p->Next = s->Next;
        free(s);
        return Ptrl;
    }
}
