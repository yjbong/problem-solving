#include <cstdio>
#define MAXM 100000
int N,M,P;
int ans;
bool happy,inf;
int next[MAXM+1];
bool check[MAXM+1];
 
void dfs(int ch){
    if(happy || inf) return;
    else if(check[ch]){
        inf=true;
        return;
    }
    check[ch]=true;
    if(next[ch]>0){
        ans++;
        dfs(next[ch]);
    }
    else happy=true;
}
int main() {
    scanf("%d %d %d",&N,&M,&P);
    for(int i=0; i<N; i++){
        int favorite,hated;
        scanf("%d %d",&favorite,&hated);
        if(next[hated]==0) next[hated]=favorite;
    }
    dfs(P);
    if(inf) ans=-1;
    printf("%d\n",ans);
    return 0;
}