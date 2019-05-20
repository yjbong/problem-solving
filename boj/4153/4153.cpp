#include <cstdio>
#include <algorithm>
 
int main(void){
 
    while(1){
        int a[3];
        scanf("%d %d %d",&a[0],&a[1],&a[2]);
        if(a[0]==0 && a[1]==0 && a[2]==0) break;
        std::sort(a,a+3);
        if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2]) printf("right\n");
        else printf("wrong\n");
    }
 
    return 0;
}