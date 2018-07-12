#include <cstdio>
#include <climits>
#include <algorithm>
#define LEFT 0
#define RIGHT 1
using namespace std;
typedef long long ll;
typedef struct _interval{

    ll start;
    ll end;
    ll cur[2];
}INTERVAL;

ll lucky[222];
ll luckys;

INTERVAL intv[222];
ll intvs;
ll n;

ll unlucky_intervals(ll start, ll end, ll num){ // 구간 [start,end]에서 num을 포함하는 unlucky구간의 개수

    ll mid=(start+end)/2;
    if(num>mid) num=(start+end)-num;

    ll len=end-start;
    ll sol=len;
    if(len%2==0){
        sol+=(mid-start)*(mid-start);
        sol-=(mid-num)*(mid-num);
    }
    else{
        sol+=(mid-start)*(mid-start+1);
        sol-=(mid-num)*(mid-num+1);
    }

    return sol;
}

int main(void){

    scanf("%lld",&luckys);
    for(ll i=0; i<luckys; i++) scanf("%lld",&lucky[i]);
    lucky[luckys++]=0;
    sort(lucky, lucky+luckys);

    ll cur_luckys=luckys;
    for(ll i=1; i<cur_luckys; i++)
        if(lucky[i]-lucky[i-1]==2)
            lucky[luckys++]=lucky[i]-1;
    sort(lucky, lucky+luckys);

    scanf("%lld",&n);
    for(ll i=1; i<luckys && n>0; i++){
        printf("%lld ",lucky[i]);
        n--;
    }

    intvs=0;
    for(ll i=1; i<luckys; i++){
        if(lucky[i]-lucky[i-1]>2){
            intv[intvs].start=lucky[i-1]+1;
            intv[intvs].end=lucky[i]-1;
            intv[intvs].cur[LEFT]=intv[intvs].start;
            intv[intvs].cur[RIGHT]=intv[intvs].end;
            intvs++;
        }
    }

    bool go=true;
    while(n>0 && go){

        go=false;
        ll intv_idx;
        ll intv_lr;
        ll min_unluckys=LLONG_MAX;

        for(ll i=0; i<intvs; i++){
            if(intv[i].cur[LEFT]<=intv[i].cur[RIGHT]){
                go=true;
                for(ll j=0; j<2; j++){
                    ll cur_unluckys=unlucky_intervals(intv[i].start, intv[i].end, intv[i].cur[j]);
                    if(min_unluckys>cur_unluckys){
                        min_unluckys=cur_unluckys;
                        intv_idx=i;
                        intv_lr=j;
                    }
                }
            }
        }

        if(go){
            printf("%lld ",intv[intv_idx].cur[intv_lr]);
            n--;

            if(intv_lr==LEFT) intv[intv_idx].cur[LEFT]++;
            else intv[intv_idx].cur[RIGHT]--;
        }
    }

    for(ll i=1; i<=n; i++) printf("%lld ",lucky[luckys-1]+i);
    printf("\n");

    return 0;
}