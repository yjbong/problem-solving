#include <cstdio>
#define MAX_N 10
#define MAX_M 50
int N; // 기타의 개수
int M; // 곡의 개수

bool playable[MAX_N][MAX_M];
bool curPlayable[MAX_M];

int main(void){
	scanf("%d %d\n",&N,&M);
	for(int i=0; i<N; i++){
		char tmp[MAX_M+1];
		scanf("%*s %s\n",tmp);
		for(int j=0; j<M; j++)
			playable[i][j]=(tmp[j]=='Y'?true:false);
	}

	int guitars=N+1;
	int songs=0;

	// 모든 경우 탐색
	for(int i=0; i<(1<<N); i++){
		int curGuitars=0;
		int curSongs=0;
		for(int j=0; j<M; j++) curPlayable[j]=false;
		for(int j=0; j<N; j++){
			if(i&(1<<j)){
				curGuitars++;
				for(int k=0; k<M; k++)
					if(playable[j][k]) curPlayable[k]=true;
			}
		}
		for(int j=0; j<M; j++) if(curPlayable[j]) curSongs++;

		if((songs<curSongs) || (songs==curSongs && guitars>curGuitars)){
			guitars=curGuitars;
			songs=curSongs;
		}
	}

	if(songs==0) printf("-1\n"); // 연주할 수 있는 곡이 없는 경우
	else printf("%d\n",guitars);
	return 0;
}