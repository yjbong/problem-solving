#include <cstdio>
#define MAX_N 100000
#define INF MAX_N+1
int N;
char now[MAX_N+1];
char tmp[MAX_N+1];
char goal[MAX_N+1];
int min2(int a, int b){ return a<b?a:b; }
int max2(int a, int b){ return a>b?a:b; }
void copyState(char src[], char dst[]){
    for(int i=0; i<N; i++) dst[i]=src[i];
}
void pushButton(char bulb[], int idx){
    if(idx==0){
        for(int i=0; i<=min2(1, N-1); i++)
            bulb[i]=(bulb[i]=='1'?'0':'1');
    }
    else if(idx==N-1){
        for(int i=max2(N-2, 0); i<=N-1; i++)
            bulb[i]=(bulb[i]=='1'?'0':'1');
    }
    else{
        for(int i=max2(idx-1, 0); i<=min2(idx+1, N-1); i++)
            bulb[i]=(bulb[i]=='1'?'0':'1');
    }
}

int main() {
    scanf("%d\n",&N);
    scanf("%s\n",now);
    scanf("%s\n",goal);

    int ans=INF;
    if(N==1){
        if(now[0]==goal[0]) ans=0;
        else ans=1;
    }
    else{ // N>=2
        int curAns;
        
        // case 1: 0번 스위치를 누름
        curAns=0;
        copyState(now, tmp);
        pushButton(tmp, 0);
        curAns++;
        for(int i=1; i<N; i++){
            // i번 스위치를 조작하여 i-1번 전구의 상태를 맞춤
            if(tmp[i-1]!=goal[i-1]){
                pushButton(tmp, i); curAns++;
            }
        }
        // N-1번 전구의 상태는 변경할 수 없음
        // 따라서 이 전구의 상태가 맞아야 now->goal 가능
        if(tmp[N-1]==goal[N-1] && ans>curAns) ans=curAns;

        // case 2: 0번 스위치를 누르지 않음
        curAns=0;
        copyState(now, tmp);
        for(int i=1; i<N; i++){
            // i번 스위치를 조작하여 i-1번 전구의 상태를 맞춤
            if(tmp[i-1]!=goal[i-1]){
                pushButton(tmp, i); curAns++;
            }
        }
        // N-1번 전구의 상태는 변경할 수 없음
        // 따라서 이 전구의 상태가 맞아야 now->goal 가능
        if(tmp[N-1]==goal[N-1] && ans>curAns) ans=curAns;
    }

    // 출력
    if(ans<INF) printf("%d\n",ans);
    else printf("-1\n");
    return 0;
}