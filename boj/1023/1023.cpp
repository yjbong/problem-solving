#include <cstdio>
typedef long long ll;
ll d[51][51]; // 현재의 '('개수 - ')'개수 = j이고, 앞으로 채워야 할 문자열의 길이가 i일 때 만들 수 있는 괄호문자열의 갯수
ll n,k;
int main(void){

        scanf("%lld %lld",&n,&k);

        d[0][0]=1;
        for(ll i=1; i<=n; i++){
                for(ll j=0; j<=n; j++){
                        if(j>0) d[i][j] += d[i-1][j-1];
                        if(j<n) d[i][j] += d[i-1][j+1];
                }
        }

        ll cj=0;
        bool minus=false;
        if(k < ((1ll<<n)-d[n][0])){
                for(ll i=n; i>=1; i--){
                        if(cj<0) minus=true;

                        ll lnum = 1ll<<(i-1);
                        if(minus==false && cj+1>=0) lnum -= d[i-1][cj+1]; // cnum = 현재 상태에서 '(' 로 시작하는 괄호ㄴㄴ문자열의 갯수

                        if(lnum-1 >= k){
                                printf("(");
                                cj++;
                        }
                        else{
                                printf(")");
                                cj--;
                                k -= lnum;
                        }
                }
        }
        else printf("-1");

        printf("\n");

        return 0;
}