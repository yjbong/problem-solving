#include <cstdio>
#include <cstring>
#define INF 100000000
char o[1111];
char n[1111];
int d[1111][1111];
int min2(int a, int b){
        return a<b?a:b;
}
int main(void){

        gets(o+1);
        gets(n+1);
        int olen=strlen(o+1);
        int nlen=strlen(n+1);

        for(int i=0; i<=olen; i++)
                for(int j=0; j<=nlen; j++) d[i][j]=INF;

        for(int i=0; i<=olen; i++){
                for(int j=i; j<=nlen; j++){
                        if(i==0 && j==0) d[i][j]=0;
                        else{
                                if(i>0 && j>0 && o[i]==n[j]) d[i][j] = min2(d[i][j], d[i-1][j-1]);
                                for(int k=i; k<j; k++) d[i][j] = min2(d[i][j], d[i][k]+1);
                        }
                }
        }
        if(d[olen][nlen]<INF) printf("%d\n",d[olen][nlen]);
        else printf("-1\n");
        return 0;
}