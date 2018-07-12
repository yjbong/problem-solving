#include <cstdio>
typedef long long ll;
ll d[11][222][222];
int main(void){

    ll n,m,r;
    scanf("%lld %lld %lld",&n,&m,&r);

    for(ll i=1; i<=m; i++)
        for(ll j=1; j<=m; j++) if(i==j) d[1][i][j]=1;

    for(ll i=2; i<=n; i++){
        for(ll j=1; j<=m; j++){
            for(ll k=1; k<=m; k++){
                d[i][j][k]=0;
                for(ll l=j; l<=m; l++){
                    if(k-j>=0) d[i][j][k]+=d[i-1][l][k-j];
                }
            }
        }
    }

    ll curr=r;
    ll curm=m;
    ll curn=n;

    ll oldj=1;
    while(curn>0){

        ll c=0;
        ll j;
        for(j=oldj; j<=curm; j++){
            if(c+d[curn][j][curm]>=curr){
                break;
            }
            c+=d[curn][j][curm];
        }
        if(curn>1) printf("%lld ",j);
        else printf("%lld\n",curm);

        curm-=j;
        curr-=c;
        curn--;
        oldj=j;
    }
    return 0;
}