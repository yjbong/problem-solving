#include <cstdio>
#include <vector>
using namespace std;

vector <int> a[222];
int c[222];
int ma[222];
int ch;

bool matched(int u){

    if(c[u]==ch) return false;
    c[u]=ch;
    for(int i=0; i<a[u].size(); i++){
        int v=a[u][i];
        if((ma[v]==-1) || ((ma[v]!=u) && matched(ma[v]))){
            ma[v]=u;
            return true;
        }
    }
    return false;
}

int main(void){

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++){
        int s;
        scanf("%d",&s);
        for(int j=0; j<s; j++){
            int t;
            scanf("%d",&t);
            a[i].push_back(t);
        }
    }

    int ans=0;
    for(int i=0; i<222; i++){
        c[i]=-1;
        ma[i]=-1;
    }
    for(ch=1; ch<=n; ch++){
        int st_node=ch;
        if(matched(st_node)) ans++;
    }
    printf("%d\n",ans);
    return 0;
}