#include <stdio.h>
#include <stdlib.h>
#define MAX 200000
#define SWAP(a,b,tmp){tmp=a; a=b; b=tmp;}
int line[MAX][2];
int lines;

int cmp(const void *a, const void *b){
        if((*((int*)a))>(*((int*)b))) return 1;
        else return 0;
}

int main(void){

        int i, M, cur_M, cur_max;
        int tmp;
        int line_use;

        scanf("%d", &M);

        i=0;
        while(1){
                scanf("%d %d", &line[i][0], &line[i][1]);
                if(line[i][0]==0 && line[i][1]==0) break;
                if(line[i][0]>line[i][1]) SWAP(line[i][0], line[i][1], tmp);
                if(line[i][0]<0) line[i][0]=0;
                if(line[i][1]<0) line[i][1]=0;
                i++;
        }

        lines=i;
        qsort(line, lines, sizeof(int)*2, cmp);

        cur_M=0, i=0, line_use=0;
        while(cur_M<M && i<lines){
                cur_max=-1;
                while(line[i][0]<=cur_M && i<lines){
                        if(cur_max<line[i][1]) cur_max=line[i][1];
                        i++;
                }
                if(cur_max<0) break;
                else if(cur_M<cur_max){
                        cur_M=cur_max;
                        line_use++;
                }
        }

        if(cur_M<M) printf("0\n");
        else printf("%d\n", line_use);

        return 0;
}