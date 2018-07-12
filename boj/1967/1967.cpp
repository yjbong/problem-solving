#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int,int> ii;
int d[11111];
bool ch[11111];
vector <ii> a[11111];

int main(void){

    int n;
    scanf("%d",&n);
    int from,to,dst;
    while(scanf("%d %d %d",&from,&to,&dst)==3){
        a[from].push_back(ii(to,dst));
        a[to].push_back(ii(from,dst));
    }

    queue<int> q;
    q.push(1);
    ch[1]=true;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(int i=0; i<a[f].size(); i++){
            int cto=a[f][i].first;
            int cdst=a[f][i].second;
            if(!ch[cto]){
                ch[cto]=true;
                d[cto]=d[f]+cdst;
                q.push(cto);
            }
        }
    }

    int max=1;
    for(int i=1; i<=n; i++) if(d[max]<d[i]) max=i;
    for(int i=1; i<=n; i++) d[i]=0,ch[i]=false;

    q.push(max);
    ch[max]=true;

    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(int i=0; i<a[f].size(); i++){
            int cto=a[f][i].first;
            int cdst=a[f][i].second;
            if(!ch[cto]){
                ch[cto]=true;
                d[cto]=d[f]+cdst;
                q.push(cto);
            }
        }
    }
    int sol=0;
    for(int i=1; i<=n; i++) if(sol<d[i]) sol=d[i];
    printf("%d\n",sol);
    return 0;
}