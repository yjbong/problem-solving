#include <cstdio>
#include <utility>
using namespace std;
typedef pair<int,int> ii; // first = h[idx], second = idx

int n; // 탑의 수
int h[500001]; // h[i] = i번 탑의 높이
int r[500001]; // a[i] = i번 탑의 신호를 수신하는 탑

ii stk[500001]; // 스택
int top;

int main(void){
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&h[i]);

	// 스택 초기화
	top=-1;
	stk[++top]=make_pair(h[n],n);

	// r 배열 세팅
	for(int i=n-1; i>=1; i--){
		while(top>=0 && h[i]>=stk[top].first){
			r[stk[top].second]=i;
			top--;
		}
		stk[++top]=make_pair(h[i],i);
	}

	// 출력
	for(int i=1; i<=n; i++) printf("%d ",r[i]);
	printf("\n");
	
	return 0;
}