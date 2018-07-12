#include <cstdio>

int n,m;
int a[222][222];
int p[222];
int t[1111];

int find2(int a){

    while(p[a]>0) a=p[a];
    return a;
}

bool union2(int a, int b){

    int pa=find2(a);
    int pb=find2(b);

    if(pa==pb) return false;
    else{
        if(pa<pb) p[pb]=pa;
        else if(pa>pb) p[pa]=pb;
        else{
            p[pb]=pa;
            p[pa]--;
        }
        return true;
    }
}

int main(void){

    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d",&a[i][j]);

    for(int i=1; i<=n; i++) p[i]=-1;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(a[i][j]) union2(i,j);

    for(int i=0; i<m; i++) scanf("%d",&t[i]);
    bool ok=true;
    for(int i=0; i<m-1; i++){
        if(find2(t[i]) != find2(t[i+1])){
            ok=false;
            break;
        }
    }
    if(ok) printf("YES\n");
    else printf("NO\n");
    return 0;
}