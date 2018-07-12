#include <stdio.h>
#define MAXSIZE 100
#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3
char board[MAXSIZE+2][MAXSIZE+2];
int main(void){
        int i,j,m,n;
        int cur_r, cur_c, cur_dir, sol;
        scanf("%d %d", &m, &n);
        for(i=0; i<=m+1; i++) board[i][0]=1, board[i][n+1]=1;
        for(j=0; j<=n+1; j++) board[0][j]=1, board[m+1][j]=1;
        for(i=1; i<=m; i++)
                for(j=1; j<=n; j++)
                        board[i][j]=0;

        cur_r=cur_c=1, cur_dir=RIGHT, sol=0;
        for(i=1; i<=m*n; i++){
                if(i>1){
                        if(cur_dir==RIGHT) cur_c++;
                        else if(cur_dir==DOWN) cur_r++;
                        else if(cur_dir==LEFT) cur_c--;
                        else if(cur_dir==UP) cur_r--;
                }

                board[cur_r][cur_c]=1;
                if(i<m*n){
                        if(cur_dir==RIGHT && board[cur_r][cur_c+1]==1){
                                cur_dir=DOWN;
                                sol++;
                        }
                        else if(cur_dir==DOWN && board[cur_r+1][cur_c]==1){
                                cur_dir=LEFT;
                                sol++;
                        }
                        else if(cur_dir==LEFT && board[cur_r][cur_c-1]==1){
                                cur_dir=UP;
                                sol++;
                        }
                        else if(cur_dir==UP && board[cur_r-1][cur_c]==1){
                                cur_dir=RIGHT;
                                sol++;
                        }
                }
        }
        printf("%d\n", sol);
        return 0;
}