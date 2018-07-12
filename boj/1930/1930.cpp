#include <cstdio>
int main(void){
    int k;
    scanf("%d",&k);
    while(k--){
        int a1,a2,a3,a4,b1,b2,b3,b4,ok=1;
        scanf("%d%d%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&b1,&b2,&b3,&b4);
        if(a1==b1 && a2==b2 && a3==b3 && a4==b4);
        else if(a1==b1 && a2==b4 && a3==b2 && a4==b3);
        else if(a1==b1 && a2==b3 && a3==b4 && a4==b2);
        else if(a1==b2 && a2==b1 && a3==b4 && a4==b3);
        else if(a1==b2 && a2==b3 && a3==b1 && a4==b4);
        else if(a1==b2 && a2==b4 && a3==b3 && a4==b1);
        else if(a1==b3 && a2==b1 && a3==b2 && a4==b4);
        else if(a1==b3 && a2==b4 && a3==b1 && a4==b2);
        else if(a1==b3 && a2==b2 && a3==b4 && a4==b1);
        else if(a1==b4 && a2==b1 && a3==b3 && a4==b2);
        else if(a1==b4 && a2==b2 && a3==b1 && a4==b3);
        else if(a1==b4 && a2==b3 && a3==b2 && a4==b1);
        else ok=0;
        printf("%d\n",ok);
    }
    return 0;
}