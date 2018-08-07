#include <cstdio>
#include <cstring>
int c,n;
char board[7][7];
char word[11]; int wordlen;
int cache[11][7][7];

const int dy[8]={-1,-1,-1, 0, 0, 1, 1, 1};
const int dx[8]={-1, 0, 1,-1, 1,-1, 0, 1};
int go(int wordidx, int y, int x){
        if(wordidx==wordlen) return 1;
        else if(cache[wordidx][y][x]>=0) return cache[wordidx][y][x];

        int ret=0;
        if(board[y][x]!=word[wordidx]) return (cache[wordidx][y][x]=ret);
        for(int i=0; i<8; i++){
                if(board[y][x]==word[wordidx]){
                        if(go(wordidx+1, y+dy[i], x+dx[i])==1){
                                ret=1;
                                break;
                        }
                }
        }
        return (cache[wordidx][y][x]=ret);
}

int main(void){

        scanf("%d",&c);
        while(c--){

                for(int i=1; i<=5; i++) scanf("%s",board[i]+1);
                for(int i=0; i<7; i++) board[i][0]=board[i][6]=0;
                for(int i=0; i<7; i++) board[0][i]=board[6][i]=0;

                scanf("%d",&n);
                while(n--){
                        scanf("%s",word);
                        wordlen=strlen(word);
                        for(int i=0; i<=wordlen; i++)
                                for(int j=0; j<7; j++)
                                        for(int k=0; k<7; k++)
                                                cache[i][j][k]=-1;

                        bool ok=false;
                        for(int i=1; i<=5; i++){
                                for(int j=1; j<=5; j++){
                                        if(go(0,i,j)==1){
                                                ok=true;
                                                break;
                                        }
                                }
                        }
                        printf("%s ",word);
                        if(ok) printf("YES\n");
                        else printf("NO\n");
                }

        }
        return 0;
}