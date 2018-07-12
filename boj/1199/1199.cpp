#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
int N; // 정점의 수
int adj[1001][1001];

long long cnt=0;
/*
void getEulerCircuit(int here, vector<int>& circuit){
	for(int there=1; there<=N; there++){
		while(adj[here][there]>0){
			cnt++;
			// 양방향 간선을 지움
			adj[here][there]--;
			adj[there][here]--;
			getEulerCircuit(there, circuit);	
		}
	}
	circuit.push_back(here);
}
*/
void getEulerCircuit(vector<int>& circuit){
	stack<int> s;
	s.push(1);
	while(!s.empty()){
		first:

		int here=s.top();
		for(int there=1; there<=N; there++){
			while(adj[here][there]>0){
				cnt++;
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
	scanf("%d",&N);
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++) scanf("%d",&adj[i][j]);

	bool ok=true;
	for(int i=1; i<=N; i++){
		int sum=0;
		for(int j=1; j<=N; j++) sum+=adj[i][j];
		// 홀수점이 존재 --> 오일러 회로를 만들 수 없음
		if(sum%2!=0){ ok=false; break; }
	}

	if(ok){
		vector <int> circuit;
		//getEulerCircuit(1, circuit);
		getEulerCircuit(circuit);

		for(int i=0; i<circuit.size(); i++) printf("%d ",circuit[i]);
		printf("\n");
		//printf("cnt = %lld\n",cnt);
	}
	else printf("-1\n");

	return 0;
}