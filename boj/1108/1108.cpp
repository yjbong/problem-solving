#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#define DEBUG 0
using namespace std;
typedef long long ll;

int N; // 링크 정보의 개수

map <string,int> name2Idx;
int d[55][55]; // d[i][j] = i번 사이트에서 j번 사이트로 직접 또는 간접적으로 가는 경로가 있으면 1, 아니면 0

vector <string> inEdgeList[55]; // i번 사이트로 들어오는 사이트들의 이름

ll score[3333]; // score[i] = i번 사이트의 점수

// idx번 사이트의 점수 계산
ll go(int idx){

	if(score[idx]>0) return score[idx]; // memoization

	if(idx>=N) return (score[idx]=1); // 링크 정보 왼쪽에 등장하지 않은 사이트 (무조건 indegree=0인 노드)

	ll ret=1;
	for(int i=0; i<inEdgeList[idx].size(); i++){
		int curSrcIdx=(name2Idx.find(inEdgeList[idx][i]))->second;
		if(curSrcIdx<N){
			if(!d[idx][curSrcIdx]) ret+=go(curSrcIdx); // idx에서 curSrcIdx로의 경로가 없어야 사이클이 없음
		}
		else ret+=go(curSrcIdx);
	}
	return (score[idx]=ret);
}

int main(void){
	scanf("%d\n",&N);

	int mapSize=0;
	for(int i=0; i<N; i++){

		int curDstIdx;

		char dstNameTmp[100];
		int edges;

		scanf("%s %d",dstNameTmp,&edges);
		string dstName(dstNameTmp);

		if(name2Idx.find(dstName)==name2Idx.end()){
			#if DEBUG
			printf("%s --> idx %d\n", dstNameTmp, mapSize);
			#endif
			name2Idx.insert(make_pair<string,int>(dstName,mapSize));
			curDstIdx=mapSize;
			mapSize++;
		}
		else curDstIdx=(name2Idx.find(dstName))->second;
		
		for(int j=0; j<edges; j++){

			char srcNameTmp[100];
			scanf("%s",srcNameTmp);

			string srcName(srcNameTmp);
			inEdgeList[curDstIdx].push_back(srcName);
		}
	}

	#if DEBUG
	for(int i=0; i<N; i++){
		printf("src idx = %d --> dst idx list = ", i);
		for(int j=0; j<inEdgeList[i].size(); j++){
			cout << inEdgeList[i][j] << " ";
		}
		printf("\n");
	}
	#endif

	for(int i=0; i<N; i++){
		for(int j=0; j<inEdgeList[i].size(); j++){
			if(name2Idx.find(inEdgeList[i][j])==name2Idx.end()){
				name2Idx.insert(make_pair<string,int>(inEdgeList[i][j],mapSize));
				mapSize++;
			}
			else{
				int curSrcIdx = (name2Idx.find(inEdgeList[i][j]))->second;
				if(curSrcIdx<N){ // 링크 정보 왼쪽에 있는 사이트만 고려
					d[curSrcIdx][i]=1; // 직접 경로 존재
				}
			}
		}
	}

	// d배열 계산 (floyd 변형)
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				if(d[i][j]<d[i][k]*d[k][j]) d[i][j]=d[i][k]*d[k][j];

	// 답 출력
	char targetNameTmp[100];
	scanf("%s\n",targetNameTmp);
	string targetName(targetNameTmp);
	int targetIdx=(name2Idx.find(targetName))->second;

	#if DEBUG
	printf("target site = %s --> idx %d\n", targetNameTmp, targetIdx);
	#endif
	printf("%lld\n",go(targetIdx));
	
	return 0;
}