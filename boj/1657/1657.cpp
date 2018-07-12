#include <cstdio>
#define UNDEF -1
#define MINF -1000000000

int n,m;
char b[15][15];

const int g[6][6]={{10,8,7,5,0,1},{8,6,4,3,0,1},{7,4,3,2,0,1},{5,3,2,2,0,1},{0,0,0,0,0,0},{1,1,1,1,0,0}};

int d[14*14][1<<14];

int test(int stat, int x){
        return stat & (1<<x);
}
int set(int stat, int x){
        return stat | (1<<x);
}
int reset(int stat, int x){
        return stat & (~(1<<x));
}
int score(int x, int y){
        if(x/m<n && y/m<n) return g[b[x/m][x%m]-'A'][b[y/m][y%m]-'A'];
        else return 0;
}
int max(int x, int y){
        if(x>y) return x;
        else return y;
}

int go(int idx, int stat){

        int cy=idx/m;
        int cx=idx%m;

        if(d[idx][stat]!=UNDEF) return d[idx][stat];

        if(cy==n-1){
                bool ok=true;
                for(int i=0; i<cx; i++){
                        if(test(stat,i)){
                                ok=false;
                                break;
                        }
                }
                if(!ok) return (d[idx][stat] = MINF);
        }
        if(cy==n-1 && cx==m-1) return (d[idx][stat] = 0);

        if(test(stat,cx)) return (d[idx][stat] = go(idx+1, reset(stat,cx)));
        else if((cx<m-1) && (test(stat,cx+1)==0)){
                return (d[idx][stat] = max( max(go(idx+1, set(stat,cx+1)) + score(idx,idx+1), go(idx+1, set(stat,cx)) + score(idx,idx+m)), go(idx+1, stat)));
        }
        else{
                return (d[idx][stat] = max( go(idx+1, set(stat,cx)) + score(idx,idx+m), go(idx+1, stat)));
        }
}

int main(void){

        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++) scanf("%s",b[i]);
        for(int i=0; i<n*m; i++)
                for(int j=0; j<(1<<m); j++) d[i][j]=UNDEF;

        go(0,0);
        printf("%d\n",d[0][0]);
        return 0;
}