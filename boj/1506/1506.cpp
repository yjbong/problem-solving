#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
int N; // 도시의 개수
ll cost[111]; // cost[i] = i번 도시에 경찰서를 세우기 위해 필요한 비용
int road[111][111]; // road[i][j] = i번 도시에서 j번 도시로 가는 길이 있는 경우 1, 없으면 0
int reach[111][111]; // reach[i][j] = i번 도시에서 j번 도시로 갈 수 있는 경우 1, 없으면 0

vector <int> s[111]; // s[i] = i번 도시를 집합의 대표값으로 하는 도시들의 목록 (i번 도시를 포함)

// for disjoint set
int p[111]; // p[i] = parent of i, (height of tree if p[i]<0)

int find2(int a){
	while(p[a]>=0) a=p[a];
	return a;
}

void union2(int a, int b){
	int pa=find2(a);
	int pb=find2(b);
	if(pa==pb) return;

	if(p[pa]<p[pb]){ // a집합의 높이가 더 높은 경우
		p[pb]=pa; // a집합에 b집합을 합침
	}
	else if(p[pa]>p[pb]){ // b집합의 높이가 더 높은 경우
		p[pa]=pb; // b집합에 a집합을 합침
	}
	else{ // 높이가 같은 경우
		p[pb]=pa; // a집합에 b집합을 합침
		p[pa]--; // a집합의 높이가 증가
	}
}

int main(void){

	scanf("%d",&N);
	for(int i=1; i<=N; i++) scanf("%lld",&cost[i]);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%1d",&road[i][j]);
			reach[i][j]=road[i][j];
		}
	}

	// reach 배열 계산 (floyd)
	for(int k=1; k<=N; k++){
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				reach[i][j] |= (reach[i][k] & reach[k][j]);
			}
		}
	}

	// disjoint set 초기화
	for(int i=1; i<=N; i++) p[i]=-1;

	// disjoint set 구성
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			if(reach[i][j] && reach[j][i]) union2(i,j);

	for(int i=1; i<=N; i++)
		s[find2(i)].push_back(i);

	// 답 계산
	ll ans=0;
	for(int i=1; i<=N; i++){
		// 각각의 set에 속한 도시들 중에서 최소 비용을 찾음
		if(s[i].size()>0){
			ll curMinCost=cost[s[i][0]];
			for(int j=1; j<s[i].size(); j++)
				if(curMinCost>cost[s[i][j]]) curMinCost=cost[s[i][j]];

			ans+=curMinCost;
		}
	}
	printf("%lld\n",ans);
	
	return 0;
}