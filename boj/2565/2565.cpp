#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii; // first: A전봇대 위치, second: B전봇대 위치
int n; // 전깃줄 개수
ii line[100]; // 전깃줄 정보
int d[100]; // line[i].second를 마지막으로 하는 최장 증가수열의 길이
int main(void){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d %d",&line[i].first,&line[i].second);
	sort(line,line+n);

	// 최장 증가 수열 계산
	for(int i=0; i<n; i++) d[i]=1;
	for(int i=0; i<n; i++)
		for(int j=0; j<i; j++)
			if(line[i].second>line[j].second && d[i]<d[j]+1) d[i]=d[j]+1;

	// 끊어야 하는 최소 전깃줄의 수 계산
	int ans=n;
	for(int i=0; i<n; i++) if(ans>n-d[i]) ans=n-d[i];
	printf("%d\n",ans);
	
	return 0;
}