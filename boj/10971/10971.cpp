#include <cstdio>
#include <algorithm>
#define MAX_N 10
using namespace std;
 
int N; // 도시의 수
int W[MAX_N][MAX_N]; // W[i][j] = 도시 i에서 j로 이동하는 비용 (0이면 이동 불가를 표현)
int P[MAX_N];
int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++) scanf("%d",&W[i][j]);
    for(int i=0; i<N; i++) P[i]=i;
    int ans=1000000000;
    do{
        bool valid=true;
        int cur=0;
        for(int i=0; i<N; i++){
            int w=W[P[i]][P[(i+1)%N]];
            if(w>0) cur+=w;
            else{ valid=false; break; }
        }
        if(valid && ans>cur) ans=cur;
    }while(next_permutation(P,P+N));
    printf("%d\n",ans);
    return 0;
}