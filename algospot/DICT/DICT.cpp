#include <cstdio>
#define MAXK 100000000
int c,n,m,k;
int d[111][111]; // d[i][j] = # of words that contains i's 'a', j's 'b'
int main(void){

    // precalc d[i][j]
    for(int i=0; i<=100; i++) d[i][0]=d[0][i]=1;
    for(int i=1; i<=100; i++){
        for(int j=1; j<=100; j++){
            d[i][j]=d[i-1][j]+d[i][j-1];
            if(d[i][j]>MAXK) d[i][j]=MAXK+1;
        }
    }

    scanf("%d",&c);
    while(c--){
        scanf("%d %d %d",&n,&m,&k);
        if(d[n][m]<k) printf("NONE\n");
        else{
            while(n>0 || m>0){
                if(m==0) { printf("a"); n--; }
                else if(n==0) { printf("b"); m--; }
                else if(d[n-1][m]>=k) { printf("a"); n--; }
                else{ k-=d[n-1][m]; printf("b"); m--; }
            }
            printf("\n");
        }
    }
    return 0;
}