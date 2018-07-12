#include <cstdio>
int T;
int N;
int A[1000]; // A[i] = i번째 카드의 점수
int S[1000]; // S[i] = A[0]+...+A[i]
int D[1000][1000]; // D[i][j] = 왼쪽 끝 카드가 A[i], 오른쪽 끝 카드가 A[j]일 때 현재 차례 플레이어가 얻을 수 있는 최대 점수
int max2(int a, int b){ return a>b?a:b; }

int rangeSum(int left, int right){ // return A[left]+A[left+1]+ ... +A[right]
	if(left>=1) return S[right]-S[left-1];
	else return S[right];
}
int getMaxVal(int left, int right){
	if(D[left][right]>=0) return D[left][right]; // memoization

	if(left>right) return 0; // 카드가 남아있지 않은 경우
	else if(left==right) return A[left]; // 카드가 1개만 있는 경우
	else{
		// 현재 플레이어가 왼쪽 끝 카드를 가져가는 경우 얻을 수 있는 점수 
		int pickLeft=A[left]+rangeSum(left+1,right)-getMaxVal(left+1,right);
		// 현재 플레이어가 오른쪽 끝 카드를 가져가는 경우 얻을 수 있는 점수
		int pickRight=A[right]+rangeSum(left,right-1)-getMaxVal(left,right-1);

		return (D[left][right]=max2(pickLeft,pickRight));
	}
}
int main(void){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=0; i<N; i++) scanf("%d",&A[i]);
		S[0]=A[0];
		for(int i=1; i<N; i++) S[i]=S[i-1]+A[i];

		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++) D[i][j]=-1;

		printf("%d\n",getMaxVal(0,N-1));
	}
	return 0;	
}