#include <cstdio>
#include <cstring>
#define INF 1000000
#define DEBUG 0
#define MAXN 1000
int T; // # of test cases;
int M,N;
int C; // # of stains

int steinFlag[MAXN]; // steinFlag[i] = i번 row의 얼룩 상태

typedef struct {
    int numUse; // 행의 얼룩을 덮기 위해 사용한 청소 도구의 수
    int coverFlag; // 청소 도구를 써서 제거할 수 있는 얼룩들의 위치
} STATE;

STATE state[30];
int numStates;
int cache[MAXN][30][30];

// state를 만든다.
void buildStates(int curColIdx, int numUse, int coverFlag, bool needToAdd){

    if(needToAdd){
        state[numStates].numUse = numUse;
        state[numStates].coverFlag = coverFlag;
        numStates++;
    }

    // Using cleaner at current col idx
    if(curColIdx+3<=M)
        buildStates(curColIdx+3, numUse+1, coverFlag|(1<<curColIdx)|(1<<(curColIdx+1))|(1<<(curColIdx+2)), true);

    // Not using cleaner at current col idx
    if(curColIdx+1<=M)
        buildStates(curColIdx+1, numUse, coverFlag, false);
}

// 얼룩의 상태(stein)와 커버 영역의 상태(cover)가 있을 때, 모든 얼룩이 덮인다면 true
bool allCovered(int stein, int cover){
    return (stein & cover) == stein;
}

// 2개 전의 행(curRowIdx-2)과 1개 전의 행(curRowIdx-1)의 얼룩 제거 상태가 각각 before2, before1일 때 curRowIdx번부터 마지막 행까지의 모든 얼룩을 덮기 위해 필요한 최소 청소 도구의 수
int solve(int curRowIdx, int before2, int before1){

    int ans=INF;
    if(curRowIdx==N) return 0; // 더 이상 남은 행이 없는 경우

    if(cache[curRowIdx][before2][before1]>=0) return cache[curRowIdx][before2][before1];

    for(int i=0; i<numStates; i++){
        int stein = steinFlag[curRowIdx];
        int cover = state[before2].coverFlag | state[before1].coverFlag | state[i].coverFlag;
        if(allCovered(stein, cover)){
            int curAns = state[i].numUse + solve(curRowIdx+1, before1, i);
            if(ans > curAns) ans = curAns;
        }
    }
    return cache[curRowIdx][before2][before1]=ans;
}

int main(void) {

    scanf("%d",&T);
    for(int tc=1; tc<=T; tc++){
        memset(cache, -1, sizeof(int)*30*30*MAXN);
        scanf("%d %d",&M,&N);
        for(int i=0; i<N; i++) steinFlag[i]=0;

        numStates=0;
        buildStates(0, 0, 0, true);
        if(M%3>0){
            state[numStates].numUse=M/3+1;
            state[numStates].coverFlag=(1<<M)-1;
            numStates++;
        }

#if DEBUG
        // 생성한 state들을 출력
        printf("numStates = %d\n", numStates);
        for(int i=0; i<numStates; i++){
            printf("state %d: numUse=%d, coverFlag=", i, state[i].numUse);
            for(int j=0; j<M; j++){
                if(state[i].coverFlag & (1<<j)) printf("O");
                else printf("X");
            }
            printf("\n");
        }
#endif

        scanf("%d",&C);
        for(int i=0; i<C; i++){
            int x,y;
            scanf("%d %d",&x,&y);
            x--,y--;
            steinFlag[y] |= (1<<x);
        }

        printf("%d\n", solve(0,0,0));
    }
    return 0;
}