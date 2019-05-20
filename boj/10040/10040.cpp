#include <cstdio>
int N; // 경기의 수
int M; // 위원의 수
int A[1001]; // A[i]=i번 경기의 개최 비용
int B[1001]; // B[i]=i번 위원의 심사 기준
int V[1001]; // V[i]=i번 경기가 받은 표
int main(void){
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++)
	    scanf("%d",&A[i]);
	for(int i=1;i<=M;i++)
	    scanf("%d",&B[i]);
	
	// 각 위원이 투표
	for(int i=1;i<=M;i++)
		for(int j=1;j<=N;j++)
			if(A[j]<=B[i]){
				V[j]++;
				break;
			}
	
	// 가장 많은 표를 받은 경기를 출력
	int maxV=-1;
	int ans;
	for(int i=1;i<=N;i++){
		if(maxV<V[i]){
			maxV=V[i];
			ans=i;
		}
	}
	printf("%d\n",ans);
	return 0;
}
