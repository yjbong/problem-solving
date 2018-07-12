#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
int meet[MAX][2];
int meets;

int int_cmp(const void *a, const void* b){

        int a1,a2,b1,b2;
        a1=*((int*)a), a2=*((int*)a+1);
        b1=*((int*)b), b2=*((int*)b+1);
        if(a2>b2 || (a2==b2 && a1>b1)) return 1;
        else return 0;
}

int main(void){

        int i, sol, cur_start;

        scanf("%d", &meets);
        for(i=0; i<meets; i++) scanf("%d %d", &meet[i][0], &meet[i][1]);
        qsort(meet, meets, sizeof(int)*2, int_cmp);

        sol=0, cur_start=0;
        for(i=0; i<meets; i++){
                if(cur_start<=meet[i][0]){
                        sol++;
                        cur_start=meet[i][1];
                }
        }
        printf("%d\n", sol);
        return 0;
}