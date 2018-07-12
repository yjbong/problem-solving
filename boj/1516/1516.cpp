#include <cstdio>
#include <queue>
using namespace std;

int N; // 건물 종류 수
int t[501]; // t[i] = i번 건물의 건설 시간
vector <int> pre[501]; // pre[i] = i번 건물을 짓기 전에 지어야 하는 건물들
int d[501]; // d[i] = i번 건물이 완성되는 최소 시간

typedef struct{
	int indeg;
	vector <int> outlist;
}NODE;
NODE v[501];

queue <int> q;
bool check[501];
int topOrder[501]; // 위상 정렬 결과
int topOrders;

int main(void){
	scanf("%d",&N);
	for(int i=1; i<=N; i++){
		scanf("%d",&t[i]);
		while(1){
			int curPre;
			scanf("%d",&curPre);
			if(curPre==-1) break;
			pre[i].push_back(curPre);

			v[curPre].outlist.push_back(i);
			v[i].indeg++;
		}
	}

	// 위상 정렬
	for(int i=1; i<=N; i++){
		if(v[i].indeg==0){
			q.push(i);
			check[i]=true;
		}
	}

	while(!q.empty()){
		int f=q.front();
		q.pop();
		topOrder[topOrders++]=f;
		for(int i=0; i<v[f].outlist.size(); i++){
			int cv=v[f].outlist[i];
			v[cv].indeg--;
		}

		for(int i=1; i<=N; i++){
			if(check[i]==false && v[i].indeg==0){
				q.push(i);
				check[i]=true;
			}
		}
	}

	// d 계산 (위상 정렬 순서)
	for(int i=0; i<topOrders; i++){
		int cur=topOrder[i];

		int maxPre=0;
		for(int j=0; j<pre[cur].size(); j++)
			if(maxPre<d[pre[cur][j]]) maxPre=d[pre[cur][j]];
		d[cur]=maxPre+t[cur];
	}

	// 답 출력
	for(int i=1; i<=N; i++) printf("%d\n",d[i]);
	
	return 0;
}