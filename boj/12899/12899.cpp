#include <cstdio>
#include <cassert>
#define MAX_N 2000000
#define MAX_X 2000000
int N;
int S[1<<22]; // 필요한 배열의 크기는 MAX_X*2 이상인 2의 거듭제곱 수 중 최소값
int base;
 
// S에 자연수 num을 추가
void push(int num){
    int idx=base+num-1;
    while(idx>0){
        S[idx]++;
        idx>>=1;
    }
}
 
// S에서 rank번째 작은 수를 리턴하고 그 수를 삭제
int pop(int rank){
    assert(S[1]>=rank);
    int idx=1;
    while(idx<base){
        if(S[idx*2]>=rank) idx=idx*2;
        else{ rank-=S[idx*2]; idx=idx*2+1; }
    }
    int ret=idx-base+1;
    while(idx>0){
        S[idx]--;
        idx>>=1;
    }
    return ret;
}

int main() {
    base=1;
    while(base<MAX_X) base<<=1;
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        int T,X;
        scanf("%d %d",&T,&X);
        if(T==1) push(X);
        else if(T==2) printf("%d\n",pop(X));
    }
    return 0;
}