#include <cstdio>
#define INF 1000000000

// 자리번호 : 중앙 0, 위쪽 1, 왼쪽 2, 아래쪽 3, 오른쪽 4
// moveCost[i][j] = i번 자리에서 j번 자리로 이동할 때 드는 힘
const int moveCost[5][5]={
	{0,2,2,2,2},
	{2,1,3,4,3},
	{2,3,1,3,4},
	{2,4,3,1,3},
	{2,3,4,3,1}
};

int orders; // 지시 사항의 개수
int order[100001]; // order[i] = i번째 지시 사항

int d[100001][5][5]; // d[i][j][k] = 왼발이 j, 오른발이 k번 자리에 있을 때, order[i~orders-1] 을 순서대로 수행하기 위해 드는 힘의 최소값

int min2(int a, int b){ return a<b?a:b; }

int go(int orderIdx, int leftPos, int rightPos){
	if(orderIdx==orders) return 0;
	if(d[orderIdx][leftPos][rightPos]>=0) return d[orderIdx][leftPos][rightPos]; // memoization

	int ret=INF;
	// 왼발이 order[orderIdx] 위치에 이미 있는 경우, 왼발을 제자리에서 움직임
	if(leftPos==order[orderIdx]){
		ret=min2(ret, go(orderIdx+1, leftPos, rightPos)+moveCost[leftPos][leftPos]);
	}
	// 오른발이 order[orderIdx] 위치에 이미 있는 경우, 오른발을 제자리에서 움직임
	else if(rightPos==order[orderIdx]){
		ret=min2(ret, go(orderIdx+1, leftPos, rightPos)+moveCost[rightPos][rightPos]);
	}
	// 이외의 경우
	else{
		// 왼발을 order[orderIdx] 위치로 이동하는 경우
		ret=min2(ret, go(orderIdx+1, order[orderIdx], rightPos)+moveCost[leftPos][order[orderIdx]]);
		// 오른발을 order[orderIdx] 위치로 이동하는 경우
		ret=min2(ret, go(orderIdx+1, leftPos, order[orderIdx])+moveCost[rightPos][order[orderIdx]]);
	}

	return (d[orderIdx][leftPos][rightPos]=ret);
}

int main(void){

	while(1){
		int curOrder;
		scanf("%d",&curOrder);
		if(curOrder==0) break;
		order[orders++]=curOrder;
	}

	for(int i=0; i<=orders; i++)
	for(int j=0; j<5; j++)
	for(int k=0; k<5; k++)
		d[i][j][k]=-1;

	printf("%d\n",go(0,0,0));
	return 0;
}