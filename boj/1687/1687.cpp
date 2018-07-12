#include <stdio.h>
#define MAX 333

char board[MAX+2][MAX+2];
int zeros[MAX+2][MAX+2];
int cur_zip[MAX+2];
int main(void){

    int i,j,k,N,M;
    char tmp[MAX+1];
    int max_rec;
    int cur_width;
    scanf("%d %d\n", &N, &M);
    for(i=1; i<=N; i++){
            scanf("%s\n", tmp);
            for(j=1; j<=M; j++) board[i][j]=tmp[j-1];
    }

    for(i=0; i<=N+1; i++){
        board[i][0]='1', board[i][M+1]='1';
        zeros[i][0]=0;
    }

    for(j=0; j<=M+1; j++){
        board[0][j]='1', board[N+1][j]='1';
        zeros[0][j]=0;
    }

    for(i=1; i<=N; i++){
        for(j=1; j<=M; j++){
            zeros[i][j]=zeros[i][j-1]+zeros[i-1][j]-zeros[i-1][j-1];
            if(board[i][j]=='0') zeros[i][j]++;
        }
    }

    max_rec=0;
    for(i=1; i<=N; i++){
        for(j=i; j<=N; j++){

            cur_zip[0]=0;
            for(k=1; k<=M; k++){
                cur_zip[k]=zeros[j][k];
                if(i>1) cur_zip[k]-=zeros[i-1][k];
            }

            cur_width=0;
            for(k=1; k<=M; k++){
                if(cur_zip[k]-cur_zip[k-1]==j-i+1) cur_width++;
                else{
                    if(max_rec<cur_width*(j-i+1)) max_rec=cur_width*(j-i+1);
                    cur_width=0;
                }
            }
            if(max_rec<cur_width*(j-i+1)) max_rec=cur_width*(j-i+1);
        }
    }

    printf("%d\n", max_rec);
    return 0;
}