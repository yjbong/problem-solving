#include <cstdio>
int N; // 수열의 길이
int T; // Target number
int A[111]; // A[i] = 수열의 i번째 수
bool D[111][20001]; // D[i][j+10000] = 부분수열 A[0~i]을 축소하여 수 j를 만들 수 있는지 여부
bool minusPlus[111]; // minusPlus[i] = A[i]에서 A[i+1]를 빼면(A[i]-A[i+1]) false, 더하면(A[i]+A[i+1]) true로 표시

int main(void){
	scanf("%d %d",&N,&T);
	for(int i=0; i<N; i++) scanf("%d",&A[i]);

	// DP 테이블 계산
	D[0][A[0]+10000]=true;
	if(N>1) D[1][A[0]-A[1]+10000]=true;
	for(int i=2; i<N; i++)
		for(int j=0; j<=20000; j++)
			D[i][j]=D[i-1][j-A[i]] || D[i-1][j+A[i]];

	if(D[N-1][T+10000]){ // 답이 존재하는 경우
		//printf("Yes\n");
		int idx=N-1;
		int num=T+10000;
		while(idx>0){
			if(D[idx-1][num+A[idx]]){ // A[idx]를 빼는 경우
				minusPlus[idx-1]=false;
				num=num+A[idx];
				idx--;
			}
			else if(D[idx-1][num-A[idx]]){ // A[idx]를 더하는 경우
				minusPlus[idx-1]=true;
				num=num-A[idx];
				idx--;
			}
		}
	}

	for(int i=0; i<N-1; i++){ // 수열 축소를 N-1번 해야 한 개의 수가 남음
		/*
		for(int j=0; j<N-1-i; j++){
			if(A[j]<0) printf("(%d)",A[j]);
			else printf("%d",A[j]);
			if(minusPlus[j]==false) printf("-");
			else printf("+");
		}
		if(A[N-1-i]<0) printf("(%d)\n",A[N-1-i]);
		else printf("%d\n",A[N-1-i]);
		*/

		int curReduceIdx=0; // + 기호가 없다면 가장 앞의 - 기호가 축소 대상
		for(int j=0; j<N-1-i; j++){
			if(minusPlus[j]==true){ curReduceIdx=j; break; }
		}
		printf("%d\n",curReduceIdx+1);

		// 시뮬레이션 (A[curReduceIdx], A[curReduceIdx+1] --> A[curReduceIdx]-A[curReduceIdx+1] 로 축소)
		A[curReduceIdx]=A[curReduceIdx]-A[curReduceIdx+1];
		for(int j=curReduceIdx+1; j<N-i-1; j++) A[j]=A[j+1];
		for(int j=curReduceIdx; j<N-i-2; j++) minusPlus[j]=minusPlus[j+1];
	}
	
	return 0;
}