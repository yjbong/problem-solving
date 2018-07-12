#include <stdio.h>
int abs2(int a){
    if(a<0) return (-a);
    else return a;
}
int main(void){
    int num1,num2;
    int r1,c1,r2,c2,sol;
    scanf("%d %d",&num1,&num2);
    c1=(num1-1)%4,c2=(num2-1)%4;
    r1=(num1-1)/4;r2=(num2-1)/4;
    sol=abs2(c1-c2)+abs2(r1-r2);
    printf("%d\n",sol);
    return 0;
}