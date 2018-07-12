#include <cstdio>
int n; // 수의 개수
int m; // 구간 업데이트 회수
int k; // 구간 합 계산 회수
long long a[1000000]; // 초기값
typedef struct node{
	long long value;
	long long lazy; // lazy propagation 값
}NODE;

NODE tree[1<<21]; // 세그먼트 트리
int leafStart; // leaf node 중 가장 작은 index

void init(){
	leafStart=1;
	while(leafStart<n) leafStart*=2;

	for(int i=leafStart; i<leafStart+n; i++) tree[i].value=a[i-leafStart];
	for(int i=leafStart+n; i<leafStart*2; i++) tree[i].value=0;
	for(int i=leafStart-1; i>=1; i--) tree[i].value=tree[i*2].value+tree[i*2+1].value;

	for(int i=1; i<leafStart*2; i++) tree[i].lazy=0;
}

///////////////////////////////////////////////////////////////////////////////////
// update(curIdx, curStart, curEnd, start, end, addValue) 의 의미
///////////////////////////////////////////////////////////////////////////////////
// a[start, end] 구간에 addValue 만큼을 더하기 위해
// 현재 세그먼트 트리에서 인덱스가 curIdx인 node를 변경할 차례이며,
// node[curIdx].value 가 나타내는 값은 a[curStart, curEnd] 구간의 합
///////////////////////////////////////////////////////////////////////////////////
void update(int curIdx, int curStart, int curEnd, int start, int end, long long addValue){

	// 업데이트 대상의 lazy 값이 0이 아닌 경우, lazy의 중복 반영을 피하기 위해 현재 lazy 값을 반영시킨 후 초기화해야 함
	if(tree[curIdx].lazy!=0){
		// lazy 값을 현재 node에 반영시킴
		tree[curIdx].value+=(curEnd-curStart+1)*tree[curIdx].lazy;
		// 현재 node가 나타내는 구간의 길이가 1보다 크면(curStart<curEnd), leaf node가 아니므로 자식 node에 lazy 전달해야 함
		if(curStart<curEnd){
			tree[curIdx*2].lazy+=tree[curIdx].lazy;
			tree[curIdx*2+1].lazy+=tree[curIdx].lazy;
		}
		// lazy 값 초기화
		tree[curIdx].lazy=0;	
	}

	// 현재 node가 표현하는 구간(a[curStart, curEnd])이 a[start, end] 와 전혀 겹치지 않는 경우
	if(end<curStart || start>curEnd) return;

	// 현재 node가 표현하는 구간(a[curStart, curEnd])이 a[start, end] 에 완전히 포함되는 경우
	if(start<=curStart && curEnd<=end){
		// original code
		tree[curIdx].value+=(curEnd-curStart+1)*addValue;
		if(curStart<curEnd){
			tree[curIdx*2].lazy+=addValue;
			tree[curIdx*2+1].lazy+=addValue;
		}
		return;
	}

	// 현재 node가 표현하는 구간이 a[start, end]에 일부 포함되는 경우
	update(curIdx*2, curStart, (curStart+curEnd)/2, start, end, addValue);
	update(curIdx*2+1, (curStart+curEnd)/2+1, curEnd, start, end, addValue);

	tree[curIdx].value=tree[curIdx*2].value+tree[curIdx*2+1].value;
}

///////////////////////////////////////////////////////////////////////////////////
// query(curIdx, curStart, curEnd, start, end) 의 의미
///////////////////////////////////////////////////////////////////////////////////
// a[start, end] 구간의 합을 구하기 위해
// 현재 세그먼트 트리에서 인덱스가 curIdx인 node를 조회할 차례이며,
// node[curIdx].value 가 나타내는 값은 a[curStart, curEnd] 구간의 합
///////////////////////////////////////////////////////////////////////////////////
long long query(int curIdx, int curStart, int curEnd, int start, int end){

	if(curStart>curEnd) return 0;

	// 업데이트 대상의 lazy 값이 0이 아닌 경우, lazy의 중복 반영을 피하기 위해 현재 lazy 값을 반영시킨 후 초기화해야 함
	if(tree[curIdx].lazy != 0){
		// lazy 값을 현재 node에 반영시킴
		tree[curIdx].value+=(curEnd-curStart+1)*tree[curIdx].lazy;
		// 현재 node가 나타내는 구간의 길이가 1보다 크면(curStart<curEnd), leaf node가 아니므로 자식 node에 lazy 전달해야 함
		if(curStart<curEnd){
			tree[curIdx*2].lazy+=tree[curIdx].lazy;
			tree[curIdx*2+1].lazy+=tree[curIdx].lazy;
		}
		// lazy 값 초기화
		tree[curIdx].lazy=0;
	}

	// 현재 node가 표현하는 구간(a[curStart, curEnd])이 a[start, end] 와 전혀 겹치지 않는 경우
	if(end<curStart || start>curEnd) return 0;

	// 현재 node가 표현하는 구간(a[curStart, curEnd])이 a[start, end] 에 완전히 포함되는 경우
	if(start<=curStart && curEnd<=end) return tree[curIdx].value;

	// 현재 node가 표현하는 구간이 a[start, end]에 일부 포함되는 경우
	return query(curIdx*2, curStart, (curStart+curEnd)/2, start, end) + query(curIdx*2+1, (curStart+curEnd)/2+1, curEnd, start, end);
}

int main(void){

	scanf("%d %d %d",&n,&m,&k);
	for(int i=0; i<n; i++) scanf("%lld",&a[i]);
	init();
	
	for(int i=0; i<m+k; i++){
		int option;
		scanf("%d",&option);

		// a[start, end] 구간에 addValue 더하기
		if(option==1){
			int start, end;
			long long addValue;
			scanf("%d %d %lld",&start,&end,&addValue);
			start--; end--;
			update(1, 0, leafStart-1, start, end, addValue);
		}
		// a[start, end] 구간 합 구하기
		else if(option==2){
			int start, end;
			long long sum;
			scanf("%d %d",&start,&end);
			start--; end--;
			sum=query(1, 0, leafStart-1, start, end);
			printf("%lld\n",sum);
		}
	}
	return 0;
}