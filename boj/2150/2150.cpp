#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct _ord{
    int pos;
    int val;
}ORD;

ORD ord[10001];

bool ch[10001];
vector <int> a[10001];
vector <int> ta[10001];
vector <int> scc[10001];
int sccs;

stack <int> s;

bool cmp(ORD a, ORD b){
    if(a.val<=b.val) return true;
    else return false;
}

void go(int cv){
    ch[cv]=true;
    for(int i=0; i<a[cv].size(); i++)
        if(!ch[a[cv][i]]) go(a[cv][i]);
    s.push(cv);
}

void go2(int cv){
    ch[cv]=true;
    scc[sccs].push_back(cv);
    for(int i=0; i<ta[cv].size(); i++)
        if(!ch[ta[cv][i]]) go2(ta[cv][i]);
}

int main(void){

    int vs,es;
    scanf("%d %d",&vs,&es);

    for(int i=0; i<es; i++){
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        a[t1].push_back(t2);
    }

    for(int i=1; i<=vs; i++) ch[i]=false;
    for(int i=1; i<=vs; i++) if(!ch[i]) go(i);

    for(int i=1; i<=vs; i++){
        for(int j=0; j<a[i].size(); j++){
            ta[a[i][j]].push_back(i);
        }
    }

    for(int i=1; i<=vs; i++) ch[i]=false;

    sccs=0;
    while(!s.empty()){
        int t=s.top();
        s.pop();
        if(!ch[t]){
            go2(t);
            sccs++;
        }
    }

    for(int i=0; i<sccs; i++)
        sort(scc[i].begin(),scc[i].begin()+scc[i].size());

    for(int i=0; i<sccs; i++){
        ord[i].pos=i;
        ord[i].val=scc[i][0];
    }
    sort(ord,ord+sccs,cmp);

    printf("%d\n",sccs);
    for(int i=0; i<sccs; i++){
        for(int j=0; j<scc[ord[i].pos].size(); j++){
            printf("%d ",scc[ord[i].pos][j]);
        }
        printf("-1\n");
    }
    return 0;
}