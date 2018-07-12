#include <stdio.h>

int time[11111];

int main(void){

    int i,j;
    int cur_t,du,qt;
    int songs,qs;
    scanf("%d %d", &songs, &qs);

    cur_t=0;

    for(i=1; i<=songs; i++){
        scanf("%d", &du);
        for(j=cur_t; j<cur_t+du; j++)
            time[j]=i;

        cur_t+=du;
    }

    for(i=1; i<=qs; i++){
        scanf("%d", &qt);
        printf("%d\n", time[qt]);
    }

    return 0;
}