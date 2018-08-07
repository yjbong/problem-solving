#include <cstdio>
#define MOD 1000000007
int c,n;
int d[111];
int a[111];
int main(void){

    d[0]=1; d[1]=1; d[2]=2;
    for(int i=3; i<=100; i++) d[i]=(d[i-1]+d[i-2])%MOD;

    a[0]=0; a[1]=0; a[2]=0;
    for(int i=3; i<=100; i++){
        if(i%2==0){
            a[i]=d[i]-d[i/2];
            if(a[i]<0) a[i]+=MOD;
            a[i]-=d[i/2-1];
            if(a[i]<0) a[i]+=MOD;
        }
        else{
            a[i]=d[i]-d[i/2];
            if(a[i]<0) a[i]+=MOD;
        }
    }

    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
    return 0;
}