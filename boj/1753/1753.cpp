#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 200000000
using namespace std;
typedef pair<int,int> ii;
int sol[22222];
vector<ii> e[22222];

int main(void){

    int vs,es,st;
    scanf("%d %d %d",&vs,&es,&st);
    for(int i=0; i<es; i++){
        int sv,ev,w;
        scanf("%d %d %d",&sv,&ev,&w);
        e[sv].push_back(ii(ev,w));
    }

    for(int i=1; i<=vs; i++) sol[i]=INF;
    sol[st]=0;
    priority_queue<ii> pq;
    for(int i=0; i<e[st].size(); i++){
        int cv=e[st][i].first;
        int cw=e[st][i].second;
        if(sol[cv]>cw){
            sol[cv]=cw;
            pq.push(ii(cv,cw));
        }
    }

    while(!pq.empty()){
        ii t=pq.top();
        pq.pop();
        int tv=t.first;
        int tw=t.second;

        for(int i=0; i<e[tv].size(); i++){
            int cv=e[tv][i].first;
            int cw=e[tv][i].second;

            if(sol[cv]>sol[tv]+cw){
                sol[cv]=sol[tv]+cw;
                pq.push(ii(cv,sol[cv]));
            }
        }
    }

    for(int i=1; i<=vs; i++){
        if(sol[i]>=INF) printf("INF\n");
        else printf("%d\n",sol[i]);
    }
    return 0;
}