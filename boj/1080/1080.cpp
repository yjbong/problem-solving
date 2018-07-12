#include <stdio.h>
int a[50][50],b[50][50];
int main(void){

        int i,j,k,l,n,m,sol,ok;
        scanf("%d %d",&n,&m);
        for(i=0; i<n; i++)
                for(j=0; j<m; j++) scanf("%1d",&a[i][j]);

        for(i=0; i<n; i++)
                for(j=0; j<m; j++) scanf("%1d",&b[i][j]);

        sol=0;
        for(i=0; i<n-2; i++){
                for(j=0; j<m-2; j++){
                        if(a[i][j]!=b[i][j]){
                                for(k=i; k<i+3; k++)
                                        for(l=j; l<j+3; l++) a[k][l]=1-a[k][l];
                                sol++;
                        }
                }
        }

        ok=1;
        for(i=0; i<n; i++){
                for(j=0; j<m; j++){
                        if(a[i][j]!=b[i][j]){
                                ok=0;
                                break;
                        }
                }
        }
        if(ok) printf("%d\n",sol);
        else printf("-1\n");
        return 0;
}