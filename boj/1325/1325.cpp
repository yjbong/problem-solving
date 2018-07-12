#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int N; // 컴퓨터의 수
int M; // 신뢰 관계의 수

vector <int> trust[10001]; // trust[i]=i번 컴퓨터를 신뢰하는 컴퓨터의 목록
int ans[10001]; // ans[i]=i번 컴퓨터를 해킹했을 때, 한번에 해킹할 수 있는 컴퓨터의 수

queue <int> q;
bool visited[10001];

int main(void){
	scanf("%d %d",&N,&M);
	for(int i=0; i<M; i++){
		int A,B;
		scanf("%d %d",&A,&B);
		// A가 B를 신뢰한다.
		trust[B].push_back(A);
	}

	for(int i=1; i<=N; i++){
		// visited 초기화
		for(int j=1; j<=N; j++) visited[j]=false;
		// 각 i번 컴퓨터를 해킹한 경우
		q.push(i);
		visited[i]=true;
		ans[i]++;
		while(!q.empty()){
			int f=q.front(); q.pop();
			// f번 컴퓨터를 신뢰하는 컴퓨터들을 추가
			for(int j=0; j<trust[f].size(); j++){
				int c=trust[f][j];
				if(!visited[c]){
					q.push(c);
					visited[c]=true;
					ans[i]++;
				}
			}
		}
	}

	int max=0;
	for(int i=1; i<=N; i++) if(max<ans[i]) max=ans[i];

	for(int i=1; i<=N; i++) if(max==ans[i]) printf("%d ",i);
	printf("\n");
	return 0;
}