#include <cstdio>
#include <algorithm>
using namespace std;
int N; // 숫자 카드의 개수
int A[500000];
int M; // 질문의 개수
int main(void){
	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%d",&A[i]);
	sort(A,A+N);

	scanf("%d",&M);
	for(int i=0; i<M; i++){
		int key;
		scanf("%d",&key);

		int found=0;
		int left=0, right=N-1;
		while(left<=right){
			int mid=(left+right)/2;
			if(key<A[mid]) right=mid-1;
			else if(key>A[mid]) left=mid+1;
			else{ found=1; break; }
		}
		printf("%d ",found);
	}
	printf("\n");

	return 0;
}