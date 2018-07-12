#include <cstdio>
#define UNKNOWN 0
#define WIN 1
#define LOSE 2
int b1,b2,b3; // 한번에 꺼낼수 있는 구슬의 개수
int win[501][501]; // win[i][j] = 1번 통에 구슬이 i개, 2번 통에 j개 남아있을 때, 현재 턴인 사람이 이길 수 있는지 여부

// 1번 통에 구슬이 k1개, 2번 통에 k2개 있을 때, 현재 턴인 사람이 이길 수 있는지 여부
int go(int k1, int k2){
	if(win[k1][k2]!=UNKNOWN) return win[k1][k2]; // memoization
	if(k1<b1 && k2<b1) return (win[k1][k2]=LOSE); // 규칙에 맞게 구슬을 꺼낼 방법이 없는 경우

	// 1번 통에서 구슬을 b1개 꺼내는 경우
	if(k1>=b1 && go(k1-b1,k2)==LOSE) return (win[k1][k2]=WIN);
	// 1번 통에서 구슬을 b2개 꺼내는 경우
	if(k1>=b2 && go(k1-b2,k2)==LOSE) return (win[k1][k2]=WIN);
	// 1번 통에서 구슬을 b3개 꺼내는 경우
	if(k1>=b3 && go(k1-b3,k2)==LOSE) return (win[k1][k2]=WIN);

	// 2번 통에서 구슬을 b1개 꺼내는 경우
	if(k2>=b1 && go(k1,k2-b1)==LOSE) return (win[k1][k2]=WIN);
	// 2번 통에서 구슬을 b2개 꺼내는 경우
	if(k2>=b2 && go(k1,k2-b2)==LOSE) return (win[k1][k2]=WIN);
	// 2번 통에서 구슬을 b3개 꺼내는 경우
	if(k2>=b3 && go(k1,k2-b3)==LOSE) return (win[k1][k2]=WIN);

	return (win[k1][k2]=LOSE);
}

int main(void){
	scanf("%d %d %d",&b1,&b2,&b3);
	for(int i=0; i<5; i++){
		int k1,k2; // 처음에 두 통에 들어있는 구슬의 개수
		scanf("%d %d",&k1,&k2);
		if(go(k1,k2)==WIN) printf("A\n");
		else printf("B\n");
	}
	return 0;
}