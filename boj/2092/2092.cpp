#include <cstdio>
#include <algorithm>
#define MOD 1000000

using namespace std;

int T; // 등장하는 수의 범위
int A; // 수열의 길이
int S,B; // 구하고자 하는 집합 크기의 범위 [S~B]

int in[4001]; // 입력된 수 리스트

int a[4001]; // 오름차순 정렬된 등장하는 수의 목록 (중복 제거), a[1]부터 시작
int as; // a배열의 크기
int c[4001]; // 입력 리스트에서 a[i]의 개수
int sum[4001]; // sum[i] = c[1]+c[2]+...c[i]

//int d[4001][4001]; // a[1~i] 에서 j개의 수를 골라 만들 수 있는 집합의 가짓수
int d[2][4001]; // mem 최적화

int main(void){

	// 입력
	scanf("%d %d %d %d",&T,&A,&S,&B);
	for(int i=0; i<A; i++) scanf("%d",&in[i]);

	// 수열 오름차순 정렬
	sort(in,in+A);

	// a, c 배열 구성
	as=0;
	for(int i=0; i<A; i++){
		if(i==0 || in[i]!=in[i-1]){
			a[++as]=in[i];
			c[++as]=1;
		}
		else c[as]++;
	}
	// sum 배열 구성
	sum[1]=c[1];
	for(int i=2; i<=as; i++) sum[i]=sum[i-1]+c[i];

	// DP
	d[0][0]=1;

	// mem 최적화 위해서 현재 구할 i는 i%2로, i를 구하기 위해 이용되는 바로 이전 값인 (i-1) 은 (1-i%2) 가 됨
	for(int i=1; i<=as; i++){
		for(int j=0; j<=sum[i]; j++){
			if(j==0) d[i%2][j]=1;
			else{
				for(int k=0; k<=c[i] && j-k>=0 ; k++) // a[i]를 0, 1, ... , c[i]개 고르는 경우를 더함
					d[i%2][j] = (d[i%2][j] + d[1-i%2][j-k]) % MOD;
			}
		}

		// 다음에 값을 업데이트할 배열 원소 초기화
		for(int j=0; j<=A; j++) d[1-i%2][j]=0;
	}
	
	// 답 구하기
	int ans=0;
	for(int i=S; i<=B; i++) ans = (ans+d[as%2][i]) % MOD;
	printf("%d\n",ans);

	return 0;
}