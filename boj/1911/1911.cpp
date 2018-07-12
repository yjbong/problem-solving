#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

int hole[MAX][2];

int cmp(const void *a, const void *b){

    int a_num, b_num;
    a_num=*((int*)a);
    b_num=*((int*)b);
    if(a_num>b_num) return 1;
    else return 0;
}

int main(void){

    int i;
    int N, L;
    int cur_needs, needs, cover;
    scanf("%d %d\n", &N, &L);
    for(i=0; i<N; i++) scanf("%d %d\n", &hole[i][0], &hole[i][1]);
    qsort(hole, N, sizeof(int)*2, cmp);

    cover=-1;
    needs=0;
    for(i=0; i<N; i++){
        if(cover<hole[i][0]){
            cur_needs=(hole[i][1]-hole[i][0])/L;
            if((hole[i][1]-hole[i][0])%L>0) cur_needs++;
            needs+=cur_needs;
            cover=hole[i][0]-1+cur_needs*L;
        }
        else{
            cur_needs=(hole[i][1]-1-cover)/L;
            if((hole[i][1]-1-cover)%L>0) cur_needs++;
            if(cur_needs<0) cur_needs=0;
            needs+=cur_needs;
            cover=cover+cur_needs*L;
        }
    }
    printf("%d\n", needs);
    return 0;
}