#include <iostream>
#define MAX_N 100
using namespace std;
char board[MAX_N][MAX_N+1];
int bomb[MAX_N][MAX_N];
int N;
 
int nearBombs(int y, int x){
    int cnt=0;
    for(int i=y-1; i<=y+1; i++){
        for(int j=x-1; j<=x+1; j++){
            if(i<0 || i>=N || j<0 || j>=N) continue;
            if(board[i][j]=='*') cnt++;
        }
    }
    return cnt;
}
int main() {
    cin  >> N;
    cin.get();
    for(int i=0; i<N; i++){
	    cin.getline(board[i],N+1);
    }
 
    int ans=0;
    if(N>=3){
        // 위쪽 테두리
        for(int j=1; j<N-1; j++){
            int givenCnt=board[0][j-1]-'0';
            if(nearBombs(0,j-1)<givenCnt) board[1][j]='*';
        }
        // 아래쪽 테두리
        for(int j=1; j<N-1; j++){
            int givenCnt=board[N-1][j-1]-'0';
            if(nearBombs(N-1,j-1)<givenCnt) board[N-2][j]='*';
        }
        // 왼쪽 테두리
        for(int i=1; i<N-1; i++){
            int givenCnt=board[i-1][0]-'0';
            if(nearBombs(i-1,0)<givenCnt) board[i][1]='*';
        }
        // 오른쪽 테두리
        for(int i=1; i<N-1; i++){
            int givenCnt=board[i-1][N-1]-'0';
            if(nearBombs(i-1,N-1)<givenCnt) board[i][N-2]='*';
        }
        // 테두리가 아닌 곳
        for(int i=2; i<=N-3; i++)
            for(int j=2; j<=N-3; j++) board[i][j]='*';
 
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                if(board[i][j]=='*') ans++;
    }
 
    cout << ans << endl;
    return 0;
}