#include <cstdio>

int n; // 석순+종유석 갯수
int h; // 동굴의 높이
int upCnt[555555]; // upCnt[i] = 높이가 i인 석순의 갯수
int downCnt[555555]; // downCnt[i] = 높이가 i인 종유석의 갯수
int upSum[555555]; // upSum[i] = upCnt[h]+ upCnt[h-1] + ... + upCnt[i]
int downSum[555555]; // downSum[i] = downCnt[h] + downCnt[h-1] + ... + downCnt[i]

int main(void){

	scanf("%d %d",&n,&h);
	for(int i=0; i<n; i++){
		int num;
		scanf("%d",&num);
		if(i%2==0) upCnt[num]++;
		else downCnt[num]++;
	}

	upSum[h]=upCnt[h];
	for(int i=h-1; i>=1; i--) upSum[i]=upSum[i+1]+upCnt[i];
	downSum[h]=downCnt[h];
	for(int i=h-1; i>=1; i--) downSum[i]=downSum[i+1]+downCnt[i];

	// 답 초기화
	int ans=n+1;
	int ansHeights;

	for(int i=1; i<=h; i++){
		// 높이 i로 비행할 경우 높이[i,h]인 석순과 높이[h-i+1,h]인 종유석을 파괴
		int curAns=upSum[i]+downSum[h-i+1];
		//printf("높이=%d --> 파괴=%d (석순=%d 종유석=%d)\n", i, curAns, upSum[i], downSum[h-i+1]);
		if(ans>curAns){
			ans=curAns;
			ansHeights=1;
		}
		else if(ans==curAns) ansHeights++;
	}
	printf("%d %d\n", ans, ansHeights);
	return 0;
}