#include <iostream>
using namespace std;
int N,M;
string S;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    cin >> S;

    int ans=0;
    int cnt;

    // index 0부터 탐색
    cnt=-1;
    for(int i=0; i<M; i+=2){
        if(cnt<0){
            if(S[i]=='I') cnt=0;
        }
        else{
            if(S[i-1]=='O' && S[i]=='I') cnt++;
            else{
                if(cnt>=N) ans+=cnt-N+1;
                cnt=-1; i-=2;
            }
        }
    }
    if(cnt>=0){
        if(cnt>=N) ans+=cnt-N+1;
    }

    // index 1부터 탐색
    cnt=-1;
    for(int i=1; i<M; i+=2){
        if(cnt<0){
            if(S[i]=='I') cnt=0;
        }
        else{
            if(S[i-1]=='O' && S[i]=='I') cnt++;
            else{
                if(cnt>=N) ans+=cnt-N+1;
                cnt=-1; i-=2;
            }
        }
    }
    if(cnt>=0){
        if(cnt>=N) ans+=cnt-N+1;
    }

    cout << ans << '\n';
    return 0;
}