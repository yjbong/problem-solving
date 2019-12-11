#include <cstdio>
int main(void){
    int H,M;
    scanf("%d %d",&H,&M);
    int time=H*60+M-45;
    if(time<0) time+=24*60;
    printf("%d %d\n",time/60,time%60);
    return 0;
}