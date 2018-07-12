#include <cstdio>
#include <queue>
#include <utility>
#define INF 10000
using namespace std;
typedef pair <int , int> ii;
queue <ii> q;
int a[15][15];
int d[1<<15][15];

int main(void){

    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%1d",&a[i][j]);

    for(int i=0; i<(1<<n); i++)
        for(int j=0; j<n; j++) d[i][j]=INF;

    d[1][0]=0;

    q.push(make_pair(1,0));
    while(!q.empty()){
        ii f=q.front();
        q.pop();
        int f_stat=f.first;
        int f_art=f.second;

        for(int i=0; i<n; i++){
            if(!(f_stat&(1<<i)) && (d[f_stat][f_art] <= a[f_art][i]) && (d[f_stat+(1<<i)][i] > a[f_art][i])){
                d[f_stat+(1<<i)][i] = a[f_art][i];
                q.push(make_pair(f_stat+(1<<i),i));
            }
        }
    }

    int sol=1;
    for(int i=0; i<(1<<n); i++){
        for(int j=0; j<n; j++){
            if(d[i][j]<INF){
                int bits=0;
                int t=i;
                while(t>0){
                    if(t%2) bits++;
                    t/=2;
                }
                if(sol<bits) sol=bits;
            }
        }
    }

    printf("%d\n",sol);
    return 0;
}