#include <cstdio>
const int dy[4]={-1,0,1,0};
const int dx[4]={0,-1,0,1};
bool m[101][101];
char s[51];
int main(void){

    int n;
    int cy,cx,cdir;
    int miny,minx,maxy,maxx;

    scanf("%d",&n);
    scanf("%s",s);

    cy=cx=50; cdir=0;
    miny=minx=maxy=maxx=50;
    m[cy][cx]=true;

    for(int i=0; i<n; i++){
        if(s[i]=='F'){
            cy+=dy[cdir]; cx+=dx[cdir];
            m[cy][cx]=true;
            if(miny>cy) miny=cy;
            if(maxy<cy) maxy=cy;
            if(minx>cx) minx=cx;
            if(maxx<cx) maxx=cx;
        }
        else if(s[i]=='R'){
            cdir++;
            if(cdir>=4) cdir-=4;
        }
        else if(s[i]=='L'){
            cdir--;
            if(cdir<0) cdir+=4;
        }
    }

    for(int i=maxy; i>=miny; i--){
        for(int j=minx; j<=maxx; j++){
            if(m[i][j]) printf(".");
            else printf("#");
        }
        printf("\n");
    }
    return 0;
}