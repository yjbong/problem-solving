#include <cstdio>
#include <queue>
#define INF 1000000000

int ssid,stid;

using namespace std;

int s[1001][3];
char a[2002][2002];
bool eat[1001][1001]; // if eat[i][j]=true, shark i can eat shark j

int n;

int pa[2002];
bool ch[2002];

bool bfs(int front){

    for(int i=0; i<=stid; i++){
        pa[i]=-1;
        ch[i]=false;
    }

    queue <int> q;
    q.push(front);
    while(!q.empty()){
        int f=q.front();
        ch[f]=true;
        q.pop();

        // if an augment path found
        if(f==stid) return true;

        for(int i=0; i<=stid; i++){
            if(!ch[i] && a[f][i]>0){
                q.push(i);
                pa[i]=f;
            }
        }
    }

    return false;
}

int main(void){

    scanf("%d",&n);
    ssid=0; stid=n*2+1;

    for(int i=1; i<=n; i++)
        scanf("%d %d %d",&s[i][0],&s[i][1],&s[i][2]);

    for(int i=1; i<=n; i++)
        a[ssid][i]=a[i][ssid]=1;

    for(int i=n+1; i<=2*n; i++)
        a[i][stid]=a[stid][i]=2;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(s[i][0]>=s[j][0] && s[i][1]>=s[j][1] && s[i][2]>=s[j][2]){
                if(s[i][0]==s[j][0] && s[i][1]==s[j][1] && s[i][2]==s[j][2]){
                    if(i<j) eat[i][j]=true;
                }
                else eat[i][j]=true;
            }
        }
    }

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(eat[i][j]) a[j][n+i]=1;

    int mf=0;

    while(bfs(ssid)){

        int t=stid;
        int path_min=INF;
        // find minimum path value of the augment path
        while(pa[t]>=0){
            if(path_min>a[pa[t]][t]) path_min=a[pa[t]][t];
            t=pa[t];
        }

        // decrease each augment path value by minimum path value
        t=stid;
        while(pa[t]>=0){
            a[pa[t]][t]-=path_min;
            a[t][pa[t]]+=path_min;
            t=pa[t];
        }

        mf+=path_min;
    }

    printf("%d\n",n-mf);

    return 0;
}