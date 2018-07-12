#include <cstdio>
#define HEAPSIZE 10000
#define INF 1000000000

int seq[1000]; // 수열
int seqSize; // 수열의 크기

int sortedSeq[1000]; // 중복 제거, 오름차순 정렬된 수열
int sortedSeqSize;

int seqDiff[1000*1000]; // sortedSeq에서 임의의 두 수를 골랐을 때, 가능한 차이값 목록
int seqDiffSize;

int gcd(int p, int q)
{
    if (q==0) return p;
    return gcd(q, p%q);
}

// minimum heap
int heap[HEAPSIZE+2];
int heapSize;
int min2(int a, int b){ return a<b?a:b; }
void heapInit(void){
	for(int i=0; i<=HEAPSIZE+1; i++) heap[i]=INF;
	heapSize=0;
}

void heapPush(int item){
	heap[++heapSize]=item;
	int idx=heapSize;
	while(idx/2>0){
		if(heap[idx/2]>heap[idx]){
			int tmp=heap[idx];
			heap[idx]=heap[idx/2];
			heap[idx/2]=tmp;
		}
		else break;
	}
}

int heapPop(void){
	int item=heap[1];

	heap[1]=heap[heapSize];
	heap[heapSize--]=INF;

	int idx=1;
	while(idx*2<=heapSize){
		int minChildIdx=idx*2;
		if(heap[idx*2]>heap[idx*2+1]) minChildIdx=idx*2+1;

		if(heap[idx]>heap[minChildIdx]){
			int tmp=heap[idx];
			heap[idx]=heap[minChildIdx];
			heap[minChildIdx]=tmp;

			idx=minChildIdx;
		}
		else break;
	}
	return item;
}

int main(void){
	scanf("%d",&seqSize);
	for(int i=0; i<seqSize; i++) scanf("%d",&seq[i]);

	// seq를 오름차순 정렬 및 중복값 제거하여 sortedSeq 생성
	heapInit();
	for(int i=0; i<seqSize; i++) heapPush(seq[i]);
	sortedSeqSize=0;
	for(int i=0; i<seqSize; i++){
		int curNum = heapPop();
		if(sortedSeqSize==0 || curNum!=sortedSeq[sortedSeqSize-1])
			sortedSeq[sortedSeqSize++]=curNum;
	}

	// seqDiff 생성
	seqDiffSize=0;
	for(int i=0; i<sortedSeqSize; i++)
		for(int j=0; j<i; j++)
			seqDiff[seqDiffSize++]=sortedSeq[i]-sortedSeq[j];

	// 답 계산
	int ans=seqDiff[0];
	for(int i=1; i<seqDiffSize; i++) ans=gcd(ans,seqDiff[i]);
	printf("%d\n",ans);
	return 0;
}