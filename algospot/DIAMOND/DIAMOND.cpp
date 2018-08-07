#include <cstdio>
#include <cstring>
int t;
int rows, cols;
char board[55][55];
int d[55][55][55]; // d[i][j][k] = 1 if (i*2+1)-sized diamond exists with center coord y=j and x=k, 0 otherwise
int min2(int a, int b){
        return a<b?a:b;
}
int main(void){
        scanf("%d",&t);
        while(t--){
                scanf("%d",&rows);
                for(int i=0; i<rows; i++){
                        scanf("%s",board[i]);
                        cols=strlen(board[i]);
                }
                for(int i=0; i<rows; i++)
                        for(int j=0; j<cols; j++)
                                d[0][i][j]=board[i][j]=='#' ? 1 : 0;

                for(int i=1; i<=(min2(rows,cols)-1)/2; i++)
                        for(int j=1; j<rows-1; j++)
                                for(int k=1; k<cols-1; k++)
                                        d[i][j][k]=d[i-1][j-1][k]*d[i-1][j+1][k]*d[i-1][j][k]*d[i-1][j][k-1]*d[i-1][j][k+1];

                int ans=0;
                for(int i=(min2(rows,cols)-1)/2; i>=0; i--)
                        for(int j=0; j<rows; j++)
                                for(int k=0; k<cols; k++)
                                        if(d[i][j][k]){ ans=i*2+1; goto out; }
out:
                printf("%d\n",ans);
        }
        return 0;
}