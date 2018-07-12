#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;

typedef struct node{
    int from;
    int to;
    int cost;
}NODE;

vector<ii> a[1001];
bool ch[1001];
int main(void){

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++){
        int from,to,cost;
        scanf("%d %d %d",&from,&to,&cost);
        a[from].push_back(ii(to,cost));
        a[to].push_back(ii(from,cost));
    }

    priority_queue <iii> pq;
    for(int i=0; i<a[1].size(); i++){
        iii tmp=make_pair(-a[1][i].second,make_pair(1,a[1][i].first)); // (cost, from, to)
        pq.push(tmp);
    }
    ch[1]=true;

    int sol=0;
    while(!pq.empty()){
        iii t=pq.top();
        pq.pop();
        int cfrom=t.second.first;
        int cto=t.second.second;
        int ccost=-t.first;
        if(!ch[cfrom] || !ch[cto]){
            ch[cfrom]=ch[cto]=true;
            sol+=ccost;
            for(int i=0; i<a[cto].size(); i++){
                iii tmp=make_pair(-a[cto][i].second,make_pair(1,a[cto][i].first)); // (cost, from, to)
                pq.push(tmp);
            }
        }
    }
    printf("%d\n",sol);
    return 0;
}