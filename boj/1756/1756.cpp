#include <cstdio>

int D, N;
int a[333333]; // a[i] = 깊이 i에서의 오븐 반지름
int m[333333]; // m[i] = 깊이 구간 [1, i] 중 최소 반지름

int min2(int a, int b){ return a<b?a:b; }

int search(int left, int right, int num){

	int idx=right+1;
	while(left<=right){
		int mid=(left+right)/2;
		if(m[mid]<num){ // 조건 만족
			if(idx>mid) idx=mid; // 리턴 값 업데이트
			right=mid-1;
		}
		else left=mid+1;
	}
	// idx : [left,right] 구간 중 처음으로 num보다 작은 위치 (최대한 깊이 1에 가깝게)
	return (idx-1); // 피자는 idx 바로 위에 들어가게 됨
}

int main(void){

	scanf("%d %d",&D,&N);
	for(int i=1; i<=D; i++) scanf("%d",&a[i]);

	// m 배열 계산
	m[1]=a[1];
	for(int i=2; i<=D; i++) m[i]=min2(m[i-1],a[i]);

	// 피자가 들어올 때마다 쌓이는 곳 계산
	int right=D;
	int ans=D;
	for(int i=0; i<N; i++){
		int size; // 피자의 사이즈
		scanf("%d",&size);
		ans=search(1, right, size); // ans = 현재 피자가 들어간 위치
		if(ans==0) break; // 더 이상 오븐에 넣을 수 없음
		right=ans-1; // 다음 피자가 들어오면 현재 피자가 들어간 위치보다 깊이가 얕은 곳만 보게 됨
	}
	printf("%d\n",ans);	
	return 0;
}