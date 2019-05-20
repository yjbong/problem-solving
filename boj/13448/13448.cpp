#include <cstdio>
#include <algorithm>
#define MAX_N 50
#define MAX_T 100000
using namespace std;
typedef long long ll;
typedef struct{
    ll M; // 문제를 풀었을 때 얻는 점수
    ll P; // 1분당 페널티 점수
    ll R; // 이 문제를 푸는데 걸리는 시간
}PROB;
int N; // 문제의 수
ll T; // 총 대회 시간
PROB p[MAX_N];
 
bool compare(PROB a, PROB b){
    // return a.R/a.P < b.R/b.P;
    return a.R*b.P < b.R*a.P;
}
ll max2(ll a, ll b){ return a>b?a:b; }
 
ll cache[MAX_N][MAX_T+1];
// solve(idx, T) = idx~N-1번 문제가 있고 남은 대회 시간이 time일 때, 얻을 수 있는 최대 점수
ll solve(int idx, ll time){
    if(idx>=N) return 0;
    if(cache[idx][time]>=0) return cache[idx][time];
 
    ll ans=0;
    // case 1: idx번 문제를 푼다
    if(time>=p[idx].R)
        ans=max2(ans, solve(idx+1, time-p[idx].R)+p[idx].M-p[idx].P*(T-(time-p[idx].R)));
    // case 2: idx번 문제를 풀지 않는다
    ans=max2(ans, solve(idx+1, time));
 
    return cache[idx][time]=ans;
}
 
int main() {
    scanf("%d %lld",&N,&T);
    for(int i=0; i<N; i++) scanf("%lld", &p[i].M);
    for(int i=0; i<N; i++) scanf("%lld", &p[i].P);
    for(int i=0; i<N; i++) scanf("%lld", &p[i].R);
    sort(p, p+N, compare);

    for(int i=0; i<N; i++)
        for(int j=0; j<=T; j++) cache[i][j]=-1;
    printf("%lld\n",solve(0, T));
	return 0;
}