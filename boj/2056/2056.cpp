#include <stdio.h>
#define MAXWORKS 10000
#define MAXPRES 100
typedef struct _work{

        int pre[MAXPRES];
        int pres;

        int basic_time;
        int real_time;

        int done;
}WORK;

WORK work[MAXWORKS+1];
int works;

int main(void){

        int i,j;
        int cur_max;
        scanf("%d", &works);
        for(i=1; i<=works; i++){
                scanf("%d", &(work[i].basic_time));
                scanf("%d", &(work[i].pres));
                for(j=0; j<work[i].pres; j++){
                        scanf("%d", &(work[i].pre[j]));
                }
        }

        for(i=1; i<=works; i++){
                cur_max=0;
                for(j=0; j<work[i].pres; j++){
                        if(cur_max<work[work[i].pre[j]].real_time) cur_max=work[work[i].pre[j]].real_time;
                }
                work[i].real_time=cur_max+work[i].basic_time;
        }

        cur_max=0;
        for(i=1; i<=works; i++){
                if(cur_max<work[i].real_time) cur_max=work[i].real_time;
        }

        printf("%d\n", cur_max);
        return 0;
}