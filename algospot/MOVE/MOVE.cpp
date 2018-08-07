#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define INF 1000000000000000000ll
typedef long long ll;
using namespace std;
int C,n,m;
ll d[10000]; // d[i] = minimum distance from start vertex 0

vector<pair<pair<ll,ll>,ll> > e_in;

vector <pair<ll,ll> > e[10000]; //vertex i's edge list. first=destination, second=edge len
priority_queue<pair<ll, ll> > pq; // list of vertex whose min distance is decided. first=-(min distance), second=vertex num

int main(void){
    scanf("%d",&C);
    while(C--){
        scanf("%d %d",&n,&m);

        while(!pq.empty()) pq.pop();
        for(int i=0; i<n; i++) d[i]=INF;
        d[0]=0;
        pq.push(make_pair(0,0));

        for(int i=0; i<n; i++) e[i].clear();
        e_in.clear();

        for(int i=0; i<m; i++){
            ll a,b,c;
            scanf("%lld %lld %lld",&a,&b,&c);
            if(a<b) e_in.push_back(make_pair(make_pair(a,b),c));
            else if(a>b) e_in.push_back(make_pair(make_pair(b,a),c));
        }
        sort(e_in.begin(),e_in.end());

        int old_a, old_b, old_c;
        old_a=-1;
        for(int i=0; i<e_in.size(); i++){
            int cur_a=e_in[i].first.first, cur_b=e_in[i].first.second, cur_c=e_in[i].second;
            if(!(old_a==cur_a && old_b==cur_b)){
                e[cur_a].push_back(make_pair(cur_b,cur_c));
                e[cur_b].push_back(make_pair(cur_a,cur_c));
                old_a=cur_a;
                old_b=cur_b;
            }
        }

        while(!pq.empty()){
            int t=pq.top().second;
            pq.pop();
            for(int i=0; i<e[t].size(); i++){
                int dest=e[t][i].first;
                int len=e[t][i].second;

                if(d[dest]>d[t]+len){
                    d[dest]=d[t]+len;
                    pq.push(make_pair(-d[dest],dest));
                }
            }
        }
        printf("%lld\n",d[n-1]);
    }
    return 0;
}