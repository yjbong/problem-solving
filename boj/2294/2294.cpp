#include <stdio.h>
#define INF 2147483647
#define SWAP(a,b,t){t=a;a=b;b=t;}
int c[100];
int d[10001];
int main(void){

    int i,j,t,n,k,cur;
    scanf("%d %d",&n,&k);
    for(i=0; i<n; i++) scanf("%d",&c[i]);
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
            if(c[i]>c[j]) SWAP(c[i],c[j],t);

    for(i=0; i<=k; i++) d[i]=INF;
    for(i=0; i<n; i++){
        if(c[i]<=k) d[c[i]]=1;
        else break;
    }

    for(i=0; i<=k; i++){
        if(d[i]!=INF){
            for(j=0; j<n; j++){
                cur=i+c[j];
                if(cur>k) break;
                else if(d[cur]>d[i]+1) d[cur]=d[i]+1;
            }
        }
    }

    if(d[k]==INF) printf("-1\n");
    else printf("%d\n",d[k]);
    return 0;
}