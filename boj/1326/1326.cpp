#include <cstdio>
#include <queue>
#define INF 1000000000
using namespace std;
int N; // 징검다리의 개수
int A[10001]; // A[i] = i번 징검다리에 써있는 수
int src; // 출발지
int dst; // 목적지
int D[10001]; // D[i] = 출발지로부터 i번 징검다리까지 가기 위해 필요한 최소 점프 수

queue <int> q;
int main(void){
	scanf("%d",&N);
	for(int i=1; i<=N; i++) scanf("%d",&A[i]);
	scanf("%d %d",&src,&dst);

	for(int i=1; i<=N; i++) D[i]=INF;
	D[src]=0;
	q.push(src);
	while(!q.empty()){
		int f=q.front(); q.pop();

		// A[f]의 배수만큼 왼쪽으로 점프
		for(int i=f-A[f]; i>=1; i-=A[f]){
			if(D[i]>D[f]+1){
				D[i]=D[f]+1;
				q.push(i);
			}
		}
		// A[f]의 배수만큼 오른쪽으로 점프
		for(int i=f+A[f]; i<=N; i+=A[f]){
			if(D[i]>D[f]+1){
				D[i]=D[f]+1;
				q.push(i);
			}
		}
	}

	if(D[dst]<INF) printf("%d\n",D[dst]);
	else printf("-1\n");
	return 0;
}