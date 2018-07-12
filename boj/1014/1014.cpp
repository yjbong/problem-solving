#include <cstdio>
#define UNDEF -1
int n,m;
char b[11][11];
int d[11*11][1<<11];

int LSB_push(int bitstring, int bitlen, int pushbit){
        return ((bitstring<<1)&((1<<bitlen)-1)) | pushbit;
}
bool test(int bitstring, int bitidx){
        return bitstring & (1<<bitidx);
}

int max(int x, int y){
        return (x>y)?x:y;
}

int go(int idx, int stat){

        int cy=idx/m;
        int cx=idx%m;

        if(d[idx][stat]!=UNDEF) return d[idx][stat];
        if(idx==n*m){
                d[idx][stat] = 0;
                return d[idx][stat];
        }

        if(b[cy][cx]=='x'){
                d[idx][stat] = go(idx+1,LSB_push(stat,m+1,0));
                return d[idx][stat];
        }
        else{
                bool ok=true;
                if(cx==0 && cx==m-1);
                else if(cx==0 && cx!=m-1){
                        if(test(stat,m-2)) ok=false;
                }
                else if(cx!=0 && cx==m-1){
                        if(test(stat,m) || test(stat,0)) ok=false;
                }
                else{
                        if(test(stat,m) || test(stat,m-2) || test(stat,0)) ok=false;
                }

                if(ok) d[idx][stat] = max(go(idx+1,LSB_push(stat,m+1,1)) + 1, go(idx+1,LSB_push(stat,m+1,0)));
                else d[idx][stat] = go(idx+1,LSB_push(stat,m+1,0));
                return d[idx][stat];
        }
}

int main(void){

        int c;
        scanf("%d",&c);
        while(c--){
                scanf("%d %d",&n,&m);
                for(int i=0; i<n; i++) scanf("%s",b[i]);
                for(int i=0; i<=n*m; i++)
                        for(int j=0; j<(1<<(m+1)); j++) d[i][j]=UNDEF;
                go(0,0);
                printf("%d\n",d[0][0]);
        }
        return 0;
}