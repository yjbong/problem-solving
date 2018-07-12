#include <cstdio>
int N;
int v;
int cnt[201]; // cnt[i+100] = i인 수가 몇개인지 기록
int main(void){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		int num;
		scanf("%d",&num);
		cnt[num+100]++;
	}
	scanf("%d",&v);
	printf("%d\n",cnt[v+100]);
	return 0;
}