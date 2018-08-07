#include <cstdio>
#include <cstring>
int t;
int rows, cols;
char board[401][401];
//int d[200][400][400]; // d[i][j][k] = true if (i*2+1)-sized diamond exists with center coord y=j and x=k, false otherwise
int d[2][400][400];

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

                int ans=0;
                for(int i=0; i<rows; i++){
                        for(int j=0; j<cols; j++){
                                d[0][i][j]=board[i][j]=='#' ? 1 : 0;
                                ans+=d[0][i][j];
                        }
                }

                int cur=1;
                for(int i=1; i<=(min2(rows,cols)-1)/2; i++){
                        for(int j=i; j<rows-i; j++){
                                for(int k=i; k<cols-i; k++){
                                        //d[i][j][k]=d[i-1][j-1][k]*d[i-1][j+1][k]*d[i-1][j][k]*d[i-1][j][k-1]*d[i-1][j][k+1];
                                        d[cur][j][k]=d[1-cur][j-1][k]*d[1-cur][j+1][k]*d[1-cur][j][k]*d[1-cur][j][k-1]*d[1-cur][j][k+1];
                                        ans+=d[cur][j][k];
                                }
                        }
                        cur=1-cur;
                }

                printf("%d\n",ans);
        }
        return 0;
}