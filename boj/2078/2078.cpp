#include<cstdio>
int main(void){
    int a,b,l=0,r=0;
    scanf("%d %d",&a,&b);
    while(a>1||b>1){
        if(b==1){
            l+=a-1;
            break;
        }
        else if(a==1){
            r+=b-1;
            break;
        }
        else if(a>b) l+=a/b, a%=b;
        else r+=b/a, b%=a;
    }
    printf("%d %d\n",l,r);
    return 0;
}