#include <cstdio>
typedef long long ll;
ll n,k,sol;
bool rem[100000];
ll dgts;
int main(void){

    scanf("%lld %lld",&n,&k);

    ll t=n;
    dgts=0;
    while(t>0){
        t/=10;
        dgts++;
    }

    ll sol=1;
    ll c=n;
    while(c%k!=0){
        if(rem[c%k]==true){
            sol=-1;
            break;
        }
        rem[c%k]=true;
        c%=k;
        for(int i=0; i<dgts; i++) c*=10;
        c+=n;
        sol++;
    }
    printf("%lld\n",sol);
    return 0;
}