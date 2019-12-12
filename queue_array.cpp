//
// Created by xylee on 2019/12/11.
//
#include <iostream>
#include <stdio.h>
#define ElementType int
#define MAXSIZE 100

struct QNode{
    ElementType Data[MAXSIZE];
    int rear;
    int front;
};
typedef struct QNode *Queue;

Queue CreateQueue( int MaxSize )
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    Q->Front = Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}
//入队列
void AddQ(Queue PtrQ, ElementType item)
{
    if((PtrQ->rear+1)%MAXSIZE ==PtrQ->front){
        printf("队列满");
        return;
    }
    PtrQ->rear = (PtrQ->rear+1)%MAXSIZE;
    PtrQ->Data[PtrQ->rear] = item;
}
//出队列
ElementType DeleteQ(Queue PtrQ)
{
    if(PtrQ->front == PtrQ->rear){
        printf("队列空");
        return false;
    }else{
        PtrQ->front = (PtrQ->front + 1)%MAXSIZE;
        return PtrQ->Data[PtrQ->front];
    }
}

