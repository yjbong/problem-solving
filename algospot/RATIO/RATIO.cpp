#include <cstdio>
#define INF 2000000001
typedef long long ll;
int t;
ll n,m,target;
bool possible(ll games, ll wins, ll target_ratio, ll x){
        ll cur=100*(wins+x)-target_ratio*(games+x);
        if(cur>=0) return true;
        else return false;
}

int main(void){

        scanf("%d",&t);
        while(t--){
                scanf("%lld %lld",&n,&m);
                target=m*100/n+1;
                ll left=0,right=INF;
                ll ans=INF;
                while(left<=right){
                        ll mid=(left+right)/2;
                        if(possible(n,m,target,mid)){
                                if(ans>mid) ans=mid;
                                right=mid-1;
                        }
                        else left=mid+1;
                }
                if(ans==INF) ans=-1;
                printf("%lld\n",ans);
        }
        return 0;
}