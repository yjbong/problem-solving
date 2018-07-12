#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair <int,int> ii;

bool cmp1(ii a, ii b){
    if(a.first<b.first) return true;
    else return false;
}
bool cmp2(ii a, ii b){
    if(a.second<b.second) return true;
    else return false;
}

ii iv[25000];
int n;

int match[25000];

int get_match_idx(int key){
    int l,m,r;

    l=0; r=n-1;
    while(l<=r){
        m=(l+r)/2;
        if(match[m]<key) l=m+1;
        else if(match[m]>key) r=m-1;
        else return m;
    }
    return -1;
}

int bit[1<<16];

void init_bit(int base){
    for(int i=0; i<base*2; i++) bit[i]=0;
}

void update_bit(int base, int idx, int add_num){

    bit[base+idx]+=add_num;
    int cur_idx=(base+idx)/2;
    while(cur_idx>=1){
        bit[cur_idx]=bit[cur_idx*2]+bit[cur_idx*2+1];
        cur_idx/=2;
    }
}

int get_sum(int base, int start, int end){

    int l=base+start;
    int r=base+end;
    int sum=0;
    while(l<r){
        if(l%2==0) l=l/2;
        else{
            sum+=bit[l];
            l=(l+1)/2;
        }
        if(r%2==1) r=r/2;
        else{
            sum+=bit[r];
            r=(r-1)/2;
        }
    }
    if(l==r) sum+=bit[l];
    return sum;
}

int main(void){

    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d %d",&(iv[i].first),&(iv[i].second));

    int base=1;
    while(base<n) base*=2;
    init_bit(base);

    sort(iv,iv+n,cmp2);
    for(int i=0; i<n; i++)
        match[i]=iv[i].second;

    int sol=0;
    sort(iv,iv+n,cmp1);
    for(int i=n-1; i>=0; i--){
        int cur_idx=get_match_idx(iv[i].second);
        if(cur_idx>=0) update_bit(base,cur_idx,1);

        int cur_sum=get_sum(base,0,cur_idx-1);
        if(sol<cur_sum) sol=cur_sum;
    }
    printf("%d\n",sol);
    return 0;
}