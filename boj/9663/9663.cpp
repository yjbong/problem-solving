#include <cstdio>
#include <cstdlib>
#define MAX_N 15

int N;
int ans;
// go(lastRow, lastCol) = 이미 놓여진 퀸들이 서로를 공격할 수 없고, 마지막에 퀸을 놓은 줄이 lastRow일 때의 상태
int qpos[MAX_N+1]; // qpos[i] = i번 row에 놓인 퀸의 col값
void go(int lastRow){
	if(lastRow==N){
		ans++;
		return;
	}

	for(int i=1; i<=N; i++){
		bool ok=true;
		// (lastRow+1, i)에 퀸을 놓을 수 있는지 확인
		for(int j=1; j<=lastRow; j++){
			if(qpos[j]==i){ ok=false; break; } // 이전에 놓은 퀸과 같은 열에 위치
			if(abs(j-(lastRow+1)) == abs(qpos[j]-i)){ ok=false; break; } // 이전에 놓은 퀸과 같은 대각선상에 위치
		}
		if(ok){
			qpos[lastRow+1]=i;
			go(lastRow+1);
		}
	}
}
int main(void){
	scanf("%d",&N);
	go(0);
	printf("%d\n",ans);
	return 0;
}