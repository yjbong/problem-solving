#include <cstdio>
#define MAX_N 1000000
using namespace std;

// 움직이지 않는 아이들은 인덱스 상으로 증가하는 방향에 있으면서 숫자가 연속이어야 한다
int n;
int a[MAX_N];
int amax[MAX_N]; // amax[i] = i+1을 마지막으로 하면서 지금까지 구해진 d[i]의 최대값
int d[MAX_N]; // d[i] = a[i]를 마지막으로 하면서 숫자가 연속인 최대 증가 수열 (ex. 2,3,5 --> X, 2,3,4 --> O)
int max2(int a, int b){ return a>b?a:b; }

int main(void){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);

	// d 배열 초기화
	for(int i=0; i<n; i++) d[i]=1;

	// DP
	for(int i=0; i<n; i++){
		if(a[i]>1) d[i]=max2(d[i],amax[a[i]-2]+1);
		amax[a[i]-1]=max2(amax[a[i]-1],d[i]);
	}

	int longest=0;
	for(int i=0; i<n; i++) longest=max2(longest,d[i]);

	printf("%d\n",n-longest);
	return 0;
}