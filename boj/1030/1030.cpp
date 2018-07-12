#include <cstdio>
#define SWAP(i,j,t){t=i;i=j;j=t;}
typedef long long ll;

ll pw[22];
ll s,N,K,R1,R2,C1,C2;
ll cal(ll r,ll c){

        ll t=s;
        while(t>0){
                if(N%2==1){
                        if(N/2-K/2<=r/pw[t-1] && r/pw[t-1]<=N/2+K/2 &&
                                N/2-K/2<=c/pw[t-1] && c/pw[t-1]<=N/2+K/2) return 1l;
                        else{
                                r%=pw[t-1];
                                c%=pw[t-1];
                        }
                }
                else{
                        if(N/2-K/2<=r/pw[t-1] && r/pw[t-1]<=N/2+K/2-1 &&
                                N/2-K/2<=c/pw[t-1] && c/pw[t-1]<=N/2+K/2-1) return 1l;
                        else{
                                r%=pw[t-1];
                                c%=pw[t-1];
                        }
                }
                t--;
        }
        return 0l;
}

int main(void){

        scanf("%lld %lld %lld %lld %lld %lld %lld",&s,&N,&K,&R1,&R2,&C1,&C2);
        ll t;
        if(R2<R1) SWAP(R1,R2,t);
        if(C2<C1) SWAP(C1,C2,t);

        pw[0]=1;
        for(ll i=1; i<=s; i++) pw[i]=pw[i-1]*N;

        for(ll i=R1; i<=R2; i++){
                for(ll j=C1; j<=C2; j++)
                        printf("%1lld",cal(i,j));
                printf("\n");
        }
        return 0;
}