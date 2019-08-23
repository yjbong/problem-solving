#include <cstdio>
#define MAX_M 1000
typedef long long ll;
int T; // 테스트 케이스 수
ll N, M;
ll check[MAX_M][MAX_M]; // check[x][y] = 직전 두 값(Si-1, Si-2)을 M으로 나눈 나머지가 각각 x, y가 될 때의 i값
  
int main() {
    scanf("%d",&T);
    for(int z=1; z<=T; z++){
        scanf("%lld %lld",&N,&M);
        printf("#%d ", z);
        if(M==1) { printf("0\n"); continue; }
        else if(N<=1){ printf("%lld\n", N); continue; }
 
        // check 초기화
        for(int i=0; i<M; i++)
            for(int j=0; j<M; j++) check[i][j]=-1;
  
        ll bfr2; // Si-2를 M으로 나눈 나머지
        ll bfr1; // Si-1을 M으로 나눈 나머지
  
        // 주기 확인
        ll start; // 주기가 시작하는 i
        ll length; // 주기의 길이
        bfr2=0;
        bfr1=1;
        for(ll i=2; ; i++){
            if(check[bfr1][bfr2]>=0) {
                //printf("S%lld and S%lld are same!\n", check[bfr1][bfr2], i);
                start=check[bfr1][bfr2];
                length=i-start;
                break;
            }
            check[bfr1][bfr2]=i;
            ll now=(bfr1*bfr1*bfr1+bfr2*bfr2*bfr2)%M;
            bfr2=bfr1;
            bfr1=now;
        }
  
        // 주기성을 이용해서 N값을 축소
        if(N>=start){
            N%=length;
            while(N<start) N+=length;
        }
  
        // 수열의 N번째 수 출력
        bfr2=0;
        bfr1=1;
        for(ll i=2; i<=N; i++){
            ll now=(bfr1*bfr1*bfr1+bfr2*bfr2*bfr2)%M;
            if(i==N) printf("%lld\n", now);
            bfr2=bfr1;
            bfr1=now;
        }
    }
  
    return 0;
}