//
// Created by xylee on 2019/12/11.
//

#include <iostream>
#include <stdio.h>
#define  ElementType int
struct Node{
    ElementType Data;
    struct Node *Next;
};

struct QNode{
    struct Node *rear;
    struct Node *front;
};
typedef struct QNode *Queue;
Queue PtrQ;
