#include <cstdio>
#include <algorithm>
using namespace std;
int N; // 저울추의 개수
int w[1001]; // 저울추 (오름차순 정렬)
int s[1001]; // s[i] = w[1]부터 w[i]까지의 합 (w[1~i]로 만들 수 있는 최대 무게)
int main(void){
	scanf("%d",&N);
	for(int i=1; i<=N; i++) scanf("%d",&w[i]);
	sort(w,w+N+1);

	// s 계산
	s[0]=w[0];
	for(int i=1; i<=N; i++) s[i]=s[i-1]+w[i];

	int ans=s[N]+1;
	for(int i=1; i<=N; i++){
		// i번째 추를 이용하여 무게 s[i-1]+1를 만들 수 없으려면 아래 2가지 조건을 모두 만족해야 함
		// 1. w[i] != s[i-1]+1
		// 2. 앞에서부터 만들 수 있는 가장 작은 무게는 1이므로, w[i]+1 > s[i-1]+1 이면 뒤쪽에 있는 추들의 무게는
		// 모두 w[i] 이상이므로 앞으로도 s[i-1]+1의 무게는 만들 수 없음
		if(w[i]!=s[i-1]+1 && w[i]+1>s[i-1]+1){
			ans=s[i-1]+1;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}