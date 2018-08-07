#include <cstdio>
#define BLACK 0
#define WHITE 1
int h,w;
int whites;
int board[20+2][20+2];
char line[20+2];

int ans;

const int block_y[4][3] = {{0,1,1},{0,0,1},{0,0,1},{0,1,1}};
const int block_x[4][3] = {{0,0,1},{0,1,0},{0,1,1},{0,0,-1}};


void print_board(void){

        for(int i=1; i<=h; i++){
                for(int j=1; j<=w; j++){
                        printf("%d",board[i][j]);
                }
                printf("\n");
        }
        printf("\n");
}
void dfs(int whites, int y, int x){

//      printf("whites = %d, y = %d, x = %d\n", whites, y, x);
//      print_board();
        if(whites==0){
                ans++;
                return;
        }

        else if(board[y][x]==BLACK){
                if(x+1<=w) dfs(whites, y, x+1);
                else if(y+1<=h) dfs(whites, y+1, 1);
                else return;
        }

        for(int i=0; i<4; i++){
                bool ok=true;
                for(int j=0; j<3; j++){
                        if(board[y+block_y[i][j]][x+block_x[i][j]]==BLACK){
                                ok=false;
                                break;
                        }
                }
                if(ok){
                        for(int j=0; j<3; j++){
                                board[y+block_y[i][j]][x+block_x[i][j]]=BLACK;
                        }
                        if(x+1<=w) dfs(whites-3, y, x+1);
                        else if(y+1<=h) dfs(whites-3, y+1, 1);
                        for(int j=0; j<3; j++){
                                board[y+block_y[i][j]][x+block_x[i][j]]=WHITE;
                        }
                }
        }
}
int main(void){

        int cases;
        scanf("%d",&cases);
        while(cases--){
                scanf("%d %d",&h,&w);
                whites=0;
                for(int i=0; i<=h+1; i++)
                        for(int j=0; j<=w+1; j++) board[i][j]=BLACK;

                for(int i=1; i<=h; i++){
                        scanf("%s",line);
                        for(int j=1; j<=w; j++){
                                if(line[j-1]=='#') board[i][j]=BLACK;
                                else{
                                        board[i][j]=WHITE;
                                        whites++;
                                }
                        }
                }

                ans=0;
                if(whites%3==0) dfs(whites,1,1);
                printf("%d\n", ans);
        }
        return 0;
}