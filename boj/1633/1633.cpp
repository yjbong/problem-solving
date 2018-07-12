#include <cstdio>
int players; // 선수의 수
int white[1000]; // white[i] = i번 선수가 백을 잡았을 때 능력치
int black[1000]; // black[i] = i번 선수가 흑을 잡았을 때 능력치
int d[1000][16][16]; // d[i][j][k] = 0~i번 선수에 대해, 백이 j명이고 흑이 k명 선발되었을 때 선발된 선수 능력치의 최대합
int max2(int a, int b){ return a>b?a:b; }
int main(void){
	players=0;
	int w,b;
	while(scanf("%d %d",&w,&b)==2){
		white[players]=w;
		black[players++]=b;
	}

	// DP
	d[0][0][0]=0;
	d[0][1][0]=white[0];
	d[0][0][1]=black[0];
	for(int i=1; i<players; i++){
		for(int j=0; j<=15; j++){
			for(int k=0; k<=15; k++){
				// i번 선수를 선택하지 않는 경우
				d[i][j][k]=max2(d[i][j][k],d[i-1][j][k]);

				// i번 선수가 백인 경우
				if(j>0) d[i][j][k]=max2(d[i][j][k],d[i-1][j-1][k]+white[i]);

				// i번 선수가 흑인 경우
				if(k>0) d[i][j][k]=max2(d[i][j][k],d[i-1][j][k-1]+black[i]);
			}
		}
	}
	printf("%d\n",d[players-1][15][15]);
	return 0;
}