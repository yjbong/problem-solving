#include <cstdio>
int n; // 사람의 수
int b[1000]; // b[i] = i번 사람의 콜라 브랜드
int d[1000][1000]; // d[i][j] = i~j 번 사람에 대하여 건배를 할 수 있는 최대 쌍의 수

int max2(int a, int b){ return a>b?a:b; }

int main(void){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&b[i]);

	int ans=0;
	if(n>=2){
		// 구간 크기가 1미만인 경우는 d[i][j]값이 0일 수밖에 없음

		// 구간 크기가 2인 경우에 대한 초기화
		for(int j=0; j<n; j++){
			// 인접한 두 사람의 콜라 브랜드가 같은 경우
			if(b[j]==b[(j+1)%n]) d[j][(j+1)%n]=1;
			else d[j][(j+1)%n]=0;
		}

		// 구간 크기가 3~n --> DP
		for(int i=2; i<n; i++){
			// 구간의 시작 인덱스가 j (구간: j~j+i)
			for(int j=0; j<n; j++){
				// case 1 : j번과 j+i번 사람이 건배하는 경우
				if(b[j]==b[(j+i)%n]) d[j][(j+i)%n]=max2(d[j][(j+i)%n], d[(j+1)%n][(j+i-1)%n]+1);

				// case 2 : 두 개로 분할된 구간의 답을 합하는 경우
				for(int k=j; k!=(j+i)%n; k=(k+1)%n)
					d[j][(j+i)%n]=max2(d[j][(j+i)%n], d[j][k]+d[(k+1)%n][(j+i)%n]);
			}
		}
		ans=d[0][n-1];
	}
	printf("%d\n",ans);
	return 0;
}