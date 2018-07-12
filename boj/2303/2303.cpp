#include <stdio.h>

int num[1000][5];
int sc[1000];

int main(void){

    int i,j,k,l,n;
    int cur_sc;
    int max_sc_idx;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        for(j=0; j<5; j++)
            scanf("%d",&num[i][j]);

    for(i=0; i<n; i++){
        sc[i]=0;
        for(j=0; j<5; j++){
            for(k=j+1; k<5; k++){
                for(l=k+1; l<5; l++){
                    cur_sc=(num[i][j]+num[i][k]+num[i][l])%10;
                    if(sc[i]<cur_sc) sc[i]=cur_sc;
                }
            }
        }
    }

    max_sc_idx=0;
    for(i=1; i<n; i++){
        if(sc[max_sc_idx]<=sc[i]) max_sc_idx=i;
    }
    printf("%d\n",max_sc_idx+1);

    return 0;
}