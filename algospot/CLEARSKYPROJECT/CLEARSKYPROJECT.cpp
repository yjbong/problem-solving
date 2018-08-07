#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#define INF 1000000000
using namespace std;
int tc,clouds,maxshots;
vector<pair<int,int> > cloud;
int pos[555]; int numpos;
int d[555][555];
int c[555]; int s[555];
int e[555][555];

int min2(int a, int b){
        return a<b?a:b;
}

int main(void){
        scanf("%d",&tc);
        while(tc--){
                cloud.clear();
                scanf("%d %d",&clouds,&maxshots);
                for(int i=0; i<clouds; i++){
                        int s,e;
                        scanf("%d %d",&s,&e);
                        cloud.push_back(make_pair(s,e));
                }
                sort(cloud.begin(), cloud.end());

                pos[0]=0; c[0]=0;
                numpos=1;
                for(int i=0; i<clouds; i++){
                        int curstart=cloud[i].first;
                        if(curstart!=pos[numpos-1]){
                                pos[numpos++]=curstart;
                                c[numpos-1]=1;
                        }
                        else c[numpos-1]++;
                }
                s[0]=0;
                for(int i=1; i<numpos; i++) s[i]=s[i-1]+c[i];

                for(int i=0; i<numpos; i++)
                        for(int j=i+1; j<numpos; j++) e[i][j]=0;

                for(int i=0; i<numpos; i++){
                        for(int j=i+1; j<numpos; j++){
                                for(int k=0; k<clouds; k++){
                                        int curstart=cloud[k].first;
                                        int curend=cloud[k].second;
                                        if(pos[i]<curstart && curstart<pos[j] && curend>=pos[j]) e[i][j]++;
                                }
                        }
                }

                for(int i=0; i<numpos; i++)
                        for(int j=0; j<=maxshots; j++) d[i][j]=INF;

                d[0][0]=0;
                for(int i=1; i<numpos; i++){
                        for(int j=1; j<=maxshots; j++){
                                for(int k=0; k<i; k++){
                                        if(s[i]==s[k]+e[k][i]+c[i]){
                                                d[i][j]=min2(d[i][j],d[k][j-1]+(e[k][i]+c[i])*pos[i]);
                                        }
                                }
                        }
                }

                int ans=INF;
                for(int i=0; i<=maxshots; i++) ans=min2(ans,d[numpos-1][i]);
                printf("%d\n",ans);
        }

        return 0;
}