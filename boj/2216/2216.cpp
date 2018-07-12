#include <cstdio>
#include <cstring>
#define MINF -9223372036854775807ll
char x[3333];
char y[3333];
long long d[3001][3001];

int main(void){

    long long a,b,c;
    int xl,yl;
    scanf("%lld %lld %lld",&a,&b,&c);

    scanf("%s",x);
    xl=strlen(x);
    scanf("%s",y);
    yl=strlen(y);

    for(int i=0; i<=xl; i++)
        for(int j=0; j<=yl; j++) d[i][j]=MINF;

    for(int i=0; i<=xl; i++) d[i][0]=b*i;
    for(int i=0; i<=yl; i++) d[0][i]=b*i;

    for(int i=1; i<=xl; i++){
        for(int j=1; j<=yl; j++){

            long long t;

                t=d[i-1][j-1];
                if(t>MINF){
                    if(x[i-1]==y[j-1]) t+=a;
                    else t+=c;
                    if(d[i][j]<t) d[i][j]=t;
                }

                t=d[i-1][j];
                if(t>MINF){
                    t+=b;
                    if(d[i][j]<t) d[i][j]=t;
                }

                t=d[i][j-1];
                if(t>MINF){
                    t+=b;
                    if(d[i][j]<t) d[i][j]=t;
                }
        }

    }
    long long sol=d[xl][yl];
    printf("%lld\n",sol);
    return 0;
}