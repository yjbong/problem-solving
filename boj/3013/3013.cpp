#include <cstdio>
typedef long long ll;
ll n,b;
ll b_idx=-1;
ll a[111111];
ll bef[111111];
ll aft[222222];

int main(void){

    scanf("%lld %lld", &n,&b);

    for(ll i=0; i<n; i++){
        scanf("%lld",&a[i]);
        if(a[i]==b) b_idx=i;
    }

    bef[b_idx]=0;
    for(ll i=b_idx-1; i>=0; i--){
        if(a[i]>b) bef[i]=bef[i+1]+1;
        else bef[i]=bef[i+1]-1;
    }

    ll sum=0;
    for(ll i=b_idx; i<n; i++){
        if(a[i]>b) sum++;
        else if(a[i]<b) sum--;
        aft[sum+100000]++;
    }

    ll sol=0;
    for(ll i=0; i<=b_idx; i++)
        sol+=aft[100000-bef[i]];

    printf("%lld",sol);

    return 0;
}