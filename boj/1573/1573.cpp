#include <cstdio>

int d[20]; // d[i] = i개의 노드를 가진 이진 검색 트리에 a부터 시작해서 사전 순서대로
	   // 서로 다른 i개의 알파벳을 붙이고 프리오더 순회했을 때 얻을 수 있는 문자열의 가짓수

int N;
int index;

// 시작 알파벳이 startChar이고, nodes개의 노드를 가진 이진 검색트리에서 index번째로 가능한 preorder 순회 결과 출력 
void preorder(int startChar, int nodes, int index){
	if(nodes==0) return;
	if(nodes==1){
		printf("%c",startChar);
		return;
	}

	for(int j=0; j<nodes; j++){
		if(index>=d[j]*d[nodes-1-j]) index-=d[j]*d[nodes-1-j];
		else{
			printf("%c",startChar+j);
			preorder(startChar, j, index/d[nodes-1-j]);
			preorder(startChar+j+1, nodes-1-j, index%d[nodes-1-j]);
			break;
		}
	}
}

int main(void){

	scanf("%d %d",&N,&index);
	index--; // 편의상 index는 1이 아니라 0부터 시작하는 것으로 생각한다

	// d 배열 계산
	d[0]=1;
	d[1]=1;
	for(int i=2; i<=N; i++){
		for(int j=0; j<i; j++){
			d[i]+=d[j]*d[i-1-j]; // 루트노드의 알파벳이 'a'+i일 때의 경우를 더함
		}
	}

	// 결과 출력
	if(index>=d[N]) printf("-1\n");
	else{
		preorder('a', N, index);
		printf("\n");
	}

	return 0;
}