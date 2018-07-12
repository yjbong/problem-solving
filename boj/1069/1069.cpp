#include <stdio.h>
#include <math.h>
double min2(double a, double b){
    if(a<b) return a;
    else return b;
}
int main(void){

    long long x,y,d,t;
    double curt,mint,dist,tmp;

    while(scanf("%lld %lld %lld %lld", &x,&y,&d,&t)==4){
        dist=sqrt(x*x+y*y);
        if(d==t || d/t==0) mint=dist;
        else{
            tmp=dist;
            mint=-1.0;
            curt=0.0;
            while(1){
                if(tmp<2*d){
                    if(mint<0.0 || mint>curt+2*t) mint=curt+2*t;
                }
                if(tmp-d>=0.0){
                    tmp-=d;
                    curt+=t;
                }
                else break;
            }
            curt+=min2(2*t,min2(t+d-tmp, tmp));
            if(mint<0.0 || mint>curt) mint=curt;
        }
        printf("%.13lf\n",mint);
    }
    return 0;
}