#include <cstdio>
int f[100];
int main(void){

    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    for(int i=1; i<=a; i++)
        for(int j=1; j<=b; j++)
            for(int k=1; k<=c; k++) f[i+j+k]++;

    int sol=0;
    for(int i=0; i<=a+b+c; i++) if(f[sol]<f[i]) sol=i;
    printf("%d\n",sol);
    return 0;
}