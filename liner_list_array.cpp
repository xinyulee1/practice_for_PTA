//
// Created by xylee on 2019/12/11.
//

#include <iostream>
#include <stdio.h>
#define ElementType int
#define MAXSIZE 100

typedef struct LNode *List;
struct LNode{
    ElementType Data[MAXSIZE];
    int Last;
};
struct LNode L;
List Ptrl;
List MakeEmpty()
//新建一个空表
{
    List Ptrl;
    Ptrl = (List)malloc(sizeof(struct LNode));
    Ptrl->Last = -1;
    return Ptrl;
}
int Find(ElementType X, List Ptrl)
{
    int i = 0;
    while(i<=Ptrl->Last && Ptrl->Data[i] !=X)
        i++;
    if(i >Ptrl->Last) return -1;
    else return i;
}
void Insert(ElementType X, int i ,List Ptrl)
{
    int j;
    if(Ptrl->Last ==MAXSIZE-1){
        printf("表满");
        return;
    }
    if(i <1 || i>Ptrl->Last+2){
        printf("位置不合法");
    }
    for(j = Ptrl->Last -1;j>=i-1;j--)
        Ptrl->Data[j+1] = Ptrl->Data[j];
    Ptrl->Data[i-1] = X;
    Ptrl->Last++;
    return;
}
void Delete(int i, List Ptrl)
{
    int j;
    if(i < 1||i >Ptrl->Last+1){
        printf("不存在第%d个元素",i);
        return;
    }
    for(j = i;j<=Ptrl->Last;j++)
        Ptrl->Data[j-1] = Ptrl->Data[j];
    Ptrl->Last--;
    return;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
