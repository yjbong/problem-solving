#include <cstdio>
typedef long long ll;
int kinds; // 구슬의 종류
int quantity[5]; // q[i] = 색이 i인 구슬의 개수
int weight[5]; // weight[i] = 색이 i인 구슬에 대한 state 가중치

ll d[1<<(3*5)][5+1][5+1]; // d[i][j][k] = 남은 구슬의 상태가 i, 마지막으로 사용된 두 구슬의 색이 각각 j, k (j가 가장 최근) 일 때, 가능한 목걸이 배치의 수

// 현재 구슬 수량으로 상태값 리턴
int getState(int curQuantity[5]){
	int ret=0;
	for(int i=0; i<kinds; i++) ret+=curQuantity[i]*weight[i];
	return ret;
}

// 현재 상태값에 대한 구슬 수량 리턴
void getQuantity(int curState, int curQuantity[5]){
	for(int i=kinds-1; i>=0; i--){
		curQuantity[i]=curState/weight[i];
		curState-=curQuantity[i]*weight[i];
	}
}

// d[state][c0][c1] 계산
ll go(int state, int c0, int c1){

	if(d[state][c0][c1]>=0) return d[state][c0][c1]; // 메모이제이션
	if(state==0) return 1; // 남은 구슬이 없는 경우

	ll ret=0;

	int curQuantity[5];
	getQuantity(state, curQuantity);
	for(int i=0; i<kinds; i++){
		// 이번에 색이 i인 구슬을 놓기 위해서는 그런 구슬이 남아있어야 하고,
		// 최근에 사용된 2개의 구슬의 색이 i가 아니어야 함
		if(i!=c0 && i!=c1 && curQuantity[i]>0){
			curQuantity[i]--;
			ret+=go(getState(curQuantity), i, c0);
			curQuantity[i]++;
		}
	}
	return (d[state][c0][c1]=ret);
}

int main(void){

	scanf("%d",&kinds);
	for(int i=0; i<kinds; i++) scanf("%d",&quantity[i]);

	// 상태값을 표시하기 위한 색깔 별 가중치 값 계산
	weight[0]=1;
	for(int i=1; i<kinds; i++) weight[i]=weight[i-1]*(quantity[i-1]+1);

	// 초기 상태값 계산
	int state = getState(quantity);

	// cache 배열 초기화
	for(int i=0; i<=state; i++)
		for(int j=0; j<=kinds; j++)
			for(int k=0; k<=kinds; k++) d[i][j][k]=-1;

	// 답 계산
	ll ans=go(state, kinds, kinds);

	// 출력
	printf("%lld\n", ans);
	return 0;
}