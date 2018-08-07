#include <cstdio>
#define MAX_TIME 1000000
#define MAX_LEN 4
#define MAX_SONGS 50

int c,n,t,m,q;
int len[MAX_SONGS];
double trans[MAX_SONGS][MAX_SONGS];

//double W[MAX_LEN*MAX_SONGS][MAX_LEN*MAX_SONGS];
double W[22][MAX_LEN*MAX_SONGS][MAX_LEN*MAX_SONGS];

//double C[MAX_LEN*MAX_SONGS];
double C[2][MAX_LEN*MAX_SONGS];

double d[MAX_LEN][MAX_SONGS]; // d[i][j] = probability that song j starts after i-minutes


int main(void){
        scanf("%d",&c);
        while(c--){
                scanf("%d %d %d",&n,&t,&m);
                for(int i=0; i<n; i++) scanf("%d",&len[i]);
                for(int i=0; i<n; i++)
                        for(int j=0; j<n; j++) scanf("%lf",&trans[i][j]);

                // until t=3, do normal dynamic programming
                for(int i=0; i<MAX_LEN; i++)
                        for(int j=0; j<n; j++) d[i][j]=0;
                d[0][0]=1;
                for(int i=1; i<MAX_LEN; i++)
                        for(int j=0; j<n; j++)
                                for(int k=0; k<n; k++)
                                        if(i-len[k]>=0) d[i][j]+=d[i-len[k]][k]*trans[k][j];

                // init 4n*1 matrix C[0] from array d
                for(int i=0; i<MAX_LEN*n; i++) C[0][i]=d[i/n][i%n];

                // build 4n*4n matrix W[0]
                for(int i=0; i<MAX_LEN*n; i++)
                        for(int j=0; j<MAX_LEN*n; j++) W[0][i][j]=0;

                for(int i=0; i<(MAX_LEN-1)*n; i++) W[0][i][i+n]=1; // first 3n rows
                for(int i=(MAX_LEN-1)*n; i<MAX_LEN*n; i++){ // next n rows
                        for(int j=0; j<n; j++){
                                W[0][i][(MAX_LEN-len[j])*n+j]=trans[j][i%n];
                        }
                }
                // build W[1], ... W[20] for fast matrix multiplication ( W[i]=W[i-1]*W[i-1], (1<<20)>MAX_TIME )
                for(int i=1; i<=20; i++){
                        for(int j=0; j<MAX_LEN*n; j++){
                                for(int k=0; k<MAX_LEN*n; k++){
                                        W[i][j][k]=0;
                                        for(int l=0; l<MAX_LEN*n; l++){
                                                W[i][j][k]+=W[i-1][j][l]*W[i-1][l][k];
                                        }
                                }
                        }
                }


                // C(time+1) = W*C(time)
                int cur=1;
                int iterations=t-3;
                for(int i=0; i<=20; i++){ // fast matrix multiplication
                        if(iterations&(1<<i)){
                                for(int j=0; j<MAX_LEN*n; j++){
                                        C[cur][j]=0;
                                        for(int k=0; k<MAX_LEN*n; k++){
                                                C[cur][j]+=W[i][j][k]*C[1-cur][k];
                                        }
                                }
                                cur=1-cur;
                        }
                }

                // print answer
                for(int i=0; i<m; i++){
                        scanf("%d",&q);
                        double ans=0;
                        for(int j=len[q]; j>=1; j--){
                                ans+=C[1-cur][(MAX_LEN-j)*n+q];
                        }
                        printf("%.8lf ",ans);
                }
                printf("\n");
        }
        return 0;
}