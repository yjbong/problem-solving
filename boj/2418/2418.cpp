#include <cstdio>
#include <cstring>

typedef long long ll;

char b[222][222];
char line[222];
char wd[111];
ll d[222][222][111];

const int dy[8]={-1,-1,-1,0,0,1,1,1};
const int dx[8]={-1,0,1,-1,1,-1,0,1};
int main(void){

    int h,w,l;
    scanf("%d %d %d\n",&h,&w,&l);
    for(int i=1; i<=h; i++){
        scanf("%s",line);
        for(int j=1; j<=w; j++){
            b[i][j]=line[j-1];
        }
    }

    scanf("%s",wd);

    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if(b[i][j]==wd[l-1]){
                d[i][j][l-1]=1;
            }
        }
    }

    for(int i=l-2; i>=0; i--){
        for(int j=1; j<=h; j++){
            for(int k=1; k<=w; k++){
                if(b[j][k]==wd[i]){
                    for(int m=0; m<8; m++){
                        d[j][k][i]+=d[j+dy[m]][k+dx[m]][i+1];
                    }
                }
            }
        }
    }

    ll sol=0;
    for(int i=1; i<=h; i++)
        for(int j=1; j<=w; j++)
            sol+=d[i][j][0];

    printf("%lld\n",sol);
    return 0;
}