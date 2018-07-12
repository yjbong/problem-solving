#include <stdio.h>
#include <stdlib.h>
#define SWAP(a,b,tmp) {tmp=a;a=b;b=tmp;}
int line[1000000][2];
int cmp(const void *a, const void *b){

    if(*((int*)a)>*((int*)b)) return 1;
    else if(*((int*)a)==*((int*)b)){
        if(*((int*)a+1)>*((int*)b+1)) return 1;
    }
    return 0;
}

int main(void){

    int i,n,tmp,sol;
    int line_start, line_end;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d %d", &line[i][0], &line[i][1]);
        if(line[i][0]>line[i][1]) SWAP(line[i][0], line[i][1], tmp);
    }
    qsort(line, n, sizeof(int)*2, cmp);

    line_start=line[0][0], line_end=line[0][1];
    sol=0;
    for(i=1; i<n; i++){
        if(line[i][0]>line_end){
            sol+=(line_end-line_start);
            line_start=line[i][0], line_end=line[i][1];
        }
        else if(line[i][1]>line_end){
            line_end=line[i][1];
        }
    }
    sol+=(line_end-line_start);
    printf("%d\n", sol);
    return 0;
}