#include <cstdio>
#define MAX_N 10000ll
typedef long long ll;
ll N; // 튜브 한 개에 들어가는 사과의 수 (크기가 1~2*N인 사과가 있음)
ll tube[2][MAX_N]; // tube[i] = i번 튜브
 
int main() {
    scanf("%lld",&N);
    if(N==1){
        // Greedy한 사과 배치
        tube[0][0]=1;
        tube[1][0]=2;
    }
    else if(N>=2){
        // Greedy한 사과 배치
        ll k=2*N-4;
        tube[0][0]=2*N-3; tube[0][N-1]=2*N-2;
        for(ll i=1; i<N-1; i++, k--) tube[0][i]=k;
        tube[1][0]=2*N-1; tube[1][N-1]=2*N;
        for(ll i=1; i<N-1; i++, k--) tube[1][i]=k;
    }
 
    // 부패도 계산
    ll remain=(2*N)*(2*N+1)/2; // 남아 있는 사과 크기의 합
    ll rot=0; // 부패도
    ll time=0;
    for(ll i=0; i<2; i++){ // 0번 tube부터 꺼내고,
        for(ll j=0; j<N; j++){ // tube의 왼쪽에서 오른쪽으로 꺼내면 되도록 배치한 것임
            rot+=remain*time;
            remain-=tube[i][j];
            time++;
        }
    }
    printf("%lld\n", rot); // 부패도 출력
    for(ll i=0; i<2; i++){ // 부패도가 최소로 되는 배치 출력
        for(ll j=0; j<N; j++) printf("%lld ",tube[i][j]);
        printf("\n");
    }
 
	return 0;
}