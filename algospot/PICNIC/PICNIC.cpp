#include <cstdio>

int n,m;
bool selected[10];
bool isFriend[10][10];
int ans;

void dfs(int pairs, int search_start){

        if(pairs == n/2){
                ans++;
                return;
        }
        for(int i=search_start; i<n; i++){
                for(int j=i+1; j<n; j++){
                        if(selected[i]==false && selected[j]==false && isFriend[i][j]==true){
                                selected[i]=selected[j]=true;
                                dfs(pairs+1, i+1);
                                selected[i]=selected[j]=false;
                        }
                }
        }
}

int main(void){
        int cases;
        scanf("%d",&cases);
        while(cases--){
                scanf("%d %d",&n,&m);
                for(int i=0; i<n; i++) selected[i]=false;
                for(int i=0; i<n; i++)
                        for(int j=0; j<n; j++) isFriend[i][j]=false;

                for(int i=0; i<m; i++){
                        int a,b;
                        scanf("%d %d",&a,&b);
                        isFriend[a][b]=isFriend[b][a]=true;
                }

                ans=0;
                dfs(0,0);
                printf("%d\n",ans);
        }
        return 0;
}