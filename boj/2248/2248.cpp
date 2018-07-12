#include <stdio.h>

long long c[32][32];
long long pw[32];

long long pos[32];
long long b[32];

int main(void){

    long long i,j;
    long long N,L,I;
    long long floor_pw;

    for(i=0; i<32; i++){
        c[i][0]=1;
        c[i][1]=i;
    }

    for(i=2; i<32; i++){
        for(j=2; j<=i; j++){
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }

    pw[0]=1;
    for(i=1; i<32; i++) pw[i]=pw[i-1]*2;
    for(i=0; i<32; i++) b[i]=0;

    scanf("%lld %lld %lld", &N, &L, &I);

    I--;

    while(I>0){

        pos[0]=1;
        i=1;
        while(1){
            pos[i]=pos[i-1]+pw[i-1];
            j=i-1;

            while(j>=L){
                pos[i]-=c[i-1][j];
                j--;
            }

            if(pos[i]>I) break;
            i++;
        }

        floor_pw=i-1;
        b[floor_pw]=1;

        I-=pos[floor_pw];
        L--;
    }

    for(i=N-1; i>=0; i--)
        printf("%lld", b[i]);
    printf("\n");

    return 0;
}