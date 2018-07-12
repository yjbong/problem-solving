#include <cstdio>
int f[1000];
int main(void){
    int n,m,l;
    scanf("%d %d %d",&n,&m,&l);
    int go=1; int cur=0; int cnt=0;
    while(1){
        f[cur]++;
        if(f[cur]==m) break;
        f[cur]%2 ? cur+=l : cur-=l;
        if(cur>=n) cur-=n;
        else if(cur<0) cur+=n;
        cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}