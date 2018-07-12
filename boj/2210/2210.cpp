#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int b[7][7];
int cnt;

char r[40000][7];
char tmp[7];
char cur_r[7];

int cmp(const void *a, const void *b){

    if(strcmp((char*)a, (char*)b)>0) return 1;
    else return 0;
}

void go(int cur_x, int cur_y, int len){

    if(b[cur_x][cur_y]<0) return;
    else{
        tmp[len]=b[cur_x][cur_y]+'0';
    }

    if(len==5){
        strcpy(r[cnt], tmp);
        cnt++;
    }

    else{
        go(cur_x+1, cur_y, len+1);
        go(cur_x-1, cur_y, len+1);
        go(cur_x, cur_y+1, len+1);
        go(cur_x, cur_y-1, len+1);
    }
}

int main(void){

    int i,j,sol;
    for(i=1; i<=5; i++)
        for(j=1; j<=5; j++)
            scanf("%d", &b[i][j]);

    for(i=0; i<7; i++){
        b[0][i]=-1;
        b[6][i]=-1;
        b[i][0]=-1;
        b[i][6]=-1;
    }

    cnt=0;
    tmp[7]='\0';
    for(i=1; i<=5; i++)
        for(j=1; j<=5; j++)
            go(i,j,0);

    qsort(r, cnt, sizeof(char)*7, cmp);

    sol=0;
    cur_r[0]='\0';
    for(i=0; i<cnt; i++){
        if(strcmp(cur_r, r[i])!=0){
            strcpy(cur_r, r[i]);
            sol++;
        }
    }

    printf("%d\n", sol);
    return 0;
}