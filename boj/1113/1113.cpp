#include <cstdio>
#include <queue>
using namespace std;
int n,m;
int h[50+2][50+2]; // height of cell
bool v[50+2][50+2]; // if visited, 1
queue <pair <int,int> > q; // for BFS

const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,-1,1};
int main(void){

        scanf("%d %d\n", &n,&m);
        for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                        scanf("%1d",&h[i][j]);
                }
        }

        int sol=0;
        for(int lv=1; lv<=9; lv++){ // lv = current level
                for(int i=1; i<=n; i++)
                        for(int j=1; j<=m; j++) v[i][j]=false;

                for(int i=1; i<=n; i++){
                        for(int j=1; j<=m; j++){
                                if(v[i][j]==false && h[i][j]<=lv){

                                        q.push(make_pair(i,j));
                                        v[i][j]=true;

                                        bool ok=true;
                                        int width=1;

                                        while(!q.empty()){
                                                int fy=q.front().first;
                                                int fx=q.front().second;
                                                q.pop();

                                                for(int k=0; k<4; k++){
                                                        int cy=fy+dy[k];
                                                        int cx=fx+dx[k];

                                                        if(h[cy][cx]==0){ // ground
                                                                ok=false;
                                                        }
                                                        else if(v[cy][cx]==false && h[cy][cx]<=lv){
                                                                q.push(make_pair(cy,cx));
                                                                v[cy][cx]=true;
                                                                width++;
                                                        }
                                                }
                                        }
                                        if(ok) sol+=width;
                                }
                        }
                }
        }
        printf("%d\n",sol);
        return 0;
}