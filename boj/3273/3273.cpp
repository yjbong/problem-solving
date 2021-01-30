#include <cstdio>
int N;
int A[100000];
int X; // 목표 수
int cnt[2000001]; // cnt[i] = 현재까지 수 i가 나온 횟수
 
int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&A[i]);
    scanf("%d",&X);
    // 투 포인터 방식
    int s=0, e=0;
    long long ans=0;
    while(s<N && e<N){
        if(s==e){
            cnt[A[s]]++;
            e++;
        }
        else{ // e가 s보다 뒤에 있을 때 ans를 업데이트한다.
           if(X>=A[e]) ans+=cnt[X-A[e]];
           s++;
        }
    }
    printf("%lld\n",ans);
	return 0;
}