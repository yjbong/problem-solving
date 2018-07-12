#include <cstdio>
int N; // 라운드 수
int A[1000000];
int B[1000000];
int main(void){
	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%d %d",&A[i],&B[i]);
	int as=0,bs=0;
	for(int i=0; i<N; i++){
		if(A[i]>B[i]) as++;
		else if(A[i]<B[i]) bs++;
	}
	printf("%d %d\n",as,bs);
	return 0;
}