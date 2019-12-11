#include <cstdio>
#define MAX_N 1000
int N; // 선배의 수
int A[MAX_N+1]; // A[i] = i번 선배의 대답
bool visited[MAX_N+1];

int main(void){
    scanf("%d",&N);
    for(int i=1; i<=N; i++) scanf("%d",&A[i]);

    int ans=0;
    int maxCnt=0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++) visited[j]=false;
        int c=i;
        int cnt=0;
        while(!visited[c]){
            visited[c]=true;
            c=A[c];
            cnt++;
        }
        if(maxCnt<cnt){ ans=i; maxCnt=cnt; }
    }
    printf("%d\n",ans);
    return 0;
}