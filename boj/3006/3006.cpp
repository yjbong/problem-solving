#include <cstdio>
#define INF 1000000000
int N; // 1~N의 수
int a[100000];

int segTree[1<<18];
int base;

int idx2seg[100000];

int getRangeSum(int start, int end){
	start+=base;
	end+=base;

	int ret=0;
	while(start<end){
		if(start%2==0) start/=2;
		else{
			ret+=segTree[start];
			start=(start+1)/2;
		}
		if(end%2==1) end/=2;
		else{
			ret+=segTree[end];
			end=(end-1)/2;
		}
	}
	if(start==end) ret+=segTree[start];
	return ret;
}
void updateSum(int idx, int val){
	idx+=base;
	segTree[idx]=val;
	idx/=2;
	while(idx>=1){
		segTree[idx]=segTree[idx*2]+segTree[idx*2+1];
		idx/=2;
	}
}

int main(void){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&a[i]);
		a[i]--; // index가 0부터인 것으로 생각
	}

	base=1;
	while(base<N) base*=2;

	for(int i=0; i<N; i++) idx2seg[a[i]]=i;

	// init segment tree
	for(int i=base; i<base*2; i++) segTree[i]=0;
	for(int i=0; i<N; i++) segTree[base+i]=1;
	for(int i=base-1; i>=1; i--) segTree[i]=segTree[i*2]+segTree[i*2+1];

	// 답 출력
	for(int i=0; i<N; i++){
		if(i%2==0){
			printf("%d\n",getRangeSum(0, idx2seg[i/2]-1));
			updateSum(idx2seg[i/2],0);
		}
		else{
			printf("%d\n",getRangeSum(idx2seg[N-1-i/2]+1, N-1));
			updateSum(idx2seg[N-1-i/2],0);
		}
	}	
	return 0;
}