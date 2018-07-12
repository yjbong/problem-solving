#include <cstdio>
#include <vector>
using namespace std;
int n; // 학생의 수
int m; // 알려진 인간관계의 개수

int p[1111]; // p[i] = 값이 음수가 아닐 경우 i의 parent, 음수이면 i는 집합의 root이고 절대값만큼이 집합의 크기
vector <int> enemy[1111]; // enemy[i] = i번 학생의 원수 리스트

// disjoint set 초기화
void init(){
	for(int i=1; i<=n; i++) p[i]=-1;
}

// a가 포함된 집합의 대표 원소를 return
int find2(int a){
	while(p[a]>=0) a=p[a];
	return a;
}

void merge2(int a, int b){
	int pa=find2(a), pb=find2(b);
	if(pa==pb) return;

	// a가 속한 집합이 더 클 경우 (b가 속한 집합을 a가 속한 집합에 합침)
	if(p[pa]<p[pb]){
		p[pa]+=p[pb];
		p[pb]=pa;
	}
	// 그 외의 경우 (a가 속한 집합을 b가 속한 집합에 합침)
	else{
		p[pb]+=p[pa];
		p[pa]=pb;
	}
}

int main(void){

	scanf("%d\n%d\n",&n,&m);
	init();

	for(int i=1; i<=m; i++){
		char state;
		int a,b;
		scanf("%c %d %d\n",&state,&a,&b);
		
		if(state=='F'){ // 조건 1, 2에 따른 팀 구성
			merge2(a,b);
		}
		else if(state=='E'){ // 쌍방에 적 목록 추가
			enemy[a].push_back(b);
			enemy[b].push_back(a);
		}
	}
	
	for(int i=1; i<=n; i++){
		for(int j=0; j<enemy[i].size(); j++){
			int curEnemy=enemy[i][j];
			// 조건 4에 따른 팀 구성
			for(int k=0; k<enemy[curEnemy].size(); k++){
				merge2(i,enemy[curEnemy][k]);
			}
		}
	}

	int ans=0;
	for(int i=1; i<=n; i++)
		if(p[i]<0) ans++; // ans = disjoint set의 개수
	
	printf("%d\n",ans);
	return 0;
}