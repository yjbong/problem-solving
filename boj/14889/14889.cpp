#include <cstdio>
#include <algorithm>
#define MAX_N 20
using namespace std;
int N;
int S[MAX_N][MAX_N];
int T[MAX_N];
int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d",&S[i][j]);
    for(int i=0; i<N; i++) T[i]=i<N/2?0:1;
    int ans=1000000000;
    do{
        int start=0, link=0;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++){
                if(T[i]==0 && T[j]==0) start+=S[i][j];
                else if(T[i]==1 && T[j]==1) link+=S[i][j];
            }
        int cur=start>=link?start-link:link-start;
        if(ans>cur) ans=cur;
    }while(next_permutation(T, T+N));
    printf("%d\n",ans);
    return 0;
}