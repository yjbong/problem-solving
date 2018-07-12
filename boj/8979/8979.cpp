#include <cstdio>
int N; // 국가의 수
int K; // 등수를 알고 싶은 국가의 번호
int gold[1001]; // gold[i] = i번 국가의 금메달 수
int silver[1001]; // silver[i] = i번 국가의 은메달 수
int bronze[1001]; // bronze[i] = i번 국가의 동메달 수

int main(void){
	scanf("%d %d",&N,&K);
	for(int i=0; i<N; i++){
		int num,g,s,b;
		scanf("%d %d %d %d",&num,&g,&s,&b);
		gold[num]=g;
		silver[num]=s;
		bronze[num]=b;
	}

	int ans=1;
	for(int i=1; i<=N; i++){
		if(gold[i]>gold[K]) ans++;
		else if(gold[i]==gold[K] && silver[i]>silver[K]) ans++;
		else if(gold[i]==gold[K] && silver[i]==silver[K] && bronze[i]>bronze[K]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}