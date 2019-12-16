//
// Created by xylee on 2019/12/15.
//
#include <stdio.h>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-function-declaration"
#define MaxTree 10
#define ElemenType int
//#define Position int
#define Tree int
#define Null -1
typedef struct Node *BinTree,*Position;
struct Node
{
    ElemenType data;
    Tree left;
    Tree right;
};
Position Find(ElemenType X,BinTree BST)
{
    while (BST)
    {
        if(X > BST->data)
            BST = BST->right;
        else if(X <BST->data)
            BST = BST->left;
        else
            return BST;
    }
    return NULL;
}
Position FindMin(BinTree BST)
{
    if(!BST) return NULL;
    else if(!BST->left)
        return BST;
    else
        return FindMin(BST->left);
}
Position FindMax(BinTree BST)
{
    if(BST)
        while (BST->right)BST = BST->right;

    return BST;
}
BinTree Insert(ElemenType X,BinTree BST)
{
    if(!BST)
    {
        BST =malloc(sizeof(struct Node));
        BST->data= X;
        BST->left = BST->right = NULL;
    }
    else
    {
        if(X < BST->data)
            return Insert(X,BST->left);
        else if(X > BST->data)
            return Insert(X,BST->right);
    }
    return BST;
}
#pragma clang diagnostic pop
BinTree Delete(ElemenType X,BinTree BST)
{
    Position Tmp;
    if( !BST ) printf("元素不存在");
    else if(X <BST->data)
        BST->left = Delete(X,BST->left);
    else if(X >BST->data)
        BST->right = Delete(X,BST->right);
    else
    {
        if(BST->left&&BST->right)
        {
            Tmp = FindMin(BST->right);
            BST->data = Tmp->data;
            BST->right = Delete(BST->data,BST->right);
        } else
        {
            Tmp = BST;
            if(!BST->left)
                BST = BST->right;
            else if(!BST->right)
                BST = BST->left;
            free(Tmp);
        }

    }
    return BST;
}
