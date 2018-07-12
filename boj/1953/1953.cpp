#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n;
int a[101][101];
int c[101];
queue <int> q;
vector <int> v[2];
int main(void){

    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        int t;
        scanf("%d",&t);
        for(int j=0; j<t; j++){
            int k;
            scanf("%d",&k);
            a[i][k]=a[k][i]=1;
        }
    }

    for(int i=1; i<=n; i++){
        if(!c[i]){
            q.push(i);
            c[i]=1;
            while(!q.empty()){
                int f=q.front();
                q.pop();
                for(int j=1; j<=n; j++){
                    if(a[f][j] && c[j]==0){
                        if(c[f]==1) c[j]=2;
                        else c[j]=1;
                        q.push(j);
                    }
                }
            }
        }
    }

    for(int i=1; i<=n; i++)
        if(c[i]>0) v[c[i]-1].push_back(i);

    for(int i=0; i<2; i++){
        printf("%d\n", v[i].size());
        for(int j=0; j<v[i].size(); j++)
            printf("%d ",v[i][j]);
        printf("\n");
    }
    return 0;
}