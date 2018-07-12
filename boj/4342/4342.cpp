#include <cstdio>

// isWinState(a,b) = 주어진 수가 a,b일 때 현재 턴인 플레이어의 승리 여부
bool isWinState(int a, int b){
	
	if(a==0 || b==0) return false; // 승부가 끝난 경우

	if(a>=b){
		// a/b > 1인 경우, 현재 플레이어는 무조건 이길 수 있는데,
		// 그 이유는 다음과 같이 상황에 따라 두 가지 선택을 할 수 있기 때문이다.
		//
		// 1. (a%b, b)가 현재 플레이어가 이기는 상태인 경우
		// 현재 플레이어는 a에서 b*(a/b-1)만큼을 뺀다. --> 다음 플레이어는 (a-b*(a/b-1), b) 인 상태에서 b를 뺄 수 밖에 없다.
		// --> 현재 플레이어 차례에서 (a-b*(a/b-1)-b, b) == (a%b, b) 가 되어 이긴다.
		// 2. (a%b, b)가 현재 플레이어가 지는 상태인 경우
		// 현재 플레이어는 바로 a에서 b*(a/b)만큼을 뺀다. --> 다음 플레이어는 (a-b*(a/b), b) == (a%b, b) 인 상태를 넘겨 받는다. 따라서 다음 플레이어가 진다.
		if(a/b > 1) return true;

		// a/b == 1인 경우, 현재 플레이어는 a에서 b를 빼는 것 이외의 선택지가 없다.
		// 따라서 다음 플레이어가 (a-b, b)를 넘겨 받았을 때의 승패 여부에 따라 현재 플레이어의 승패 여부가 결정된다.
		else return (!isWinState(a-b, b));
	}
	else{
		if(b/a > 1) return true;
		else return (!isWinState(a, b-a));
	}
}

int main(void){

	while(1){
		int a,b;
		scanf("%d %d",&a,&b);
		if(a==0 && b==0) break;
		if(isWinState(a,b)) printf("A wins\n");
		else printf("B wins\n");
	}
	return 0;
}