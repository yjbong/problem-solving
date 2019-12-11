#include <cstdio>
int T, D[10], Ds;
int main() {
    scanf("%d",&T);
    Ds=0;
    while(T>0){ D[Ds++]=T%9; T/=9; }
    for(int i=Ds-1; i>=0; i--) printf("%d",D[i]);
    return 0;
}