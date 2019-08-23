#include <cstdio>
#define MAX_N 123456
#define BIG 1000000000000000000ll
using namespace std;
typedef long long ll;
int N; // 방의 개수 N (1 ≤ N ≤ 123,456)
ll HATK; // 용사의 초기 공격력 (1 ≤ HATK ≤ 1,000,000)
 
// i번째 방의 정보를 나타내는 세개의 정수
// ti, ai, hi (ti ∈ {1, 2}, 1 ≤ ai, hi ≤ 1,000,000)
// ti가 1인 경우 공격력이 ai이고 생명력이 hi인 몬스터가 있고, ti가 2인 경우 용사의 공격력 HATK를 ai만큼 증가시켜주고 용사의 현재 생명력 HCurHP를 hi만큼 회복시켜주는 포션이 있음
ll t[MAX_N], a[MAX_N], h[MAX_N];
 
bool runGame(ll HMaxHP){
    ll HCurHP=HMaxHP;
    ll HCurATK=HATK;
    ll hitsNeed; // 몬스터를 잡기 위해 필요한 공격 횟수
    for(int i=0; i<N; i++){
        switch(t[i]){
            case 1: // 몬스터
                hitsNeed=h[i]/HCurATK+(h[i]%HCurATK?1:0);
                HCurHP-=a[i]*(hitsNeed-1);
                if(HCurHP<=0) return false;
                break;
            case 2: // 포션
                HCurATK+=a[i];
                HCurHP+=h[i];
                if(HCurHP>HMaxHP) HCurHP=HMaxHP;
        }
    }
    return true;
}
int main() {
    scanf("%d %lld",&N,&HATK);
    for(int i=0; i<N; i++)
        scanf("%lld %lld %lld",&t[i],&a[i],&h[i]);
    // 필요한 최소 HMaxHP를 이분 탐색으로 확인
    ll left=1, right=BIG;
    ll ans=BIG;
    while(left<=right){
        ll mid=(left+right)/2;
        if(runGame(mid)){
            if(ans>mid) ans=mid;
            right=mid-1;
        }
        else left=mid+1;
    }
    printf("%lld\n",ans);
    return 0;
}