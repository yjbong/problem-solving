#include <cstdio>
int N;
int A[1000000];
int main(void){
	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%d",&A[i]);
	int min=1000001;
	int max=-1000001;
	for(int i=0; i<N; i++){
		if(min>A[i]) min=A[i];
		if(max<A[i]) max=A[i];
	}
	printf("%d %d\n",min,max);
	return 0;
}