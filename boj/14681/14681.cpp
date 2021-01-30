#include <cstdio>
int main(void){
    int x,y;
    scanf("%d %d",&x,&y);
    int ans;
    if(x>0 && y>0) ans=1;
    else if(x<0 && y>0) ans=2;
    else if(x<0 && y<0) ans=3;
    else ans=4;
    printf("%d\n",ans);
    return 0;
}