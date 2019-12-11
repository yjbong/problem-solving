#include <cstdio>
#define MAX_N 2000000000ll
#define MAX_M 10000ll
#define FAST 1
using namespace std;
typedef long long ll;
ll N;
ll M;
ll R[MAX_M+1]; // R[i]=i번 놀이기구의 운행시간
ll getStartTime(){
    // N명이 이용 완료하는 시점 tn을 구한다.
    ll left=0, right=MAX_N*30, Tn=right;
    while(left<=right){
        ll mid=(left+right)/2;
        ll curNum=0; // mid 시점까지 기구를 이용 완료한 어린이의 수
        for(int i=1; i<=M; i++) curNum+=mid/R[i];
        if(curNum<N) left=mid+1;
        else{
            if(Tn>mid) Tn=mid;
            right=mid-1;
        }
    }

    // 놀이기구 중 가장 운행시간이 긴 값 Rmax를 찾는다.
    ll Rmax=0;
    for(int i=1; i<=M; i++)
        if(Rmax<R[i]) Rmax=R[i];

    // 시뮬레이션 시작은 Tn-Rmax부터 하면 된다.
    return Tn-Rmax;
}
int main() {
    scanf("%lld %lld",&N,&M);
    for(int i=1; i<=M; i++) scanf("%lld",&R[i]);
    ll time; // 현재 시점
    ll curIdx; // 이번에 탑승할 아이의 번호

    if(N<=M){
        printf("%lld\n",N);
        return 0;
    }

    if(FAST){
        time=getStartTime();
        curIdx=1;
        for(int i=1; i<=M; i++) curIdx+=time/R[i];
        for(int i=1; i<=M; i++)
            if(time%R[i]) curIdx++;
    }
    else{ // Naive 방법
        time=0; 
        curIdx=1;
    }

    // 시뮬레이션
    while(1){
        for(int i=1; i<=M; i++){
            if(time%R[i]==0){
                if(curIdx==N){
                    printf("%d\n", i);
                    goto out;
                }
                curIdx++;
            }
        }
        time++;
    }
out:
    return 0;
}