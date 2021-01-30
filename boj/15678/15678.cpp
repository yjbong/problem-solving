#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
 
typedef long long ll;
typedef pair<ll,int> ii;
 
int n, d;
 
ll D[100000]; // D[i] = i번 징검다리를 마지막으로 밟았을 때 가능한 최대 점수
ll A[100000]; // A[i] = i번 징검다리에 쓰여 있는 수
 
priority_queue<ii> pq;
 
int main() {
 
    scanf("%d %d",&n,&d);
    for(int i=0; i<n; i++) scanf("%lld",&A[i]);
 
    ll ans=A[0];
    for(int i=0; i<n; i++){
        D[i]=A[i];
        while(!pq.empty()){
            ii top=pq.top();
            int topIdx=top.second;
            if(i-topIdx<=d){
                ll topVal=top.first;
                if(topVal>0) D[i]+=topVal;
                break;
            }
            else pq.pop();
        }
        pq.push(make_pair(D[i],i));
        if(ans<D[i]) ans=D[i];
    }
    printf("%lld\n",ans);
    return 0;
}