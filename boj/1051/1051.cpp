#include <stdio.h>
int b[50][50];
int main(void){

    int i,j,k,rs,cs,sol;
    scanf("%d %d",&rs,&cs);
    for(i=0; i<rs; i++){
        for(j=0; j<cs; j++){
            scanf("%1d",&b[i][j]);
        }
    }
    sol=0;
    for(i=0; i<rs; i++){
        for(j=0; j<cs; j++){
            for(k=0; k<50; k++){
                if(i+k<rs && j+k<cs){
                    if(b[i][j]==b[i+k][j] && b[i][j]==b[i][j+k] && b[i][j]==b[i+k][j+k]){
                        if(sol<k+1) sol=k+1;
                    }
                }
            }
        }
    }
    printf("%d\n",sol*sol);

    return 0;
}