#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
int N; // 정점의 수
int M; // 간선의 수
int adj[1001][1001];

void getEulerCircuit(vector<int>& circuit, vector<int>& oddV){
	stack<int> s;

	if(oddV.size()==2) s.push(oddV[0]);
	else s.push(1);

	while(!s.empty()){
		first:

		int here=s.top();
		for(int there=1; there<=N; there++){
			while(adj[here][there]>0){
				// 양방향 간선을 지움
				adj[here][there]--;
				adj[there][here]--;
				s.push(there);
				goto first;
			}
		}
		
		s.pop();
		circuit.push_back(here);
	}
}

int main(void){
	scanf("%d %d",&N,&M);
	for(int i=1; i<=M; i++){
		int here,there;
		scanf("%d %d %*d",&here,&there);
		adj[here][there]++;
		adj[there][here]++;
	}

	vector <int> oddV;
	for(int i=1; i<=N; i++){
		int sum=0;
		for(int j=1; j<=N; j++) sum+=adj[i][j];
		// 홀수점이 존재
		if(sum%2!=0){ oddV.push_back(i); }
	}
	if(oddV.size()==0 || oddV.size()==2){
		vector <int> circuit;
		getEulerCircuit(circuit,oddV);

		for(int i=0; i<circuit.size(); i++) printf("%d ",circuit[i]);
		printf("-1\n");
	}
	else printf("-1\n");

	return 0;
}