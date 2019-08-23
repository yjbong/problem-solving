#include <cstdio>
#include <algorithm>
using namespace std;
int N; // 사람의 수
int P[1000]; // P[i]=i번째 사람의 소요 시간

int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&P[i]);
    sort(P, P+N);
    int ans=0, wait=0;
    for(int i=0; i<N; i++){
        ans+=wait+P[i];
        wait+=P[i];
    }
    printf("%d\n",ans);
    return 0;
}