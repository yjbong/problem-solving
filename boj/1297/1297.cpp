#include <stdio.h>
#include <math.h>
int main(void){
    int a,b,c;
    double k;
    int h,w;
    scanf("%d %d %d", &a, &b, &c);
    k=a/sqrt(b*b+c*c);
    h=(int)(b*k);
    w=(int)(c*k);
    printf("%d %d\n", h, w);
    return 0;
}