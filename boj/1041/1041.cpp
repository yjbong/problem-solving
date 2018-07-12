#include <cstdio>
#define INF 1000000000000ll
typedef long long ll;
const ll sums[6]={0,6,12,8,0,6};
const ll sum[6][12][6]={
    {{}},
    {{0},{1},{2},{3},{4},{5}},
    {{0,1},{0,2},{0,3},{0,4},{1,2},{1,3},{1,5},{2,4},{2,5},{3,4},{3,5},{4,5}},
    {{0,1,2},{0,1,3},{0,2,4},{0,3,4},{1,2,5},{1,3,5},{2,4,5},{3,4,5}},
    {{}},
    {{0,1,2,3,4},{0,1,2,3,5},{0,1,2,4,5},{0,1,3,4,5},{0,2,3,4,5},{1,2,3,4,5}}
};

ll minsum[6];

ll d[6];
ll a[6];

int main(void){

    ll n;
    scanf("%lld",&n);
    for(ll i=0; i<6; i++) scanf("%lld",&d[i]);
    for(ll i=0; i<6; i++){
        minsum[i]=INF;
        for(ll j=0; j<sums[i]; j++){
            ll cursum=0;
            for(ll k=0; k<i; k++) cursum+=d[sum[i][j][k]];
            if(minsum[i]>cursum) minsum[i]=cursum;
        }
    }

    if(n==1) a[5]=1;
    else{
        a[3]=4;
        a[2]=(2*n-3)*4;
        a[1]=(n-2)*(n-2)+(n-2)*(n-1)*4;
    }

    ll sol=0;
    for(ll i=0; i<6; i++)
        sol+=a[i]*minsum[i];

    printf("%lld\n",sol);
    return 0;
}