#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int c; // # of tc
int n; // # of buildings
int m; // # of edges already connected
int x[5000];
int y[5000];
typedef pair<double, pair<int, int> > EDGE; // first=length, second.first=from, second.second=to
vector <EDGE> edge_list;

int p[5000]; // p[i]>=0, then p[i]=vertex i's parent
             // p[i]<0, then  vertex i is representative of set, and size of set is (-p[i]).

int find2(int a){ // find vertex a's set representative

        while(p[a]>=0) a=p[a];
        return a;
}

int union2(int a, int b){ // merge 2 sets(the set including vertex a and the set including vertex b), return size of merged set
        int rep_a=find2(a);
        int rep_b=find2(b);
        if(rep_a==rep_b) return (-p[rep_a]);

        if(p[rep_a]<=p[rep_b]){ // attach b's set to a's
                p[rep_a]+=p[rep_b];
                p[rep_b]=rep_a;
                return (-p[rep_a]);
        }
        else{ // attach a's set to b's
                p[rep_b]+=p[rep_a];
                p[rep_a]=rep_b;
                return (-p[rep_b]);
        }
}

int main(void){

        scanf("%d",&c);
        while(c--){
                scanf("%d %d",&n,&m);
                for(int i=0; i<n; i++) scanf("%d",&x[i]);
                for(int i=0; i<n; i++) scanf("%d",&y[i]);

                // make edge list and sort it by length
                edge_list.clear();
                for(int i=0; i<n; i++){
                        for(int j=i+1; j<n; j++){
                                double cur_dist=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                                edge_list.push_back(make_pair(cur_dist,make_pair(i,j)));
                        }
                }
                sort(edge_list.begin(), edge_list.end());

                // init p[] array
                for(int i=0; i<n; i++) p[i]=-1;

                // connect existing edges
                for(int i=0; i<m; i++){
                        int a,b;
                        scanf("%d %d",&a,&b);
                        union2(a,b);
                }

                // kruskal
                double ans=0;
                for(int i=0; i<edge_list.size(); i++){
                        double length=edge_list[i].first;
                        int from=edge_list[i].second.first;
                        int to=edge_list[i].second.second;
                        if(find2(from)!=find2(to)) ans+=length;
                        if(union2(from,to)==n) break;
                }

                printf("%lf\n",ans);
        }
        return 0;
}