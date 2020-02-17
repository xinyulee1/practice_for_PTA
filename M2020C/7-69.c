// change
#include <stdio.h>
int main () {
    int d1,d3,r;
    int n,x,count =0,total = 0;
    scanf("%d",&n);
    x = n-8;
    for (int i = x/5; i >=0  ; --i)
    {
        d1 = x-5*i;
        for (int j = d1/2; j >=0 ; --j)
        {
            d3 = d1-2*j;
            printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n",1+i,1+j,1+d3,3+i+j+d3);
            count++;
        }
    }
    printf("count = %d\n",count);
    return 0;
}
