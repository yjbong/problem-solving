#include <stdio.h>
int f[100001];
int main(void){

    int i,n,cur,ok,sol;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&cur);
        f[cur]++;
    }

    ok=0;
    for(i=100000; i>=0; i--){
        if(f[i]==i){
            sol=i;
            ok=1;
            break;
        }
    }
    if(ok) printf("%d\n",sol);
    else printf("-1\n");
    return 0;
}