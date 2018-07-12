#include <cstdio>
#include <deque>
int N; // 카드의 수
std::deque <int> dq;
int ans[1001];
int main(void){
	scanf("%d",&N);
	for(int i=1; i<=N; i++) dq.push_back(i);

	// 시뮬레이션
	for(int i=1; i<=N; i++){
		for(int j=0; j<i; j++){
			int f=dq.front();
			dq.pop_front();
			dq.push_back(f);
		}
		int f=dq.front();
		dq.pop_front();
		ans[f]=i; // i번 카드가 있어야 할 곳은 초기 상태에서 f번째 위치이다
	}
	// 출력
	for(int i=1; i<=N; i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}