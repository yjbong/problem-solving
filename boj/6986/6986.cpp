#include <cstdio>
#include <algorithm>
using namespace std;
int N; // 전체 점수의 개수
int K; // 제외되는 점수의 개수
int A[100000];

int main(){
    scanf("%d %d",&N,&K);
    for(int i=0; i<N; i++){
        int integer, mantissa;
        scanf("%d.%d",&integer,&mantissa);
        A[i]=integer*100+mantissa*10;
    }
    sort(A,A+N);
    if(false){
        for(int i=0; i<N; i++) {
            printf("%d\n",A[i]);
        }
    }

    // 절사평균
    int cutSum=0;
    for(int i=K; i<N-K; i++) {
        cutSum=cutSum+A[i];
    }
    int cutN=N-K*2;
    int cutAvg=cutSum/cutN;
    if((cutSum%cutN)*2 >= cutN) {
        cutAvg=cutAvg+1;
    }
    printf("%d.%02d\n",cutAvg/100,cutAvg%100);

    // 보정평균
    int modiSum=0;
    for(int i=0; i<N; i++) {
        if(i<K) {
            modiSum=modiSum+A[K];
        } else if(i>=N-K) {
            modiSum=modiSum+A[N-K-1];
        } else {
            modiSum=modiSum+A[i];
        }
    }
    int modiAvg=modiSum/N;
    if((modiSum%N)*2 >= N) {
        modiAvg=modiAvg+1;
    }
    printf("%d.%02d\n",modiAvg/100,modiAvg%100);
    return 0;
}