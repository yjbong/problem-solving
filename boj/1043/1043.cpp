#include <cstdio>
#include <queue>
using namespace std;
queue <int> q;
int n,m,t;
bool c[51];
bool pc[51][51];

int main(void){

    scanf("%d %d",&n,&m);
    scanf("%d",&t);
    for(int i=0; i<t; i++){
        int a;
        scanf("%d",&a);
        c[a-1]=true;
        q.push(a-1);
    }

    for(int i=0; i<m; i++){
        scanf("%d",&t);
        for(int j=0; j<t; j++){
            int a;
            scanf("%d",&a);
            pc[i][a-1]=true;
        }
    }

    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(int i=0; i<m; i++){
            if(pc[i][f]){
                for(int j=0; j<n; j++){
                    if(pc[i][j] && !c[j]){
                        c[j]=true;
                        q.push(j);
                    }
                }
            }
        }
    }

    int sol=0;
    for(int i=0; i<m; i++){
        bool ok=true;
        for(int j=0; j<n; j++){
            if(pc[i][j] && c[j]){
                ok=false;
                break;
            }
        }
        if(ok) sol++;
    }
    printf("%d\n",sol);
    return 0;
}