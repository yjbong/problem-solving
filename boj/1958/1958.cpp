#include <cstdio>
#include <cstring>
char x[111],y[111],z[111];
int d[111][111][111];
int max2(int a, int b){
    if(a>b) return a;
    else return b;
}

int main(void){

    int xl,yl,zl;
    scanf("%s",x+1);
    scanf("%s",y+1);
    scanf("%s",z+1);

    xl=strlen(x+1);
    yl=strlen(y+1);
    zl=strlen(z+1);

    for(int i=1; i<=xl; i++){
        for(int j=1; j<=yl; j++){
            for(int k=1; k<=zl; k++){
                if(x[i]==y[j] && y[j]==z[k]) d[i][j][k]=d[i-1][j-1][k-1]+1;
                else d[i][j][k]=max2(max2(d[i-1][j][k], d[i][j-1][k]),d[i][j][k-1]);
            }
        }
    }
    printf("%d\n",d[xl][yl][zl]);
    return 0;
}