#include <cstdio>
#include <queue>
#include <utility>
#define MAX_N 500000
#define INF 1000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
ll max2(ll a, ll b){ return a>b?a:b; }

int N; // 문제의 개수(1~N번 문제)
int M; // 보너스 점수를 얻기 위해 필요한 코인의 수
ll point[MAX_N+1]; // point[i] = i번 문제를 맞히거나 틀렸을 때 가감되는 점수
ll sumPoint[MAX_N+1]; // sumPoint[i] = point[1]+...+point[i]
ll bonus[MAX_N+1]; // bonus[i] = i번 문제의 보너스 점수

ll D[MAX_N+1]; // D[i] = 1~i번 문제까지 풀고 나서 코인이 0개인 상황일 때의 가능한 최대 점수
priority_queue <ii> pq; // element의 first: D[k]-sumPoint[k], second: k

int main() {

    // 입력
    scanf("%d %d",&N,&M);
    for(int i=1; i<=N; i++) scanf("%lld",&point[i]);
    for(int i=1; i<=N; i++) scanf("%lld",&bonus[i]);

    // sumPoint
    sumPoint[0]=0;
    for(int i=1; i<=N; i++) sumPoint[i]=sumPoint[i-1]+point[i];

    // D 배열 계산
    for(int i=0; i<=N; i++) D[i]=-INF;
    D[0]=0;
    pq.push(make_pair(D[0]-sumPoint[0], 0));

    for(int i=1; i<=N; i++){

        // case 1: i번 문제를 틀려서 코인 0개가 됨
        ll val1=-INF;
        while(!pq.empty()){
            ii f=pq.top();
            if(f.second>=max2(0,i-M)){
                val1=f.first;
                break;
            }
            else pq.pop();
        }
        val1+=sumPoint[i-1]-point[i];

        // case 2: i번 문제를 맞혀서 코인 0개가 됨 (즉, i-M번 문제에서 코인이 0개였고 i-M+1~i번 문제를 모두 맞혀서 i번 문제의 보너스 점수를 받음)
        ll val2=-INF;
        if(i>=M) val2=D[i-M]+sumPoint[i]-sumPoint[i-M]+bonus[i];

        // case 1과 2 중 더 큰 값을 취함
        D[i]=max2(D[i], val1);
        D[i]=max2(D[i], val2);

        // pq (max heap) 업데이트
        pq.push(make_pair(D[i]-sumPoint[i], i));
    }

    // 답 계산
    ll ans=D[N]; // 정의에 따라 D[N]은 N번 문제에서 코인 0개일 때의 최대 점수이므로, N번 문제를 맞혔으나 N번 문제의 보너스 점수를 받지 못한 경우는 고려하지 않은 것이다. 아래에서 그런 경우를 고려한다.
    for(int k=max2(0,N-M+1); k<N; k++)
        ans=max2(ans, D[k]+sumPoint[N]-sumPoint[k]);
    printf("%lld\n",ans);

    return 0;
}