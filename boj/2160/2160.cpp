#include <cstdio>
char a[50][5][8];
int n;
int main(void){

    scanf("%d",&n);
    for(int i=0; i<n; i++)
        for(int j=0; j<5; j++) scanf("%s",a[i][j]);

    int sol_i,sol_j,dif;
    dif=5*7; sol_i=0; sol_j=1;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int cur_dif=0;
            for(int k=0; k<5; k++){
                for(int l=0; l<7; l++){
                    if(a[i][k][l]!=a[j][k][l]) cur_dif++;
                }
            }
            if(dif>cur_dif){
                dif=cur_dif; sol_i=i; sol_j=j;
            }
        }
    }
    printf("%d %d\n",sol_i+1,sol_j+1);
    return 0;
}