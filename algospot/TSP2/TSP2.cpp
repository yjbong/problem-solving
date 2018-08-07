#include <cstdio>
#include <vector>
#define MAX_N 15
using namespace std;
int c,n;
double dist[MAX_N][MAX_N];
double d[1<<MAX_N][MAX_N];
vector <int> state_list[MAX_N+1];

int main(void){

        for(int i=0; i<(1<<MAX_N); i++){
                int bits=0;
                for(int j=0; j<MAX_N; j++)
                        if(i&(1<<j)) bits++;
                state_list[bits].push_back(i);
        }
        scanf("%d",&c);
        while(c--){
                scanf("%d",&n);
                for(int i=0; i<n; i++)
                        for(int j=0; j<n; j++)
                                scanf("%lf",&dist[i][j]);

                for(int i=0; i<=n; i++) state_list[i].clear();
                for(int i=0; i<(1<<n); i++){
                        int bits=0;
                        for(int j=0; j<n; j++) if(i&(1<<j)) bits++;
                        state_list[bits].push_back(i);
                }

                for(int i=0; i<(1<<n); i++)
                        for(int j=0; j<n; j++) d[i][j]=1e200;

                for(int i=0; i<n; i++) d[1<<i][i]=0; // can start from every city

                for(int i=2; i<=n; i++){
                        for(int j=0; j<state_list[i].size(); j++){
                                int cur_state=state_list[i][j];
                                for(int k=0; k<n; k++){
                                        if(cur_state&(1<<k)){
                                                for(int l=0; l<n; l++){
                                                        if(l!=k && (cur_state&(1<<l))){
                                                                if(d[cur_state][k]>d[cur_state-(1<<k)][l]+dist[l][k]){
                                                                        d[cur_state][k]=d[cur_state-(1<<k)][l]+dist[l][k];
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                }

                double ans=1e200;
                for(int i=0; i<n; i++)
                        if(ans>d[(1<<n)-1][i]) ans=d[(1<<n)-1][i];
                printf("%.10lf\n",ans);
        }
        return 0;
}