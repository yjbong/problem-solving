#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#define MAX_N 50
using namespace std;
int N; // 학생의 수
int grade[MAX_N]; // grade[i] = i번 학생의 학년
char hate[MAX_N][MAX_N+1]; // hate[i][j] = i번과 j번 학생이 서로 싫어하면 Y, 아니면 N

int matchA[MAX_N]; // matchA[i] = A[i]와 match된 B의 원소 idx
int matchB[MAX_N]; // matchB[i] = B[i]와 match된 A의 원소 idx
vector<int> adj[MAX_N]; // adj[i] = A[i]와 연결된 B의 원소들
bool visited[MAX_N];

// matching(idx) = 전체 매칭 수를 증가시키면서 A[idx]를 매칭시킬 수 있으면 true
bool matching(int idx){
    visited[idx]=true;
    for(int i=0; i<adj[idx].size(); i++){
        int curB=adj[idx][i];
        // A[idx]가 바로 B[curB]와 매칭 가능하거나,
        // 이미 B[curB]와 매칭되어 있던 A의 원소가 다른 B의 원소와 매칭 가능하다면 전체 매칭 수가 1증가될 수 있음
        if(matchB[curB]<0 || (!visited[matchB[curB]] && matching(matchB[curB]))){
            matchA[idx]=curB;
            matchB[curB]=idx;
            return true;
        }
    }
    return false;
}

// getOut(g1, g2) = g1학년과 g2학년이 같은 조에 편성될 때, 세미나에 빠지게 되는 학생의 최소 수
int getOut(int g1, int g2){
    int out=0;
    // 초기화
    for(int i=0; i<N; i++){
        adj[i].clear();
        matchA[i]=matchB[i]=-1;
    }
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(grade[i]==g1 && grade[j]==g2 && hate[i][j]=='Y') adj[i].push_back(j);
    // 학년이 g1인 학생들 각각에 대해 matching 시도
    for(int i=0; i<N; i++){
        if(grade[i]==g1){
            for(int j=0; j<N; j++) visited[j]=false;
            if(matching(i)) out++;
        }
    }
    return out;
}

int min2(int a, int b){ return a<b?a:b; }

int main() {
    // 입력
    scanf("%d\n",&N);
    for(int i=0; i<N; i++) scanf("%1d",&grade[i]);
    scanf("\n");
    for(int i=0; i<N; i++){
        fgets(hate[i], N+1, stdin);
        scanf("\n");
    }

    // 1~3학년까지 있는데 2개 조로 만들다 보니 두 개 학년은 같은 조에 들어가야 함
    int out=N; // 세미나에 빠지게 되는 학생의 최소값
    // case 1 : 1, 2학년이 같은 조에 들어감
    out=min2(out,getOut(1,2));
    // case 2 : 1, 3학년이 같은 조에 들어감
    out=min2(out,getOut(1,3));
    // case 3 : 2, 3학년이 같은 조에 들어감
    out=min2(out,getOut(2,3));

    // 출력
    printf("%d\n",N-out);
    return 0;
}