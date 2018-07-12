#include <cstdio>
typedef long long ll;
int N;
ll src, dst; // 시작, 도착 위치

ll fib[51]; // fib[i] = i번째 피이보나치 트리의 노드 개수

int main(void){
	fib[0]=fib[1]=1;
	for(int i=2; i<=50; i++) fib[i]=1+fib[i-1]+fib[i-2];

	scanf("%d %lld %lld",&N,&src,&dst);

	// step 1 : src와 dst가 동시에 속해 있는 가장 작은 트리를 찾음
	int curFib=N;
	while(curFib>=0){
		// leftNodes = 왼쪽 서브트리에 속하는 노드의 개수
		ll leftNodes = curFib>=2 ? leftNodes=fib[curFib-2] : 0;

		// src 또는 dst가 root 노드인 경우 src 또는 dst가 최소 공통 조상
		if(src==1 || dst==1) break;

		// i번째 피이보나치 트리의 왼쪽에는 fib[i-2]개의 노드가 있음. 왼쪽 서브트리에 속하는 노드 번호는 2~fib[i-2]+1
		// i번째 피이보나치 트리의 오른쪽에는 fib[i-1]개의 노드가 있음. 오른쪽 서브트리에 속하는 노드 번호는 fib[i-2]+2~fib[i]
		// src와 dst가 같은 서브트리에 속하지 않을 경우, 현 단계의 root는 최소 공통 조상이다
		if(src<=1+leftNodes && dst>1+leftNodes) break;
		if(dst<=1+leftNodes && src>1+leftNodes) break;

		// src와 dst가 모두 왼쪽 서브트리에 속하는 경우,
		// 왼쪽 서브트리의 root를 새로운 root 노드로 하여 src, dst인덱스 재계산
		if(src<=1+leftNodes && dst<=1+leftNodes){
			src-=1; dst-=1;
			curFib-=2; // i번째 트리에서 i-2번째 트리로 축소
		}
		// src와 dst가 모두 오른쪽 서브트리에 속하는 경우,
		// 오른쪽 서브트리의 root를 새로운 root 노드로 하여 src, dst인덱스 재계산
		if(src>1+leftNodes && dst>1+leftNodes){
			src-=(1+leftNodes); dst-=(1+leftNodes);
			curFib-=1; // i번째 트리에서 i-1번째 트리로 축소
		}
	}

	ll curIdx;
	ll curSrc, curDst;
	int ansFib=curFib; // 앞으로 ansFib번째 피이보나치 트리에서 경로를 찾는다

	// step 2 : src 에서 최소 공통 조상까지 이동하는 경로 계산
	// = 최소 공통 조상(ansFib번째 피이보나치 트리의 root)에서 src로 이동하기 위한 경로의 길이를 계산
	curFib=ansFib;
	curSrc=src;
	int upCount=0;
	while(curFib>=0 && curSrc>1){
		ll leftNodes = curFib>=2 ? leftNodes=fib[curFib-2] : 0;
		if(curSrc<=1+leftNodes){ // src가 왼쪽 서브트리에 속함 (왼쪽 서브트리의 root로 이동)
			curSrc-=1;
			upCount++;
			curFib-=2;
		}
		else{ // src가 오른쪽 서브트리에 속함 (오른쪽 서브트리의 root로 이동)
			curSrc-=(1+leftNodes);
			upCount++;
			curFib-=1;
		}
	}
	for(int i=0; i<upCount; i++) printf("U"); // src --> 최소 공통 조상까지의 경로 출력

	// step 3 : 최소 공통 조상에서 dst까지 이동하는 경로 계산
	curFib=ansFib;
	curDst=dst;
	while(curFib>=0 && curDst>1){
		ll leftNodes = curFib>=2 ? leftNodes=fib[curFib-2] : 0;
		if(curDst<=1+leftNodes){ // dst가 왼쪽 서브트리에 속함 (왼쪽 서브트리의 root로 이동)
			curDst-=1;
			printf("L");
			curFib-=2;
		}
		else{ // dst가 오른쪽 서브트리에 속함 (오른쪽 서브트리의 root로 이동)
			curDst-=(1+leftNodes);
			printf("R");
			curFib-=1;
		}
	}
	printf("\n");
	return 0;
}