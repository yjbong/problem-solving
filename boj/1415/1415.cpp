#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
bool p[555555];
bool c[555555];

ll a[55];

ll b[55];
ll bf[55];
ll bs;

ll n;
ll d[2][555555];
vector <ll> v[2];

int main(void){

    p[0]=p[1]=true;
    for(ll i=2; i<=500000; i++)
        if(!p[i]) for(ll j=i*2; j<=500000; j+=i) p[j]=true;

    scanf("%lld",&n);
    for(ll i=0; i<n; i++) scanf("%lld",&a[i]);

    sort(a,a+n);

    b[0]=a[0];
    bf[0]=1;
    bs=1;

    for(ll i=1; i<n; i++){
        if(b[bs-1]==a[i]) bf[bs-1]++;
        else{
            b[bs]=a[i];
            bf[bs]=1;
            bs++;
        }
    }

    v[0].push_back(0);
    d[0][0]=1;

    ll now,old;
    for(ll i=1; i<=bs; i++){
        now=i%2;
        old=1-now;
        for(ll j=0; j<=500000; j++){
            d[now][j]=0;
            c[j]=false;
        }

        for(ll j=0; j<v[old].size(); j++){
            for(ll k=0; k<=bf[i-1]; k++){
                d[now][v[old][j] + k*b[i-1]]+=d[old][v[old][j]];
                if(!c[v[old][j] + k*b[i-1]]){
                    v[now].push_back(v[old][j] + k*b[i-1]);
                    c[v[old][j] + k*b[i-1]] = true;
                }
            }
        }
        v[old].clear();
    }

    ll sol=0;
    for(ll i=0; i<=500000; i++)
        if(!p[i]) sol+=d[now][i];


    printf("%lld\n",sol);
    return 0;
}