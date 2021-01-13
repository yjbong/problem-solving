#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>
#include <algorithm>
#define INF 1000000000000000000ll
#define MAXN 36
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
int N; // 선수의 수
ll t1[MAXN]; // 팀장1이 i번 선수에 매긴 점수
ll t2[MAXN]; // 팀장2가 i번 선수에 매긴 점수
// 선수가 0~N-1번까지 있을 때, 뒤의 N/2명(N/2~N-1)에 대한 DB를 만든다.
 
// dict[i] = (N/2~N-1)번 선수에 대해 2번 팀을 선택한 선수가 i명(state에서 set인 bit가 i개)인 경우 (first: 1번팀 점수합 - 2번팀 점수합(=diff), second: state)
vector<ii> dict[MAXN/2+1];
 
// cmp1: ii를 diff의 오름차순, state의 오름차순으로 정렬
bool cmp1(ii a, ii b){
    if(a.first<b.first) return true;
    else if(a.first>b.first) return false;
    else{
        return a.second<b.second;
    }
}
 
// cmp2: ii를 diff의 오름차순, state의 내림차순으로 정렬
bool cmp2(ii a, ii b){
    if(a.first<b.first) return true;
    else if(a.first>b.first) return false;
    else{
        return a.second>b.second;
    }
}
 
int main() {
    scanf("%d",&N);
    for(ll i=0; i<N; i++) scanf("%lld",&t1[i]);
    for(ll i=0; i<N; i++) scanf("%lld",&t2[i]);
 
    // 0번 선수가 최상위 bit, N-1번 선수가 최하위 bit여야 한다.
    // 즉, 0번 선수는 N-1번 bit, N-1번 선수가 0번 bit이므로
    // i번 bit는 N-1-i번 선수를 나타낸다.
 
    for(ll i=0; i<(1ll<<(N/2)); i++){
        ll bits=0;
        ll diff=0;
        // bit 번호 0 ~ N/2-1 (선수 번호 N-1 ~ N/2)
        for(ll j=0; j<N/2; j++){ // j = bit 번호
            if(i&(1ll<<j)){ bits++; diff-=t2[N-1-j]; }
            else diff+=t1[N-1-j];
        }
        dict[bits].push_back(make_pair(diff,i));
    }
 
    ll ansDiff=INF, ansState=INF; // 구하려는 답
 
    // sorting
    for(ll i=0; i<=N/2; i++)
        sort(dict[i].begin(),dict[i].end(),cmp1);
 
    for(ll i=0; i<(1ll<<(N/2)); i++){
 
        // 앞쪽 선수(0~N/2-1)에서 정해진 상태 확인
        ll bits=0;
        ll diff=0;
        for(ll j=N/2; j<N; j++){
            // 앞쪽 선수(0~N/2-1)는 (N/2~N-1)번 bit이므로
            // i는 실제로 N/2만큼 left shift시킨 state값으로 봐야한다.
            if((i<<(N/2))&(1ll<<j)){ bits++; diff-=t2[N-1-j]; }
            else diff+=t1[N-1-j];
        }
 
        // 뒤쪽 선수(N/2~N-1) 탐색
        ll tgtBits=N/2-bits; // 뒤쪽에서 2번 팀에 이만큼 더 와야 함
        ll tgtDiff=-diff; // 뒤쪽에서 능력치 차이가 이만큼 나기를 원함
 
        // tgtDiff 이상인 가장 최적 상태 찾기
        ll cdiff=INF, cstate=INF;
        ll left=0, right=dict[tgtBits].size()-1;
        while(left<=right){
            ll mid=(left+right)/2;
            if(tgtDiff<=dict[tgtBits][mid].first){
                // update cdiff & cstate
                if(cdiff>dict[tgtBits][mid].first ||
                   (cdiff==dict[tgtBits][mid].first &&
                    cstate>dict[tgtBits][mid].second)){
                    cdiff=dict[tgtBits][mid].first;
                    cstate=dict[tgtBits][mid].second;
                }
                right=mid-1;
            }
            else // tgtDiff>dict[tgtBits][mid].first
                left=mid+1;
        }
 
        // update ansDiff & ansState
        ll curDiff=llabs(diff+cdiff);
        ll curState=(i<<(N/2))|cstate;
        if(ansDiff>curDiff ||
           (ansDiff==curDiff && ansState>curState)){
            ansDiff=curDiff;
            ansState=curState;
        }
    }
 
    // sorting
    for(ll i=0; i<=N/2; i++)
        sort(dict[i].begin(),dict[i].end(),cmp2);
 
    for(ll i=0; i<(1ll<<(N/2)); i++){
 
        // 앞쪽 선수(0~N/2-1)에서 정해진 상태 확인
        ll bits=0;
        ll diff=0;
        for(ll j=N/2; j<N; j++){
            // 앞쪽 선수(0~N/2-1)는 (N/2~N-1)번 bit이므로
            // i는 실제로 N/2만큼 left shift시킨 state값으로 봐야한다.
            if((i<<(N/2))&(1ll<<j)){ bits++; diff-=t2[N-1-j]; }
            else diff+=t1[N-1-j];
        }
 
        // 뒤쪽 선수(N/2~N-1) 탐색
        ll tgtBits=N/2-bits; // 뒤쪽에서 2번 팀에 이만큼 더 와야 함
        ll tgtDiff=-diff; // 뒤쪽에서 능력치 차이가 이만큼 나기를 원함
 
        // tgtDiff 이하인 가장 최적 상태 찾기
        ll cdiff=-INF, cstate=INF;
        ll left=0, right=dict[tgtBits].size()-1;
        while(left<=right){
            ll mid=(left+right)/2;
            if(tgtDiff>=dict[tgtBits][mid].first){
                // update cdiff & cstate
                if(cdiff<dict[tgtBits][mid].first ||
                   (cdiff==dict[tgtBits][mid].first &&
                    cstate>dict[tgtBits][mid].second)){
                    cdiff=dict[tgtBits][mid].first;
                    cstate=dict[tgtBits][mid].second;
                }
                left=mid+1;
            }
            else // tgtDiff<dict[tgtBits][mid].first
                right=mid-1;
        }
 
        // update ansDiff & ansState
        ll curDiff=llabs(diff+cdiff);
        ll curState=(i<<(N/2))|cstate;
        if(ansDiff>curDiff ||
           (ansDiff==curDiff && ansState>curState)){
            ansDiff=curDiff;
            ansState=curState;
        }
    }
 
    // 답 출력
    //printf("%d\n",ansDiff);
    for(ll i=N-1; i>=0; i--){
        // i번 선수가 팀 1이면 (N-1-i)번 bit가 0이고, 팀 2이면 1이다.
        if(ansState&(1ll<<i)) printf("2 ");
        else printf("1 ");
    }
    printf("\n");
    return 0;
}