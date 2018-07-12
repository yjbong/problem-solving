#include <cstdio>

int N; // 지방의 수
int M; // 총 예산액

int budget[10000]; // budget[i] = i번 지방에서 요청한 예산

// 상한액을 curLimit일 때 예산 배정이 가능한지 확인
bool isPossible(int curLimit){
	int totalBudget=0;
	for(int i=0; i<N; i++){
		if(budget[i]>curLimit) totalBudget+=curLimit;
		else totalBudget+=budget[i];
	}
	if(totalBudget>M) return false;
	else return true;
}

int main(void){

	scanf("%d",&N);

	int left, right;
	left=right=0;
	for(int i=0; i<N; i++){
		scanf("%d",&budget[i]);
		// 요청 예산 중 최대값을 고려할 상한액의 최대 범위로 설정
		if(right<budget[i]) right=budget[i];
	}
	scanf("%d",&M);

	int ans=0;
	while(left<=right){
		int mid=(left+right)/2;
		if(isPossible(mid)){
			if(ans<mid) ans=mid;
			left=mid+1;				
		}
		else right=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}