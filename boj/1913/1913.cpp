#include <stdio.h>
#define MAXSIZE 999
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
int board[MAXSIZE+1][MAXSIZE+1];
int main(void){

        int i,j,n,target;
        int cur_r, cur_c, cur_dir;
        int target_r, target_c;

        scanf("%d %d", &n, &target);

        for(i=1; i<=n; i++)
                for(j=1; j<=n; j++)
                        board[i][j]=0;

        cur_r=cur_c=n/2+1;
        cur_dir=LEFT;
        for(i=1; i<=n*n; i++){

                if(i>1){
                        if(cur_dir==UP) cur_r--;
                        else if(cur_dir==RIGHT) cur_c++;
                        else if(cur_dir==DOWN) cur_r++;
                        else if(cur_dir==LEFT) cur_c--;
                }

                if(board[cur_r][cur_c]==0){
                        board[cur_r][cur_c]=i;
                        if(i==target){
                                target_r=cur_r;
                                target_c=cur_c;
                        }
                }

                if((cur_dir+1)%4==UP && (board[cur_r-1][cur_c]==0)) cur_dir=UP;
                else if((cur_dir+1)%4==RIGHT && (board[cur_r][cur_c+1]==0)) cur_dir=RIGHT;
                else if((cur_dir+1)%4==DOWN && (board[cur_r+1][cur_c]==0)) cur_dir=DOWN;
                else if((cur_dir+1)%4==LEFT && (board[cur_r][cur_c-1]==0)) cur_dir=LEFT;
        }

        for(i=1; i<=n; i++){
                for(j=1; j<=n; j++){
                        printf("%d", board[i][j]);
                        if(j<n) printf(" ");
                }
                printf("\n");
        }

        printf("%d %d\n", target_r, target_c);
        return 0;
}