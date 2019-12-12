//
// Created by xylee on 2019/12/11.
//
#include <iostream>
#include <stdio.h>
#define ElementType int
#define MAXSIZE 100

typedef struct SNode *Stack;
struct SNode{
    ElementType Data[MAXSIZE];
    int Top;
};
void Push(Stack Ptrs,ElementType item)
{
    if(Ptrs->Top ==MAXSIZE-1){
        printf("堆栈满");return;
    }else{
        Ptrs->Data[++(Ptrs->Top)] = item;
        return;
    }
}
ElementType Pop(Stack Ptrs)
{
    if(Ptrs->Top ==-1){
        printf("堆栈空");
        return false;
    }else
        return(Ptrs->Data[(Ptrs->Top)--]);
}
