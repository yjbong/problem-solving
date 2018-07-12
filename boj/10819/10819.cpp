#include <cstdio>
#include <cstdlib>
#include <algorithm>
int N; // 배열 크기
int A[8]; // 배열
int order[8];
int main(void){
	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%d",&A[i]);
	for(int i=0; i<N; i++) order[i]=i;

	int ans=0;
	do{
		int curAns=0;
		for(int i=0; i<N-1; i++) curAns+=abs(A[order[i]]-A[order[i+1]]);
		if(ans<curAns) ans=curAns;	
	}while(std::next_permutation(order,order+N));
	printf("%d\n",ans);
	return 0;
}