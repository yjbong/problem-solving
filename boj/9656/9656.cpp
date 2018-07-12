#include <cstdio>
#define MAXSTONES 1000
#define UNKNOWN 0
#define WIN 1
#define LOSE 2
int N;
int winningState[MAXSTONES+1]; // cache

// win(i) = 돌이 i개 남아 있을 때, 현재 턴인 사람의 승리 여부
int win(int stones){
	if(winningState[stones]!=UNKNOWN) return winningState[stones];
	if(stones==0) return (winningState[stones]=WIN);

	// 현재 턴에서 돌을 1개 가져가는 경우
	if(stones-1>=0 && win(stones-1)==LOSE) return (winningState[stones]=WIN);

	// 현재 턴에서 돌을 3개 가져가는 경우
	if(stones-3>=0 && win(stones-3)==LOSE) return (winningState[stones]=WIN);

	return (winningState[stones]=LOSE);
}

int main(void){

	scanf("%d",&N);
	for(int i=0; i<=N; i++) winningState[i]=UNKNOWN;
	if(win(N)==WIN) printf("SK\n");
	else printf("CY\n");
	return 0;
}