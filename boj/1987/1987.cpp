#include <cstdio>
int st;
int sol;
int b[22][22];
char l[22];
const int dy[4]={-1,1,0,0};
const int dx[4]={0,0,1,-1};

void go(int y, int x, int l){

    if(b[y][x]&st) return;

    if(sol<l) sol=l;
    st+=b[y][x];
    for(int i=0; i<4; i++)
        go(y+dy[i],x+dx[i],l+1);

    st-=b[y][x];
}

int main(void){

    int r,c;
    scanf("%d %d",&r,&c);
    for(int i=0; i<=r+1; i++)
        for(int j=0; j<=c+1; j++) b[i][j]=(1<<26)-1;
    for(int i=1; i<=r; i++){
        scanf("%s",l);
        for(int j=1; j<=c; j++){
             b[i][j]=1<<(l[j-1]-'A');
        }
    }
    sol=st=0;
    go(1,1,1);
    printf("%d\n",sol);
    return 0;
}