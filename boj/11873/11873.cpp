#include <cstdio>
#include <stack>
#include <utility>
#define MAX_N 1000
#define MAX_M 1000
using namespace std;
typedef pair<int,int> ii;
int N,M;
int A[MAX_N][MAX_M];
int max2(int a, int b){ return a>b?a:b; }
stack <ii> stk; // first=value, second=index
int main() {
    while(1){
        scanf("%d %d",&N,&M);
        if(N==0 && M==0) break;
        // 입력
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                scanf("%d",&A[i][j]);
        // 입력을 변환한다. 변환 후 A[i][j]는 A의 i행 j열을 마지막으로 하는 수직 방향으로 연속된 1의 개수를 갖는다.
        for(int i=1; i<N; i++)
            for(int j=0; j<M; j++)
                if(A[i][j]) A[i][j]=A[i-1][j]+1;

        int ans=0;
        for(int i=0; i<N; i++){
            // 각 행 A[i] 에 대하여 스택으로 최대 직사각형을 구한다.
            for(int j=0; j<M; j++){
                int index=j;
                // 스택에 있는 value가 현재 A[i][j]값보다 크다면 j열 이후로는 이 value가 쓰일 수 없으므로 답을 업데이트한 후에 버림
                while(!stk.empty() && stk.top().first>A[i][j]){
                    ans=max2(ans, stk.top().first*(j-stk.top().second));
                    index=stk.top().second;
                    stk.pop();
                }
                // 현재 value를 스택에 push
                if(stk.empty()) stk.push(make_pair(A[i][j], index));
                else if(stk.top().first<A[i][j]) stk.push(make_pair(A[i][j], index));
            }
            // 스택에 남아 있는 값들로 답을 업데이트
            while(!stk.empty()){
                ans=max2(ans, stk.top().first*(M-stk.top().second));
                stk.pop();
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}