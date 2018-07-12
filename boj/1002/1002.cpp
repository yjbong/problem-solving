#include <stdio.h>
#include <math.h>
int main(void){
        int cases;
        long double x1,y1,r1,x2,y2,r2;
        long double dst;
        int result;
        scanf("%d", &cases);
        while(cases--){
                scanf("%llf %llf %llf %llf %llf %llf", &x1,&y1,&r1,&x2,&y2,&r2);
                dst=(long double)sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
                if(dst==0){
                        if(fabs(r1-r2)==0) result=-1;
                        else result=0;
                }
                else{
                        if(r1+r2<dst) result=0;
                        else if(r1+r2==dst) result=1;
                        else{
                                if(fabs(r1-r2)<dst) result=2;
                                else if(fabs(r1-r2)==dst) result=1;
                                else result=0;
                        }
                }
                printf("%d\n", result);
        }
        return 0;
}