#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100000
#define MAXLEN 20
typedef struct _mon{

        char name[MAXLEN+1];
        int num;
}MON;

MON mon[MAX];
int mons;
char name[MAX][MAXLEN+1];

int cmp_func(const void *a, const void *b){

        if( strcmp(((MON*)a)->name, ((MON*)b)->name)>0) return 1;
        else return 0;
}
int bin_search(char key[MAXLEN]){

        int left, right, mid;
        left=0, right=mons-1;
        while(left<=right){
                mid=(left+right)/2;
                if(strcmp(key, mon[mid].name)>0) left=mid+1;
                else if(strcmp(key, mon[mid].name)<0) right=mid-1;
                else return mid;
        }
        return -1;
}

int main(void){

        int i,j;
        int qs, tmp;
        char cur_q[MAXLEN+1];
        scanf("%d %d\n", &mons, &qs);
        for(i=0; i<mons; i++){
                scanf("%s\n", mon[i].name);
                strcpy(name[i], mon[i].name);
                mon[i].num=i+1;
        }

        qsort(mon, mons, sizeof(MON), cmp_func);
        for(i=0; i<qs; i++){
                scanf("%s\n", cur_q);
                if(cur_q[0]>='0' && cur_q[0]<='9'){
                        tmp=atoi(cur_q);
                        printf("%s\n", name[tmp-1]);
                }
                else{
                        tmp=bin_search(cur_q);
                        if(tmp<0) printf("NOT FOUND\n");
                        else printf("%d\n", mon[tmp].num);
                }
        }
        return 0;
}