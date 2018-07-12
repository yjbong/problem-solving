#include <stdio.h>
typedef struct _point{
    long long x;
    long long y;
}POINT;

int ccw(POINT p0, POINT p1, POINT p2){

    long long tmp=(p0.x*p1.y+p1.x*p2.y+p2.x*p0.y)-(p1.x*p0.y+p2.x*p1.y+p0.x*p2.y);
    if(tmp==0) return 0;
    else if(tmp>0) return 1;
    else return -1;
}

int main(void){

    POINT p0,p1,p2;
    long long d01,d12,d20,a,b,c,max;
    scanf("%lld %lld %lld %lld %lld %lld",&p0.x,&p0.y,&p1.x,&p1.y,&p2.x,&p2.y);
    if(ccw(p0,p1,p2)==0) printf("X\n");
    else{
        d01=(p1.x-p0.x)*(p1.x-p0.x)+(p1.y-p0.y)*(p1.y-p0.y);
        d12=(p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y);
        d20=(p0.x-p2.x)*(p0.x-p2.x)+(p0.y-p2.y)*(p0.y-p2.y);
        max=d01;
        if(max<d12) max=d12;
        if(max<d20) max=d20;

        if(max==d01) c=d01,a=d12,b=d20;
        else if(max==d12) c=d12,a=d01,b=d20;
        else if(max==d20) c=d20,a=d01,b=d12;

        if(a==b && b==c) printf("JungTriangle\n");
        else if(a==b || b==c || c==a){
            if(c>a+b) printf("Dunkak2Triangle\n");
            else if(c==a+b) printf("Jikkak2Triangle\n");
            else if(c<a+b) printf("Yeahkak2Triangle\n");
        }
        else{
            if(c>a+b) printf("DunkakTriangle\n");
            else if(c==a+b) printf("JikkakTriangle\n");
            else if(c<a+b) printf("YeahkakTriangle\n");
        }
    }
    return 0;
}