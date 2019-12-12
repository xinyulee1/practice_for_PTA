//
// Created by xylee on 2019/12/11.
//
#include <iostream>
#include <stdio.h>
#define  ElementType int
typedef struct SNode *Stack;
struct SNode{
    ElementType Data;
    struct SNode *Next;
};
Stack CreateStack()
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next =NULL;
    return S;
}
int IsEmpty(Stack S)
{
    return(S->Next ==NULL);
}
void Push(ElementType item, Stack S)
{
    struct SNode *TmpCell;
    TmpCell = (struct SNode *)malloc(sizeof(struct SNode));
    TmpCell->Data = item;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}
ElementType Pop(Stack S)
{
    struct SNode *FirstCell;
    ElementType TopElem;
    if(IsEmpty(S)){
        printf("堆栈空");return NULL;
    }else{
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        TopElem = FirstCell->Data;
        free(FirstCell);
        return TopElem;
    }
}
