#include <cstdio>
#define MOD 1000000009ll
#define MAX_N 1000000
typedef long long ll;
int N,K;
ll D[MAX_N+1]; // D[i] = 길이가 i인 안전한 암호의 개수
 
int main() {
    scanf("%d %d",&N,&K);
    D[0]=1;
    for(int i=1; i<=N; i++){
        D[i]=(D[i-1]*K)%MOD;
        if(i>=5){
            D[i]=(D[i]-D[i-5]+MOD)%MOD; // ABABC를 포함하는 암호들을 제외
            D[i]=(D[i]-D[i-5]+MOD)%MOD; // ABCBC를 포함하는 암호들을 제외
        }
        if(i>=7){
            D[i]=(D[i]+D[i-7])%MOD; // ABABCBC를 포함하는 암호들을 추가 (ABABC와 ABCBC를 제외할 때 중복으로 두번 빼게 되므로)
        }
    }
    printf("%lld\n",D[N]);
    return 0;
}