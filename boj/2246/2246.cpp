#include <stdio.h>
#include <stdlib.h>
typedef struct _condo{
    int num;
    int d;
    int c;
    int is_ok;
}CONDO;
CONDO condo[10000];
CONDO tmp[10000];

int cmp1(const void *a, const void *b){
    if( ((CONDO*)a)->d > ((CONDO*)b)->d) return 1;
    else if( ((CONDO*)a)->d == ((CONDO*)b)->d){
        if( ((CONDO*)a)->c < ((CONDO*)b)->c) return 1;
    }

    else return 0;
}

int cmp2(const void *a, const void *b){
    if( ((CONDO*)a)->c > ((CONDO*)b)->c) return 1;
    else if( ((CONDO*)a)->c == ((CONDO*)b)->c){
        if( ((CONDO*)a)->d < ((CONDO*)b)->d) return 1;
    }
    else return 0;
}

int main(void){

    int i,n,d,c,min,sol;
    int cnt;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d %d", &d,&c);
        condo[i].d=d;
        condo[i].c=c;
        condo[i].num=i;
        condo[i].is_ok=0;
    }

    for(i=0; i<n; i++){
        tmp[i].num=condo[i].num;
        tmp[i].d=condo[i].d;
        tmp[i].c=condo[i].c;
    }

    qsort(tmp, n, sizeof(CONDO), cmp1);

    min=-1;
    cnt=0;
    for(i=0; i<n; i++){
        if(min<0 || min>tmp[i].c){
            min=tmp[i].c;
            condo[tmp[i].num].is_ok=1;
            cnt++;
        }
    }

    for(i=0; i<n; i++){
        tmp[i].num=condo[i].num;
        tmp[i].d=condo[i].d;
        tmp[i].c=condo[i].c;
    }

    qsort(tmp, n, sizeof(CONDO), cmp2);

    min=-1;
    sol=0;
    for(i=0; i<n; i++){

        if(min<0 || min>tmp[i].d){
            min=tmp[i].d;
            if(condo[tmp[i].num].is_ok==1) sol++;
        }
    }

    printf("%d\n", sol);
    return 0;
}