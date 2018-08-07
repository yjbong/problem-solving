#include <cstdio>
int t,n,V;
int v[100];
int c[100];
int k[100];

int new_n;
int new_v[100*15];
int new_c[100*15];

//int d[100*15][10001]; // d[i][j] = maximum sum of credit where there are item[0~i], and capacity is j
int d[2][10001];

int max2(int a, int b){
        return a>b?a:b;
}
int main(void){

        scanf("%d",&t);
        while(t--){
                scanf("%d %d",&n,&V);
                for(int i=0; i<n; i++) scanf("%d %d %d",&v[i],&c[i],&k[i]);

                new_n=0;
                for(int i=0; i<n; i++){
                        int j=0;
                        while(k[i]>=(1<<j)-1) j++;
                        for(int l=0; l<j-1; l++){
                                new_v[new_n]=(1<<l)*v[i];
                                new_c[new_n++]=(1<<l)*c[i];
                        }
                        int tmp=(1<<(j-1))-1;
                        if(k[i]-tmp>0){
                                new_v[new_n]=(k[i]-tmp)*v[i];
                                new_c[new_n++]=(k[i]-tmp)*c[i];
                        }
                }

                // 0-1 knapsack
                for(int i=0; i<=V; i++)
                        d[0][i]=(i>=new_v[0] ? new_c[0]:0);

                int cur=1;
                for(int i=1; i<new_n; i++){
                        for(int j=0; j<=V; j++){
                                d[cur][j]=d[1-cur][j];
                                if(j-new_v[i]>=0) d[cur][j]=max2(d[cur][j],d[1-cur][j-new_v[i]]+new_c[i]);
                        }
                        cur=1-cur;
                }
                printf("%d\n",d[1-cur][V]);
        }
        return 0;
}