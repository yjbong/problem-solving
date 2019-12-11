#include <cstdio>
#define INF 1000000000000000ll
long long N,A;
long long P[33]; // P[i]=A의 i승(그 값이 INF보다 큰 경우는 INF로...)
int main() {
    scanf("%lld %lld",&N,&A);
    P[0]=1;
    for(int i=1; i<33; i++){
        P[i]=P[i-1]*A;
        if(P[i]>INF) P[i]=INF;
    }
    long long ans=0;
    for(int i=1; i<33; i++) ans+=N/P[i];
    printf("%lld\n",ans);
    return 0;
}