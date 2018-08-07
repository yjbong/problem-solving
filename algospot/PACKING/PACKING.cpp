#include <cstdio>
#include <utility>
using namespace std;
int c,n,W;
char name[111][22];
int w[111];
int p[111];

bool s[111];
int d[111][1111];
pair <int,int> next[111][1111];

int go(int idx, int space){
        if(d[idx][space]>=0) return d[idx][space];

        if(idx>n-1 || space==0) return (d[idx][space]=0);

        int ret=0;
        if(w[idx]<=space){
                int select=p[idx]+go(idx+1,space-w[idx]);
                if(ret<select){
                        ret=select;
                        next[idx][space].first=idx+1;
                        next[idx][space].second=space-w[idx];
                }
        }
        int noselect=go(idx+1,space);
        if(ret<noselect){
                ret=noselect;
                next[idx][space].first=idx+1;
                next[idx][space].second=space;
        }

        return (d[idx][space]=ret);
}

int main(void){

        scanf("%d",&c);
        while(c--){
                scanf("%d %d",&n,&W);
                for(int i=0; i<n; i++)
                        scanf("%s %d %d",name[i],&w[i],&p[i]);

                for(int i=0; i<=n; i++)
                        for(int j=0; j<=W; j++) d[i][j]=-1;

                for(int i=0; i<=n; i++){
                        for(int j=0; j<=W; j++){
                                next[i][j].first=next[i][j].second=-1;
                        }
                }
                for(int i=0; i<n; i++) s[i]=false;
                int ans=go(0,W);
                int items=0;

                int idx=0; int space=W;
                while(idx<n && space>0){
                        int nextidx=next[idx][space].first;
                        int nextspace=next[idx][space].second;
                        if(nextspace >=0 && space>nextspace){
                                s[idx]=true;
                                items++;
                        }

                        idx=nextidx;
                        space=nextspace;
                }
                printf("%d %d\n",ans,items);
                for(int i=0; i<n; i++) if(s[i]) printf("%s\n",name[i]);
        }
        return 0;
}