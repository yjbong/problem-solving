#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int Ds; // D의 크기
int Ms; // M의 크기
ll D[50], M[50];
ll GCD(ll a, ll b){
    if(b==0) return a;
    else return GCD(b,a%b);
}
ll LCM(ll a, ll b){
    ll d=GCD(a,b);
    return a*b/d;
}
bool isNotPrime[33333];
vector<int> prime;

int main() {
    // sqrt(10^9) 이하의 모든 소수를 구해 놓는다.
    isNotPrime[0]=isNotPrime[1]=true;
    for(int i=2; i<33333; i++){
        if(!isNotPrime[i]){
            prime.push_back(i);
            for(int j=i*2; j<33333; j+=i) isNotPrime[j]=true;
        }
    }

    // 입력
    cin >> Ds >> Ms;
    for(int i=0; i<Ds; i++) cin >> D[i];
    for(int i=0; i<Ms; i++) cin >> M[i];

    bool isValid=true;
    // GCD of M을 구한다.
    ll mgcd=M[0];
    for(int i=1; i<Ms; i++) mgcd=GCD(mgcd, M[i]);
    // LCM of D를 구한다.
    ll dlcm=D[0];
    for(int i=1; i<Ds; i++){
        dlcm=LCM(dlcm, D[i]);
        // dlcm이 mgcd보다 크면 답은 존재하지 않는다.
        if(dlcm>mgcd){ isValid=false; break; }
    }
    // mgcd가 dlcm의 배수가 아니면 답은 존재하지 않는다.
    if(mgcd%dlcm!=0) isValid=false; 

    if(isValid){
        mgcd/=dlcm; // mgcd를 dlcm으로 나눈다.
        // 나누고 난 뒤 mgcd의 약수의 개수를 구한다.
        ll ans=1;
        int primes=prime.size();
        for(int i=0; i<primes; i++){
            ll cur=1;
            while(mgcd%prime[i]==0){ cur++; mgcd/=prime[i]; }
            ans*=cur;
        }
        if(mgcd>1) ans*=2;
        cout << ans << endl;
    }
    else cout << "0" << endl;
    return 0;
}