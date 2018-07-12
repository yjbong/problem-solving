#include <cstdio>
#define MOD 1000000000ll
long long mat[64][2][2];

int main(void){

    mat[0][0][0]=0,mat[0][0][1]=1;
    mat[0][1][0]=1,mat[0][1][1]=1;
    for(int i=1; i<64; i++){
        mat[i][0][0]=((mat[i-1][0][0]*mat[i-1][0][0])%MOD+(mat[i-1][0][1]*mat[i-1][1][0])%MOD)%MOD;
        mat[i][0][1]=((mat[i-1][0][0]*mat[i-1][0][1])%MOD+(mat[i-1][0][1]*mat[i-1][1][1])%MOD)%MOD;
        mat[i][1][0]=((mat[i-1][1][0]*mat[i-1][0][0])%MOD+(mat[i-1][1][1]*mat[i-1][1][0])%MOD)%MOD;
        mat[i][1][1]=((mat[i-1][1][0]*mat[i-1][0][1])%MOD+(mat[i-1][1][1]*mat[i-1][1][1])%MOD)%MOD;
    }

    long long a,b;
    scanf("%lld %lld",&a,&b);

    a--; // find sum of f(1),f(2), ... ,f(a-1) and subtract it from sum of f(1),f(2), ... ,f(b).
    long long lsum,rsum;
    long long cmat[2][2];
    long long t[2][2];

    long long cl=a+2; // find (a+2)th fib num
    cmat[0][0]=1, cmat[0][1]=0;
    cmat[1][0]=0, cmat[1][1]=1;
    for(int i=0; i<64 && cl>0; i++,cl/=2){
        if(cl%2==1){
            t[0][0]=((cmat[0][0]*mat[i][0][0])%MOD+(cmat[0][1]*mat[i][1][0])%MOD)%MOD;
            t[0][1]=((cmat[0][0]*mat[i][0][1])%MOD+(cmat[0][1]*mat[i][1][1])%MOD)%MOD;
            t[1][0]=((cmat[1][0]*mat[i][0][0])%MOD+(cmat[1][1]*mat[i][1][0])%MOD)%MOD;
            t[1][1]=((cmat[1][0]*mat[i][0][1])%MOD+(cmat[1][1]*mat[i][1][1])%MOD)%MOD;

            cmat[0][0]=t[0][0],cmat[0][1]=t[0][1];
            cmat[1][0]=t[1][0],cmat[1][1]=t[1][1];
        }
    }
    lsum=cmat[0][1]-1;
    if(lsum<0) lsum+=MOD;

    long long cr=b+2; // find (b+2)th fib num
    cmat[0][0]=1, cmat[0][1]=0;
    cmat[1][0]=0, cmat[1][1]=1;
    for(int i=0; i<64 && cr>0; i++,cr/=2){
        if(cr%2==1){
            t[0][0]=((cmat[0][0]*mat[i][0][0])%MOD+(cmat[0][1]*mat[i][1][0])%MOD)%MOD;
            t[0][1]=((cmat[0][0]*mat[i][0][1])%MOD+(cmat[0][1]*mat[i][1][1])%MOD)%MOD;
            t[1][0]=((cmat[1][0]*mat[i][0][0])%MOD+(cmat[1][1]*mat[i][1][0])%MOD)%MOD;
            t[1][1]=((cmat[1][0]*mat[i][0][1])%MOD+(cmat[1][1]*mat[i][1][1])%MOD)%MOD;

            cmat[0][0]=t[0][0],cmat[0][1]=t[0][1];
            cmat[1][0]=t[1][0],cmat[1][1]=t[1][1];
        }
    }
    rsum=cmat[0][1]-1;
    if(rsum<0) rsum+=MOD;

    long long sol=rsum-lsum;
    if(sol<0) sol+=MOD;
    else if(sol>=MOD) sol%=MOD;
    printf("%lld\n",sol);
    return 0;
}