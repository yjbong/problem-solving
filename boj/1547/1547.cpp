#include <cstdio>
#define SWAP(a,b,t){t=a;a=b;b=t;}
int a[4];
int main(void){

    a[1]=1;
    int n;
    scanf("%d",&n);
    while(n--){
        int x,y,t;
        scanf("%d %d",&x,&y);
        SWAP(a[x],a[y],t);
    }
    for(int i=1; i<=3; i++){
        if(a[i]){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}