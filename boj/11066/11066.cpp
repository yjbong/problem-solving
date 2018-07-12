#include <cstdio>
#define INF 2000000000
int T; // 테스트 케이스
int K; // 소설 장의 수
int a[500]; // 각 장의 크기
int s[500]; // s[i] = a[0]+a[1]+...+a[i]

int d[500][500]; // d[i][j] = a[i]~a[j]를 합치기 위한 최소 비용

int min2(int a, int b){ return a<b?a:b; }
int main(void){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&K);
		for(int i=0; i<K; i++) scanf("%d",&a[i]);

		// s계산
		s[0]=a[0];
		for(int i=1; i<K; i++) s[i]=s[i-1]+a[i];

		// d계산
		// 배열 초기화
		for(int i=0; i<K; i++){
			for(int j=0; j<K; j++){
				if(i==j) d[i][j]=0; // 1장인 경우 (합칠 필요 없음)
				else d[i][j]=INF;
			}
		}
		// DP
		for(int i=1; i<K; i++){
			for(int j=0; j+i<K; j++){
				for(int k=j; k<j+i; k++){
					int leftSize=s[k]-(j>0?s[j-1]:0);
					int rightSize=s[j+i]-s[k];
					d[j][j+i]=min2(d[j][j+i], d[j][k]+d[k+1][j+i]+leftSize+rightSize);
				}
			}
		}
		printf("%d\n",d[0][K-1]);
	}
	return 0;
}