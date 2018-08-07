#include <cstdio>
int c,n,x,m,t;
int a[200];
double trans[20][200][200]; // (1<<20) > 1000000
double xtrans[2][200][200];
int main(void){
        scanf("%d",&c);
        while(c--){
                scanf("%d %d %d %d",&n,&x,&m,&t);
                for(int i=0; i<n; i++){
                        scanf("%d",&a[i]);
                        a[i]--;
                }

                // init transition array
                for(int i=0; i<20; i++)
                        for(int j=0; j<n; j++)
                                for(int k=0; k<n; k++)
                                        trans[i][j][k]=0;

                // build trans[0] (1-th transition matrix)
                for(int i=0; i<n; i++){
                        if(i==0){
                                trans[0][i][a[i]]=1.0;
                        }
                        else{
                                for(int j=a[i]-t; j<=a[i]+t; j++){
                                        if(j<0) trans[0][i][j+n]=1.0/(t*2+1);
                                        else if(j>=n) trans[0][i][j-n]=1.0/(t*2+1);
                                        else trans[0][i][j]=1.0/(t*2+1);
                                }
                        }
                }

                // calc trans[1~19] for fast matrix multiplication (trans[i]=trans[i-1]*trans[i-1])
                for(int i=1; i<20; i++)
                        for(int j=0; j<n; j++)
                                for(int k=0; k<n; k++)
                                        for(int l=0; l<n; l++)
                                                trans[i][j][k]+=trans[i-1][j][l]*trans[i-1][l][k];

                // get x-th transition matrix
                for(int i=0; i<n; i++)
                        for(int j=0; j<n; j++)
                                xtrans[0][i][j]=(i==j?1:0);

                int cur=1;
                for(int i=0; i<20; i++){
                        if(x&(1<<i)){
                                for(int j=0; j<n; j++){
                                        for(int k=0; k<n; k++){
                                                xtrans[cur][j][k]=0;
                                                for(int l=0; l<n; l++){
                                                        xtrans[cur][j][k]+=trans[i][j][l]*xtrans[1-cur][l][k];
                                                }
                                        }
                                }
                                cur=1-cur;
                        }
                }

                // print answer
                for(int i=0; i<m; i++){
                        int q;
                        scanf("%d",&q);
                        q--;
                        printf("%.5lf ",xtrans[1-cur][0][q]);
                }
                printf("\n");
        }
        return 0;
}