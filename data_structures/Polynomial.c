#include <stdio.h>
#include <stdlib.h>
/*
 * 练习内容：线性表部分
 * 结构：链表
 * 输入：分别两个数组，开头为非零项个数，接下来为系数和指数
 * 输出：两个数组的乘积以及和
 */
typedef struct PolyNode *Polynomial;
struct PolyNode{
    int coef;//系数
    int expon;//指数
    Polynomial link;//指向下一项的指针
};
void Attach(int c,int e,Polynomial *pRear);
Polynomial Add(Polynomial P1,Polynomial P2);
Polynomial ReadPoly();
Polynomial Mult(Polynomial P1,Polynomial P2);
void PrintPoly(Polynomial P);
Polynomial ReadPoly()
{
    Polynomial P,Rear,t;
    int c,e,N;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    scanf("%d",&N);
    P->link = NULL;
    Rear = P;
    while(N--){
        scanf("%d %d",&c,&e);
        Attach(c,e,&Rear);
    }
    t = P; P = P->link;free(t);//删除临时生成的头结点
    return P;
}
void Attach(int c,int e,Polynomial *pRear){
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = c;//对新节点赋值
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P;
    *pRear = P;//修改pRear的数值
}
Polynomial Add(Polynomial P1,Polynomial P2)
{
    Polynomial Rear,t,P;
    int sum;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    Rear = P;
    while(P1 && P2) {
        if (P1->expon == P2->expon) {
            sum = P1->coef + P2->coef;
            if (sum)Attach(sum, P1->expon, &Rear);
            P1 = P1->link;
            P2 = P2->link;

        } else if (P1->expon > P2->expon) {
            Attach(P1->coef, P1->expon, &Rear);
            P1 = P1->link;
        } else {
            Attach(P2->coef, P2->expon, &Rear);
            P2 = P2->link;
        }
    }
    while(P1){
        Attach(P1->coef,P1->expon,&Rear);
        P1 = P1->link;
    }
    while(P2){
        Attach(P2->coef,P2->coef,&Rear);
        P2 = P2->link;
    }
    Rear->link =NULL;
    t = P;
    P = P->link;
    free(t);

    return P;

}
Polynomial Mult(Polynomial P1,Polynomial P2)
{
    Polynomial P,Rear,t1,t2,t;
    int c,e,sum;
    if(!P1||!P2)return NULL;
    t1 = P1;t2 = P2;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    Rear = P;
    while(t2){
        /*先用P1的第一项乘以P*/
        sum = t1->coef*t2->coef;
//        if(sum==0)break;
        Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
        t2 = t2->link;
    }
    t1 = t1->link;

    while(t1){
        t2 = P2;Rear = P;
        while(t2) {
            e = t1->expon + t2->expon;
            c = t1->coef * t2->coef;
            while (Rear->link && Rear->link->expon > e)
                Rear = Rear->link;
            if (Rear->link && Rear->link->expon == e) {
                if (Rear->link->coef + c) {
                    Rear->link->coef += c;
                } else {
                    t = Rear->link;
                    Rear->link = t->link;
                    free(t);
                }
            } else {
                t = (Polynomial) malloc(sizeof(struct PolyNode));
                t->coef = c;
                t->expon = e;
                t->link = Rear->link;
                Rear->link = t;
                Rear = Rear->link;
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }

    t2 =P;P = P->link;free(t2);
    return P;
}
void PrintPoly(Polynomial P){
    //输出多项式
    int flag = 0;
    if(!P){printf("0 0\n");return;}
    while(P){
        if(!flag)
            flag =1 ;
        else
            printf(" ");
        if(P->coef==0)printf("0 0");
        else
            printf("%d %d",P->coef,P->expon);
        P =P->link;
    }

}
int main() {
    Polynomial P1,P2,PP,PS;
    P1 = ReadPoly();
    P2 = ReadPoly();
    PP = Mult(P1,P2);
    PrintPoly(PP);
    printf("\n");
    PS = Add(P1,P2);
    PrintPoly(PS);

    return 0;
}
