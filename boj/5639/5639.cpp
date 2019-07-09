#include <cstdio>
#define MAX_N 10000
using namespace std;

int N;
int preorder[MAX_N]; // preorder[i] = 전위순회에서 i번째 방문하는 노드의 값

void postFromPre(int s, int e){
    if(e-s<0) return;

    int k=e+1;
    for(int i=s+1; i<=e; i++)
        if(preorder[s]<preorder[i]){ k=i; break; }
    
    postFromPre(s+1, k-1);
    postFromPre(k, e);
    printf("%d\n",preorder[s]);
}
int main() {
    N=0;
    while(scanf("%d",&preorder[N])==1) N++;

    // run
    postFromPre(0, N-1);
    return 0;
}