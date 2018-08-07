#include <cstdio>
#include <cfloat>
#define MAX_N 8

int c,n;
bool visited[MAX_N];
double dist[MAX_N][MAX_N];

double go(int visits, int last_visit, double distsum){

        if(visits==n){
                return distsum;
        }
        double ret=DBL_MAX;
        for(int i=0; i<n; i++){
                if(!visited[i]){
                        visited[i]=true;
                        double cur_distsum=go(visits+1,i,distsum+dist[last_visit][i]);
                        if(ret>cur_distsum) ret=cur_distsum;
                        visited[i]=false;
                }
        }
        return ret;
}

int main(void){

        scanf("%d",&c);
        while(c--){
                scanf("%d",&n);
                for(int i=0; i<n; i++)
                        for(int j=0; j<n; j++)
                                scanf("%lf",&dist[i][j]);

                for(int i=0; i<n; i++) visited[i]=false;

                double ans=DBL_MAX;
                for(int i=0; i<n; i++){
                        visited[i]=true;
                        double cur_ans=go(1,i,0);
                        if(ans>cur_ans) ans=cur_ans;
                        visited[i]=false;
                }
                printf("%.10lf\n",ans);
        }
        return 0;
}