#include <stdio.h>
#include <stdlib.h>
int sc[50];
int cmp(const void *a, const void *b){
    if(*((int*)a)<*((int*)b)) return 1;
    else return 0;
}

int main(void){

    int i,n,p,new_sc,sol;

    scanf("%d %d %d", &n, &new_sc, &p);
    for(i=0; i<50; i++) sc[i]=-1;
    for(i=0; i<n; i++) scanf("%d", &sc[i]);
    qsort(sc, n, sizeof(int), cmp);

    if(new_sc<=sc[p-1]) printf("-1\n");
    else{
        sol=1;
        for(i=0; i<n; i++){
            if(sc[i]>new_sc) sol++;
            else break;
        }
        printf("%d\n", sol);
    }

    return 0;
}