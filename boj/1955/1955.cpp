#include <cstdio>
#include <cmath>
int d[10001];
int f[11];
int main(void){

    f[0]=f[1]=1;
    for(int i=2; i<=10; i++) f[i]=f[i-1]*i;
    int n;
    scanf("%d",&n);
    d[0]=0; d[1]=1; d[2]=2;

    for(int i=3; i<=n; i++){
        d[i]=i;
        for(int j=1; j<i; j++) if(d[i]>d[j]+d[i-j]) d[i]=d[j]+d[i-j];
        int sqrn=(int)sqrt(n);
        for(int j=2; j<=sqrn; j++) if(i%j==0 && d[i]>d[j]+d[i/j]) d[i]=d[j]+d[i/                                                                                                                                                             j];
        for(int j=1; f[j]<=i; j++) if(d[i]>d[j]+d[i-f[j]]) d[i]=d[j]+d[i-f[j]];
        for(int j=2; f[j]<=i; j++) if(i%f[j]==0 && d[i]>d[j]+d[i/f[j]]) d[i]=d[j                                                                                                                                                             ]+d[i/f[j]];
    }
    printf("%d\n",d[n]);
    return 0;
}