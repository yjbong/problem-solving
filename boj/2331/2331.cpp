#include <cstdio>
#include <vector>
typedef long long ll;
using namespace std;
vector <int> v;
int main(void){

    ll a,p;
    scanf("%lld %lld",&a,&p);
    v.push_back(a);

    bool out;
    while(1){
        ll c=0;
        ll t=v[v.size()-1];
        while(t>0){
            ll t2=1;
            for(int i=0; i<p; i++) t2*=(t%10);
            c+=t2;
            t/=10;
        }
        out=false;
        for(int i=0; i<v.size(); i++){
            if(c==v[i]){
                printf("%d\n",i);
                out=true;
            }
        }
        if(!out) v.push_back(c);
        else break;
    }
    return 0;
}