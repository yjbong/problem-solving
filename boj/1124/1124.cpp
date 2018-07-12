#include <cstdio>
#include <cmath>
int p[1000];
int d[111111];
int ps;
bool is_p(int n){
    if(n<2) return false;
    int sqrt_n=(int)sqrt(n);
    for(int i=2; i<=sqrt_n; i++) if(n%i==0) return false;
    return true;
}

int main(void){

    int a,b;
    scanf("%d %d",&a,&b);

    ps=0;
    for(int i=0; i<=(int)sqrt(b); i++) if(is_p(i)) p[ps++]=i;

    for(int i=a; i<=b; i++){
        int t=i;
        for(int j=0; j<ps; j++){
            while(t%p[j]==0){
                d[i]++;
                t/=p[j];
            }
        }
        if(t>1) d[i]++;
    }

    int sol=0;
    for(int i=a; i<=b; i++) if(is_p(d[i])) sol++;
    printf("%d\n",sol);
    return 0;
}