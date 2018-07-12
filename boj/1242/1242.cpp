#include<cstdio>
int n,m,k,c,s;
int main(void){
    scanf("%d %d %d",&n,&m,&k);
    k--; c=0;
    s=1;
    while(1){
        int d=(c+m-1)%n;
        if(d==k) break;
        else if(d<k) k--;
        n--; c=d%n; s++;
    }
    printf("%d\n",s);
    return 0;
}