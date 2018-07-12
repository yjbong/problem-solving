#include <cstdio>
#include <cmath>
int p[30];
int ps;
bool c[100001];
int main(void){

    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=2; i<=k; i++){
        int sqrt_i=(int)sqrt(i);
        bool ok=true;
        for(int j=2; j<=sqrt_i; j++){
            if(i%j==0){
                ok=false;
                break;
            }
        }
        if(ok) p[ps++]=i;
    }

    c[1]=true;
    for(int i=0; i<ps; i++){
        for(int j=1; j<=n; j++){
            if(c[j]){
                int t=j*p[i];
                while(t<=n){
                    c[t]=true;
                    t*=p[i];
                }
            }
        }
    }
    int sol=0;
    for(int i=1; i<=n; i++) if(c[i]) sol++;
    printf("%d\n",sol);
    return 0;
}