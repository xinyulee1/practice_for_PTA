//
// Created by xylee on 2019/12/11.
//
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 )
{
    List p1,p2,p,L;
    L = (List) malloc(sizeof(PtrToNode));
    p1 =L1->Next;
    p2 =L2->Next;
    p = L;
    while(p1 != NULL&&p2 !=NULL)
    {
        if(p1->Data <= p2->Data)
        {
            p->Next = p1;
            p = p1;
            p1 = p1->Next;
        }
        else
        {
            p->Next = p2;
            p = p2;
            p2 = p2->Next;
        }
    }
    p->Next = p1?p1:p2;
    L1->Next = NULL;
    L2->Next = NULL;
    return L;

}

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}
void Print(List L){
//	此函数的作用：打印链表中的元素
    List P=L->Next;
    if(P!=NULL)
    {
        List r;
        r = L;
        while(r->Next)
        {
            r = r->Next;
            printf("%d ",r->Data);
        }
    }
    else
    {
        printf("NULL");
    }
    printf("\n");
};
List Read()
{
    int n;
    scanf("%d",&n);
    List L = (List) malloc(sizeof(PtrToNode));
    L->Next = NULL;
    if(n !=0){
        List r = L;
        for (int i = 0; i < n ; ++i) {
            List p=(List)malloc(sizeof(struct Node));
            scanf("%d",&(p->Data));
            p->Next =NULL;
            r->Next = p;
            r = p;
        }
    }
    return L;
}
