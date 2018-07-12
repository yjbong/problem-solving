#include <cstdio>
int n;
int d[20][20];
bool s[20][20];
int main(void){

    scanf("%d",&n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&d[i][j]);
            s[i][j]=true;
        }
    }

    bool ok=true;
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=k && j!=k){
                    if(d[i][j]>d[i][k]+d[k][j]){
                        ok=false;
                        goto out;
                    }
                    else if(d[i][j]==d[i][k]+d[k][j]) s[i][j]=false;
                }
            }
        }
    }

out:
    if(ok){
        int sol=0;
        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
                if(s[i][j]) sol+=d[i][j];
        printf("%d\n",sol);
    }
    else printf("-1\n");
    return 0;
}