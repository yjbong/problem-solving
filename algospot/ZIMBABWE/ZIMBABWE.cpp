#include <cstdio>
#define BIGNUM 1000000007ll
typedef long long ll;
int c;
ll e,m;
int dgt[20];
int dgts;
int numcnt[10];

ll cache[1<<15][20][2];

int get_bitmask(void){
        int cur_numcnt[10];
        int ret=0;
        for(int i=0; i<10; i++) cur_numcnt[i]=numcnt[i];
        for(int i=0; i<dgts; i++){
                if(cur_numcnt[dgt[i]]>0){
                        ret |= (1<<i);
                        cur_numcnt[dgt[i]]--;
                }
        }
        return ret;
}

ll go(int remain_dgts, ll cur_num, int all_dgt){ // n = num of digits to decide, cur_num = decided_number MOD m, all_digit = if all digit(0~9) are possible then 1, else 0

    int cur_bitmask;

    cur_bitmask=get_bitmask();
    if(cache[cur_bitmask][cur_num][all_dgt]>=0)
        return cache[cur_bitmask][cur_num][all_dgt];

    if(remain_dgts==0){
        if(cur_num==0 && all_dgt){
            return (cache[cur_bitmask][cur_num][all_dgt]=1);
        }
        else{
            return (cache[cur_bitmask][cur_num][all_dgt]=0);
        }
    }

    int end_dgt;
    if(all_dgt) end_dgt=9;
    else end_dgt=dgt[remain_dgts-1];

    ll ret=0;
    for(int i=0; i<=end_dgt; i++){
        if(numcnt[i]>0){
            numcnt[i]--;
            if(all_dgt) ret=(ret+go(remain_dgts-1, (cur_num*10+i)%m, 1))%BIGNUM;
            else if(i<dgt[remain_dgts-1]) ret=(ret+go(remain_dgts-1, (cur_num*10+i)%m, 1))%BIGNUM;
            else ret=(ret+go(remain_dgts-1, (cur_num*10+i)%m, 0))%BIGNUM;
            numcnt[i]++;
        }
    }

    cur_bitmask=get_bitmask();
    return (cache[cur_bitmask][cur_num][all_dgt]=ret);
}

int main(void){

    scanf("%d",&c);
    while(c--){
        scanf("%lld %lld",&e,&m);
        for(int i=0; i<10; i++) numcnt[i]=0;
        dgts=0;
        while(e>0){
            dgt[dgts++]=e%10;
            numcnt[e%10]++;
            e/=10;
        }
        for(int i=0; i<(1<<dgts); i++)
            for(int j=0; j<m; j++)
                for(int k=0; k<2; k++) cache[i][j][k]=-1;

        printf("%lld\n",go(dgts,0,0));
    }
    return 0;
}