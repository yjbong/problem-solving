#include <cstdio>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;
int c,n;
pair <double,double> coord[100];
double dist[100][100];
bool visited[100];
queue <int> q;

bool connected(double range){
        for(int i=0; i<n; i++) visited[i]=false;
        q.push(0); visited[0]=true;
        int cnt=1;
        while(!q.empty()){
                int f=q.front();
                q.pop();
                for(int i=0; i<n; i++){
                        if(!visited[i] && dist[f][i]<=range){
                                q.push(i);
                                visited[i]=true;
                                cnt++;
                        }
                }
        }
        if(cnt==n) return true;
        else return false;
}

int main(void){

        scanf("%d",&c);
        while(c--){
                scanf("%d",&n);
                for(int i=0; i<n; i++)
                        scanf("%lf %lf",&coord[i].first,&coord[i].second);
                for(int i=0; i<n; i++){
                        for(int j=0; j<n; j++){
                                double x1=coord[i].first; double y1=coord[i].second;
                                double x2=coord[j].first; double y2=coord[j].second;
                                dist[i][j]=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
                        }
                }

                double left=0, right=1000000;
                double ans=right;
                for(int i=0; i<100; i++){
                        double mid=(left+right)/2;
                        if(connected(mid)){
                                if(ans>mid) ans=mid;
                                right=mid;
                        }
                        else left=mid;
                }
                printf("%.2lf\n",ans);
        }
        return 0;
}