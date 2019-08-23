#include <cstdio>
#include <cmath>
typedef long long ll;
int N; // 인형의 수
int K; // 최소한 배치해야 하는 인형의 수
ll A[500]; // A[i]=i번 인형을 선호하는 사람의 수
ll S[500]; // S[i]=A[0]+A[1]+...+A[i]
ll S2[500]; // S2[i]=A[0]^2+A[1]^2+...+A[i]^2
int main() {
    scanf("%d %d",&N,&K);
    for(int i=0; i<N; i++) scanf("%lld",&A[i]);
    S[0]=A[0];
    for(int i=1; i<N; i++) S[i]=S[i-1]+A[i];
    S2[0]=A[0]*A[0];
    for(int i=1; i<N; i++) S2[i]=S2[i-1]+A[i]*A[i];
 
    // 배치할 인형의 수는 K, K+1, ..., N개까지
    long double ans=-1.0;
    for(int k=K; k<=N; k++){
        for(int i=0; i+k-1<N; i++){
            // i번부터 순서대로 k개 인형의 선호도에 대한 표준편차 계산
            ll sum=S[i+k-1]-(i>0?S[i-1]:0);
            long double avg=(double)sum/k;
            long double var=(S2[i+k-1]-(i>0?S2[i-1]:0)-2*sum*avg+k*avg*avg)/k;
            long double stdev=sqrtl(var);
            // update ans
            if(ans<0.0 || ans>stdev) ans=stdev;
        }
    }
    printf("%.11Lf\n",ans);
    return 0;
}