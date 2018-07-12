#include <stdio.h>
#include <string.h>
int r[50][50];
int f[50];
char l[51];
int main(void){

        int i,j,k,n,sol;
        scanf("%d",&n);
        for(i=0; i<n; i++){
                scanf("%s",l);
                for(j=0; j<strlen(l); j++){
                        if(l[j]=='Y') r[i][j]=1;
                        else r[i][j]=0;
                }
        }

        for(i=0; i<n; i++) f[i]=0;
        for(i=0; i<n; i++){
                for(j=0; j<n; j++){
                        if(i!=j){
                                if(r[i][j]) f[i]++;
                                else{
                                        for(k=0; k<n; k++){
                                                if(r[i][k] && r[k][j]){
                                                        f[i]++;
                                                        break;
                                                }
                                        }
                                }
                        }
                }
        }

        sol=f[0];
        for(i=1; i<n; i++) if(sol<f[i]) sol=f[i];
        printf("%d\n",sol);
        return 0;
}