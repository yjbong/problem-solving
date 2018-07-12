#include <stdio.h>
#include <math.h>

char line[10];
long long b[10][10];
long long n,m;
long long maxsqr;

void go(long long curr, long long curc, long long rstep, long long cstep, long long num){

    if(curr<0 || curr>=n) return;
    if(curc<0 || curc>=m) return;
    num*=10;
    num+=b[curr][curc];

    if(sqrt(num)==(long long)(sqrt(num))){
        if(maxsqr<num) maxsqr=num;
    }

    go(curr+rstep, curc+cstep, rstep, cstep, num);
}

int main(void){

    long long i,j,k,l;
    scanf("%lld %lld", &n, &m);

    for(i=0; i<n; i++){
        scanf("%s", line);
        for(j=0; j<m; j++){
            b[i][j]=line[j]-'0';
        }
    }

    maxsqr=-1;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            for(k=-8; k<=8; k++){
                for(l=-8; l<=8; l++){
                    if(k!=0 || l!=0) go(i,j,k,l,0);
                }
            }
        }
    }
    printf("%lld\n",maxsqr);
    return 0;
}