#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX_N 1000
#define MAX_WEIGHT 10000
using namespace std;

int N; // 짐칸의 수
int A[MAX_N]; // A[i] = i번 짐칸에 놓인 짐의 무게
vector <int> cycle[MAX_N]; // cycle[i] = i번 cycle에 속하는 짐칸의 목록
int cycles;

int sortedA[MAX_N]; // 정렬된 상태의 A배열
int position[MAX_WEIGHT+1]; // position[i] = 무게가 i인 짐의 sortedA에서의 위치

bool check[MAX_N];
int min2(int a, int b){ return a<b?a:b; }

int main(void){

	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%d",&A[i]);
	for(int i=0; i<N; i++) sortedA[i]=A[i];
	sort(sortedA,sortedA+N);
	for(int i=0; i<=MAX_WEIGHT; i++) position[i]=-1;
	for(int i=0; i<N; i++) position[sortedA[i]]=i;

	// cycle 구하기
	cycles=0;
	for(int i=0; i<N; i++){
		if(!check[i]){
			bool cycleEnd;
			int curIdx=i;
			while(1){
				check[curIdx]=true;
				bool cycleEnd=false;
				for(int j=0; j<cycle[cycles].size(); j++)
					if(cycle[cycles][j]==curIdx){ cycleEnd=true; break; }
				if(cycleEnd){
					cycles++;
					break;
				}
				else{
					cycle[cycles].push_back(curIdx);
					curIdx=position[A[curIdx]];
				}
			}
		}
	}

	// 전체 배열에서 가장 가벼운 짐의 위치 확인
	int globalMinIdx=-1;
	for(int i=0; i<N; i++)
		if(globalMinIdx<0 || A[globalMinIdx]>A[i]) globalMinIdx=i;

	int ans=0;
	// 각 사이클에 대한 계산
	for(int i=0; i<cycles; i++){
		if(cycle[i].size()>1){
			// 현재 cycle에 속한 가장 가벼운 짐의 위치를 찾는다
			int cycleMinIdx=-1;
			for(int j=0; j<cycle[i].size(); j++){
				if(cycleMinIdx<0 || A[cycleMinIdx]>A[cycle[i][j]]) cycleMinIdx=cycle[i][j];
			}

			// caseOneCost =  사이클에 속한 가장 가벼운 짐을 swap하면서 정렬하는 경우, cycle에 속한 모든 짐들을 제자리에 놓기 위한 비용
			// 1. 정렬은 cycleMinIdx의 위치에 원래 놓여 있어야 하는 짐(A[position[cycleMinIdx])과 A[cycleMinIdx]를 swap하는 방식으로 cycle에 포함된 원소가 모두 제자리에 위치할 때까지 진행한다.
			int caseOneCost=0;
			for(int j=0; j<cycle[i].size(); j++)
				if(A[cycle[i][j]]!=A[cycleMinIdx]) caseOneCost+=A[cycleMinIdx]+A[cycle[i][j]];
		
			// caseTwoCost =  전체 배열에서 가장 가벼운 짐을 이용하여 cycle에 속한 모든 짐들을 제자리에 놓기 위한 비용
			// 1. 이 방법은 cycle 내에서 가장 가벼운 짐(globalMin)과 전체 배열에서 가장 가벼운 짐(cycleMin)을 swap하고,
			// 2. caseOneCost와 같은 방법으로 정렬한 후,
			// 3. 다시 globalMin과 cycleMin을 swap하여 제자리로 돌려놓아야 함
		
			int caseTwoCost=0;
			caseTwoCost+=A[globalMinIdx]+A[cycleMinIdx];
			for(int j=0; j<cycle[i].size(); j++)
				if(A[cycle[i][j]]!=A[cycleMinIdx]) caseTwoCost+=A[globalMinIdx]+A[cycle[i][j]];
			caseTwoCost+=A[globalMinIdx]+A[cycleMinIdx];

			ans+=min2(caseOneCost,caseTwoCost);
		}
	}
	printf("%d\n",ans);
	return 0;
}