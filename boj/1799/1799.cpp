#include <cstdio>
int a[55][55];
int c[55];
int ma[55];
int ch;
int m,n,k;
int b[11][11];

bool matched(int u){

    if(c[u]==ch) return false;
    c[u]=ch;
    for(int i=0; i<(n*2-1)*2; i++){
        if(a[u][i]==1){
            if((ma[i]==-1) || ((ma[i]!=u) && matched(ma[i]))){
                ma[i]=u;
                return true;
            }
        }
    }
    return false;
}

int main(void){

    scanf("%d",&n);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) scanf("%d",&b[i][j]);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int diag0=i+j; int diag1=i+n-1-j;
            if(b[i][j]) a[diag0][diag1+n*2-1]=1;
        }
    }

    int ans=0;
    for(int i=0; i<(n*2-1)*2; i++){
        c[i]=-1;
        ma[i]=-1;
    }
    for(ch=0; ch<n*2-1; ch++){
        int st_node=ch;
        if(matched(st_node)) ans++;
    }
    printf("%d\n",ans);
    return 0;
}