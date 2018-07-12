#include <stdio.h>
typedef struct _point{
    long long x;
    long long y;
}POINT;
long long b[50];

int ccw(POINT p0, POINT p1, POINT p2){

    long long tmp=(p0.x*p1.y+p1.x*p2.y+p2.x*p0.y)-(p1.x*p0.y+p2.x*p1.y+p0.x*p2.y);
    if(tmp==0) return 0;
    else if(tmp>0) return 1;
    else return -1;
}

int main(void){

    long long i,j,k,n,max,cur,ok;
    POINT p0,p1,p2;
    scanf("%lld",&n);
    for(i=0; i<n; i++) scanf("%lld",&b[i]);
    max=0;
    for(i=0; i<n; i++){
        cur=0;
        for(j=0; j<i; j++){
            ok=1;
            for(k=j+1; k<i; k++){
                p0.x=j, p0.y=b[j];
                p1.x=k, p1.y=b[k];
                p2.x=i, p2.y=b[i];
                if(ccw(p0,p1,p2)<=0){
                    ok=0;
                    break;
                }
            }
            if(ok) cur++;
        }
        for(j=i+1; j<n; j++){
            ok=1;
            for(k=i+1; k<j; k++){
                p0.x=j, p0.y=b[j];
                p1.x=k, p1.y=b[k];
                p2.x=i, p2.y=b[i];
                if(ccw(p0,p1,p2)>=0){
                    ok=0;
                    break;
                }
            }
            if(ok) cur++;
        }
        if(max<cur) max=cur;
    }
    printf("%lld\n",max);
    return 0;
}