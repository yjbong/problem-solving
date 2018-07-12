#include <cstdio>
#include <vector>
#define INF 1000000000
using namespace std;
int d[2][100001];
int h[351];
int s[351];
int H,N;
bool c[100001];
vector <int> v[2];
int min(int a, int b){
    if(a<b) return a;
    else return b;
}

int main(void){

    scanf("%d %d",&H,&N);
    for(int i=1; i<=N; i++) scanf("%d %d",&h[i],&s[i]);
    v[0].clear(); v[1].clear();
    for(int j=0; j<=H; j++) d[0][j]=INF;
    d[0][0]=INF; v[0].push_back(0); c[0]=true;
    int sol=0;
    for(int i=1; i<=N; i++){
        int newv=i%2; int oldv=1-newv;
        for(int j=0; j<=H; j++){ c[j]=false; d[newv][j]=0;}
        for(int j=0; j<v[oldv].size(); j++){
            if(!c[v[oldv][j]]){ v[newv].push_back(v[oldv][j]); c[v[oldv][j]]=true; }
            if(d[newv][v[oldv][j]]<d[oldv][v[oldv][j]]) d[newv][v[oldv][j]]=d[oldv][v[oldv][j]];

            if(v[oldv][j]==H) if(sol<d[newv][v[oldv][j]]) sol=d[newv][v[oldv][j]];

            if(v[oldv][j]+h[i]<=H){
                if(!c[v[oldv][j]+h[i]]){ v[newv].push_back(v[oldv][j]+h[i]); c[v[oldv][j]+h[i]]=true; }
                if(d[newv][v[oldv][j]+h[i]]<min(d[oldv][v[oldv][j]],s[i])) d[newv][v[oldv][j]+h[i]]=min(d[oldv][v[oldv][j]],s[i]);

                if(v[oldv][j]+h[i]==H) if(sol<d[newv][v[oldv][j]+h[i]]) sol=d[newv][v[oldv][j]+h[i]];
            }
        }

        v[oldv].clear();
    }
    printf("%d\n",sol);
    return 0;
}