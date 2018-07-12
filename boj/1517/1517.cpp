#include <cstdio>
#include <algorithm>
using namespace std;

int N; // 수열의 길이
int A[500000];

// for segment tree
int seg[1<<20];
int base;

// seg[base+idx]의 값을 add만큼 증가
void update(int idx, int add){
	idx+=base;
	seg[idx]+=add;
	idx/=2;
	while(idx>=1){
		seg[idx]=seg[idx*2]+seg[idx*2+1];
		idx/=2;
	}
}

// seg[base+left] ~ seg[base+right] 까지의 부분합을 구한다.
int querySum(int left, int right){

	int ret=0;
	left+=base, right+=base;

	while(left<right){
		if(left%2==0) left/=2;
		else{
			ret+=seg[left];
			left=(left+1)/2;
		}

		if(right%2==1) right/=2;
		else{
			ret+=seg[right];
			right=(right-1)/2;
		}
	}
	if(left==right) ret+=seg[left];

	return ret;
}

int main(void){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&A[i]);
		seg[i]=A[i];
	}
	sort(seg,seg+N);

	base=1;
	while(base<N) base*=2;

	int searchStart=N;
	int searchEnd=N;
	for(int i=0; i<N; i++)
		if(i==0 || seg[i]!=seg[i-1]) seg[searchEnd++]=seg[i];

	// A에 등장하는 수의 가짓수를 X라 했을 때, [10억 ~ 10억] 범위에 걸쳐 있는 A값들을
	// [0~X-1] 범위로 변경하여 segment tree의 인덱스와 일치시킨다.
	for(int i=0; i<N; i++){
		int left=searchStart, right=searchEnd-1;
		while(left<=right){
			int mid=(left+right)/2;
			if(A[i]>seg[mid]) left=mid+1;
			else if(A[i]<seg[mid]) right=mid-1;
			else{
				A[i]=mid-searchStart;
				break;
			}
		}
	}

	// segment tree 초기화
	for(int i=0; i<base*2; i++) seg[i]=0;

	// 답 계산
	long long ans=0;
	for(int i=N-1; i>=0; i--){
		ans+=querySum(0,A[i]-1); // 원래 수열에서 A[i] 보다 뒤에 있으면서 값이 작은 수들의 개수를 더한다.
		update(A[i],1); // 현재 A[i]를 segment tree에 업데이트
	}
	printf("%lld\n",ans);
	
	return 0;
}