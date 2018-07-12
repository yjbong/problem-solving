#include <stdio.h>
#define MAX 14
#define EAST 0
#define WEST 1
#define SOUTH 2
#define NORTH 3
int board[MAX*2+1][MAX*2+1];
int n;
double prob[4];
double result;
void go(int steps, int cur_x, int cur_y, double cur_prob){

        if(board[cur_x][cur_y]==1) return;
        if(steps==n){
                result+=cur_prob;
                return;
        }

        board[cur_x][cur_y]=1;
        go(steps+1, cur_x+1, cur_y, cur_prob*prob[EAST]);
        go(steps+1, cur_x-1, cur_y, cur_prob*prob[WEST]);
        go(steps+1, cur_x, cur_y-1, cur_prob*prob[SOUTH]);
        go(steps+1, cur_x, cur_y+1, cur_prob*prob[NORTH]);
        board[cur_x][cur_y]=0;
}

int main(void){
        int i, j;
        scanf("%d", &n);
        scanf("%lf %lf %lf %lf", &prob[0], &prob[1], &prob[2], &prob[3]);
        for(i=0; i<4; i++) prob[i]/=100.0;
        for(i=14-n; i<=14+n; i++)
                for(j=14-n; j<=14+n; j++)
                        board[i][j]=0;
        go(0, 14, 14, 1.0);
        printf("%.10lf\n", result);
        return 0;
}