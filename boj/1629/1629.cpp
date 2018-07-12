#include <cstdio>
long long pw[32];
int main(void){

    long long a,b,c;
    scanf("%lld %lld %lld",&a,&b,&c);
    pw[1]=a%c;
    for(int i=2; i<32; i++) pw[i]=(pw[i-1]*pw[i-1])%c;

    int i=1;
    long long sol=1;
    while(b>0){
        if(b%2) sol=(sol*pw[i])%c;
        i++;
        b/=2;
    }
    printf("%lld\n",sol);
    return 0;
}