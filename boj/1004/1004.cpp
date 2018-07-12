#include <stdio.h>
#include <math.h>
#define MAX_CIRCLE 50
typedef struct _circle{
        long double x;
        long double y;
        long double r;
}CIRCLE;
int main(void){

        int i,j,cases;
        long double x[2],y[2];
        CIRCLE circle[MAX_CIRCLE];
        int in_circle[MAX_CIRCLE];
        int circles;
        int min_thru;
        long double dst;
        scanf("%d", &cases);
        while(cases--){
                scanf("%llf %llf %llf %llf", &x[0],&y[0],&x[1],&y[1]);
                scanf("%d", &circles);
                for(i=0; i<circles; i++)
                        scanf("%llf %llf %llf", &(circle[i].x), &(circle[i].y), &(circle[i].r));
                for(i=0; i<circles; i++) in_circle[i]=0;
                min_thru=0;

                for(i=0; i<2; i++){
                        for(j=0; j<circles; j++){
                                dst=(long double)sqrt((circle[j].x-x[i])*(circle[j].x-x[i])+(circle[j].y-y[i])*(circle[j].y-y[i]));
                                if(dst < circle[j].r){
                                        if(in_circle[j]==0){
                                                in_circle[j]=1;
                                                min_thru++;
                                        }
                                        else{
                                                in_circle[j]=0;
                                                min_thru--;
                                        }
                                }
                        }
                }

                printf("%d\n", min_thru);
        }

        return 0;
}