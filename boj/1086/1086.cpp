#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <vector>
#define DIGITS 17
#define LIMIT 100000000000000000ll // max 17 digits
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
int N,K;
char s[55];
ll num[15][3]; // num[i][0] is least digits of num[i]
ll dgt[15]; // dgt[i]: the number of digits of num[i]
ll stat_dgt[1<<15];

ll rem[15]; // rem[i]: the remainder of num[i] when divided by K
ll tenmodK[15*50+1];

ll d[1<<15][100];
vector <int> v[16]; // v[i]: list of state which has (i)set bits

ll gcd(ll a, ll b){
        ll t;
        if(a<b){ t=a; a=b; b=t; }
        while(b>0){
                a%=b;
                t=a; a=b; b=t;
        }
        return a;
}

int main(void){

        scanf("%d",&N);
        for(int i=0; i<N; i++){
                scanf("%s",s);
                int sl=strlen(s);
                dgt[i]=sl;

                int idx=0;
                int t=sl-1;
                while(t-DIGITS+1>=0){
                        num[i][idx] = atoll(s+(t-DIGITS+1));
                        s[t-DIGITS+1]='\0';
                        t=t-DIGITS;
                        idx++;
                }
                if(t>=0) num[i][idx] = atoll(s);
        }

        for(int i=0; i<(1<<N); i++)
                for(int j=0; j<N; j++)
                        if(i&(1<<j)) stat_dgt[i]+=dgt[j];

        scanf("%d",&K);
        for(int i=0; i<N; i++){
                rem[i]=0;
                for(int j=0; j<3; j++){
                        ll crem=num[i][j]%K;
                        for(int k=0; k<j; k++) crem=((crem%K)*(LIMIT%K))%K;
                        rem[i]=(rem[i]+crem)%K;
                }
        }

        tenmodK[0]=1;
        for(int i=1; i<=15*50; i++)
                tenmodK[i]=((tenmodK[i-1]%K)*(10%K))%K;

        for(int i=0; i<(1<<N); i++){
                int cur_bits=0; int t=i;
                while(t>0){
                        if(t%2) cur_bits++;
                        t/=2;
                }
                v[cur_bits].push_back(i);
        }

        d[0][0]=1;
        for(int i=1; i<=N; i++){
                for(int j=0; j<v[i].size(); j++){
                        int cstat=v[i][j];
                        for(int k=0; k<K; k++){

                                for(int l=0; l<N; l++){
                                        if(cstat&(1<<l)){

                                                int t = k - ((rem[l] * tenmodK[stat_dgt[cstat-(1<<l)]]) % K );
                                                if(t<0) t+=K;

                                                d[cstat][k] += d[cstat-(1<<l)][t];
                                        }
                                }
                        }
                }
        }

        ll ja,mo;

        ja=d[(1<<N)-1][0];
        mo=1;
        for(ll i=2; i<=N; i++) mo*=i;

        ll g=gcd(ja,mo);
        ja/=g; mo/=g;
        printf("%lld/%lld\n",ja,mo);

        return 0;
}