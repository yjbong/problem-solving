#include <cstdio>
int main(void){
    int d,ans=0;
    scanf("%d",&d);
    for(int i=0; i<5; i++){
        int n;
        scanf("%d",&n);
        if(n==d) ans++;
    }
    printf("%d\n",ans);
    return 0;
}