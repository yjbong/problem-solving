#include <cstdio>
int a[666][666];
int c[666];
int ma[666];
int ch;
int m,n,k;

bool matched(int u){

    if(c[u]==ch) return false;
    c[u]=ch;
    for(int i=0; i<m+n; i++){
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

    scanf("%d %d %d",&m,&n,&k);
    for(int i=0; i<m; i++)
        for(int j=m; j<m+n; j++) a[i][j]=1;

    for(int i=0; i<k; i++){
        int y,x;
        scanf("%d %d",&y,&x);
        a[y-1][m+x-1]=0;
    }

    int ans=0;
    for(int i=0; i<m+n; i++){
        c[i]=-1;
        ma[i]=-1;
    }
    for(ch=0; ch<m; ch++){
        int st_node=ch;
        if(matched(st_node)) ans++;
    }
    printf("%d\n",ans);
    return 0;
}