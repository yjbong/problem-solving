#include <cstdio>
#include <cstring>

typedef long long ll;

char b[111][111];
char line[111];
char wd[111];
ll d[111][111][111];

const int dy[4]={-1,1,0,0};
const int dx[4]={0,0,1,-1};
int main(void){

    int h,w,mv;
    scanf("%d %d %d\n",&h,&w,&mv);
    for(int i=1; i<=h; i++){
        scanf("%s",line);
        for(int j=1; j<=w; j++){
            b[i][j]=line[j-1];
        }
    }

    scanf("%s",wd);
    int l=strlen(wd);

    for(int i=1; i<=h; i++)
        for(int j=1; j<=w; j++)
            if(b[i][j]==wd[l-1])
                d[i][j][l-1]=1;

    for(int i=l-2; i>=0; i--)
        for(int j=1; j<=h; j++)
            for(int k=1; k<=w; k++)
                if(b[j][k]==wd[i])
                    for(int m=0; m<4; m++)
                        for(int n=1; n<=mv; n++)
                            if(j+dy[m]*n>=1 && j+dy[m]*n<=h && k+dx[m]*n>=1 && k+dx[m]*n<=w)
                                d[j][k][i]+=d[j+dy[m]*n][k+dx[m]*n][i+1];

    ll sol=0;
    for(int i=1; i<=h; i++)
        for(int j=1; j<=w; j++)
            sol+=d[i][j][0];

    printf("%lld\n",sol);
    return 0;
}