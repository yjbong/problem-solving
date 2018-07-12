#include <stdio.h>
#include <math.h>

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

    POINT a,b,c;
    double d1,d2,d3,e1,e2,e3,min,max;
    scanf("%lld %lld %lld %lld %lld %lld",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
    if(ccw(a,b,c)==0) printf("-1\n");
    else{
        d1=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
        d2=sqrt((b.x-c.x)*(b.x-c.x)+(b.y-c.y)*(b.y-c.y));
        d3=sqrt((c.x-a.x)*(c.x-a.x)+(c.y-a.y)*(c.y-a.y));
        e1=2*(d1+d2);
        e2=2*(d2+d3);
        e3=2*(d3+d1);
        min=max=e1;
        if(min>e2) min=e2;
        if(max<e2) max=e2;
        if(min>e3) min=e3;
        if(max<e3) max=e3;
        printf("%.10lf\n",max-min);
    }
    return 0;
}