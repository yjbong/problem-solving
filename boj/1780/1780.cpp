#include <stdio.h>
int board[2187][2187];
int result[3]; /* -1, 0, 1 papers */

void calc(int x, int y, int size){

        int i, j, is_all_same, upleft;

        is_all_same=1;
        upleft=board[x][y];

        for(i=x; i<x+size; i++){
                for(j=y; j<y+size; j++){
                        if(board[i][j]!=upleft){
                                is_all_same=0;
                                break;
                        }
                }
        }

        if(is_all_same==1){
                result[upleft+1]++;
        }

        else{
                for(i=0; i<3; i++){
                        for(j=0; j<3; j++){
                                calc(x+(size/3)*i, y+(size/3)*j, size/3);
                        }
                }
        }
}



int main(void){

        int i, j;
        int N;

        for(i=0; i<3; i++) result[i]=0;

        scanf("%d", &N);
        for(i=0; i<N; i++)
                for(j=0; j<N; j++)
                        scanf("%d", &board[i][j]);

        calc(0, 0, N);

        for(i=0; i<3; i++)
                printf("%d\n", result[i]);

        return 0;
}