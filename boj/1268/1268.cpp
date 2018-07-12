#include <stdio.h>
#define MAX 1000
int ban[MAX+1][5];
int main(void){

    int i,j,k,n;
    int cursame, maxsame;
    int maxidx;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
        for(j=0; j<5; j++)
            scanf("%d", &ban[i][j]);

    maxsame=0, maxidx=1;
    for(i=1; i<=n; i++){
        cursame=0;
        for(j=1; j<=n; j++){
            if(i!=j){
                for(k=0; k<5; k++) if(ban[i][k]==ban[j][k]) break;
                if(k<5) cursame++;
            }
        }
        if(maxsame<cursame){
            maxsame=cursame;
            maxidx=i;
        }
    }

    printf("%d\n", maxidx);
    return 0;
}