#include <cstdio>
#include <algorithm>
int N; // 순열의 길이
int a[10000]; // 순열
int main(void){
	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%d",&a[i]);
	int idx=N-1; // 뒤에서부터 봤을 때, 내림차순 순열이 시작되는 인덱스
	for(int i=N-2; i>=0; i--){
		if(a[i]>a[idx]) idx--;
		else break;
	}
	if(idx==0) printf("-1\n");
	else{
		// idx-1 과 swap할 원소를 정함
		int swapIdx=-1;
		for(int i=N-1; i>=idx; i--)
			if(a[i]>a[idx-1])
				if(swapIdx<0 || a[swapIdx]>a[i]) swapIdx=i;

		// swap
		int tmp=a[idx-1];
		a[idx-1]=a[swapIdx];
		a[swapIdx]=tmp;

		// idx부터 끝까지 오름차순 소트
		std::sort(a+idx,a+N);

		// 답 출력
		for(int i=0; i<N; i++) printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}