#include <cstdio>
#include <cassert>
#define MAX_N 500000
int N; // 부대의 개수
int M; // 명령의 개수
int A[1<<20]; // 필요한 배열의 크기는 MAX_N*2 이상인 2의 거듭제곱 수 중 최소값
int base;

// idx번 부대의 인원이 num만큼 변화
void update(int idx, int num){
    idx=base+idx-1;
    assert(A[idx]+num>=0);
    while(idx>0){
        A[idx]+=num;
        idx>>=1;
    }
}

// 군번이 num인 군인이 속하는 부대의 번호를 리턴
int getSquad(int num){
    assert(A[1]>=num);
    int idx=1;
    while(idx<base){
        if(A[idx*2]>=num) idx=idx*2;
        else{ num-=A[idx*2]; idx=idx*2+1; }
    }
    return idx-base+1;
}

int main() {
    scanf("%d",&N);
    base=1;
    while(base<N) base<<=1;
    for(int i=1; i<=N; i++){
        int num;
        scanf("%d",&num);
        update(i,num);
    }
    scanf("%d",&M);
    for(int i=1; i<=M; i++){
        int cmd, squad, num;
        scanf("%d",&cmd);
        if(cmd==1){
            scanf("%d %d",&squad,&num);
            update(squad,num);
        }
        else if(cmd==2){
            scanf("%d",&num);
            printf("%d\n",getSquad(num));
        }
    }
    return 0;
}