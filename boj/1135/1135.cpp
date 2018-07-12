#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000000
using namespace std;
int n; // 직원의 수
int d[50]; // d[i] = i번 직원을 root로 하는 subtree에 속한 모든 직원들이 i번 직원으로부터 소식을 듣는데 걸리는 최소 시간
int p[50]; // p[i] = i번 직원의 상사 (-1일 경우 상사가 없음)
vector <int> c[50]; // c[i] = i번 직원의 직속 부하 리스트

// 위상 정렬용 자료
typedef struct{
	int indeg;
	vector <int> outlist;
}VERTEX;
VERTEX v[50];
queue <int> q;
bool visit[50];

int order[50]; // order = 위상 정렬 결과
int orders;

// 정렬용 함수
bool cmp(int i, int j){
	return (d[i]>d[j]);
}
int main(void){

	// 입력
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&p[i]);
		if(p[i]>=0) c[p[i]].push_back(i);
	}
	
	// 위상 정렬
	for(int i=0; i<n; i++){
		for(int j=0; j<c[i].size(); j++){
			v[i].indeg++;
			v[c[i][j]].outlist.push_back(i);
		}	
	}
	for(int i=0; i<n; i++){
		if(visit[i]==false && v[i].indeg==0){
			q.push(i);
			visit[i]=true;
		}
	}
	while(!q.empty()){
		int f=q.front();
		q.pop();
		order[orders++]=f;
		for(int i=0; i<v[f].outlist.size(); i++){
			int cv=v[f].outlist[i];
			v[cv].indeg--;	
		}

		for(int i=0; i<n; i++){
			if(visit[i]==false && v[i].indeg==0){
				q.push(i);
				visit[i]=true;
			}
		}
	}

	// 위상 정렬 순서대로 d 배열 계산
	for(int i=0; i<orders; i++){
		int ci=order[i];
		d[ci]=0;
		if(c[ci].size()>0){
			sort(c[ci].begin(), c[ci].end(),cmp);
			for(int j=0; j<c[ci].size(); j++){
				if(d[ci] < d[c[ci][j]]+(j+1)){
					d[ci] = d[c[ci][j]]+(j+1);
				}
			}
		}
	}

	// 답
	printf("%d\n",d[0]);
	return 0;
}