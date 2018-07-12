#include <cstdio>
#include <algorithm>
#define INF 1000000000000000000ll
using namespace std;
typedef long long ll;
int n; // 수열의 길이
ll a[2001]; // a[i] = 입력된 수열의 i번째 원소

ll ainc[2001]; // ainc[i] = 오름차순 정렬된 수열 a의 i번째 원소
ll dinc[2001][2001]; // 단조증가수열 b에 대해, b[i]==ainc[j] 일 때, |a[1]-b[1]+ ... +|a[i]-b[i]| 의 최소값

ll adec[2001]; // ainc[i] = 내림차순 정렬된 수열 a의 i번째 원소
ll ddec[2001][2001]; // 단조감소수열 b에 대해, b[i]==adec[j] 일 때, |a[1]-b[1]+ ... +|a[i]-b[i]| 의 최소값

int baseIdx;

ll segTree[2][1<<12]; // min heap

ll abs2(ll a){ return a>=0?a:(-a); }
ll min2(ll a, ll b){ return a<b?a:b; }

void init(ll tree[]){ for(int i=baseIdx*2-1; i>=1; i--) tree[i]=INF; }

void update(ll tree[], int idx, ll val){
	idx+=baseIdx;
	tree[idx]=min2(tree[idx],val);
	idx/=2;

	while(idx>0){
		tree[idx]=min2(tree[idx*2],tree[idx*2+1]);
		idx/=2;
	}
}

ll query(ll tree[], int leftIdx, int rightIdx){

	ll minVal=INF;

	leftIdx+=baseIdx;
	rightIdx+=baseIdx;

	while(leftIdx<=rightIdx){
		if(leftIdx%2==0) leftIdx/=2;
		else{
			minVal=min2(minVal,tree[leftIdx]);
			leftIdx=(leftIdx+1)/2;
		}

		if(rightIdx%2==1) rightIdx/=2;
		else{
			minVal=min2(minVal,tree[rightIdx]);
			rightIdx=(rightIdx-1)/2;
		}
	}

	if(leftIdx==rightIdx) minVal=min2(minVal,tree[leftIdx]);
	return minVal;
}


int main(void){

	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%lld",&a[i]);

	baseIdx=1;
	while(baseIdx<n) baseIdx*=2;

	int curTree;

	ll ans=INF;

	// b[i]가 단조증가수열인 경우
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) dinc[i][j]=INF;

	for(int i=0; i<n; i++) ainc[i]=a[i];
	sort(ainc,ainc+n);

	curTree=0; // 이번 iteration에서 업데이트되는 Tree의 인덱스 (이번 iteration에서 참조되는 Tree의 인덱스 = 1-curTree)
	init(segTree[curTree]);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i>0) dinc[i][j]=min2(dinc[i][j], query(segTree[1-curTree],0,j)+abs2(a[i]-ainc[j]));
			else dinc[i][j]=min2(dinc[i][j],abs2(a[i]-ainc[j]));

			update(segTree[curTree],j,dinc[i][j]);
		}

		curTree=1-curTree;
		init(segTree[curTree]);
	}
	for(int j=0; j<n; j++) ans=min2(ans,dinc[n-1][j]);
	
	
	// b[i]가 단조감소수열인 경우
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) ddec[i][j]=INF;

	for(int i=0; i<n; i++) adec[i]=ainc[n-1-i];

	curTree=0; // 이번 iteration에서 업데이트되는 Tree의 인덱스 (이번 iteration에서 참조되는 Tree의 인덱스 = 1-curTree)
	init(segTree[curTree]);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i>0) ddec[i][j]=min2(ddec[i][j], query(segTree[1-curTree],0,j)+abs2(a[i]-adec[j]));
			else ddec[i][j]=min2(ddec[i][j],abs2(a[i]-adec[j]));

			update(segTree[curTree],j,ddec[i][j]);
		}

		curTree=1-curTree;
		init(segTree[curTree]);
	}
	for(int j=0; j<n; j++) ans=min2(ans,ddec[n-1][j]);

	printf("%lld\n",ans);
	return 0;
}