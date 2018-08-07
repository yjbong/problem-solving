#include <cstdio>
#include <queue>
#include <utility>
#define INF 1000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int c,v,e,n;
ll d[111][111]; // d[i][j] = distance of shortest path between vertex i and j
ll p1[111][111]; // p1[i][j] = # of shortest paths that starts at vertex 1(start vertex) and ends at vertex j, with passing i vertices
ll p2[111][111]; // p2[i][j] = # of shortest paths that starts at vertex v(end vertex) and ends at vertex j, with passing i vertices
ll p[111]; // p[i] = # of shortest paths that starts at vertex 1(start) and ends at vertex v(end), with passing vertex i
queue <int> q;
bool check[111];

typedef struct{
        vector <ii> edge; // list of existing edges from this node. first=to, second=weight
        vector <int> in_v; // list of in vertex
        vector <int> out_v; // list of out vertex
}NODE;
NODE node[111];


ll gcd(ll a, ll b){
    if(a==0 && b==0) return 1;
    else if(a==0) return b;
    else if(b==0) return a;
    else return gcd(b, a%b);
}

ll min2(ll a, ll b){
        return a<b?a:b;
}

int main(void){
        scanf("%d",&c);
        while(c--){
                scanf("%d %d %d",&v,&e,&n);
                for(int i=1; i<=v; i++)
                        for(int j=1; j<=v; j++) d[i][j]=(i==j?0:INF);
                for(int i=1; i<=v; i++) node[i].edge.clear();

                for(int i=0; i<e; i++){
                        ll a,b,t;
                        scanf("%lld %lld %lld",&a,&b,&t);
                        if(d[a][b]>t) d[a][b]=t;
                        if(d[b][a]>t) d[b][a]=t;
                        node[a].edge.push_back(make_pair(b,t));
                        node[b].edge.push_back(make_pair(a,t));
                }

                for(int k=1; k<=v; k++)
                        for(int i=1; i<=v; i++)
                                for(int j=1; j<=v; j++)
                                        d[i][j]=min2(d[i][j],d[i][k]+d[k][j]);

                // init node
                for(int i=1; i<=v; i++){
                        node[i].in_v.clear();
                        node[i].out_v.clear();
                }

                // build previous vertex list
                for(int i=1; i<=v; i++) check[i]=false;
                while(!q.empty()) q.pop();

                q.push(1);
                check[1]=true;
                while(!q.empty()){
                        int f=q.front();
                        q.pop();

                        for(int i=0; i<node[f].edge.size(); i++){
                                int cur_v=node[f].edge[i].first;
                                int cur_w=node[f].edge[i].second;
                                if(d[f][v]==cur_w+d[cur_v][v]){
                                        node[cur_v].in_v.push_back(f);
                                        node[f].out_v.push_back(cur_v);
                                        if(!check[cur_v]){
                                                q.push(cur_v);
                                                check[cur_v]=true;
                                        }
                                }
                        }
                }

                for(int i=0; i<=v; i++)
                    for(int j=0; j<=v; j++)
                        p1[i][j]=0;

                p1[1][1]=1;
                for(int i=2; i<=v; i++){
                    for(int j=1; j<=v; j++){
                        for(int k=0; k<node[j].in_v.size(); k++){
                            int cur_v=node[j].in_v[k];
                            p1[i][j]+=p1[i-1][cur_v];
                        }
                    }
                }

                for(int i=0; i<=v; i++)
                    for(int j=0; j<=v; j++)
                        p2[i][j]=0;

                p2[1][v]=1;
                for(int i=2; i<=v; i++){
                    for(int j=1; j<=v; j++){
                        for(int k=0; k<node[j].out_v.size(); k++){
                            int cur_v=node[j].out_v[k];
                            p2[i][j]+=p2[i-1][cur_v];
                        }
                    }
                }

                for(int i=1; i<=v; i++){
                    ll p1_sum=0;
                    for(int j=1; j<=v; j++) p1_sum+=p1[j][i];

                    ll p2_sum=0;
                    for(int j=1; j<=v; j++) p2_sum+=p2[j][i];

                    p[i]=p1_sum*p2_sum;
                }

                // print answer
                for(int i=0; i<n; i++){
                        int q;
                        scanf("%d",&q);
                        printf("%lld/%lld\n",p[q]/gcd(p[1],p[q]),p[1]/gcd(p[1],p[q]));
                }
        }

        return 0;
}