#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
int app[MAX][2];
int cmp(const void *a, const void *b){
    if(*((int*)a)>*((int*)b)) return 1;
    else return 0;
}
int main(void){

    int i,cases,apps,min,sol;

    scanf("%d", &cases);
    while(cases--){
        scanf("%d", &apps);
        for(i=0; i<apps; i++)
            scanf("%d %d", &app[i][0], &app[i][1]);
        qsort(app, apps, sizeof(int)*2, cmp);

        min=MAX+1;
        sol=0;
        for(i=0; i<apps; i++){
            if(min>app[i][1]){
                sol++;
                min=app[i][1];
            }
        }
        printf("%d\n", sol);
    }
    return 0;
}