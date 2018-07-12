#include <cstdio>
int N; // 일수
int T[15]; // T[i]=i일에 하는 상담에 걸리는 일수 (0<=i<N)
int P[15]; // P[i]=i일에 하는 상담의 수익

int main(void){
	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%d %d",&T[i],&P[i]);

	int ans=0;
	for(int i=0; i<(1<<N); i++){
		int curAns=0;
		for(int j=0; j<N; j++){
			// j일에 상담을 하기로 함
			if(i&(1<<j)){
				if(j+T[j]-1<N){ // 상담 가능한 경우
					curAns+=P[j];
					j+=T[j]-1; // 이 상담을 하면 추가로 건너뛰게 되는 일자
				}
			}
		}
		if(ans<curAns) ans=curAns;
	}
	printf("%d\n",ans);
	return 0;
}