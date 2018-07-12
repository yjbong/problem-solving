#include <stdio.h>
#include <stdlib.h>

int num[10000];
int cmp(const void *a, const void *b){
    if(*((int*)a)>*((int*)b)) return 1;
    else return 0;
}

int main(void){

    int i,j,n;
    int cur_needs, min_needs;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &num[i]);
    qsort(num, n, sizeof(int), cmp);

    min_needs=5;
    for(i=0; i<n; i++){
        cur_needs=5;
        for(j=i; j<=i+4; j++){
            if(j<n){
                if(num[j]<=num[i]+4) cur_needs--;
            }
        }
        if(min_needs>cur_needs) min_needs=cur_needs;
    }
    printf("%d\n", min_needs);
    return 0;
}