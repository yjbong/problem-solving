#include <cstdio>
#include <cmath>
typedef unsigned long long ll;
 
int N; // 면적의 수

ll apow[33]; // apow[i]=(a^(2^i)) mod n
bool MillerRabin(ll n){
    if(n<2ull) return false;
    else if(n==2ull) return true;
    else if(n%2ull==0ull) return false;
 
    // n은 3 이상의 홀수
    // n-1==d*2^s (d는 홀수, s는 양의 정수)
    ll d=n-1,s=0ull;
    while(d%2ull==0ull){ s++; d/=2ull; }
 
    ll a[]={2ull,7ull,61ull}; // int 범위 내의 수에 대해서는 충분한 테스트임
    int tests=sizeof(a)/sizeof(ll);
 
    int score=0;
    for(int i=0; i<tests; i++){
 
        if(a[i]>n-2ull){ score++; continue; } // 테스트에 쓰이는 a는 2이상 n-2 이하여야 함
 
        apow[0]=a[i]%n;
        for(ll j=1ull; j<=32ull; j++) apow[j]=(apow[j-1]*apow[j-1])%n;
        ll ad=1ull; // ad=(a^d)mod n
        for(ll j=0ull; j<=32ull; j++) if(d&(1ull<<j)) ad=(ad*apow[j])%n;
 
        // 소수 테스트
        if(ad%n==1ull){ score++; continue; }
        ll adr=ad; // adr=(a^(d*(2^r)))mod n
        bool ok=false;
        for(ll r=0ull; r<s; r++){
            if(adr%n==n-1ull){ ok=true; break; }
            adr=(adr*adr)%n;
        }
        if(ok) score++;
    }

    return (score==tests);
}


int main() {
    scanf("%d",&N);
    int ans=0;
    while(N--){
        ll A; // 면적
        scanf("%llu",&A);
        if(A<4ull) ans++;
        else if(MillerRabin(2*A+1)) ans++; // 2*A+1 이 소수이면 불가능한 면적
    }
    printf("%d\n",ans);
    return 0;
}