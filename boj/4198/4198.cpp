#include <cstdio>
#define MAX_N 2000

int N; // 열차의 개수
long long w[MAX_N]; // w[i] = i번 열차의 중량
int lis[MAX_N]; // lis[i] = w[i]를 시작으로 하는 최장 단조 증가 수열의 갈이
int lds[MAX_N]; // lds[i] = w[i]를 시작으로 하는 최장 단조 감소 수열의 길이

int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%lld",&w[i]);

    // lis, lds 배열 구하기
    for(int i=N-1; i>=0; i--){
        lis[i]=lds[i]=1;
        for(int j=i+1; j<N; j++){
            if(w[i]<w[j] && lis[i]<lis[j]+1) lis[i]=lis[j]+1;
            if(w[i]>w[j] && lds[i]<lds[j]+1) lds[i]=lds[j]+1;
        }
    }

    // 최초에 배치하는 차량을 i라고 했을 때, 각 i중에서 가장 많은 열차를 배열하는 경우의 길이가 답
    int ans=0;
    for(int i=0; i<N; i++){
        if(ans<lis[i]+lds[i]-1) ans=lis[i]+lds[i]-1;
    }
    printf("%d\n",ans);
    return 0;
}