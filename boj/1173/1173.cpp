#include <stdio.h>
#define INF 1000000000000000000ll
long long d[222][222];

int main(void){

        long long i,j,k,N,m,M,T,R;
        long long curmin,sol;
        scanf("%lld %lld %lld %lld %lld",&N,&m,&M,&T,&R);
        if(m+T>M) printf("-1\n");
        else{
                for(i=0; i<=N; i++)
                        for(j=0; j<=M; j++) d[i][j]=INF;

                d[0][m]=0;
                for(i=1; i<=N; i++){
                        for(j=M; j>=m; j--){
                                if(j==m){
                                        curmin=d[i][j];
                                        for(k=j+R; k>=j+1; k--){
                                                if(k<=M){
                                                        if(curmin>d[i][k]+1) curmin=d[i][k]+1;
                                                }
                                        }
                                        d[i][j]=curmin;
                                }
                                else{
                                        curmin=d[i][j];
                                        if(j+R<=M){
                                                if(curmin>d[i][j+R]+1) curmin=d[i][j+R]+1;
                                        }
                                        if(j-T>=m){
                                                if(curmin>d[i-1][j-T]+1) curmin=d[i-1][j-T]+1;
                                        }
                                        d[i][j]=curmin;
                                }
                        }
                }

                sol=d[N][m];
                for(j=m+1; j<=M; j++)
                        if(sol>d[N][j]) sol=d[N][j];

                printf("%lld\n",sol);
        }

        return 0;
}