#include <cstdio>
#include <stack>
#include <utility>
#define MAX_N 100000
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii; // first: 구간 인덱스, second: 현재 구간에서의 최소값 (인덱스는 1부터 시작)

int N; // 수열의 길이 a[1]~a[N]
ll a[MAX_N+1]; // 수열
ll s[MAX_N+1]; // s[i] = a[1]+a[2]+...+a[i]

stack <ii> stk;

int main(void){
	scanf("%d",&N);
	for(int i=1; i<=N; i++) scanf("%lld",&a[i]);

	// s 계산
	s[0]=0;
	for(int i=1; i<=N; i++) s[i]=s[i-1]+a[i];

	ll ans=-1;
	ll ansStartIdx=-1;
	ll ansEndIdx=-1;
	for(int i=1; i<=N; i++){
		ll minValOfTop;
		ll startIdxOfTop;
		ll pushIdx=i;

		// 스택에는 현재까지 유효한 "구간 인덱스와 최소값 쌍"이 들어있다.
		// 만약 a[i]가 스택의 top에 들어있는 구간의 최소값 보다 작다면, top은 더이상 유효하지 않다.
		// 아래 루프에서는 유효하지 않게된 top을 삭제하기 전에 top의 내용을 답에 반영한다.
		//while((!stk.empty()) && a[i]<(minValOfTop=stk.top().second)){
		while((!stk.empty()) && a[i]<=(minValOfTop=stk.top().second)){
			startIdxOfTop=stk.top().first;
			if(ans<(s[i-1]-s[startIdxOfTop-1])*minValOfTop){ // top에서 나타내는 구간 시작값부터, i-1을 구간 마지막으로 하는 경우의 점수를 답과 비교
				ans=(s[i-1]-s[startIdxOfTop-1])*minValOfTop;
				ansStartIdx=startIdxOfTop;
				ansEndIdx=i-1;
			}
			pushIdx=startIdxOfTop; // pushIdx는 a[i]를 최소값으로 반영하는 구간 시작값을 저장한다.
			stk.pop(); // a[i]에 대해, 유효한 top을 만날때까지 top을 삭제
		}
		stk.push(make_pair(pushIdx,a[i])); // a[i]를 최소값으로 하는 유효한 쌍을 push
		/*
		printf("stack at iteration %d\n",i);
		stack <ii> tmp;
		while(!stk.empty()){
			printf("(%lld,%lld) ", stk.top().first, stk.top().second);
			tmp.push(stk.top());
			stk.pop();
		}
		printf("\n");
		while(!tmp.empty()){
			stk.push(tmp.top());
			tmp.pop();
		}
		*/
	}

	// 스택에 남아있는 쌍에 대한 처리
	while(!stk.empty()){
		ll minValOfTop=stk.top().second;
		ll startIdxOfTop=stk.top().first;
		if(ans<(s[N]-s[startIdxOfTop-1])*minValOfTop){ // top에서 나타내는 구간 시작값부터, N을 구간 마지막으로 하는 경우의 점수를 답과 비교
			ans=(s[N]-s[startIdxOfTop-1])*minValOfTop;
			ansStartIdx=startIdxOfTop;
			ansEndIdx=N;
		}
		stk.pop();
	}
	// 답 출력
	printf("%lld\n",ans);
	printf("%lld %lld\n",ansStartIdx,ansEndIdx);
	return 0;
}