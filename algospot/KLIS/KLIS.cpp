#include <cstdio>
#define MAX_K 2147483647ll
typedef long long ll;
int c,n; ll k;
int a[555];
ll d[555][555];
int pos[111111];
int order[555]; int orders;
int order_val[555];

int main(void){
        scanf("%d",&c);
        while(c--){
                for(int i=0; i<=100000; i++) pos[i]=-1;
                scanf("%d %lld",&n,&k);
                for(int i=0; i<n; i++){
                        scanf("%d",&a[i]);
                        pos[a[i]]=i;
                }

                orders=0;
                for(int i=0; i<=100000; i++){
                        if(pos[i]>=0){
                                order[orders]=pos[i];
                                order_val[orders++]=i;
                        }
                }

                int lis_len=1;
                for(int i=0; i<n; i++) d[1][i]=1;
                for(int i=2; i<=n; i++){
                        for(int j=0; j<n; j++){
                                d[i][j]=0;
                                for(int k=j+1; k<n; k++)
                                        if(a[j]<a[k]) d[i][j]+=d[i-1][k];

                                if(d[i][j]>MAX_K) d[i][j]=MAX_K+1;
                                if(d[i][j]>0 && lis_len<i) lis_len=i;
                        }
                }

                printf("%d\n",lis_len);

                int cur_len=lis_len;
                int old_start=-1;
                int old_val=-1;

                for(int i=lis_len; i>0; i--){
                        for(int j=0; j<n; j++){
                                if(order_val[j]>old_val && order[j]>old_start){
                                        if(k > d[i][order[j]]) k-=d[i][order[j]];
                                        else{
                                                printf("%d ", order_val[j]);
                                                old_start=order[j];
                                                old_val=order_val[j];
                                                break;
                                        }
                                }
                        }
                }
                printf("\n");
        }
        return 0;
}