#include <cstdio>
int mat[12][200][200];
int cmat[200][200];
int tmat[200][200];
int main(void){

    int n,t,m;
    scanf("%d %d %d",&n,&t,&m);
    for(int i=0; i<n; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        mat[0][i][a-1]=1;
        mat[0][i][b-1]=1;
    }

    for(int i=1; i<12; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                for(int l=0; l<n; l++)
                    mat[i][j][k]+=mat[i-1][j][l]*mat[i-1][l][k];
                if(mat[i][j][k]) mat[i][j][k]=1;
            }
        }
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) if(i==j) cmat[i][j]=1;

    for(int i=0; i<12 && t>0; i++,t/=2){
        if(t%2){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    tmat[j][k]=0;
                    for(int l=0; l<n; l++)
                        tmat[j][k]+=cmat[j][l]*mat[i][l][k];
                    if(tmat[j][k]) tmat[j][k]=1;
                }
            }
            for(int j=0; j<n; j++)
                for(int k=0; k<n; k++) cmat[j][k]=tmat[j][k];
        }
    }
    for(int i=0; i<m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(cmat[a-1][b-1]) printf("death\n");
        else printf("life\n");
    }
    return 0;
}