#include <cstdio>
int ox[101]; // ox[i] : i번 문제 결과
int score[101]; // score[i] : i번 문제 점수
int n;
int main(void){
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&ox[i]);
	for(int i=1; i<=n; i++){
		if(ox[i]) score[i]=score[i-1]+1;
		else score[i]=0;
	}
	int ans=0;
	for(int i=1; i<=n; i++) ans+=score[i];
	printf("%d\n",ans);
	return 0;
}