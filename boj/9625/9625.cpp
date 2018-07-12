#include <cstdio>
long long A[46]; // A[i] = 버튼을 i번 눌렀을 때 A의 개수
long long B[46]; // B[i] = 버튼을 i번 눌렀을 때 B의 개수

int main(void){
	int K;
	scanf("%d",&K);
	A[0]=1; B[0]=0;
	for(int i=1; i<=K; i++){
		A[i]=B[i-1];
		B[i]=A[i-1]+B[i-1];
	}
	printf("%lld %lld\n",A[K],B[K]);
	return 0;
}