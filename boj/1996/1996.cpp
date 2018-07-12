#include <stdio.h>
#define MAXSIZE 1000
char info[MAXSIZE+2][MAXSIZE+2];
char map[MAXSIZE+2][MAXSIZE+2];

int main(void){

        int i,j,k,l;
        int n;
        scanf("%d\n", &n);
        for(i=1; i<=n; i++){
                for(j=1; j<=n; j++){
                        scanf("%c", &info[i][j]);
                        if(j==n) scanf("\n");
                }
        }

        for(i=0; i<=n+1; i++) info[i][0]='.', info[i][n+1]='.';
        for(j=0; j<=n+1; j++) info[0][j]='.', info[n+1][j]='.';

        for(i=1; i<=n; i++){
                for(j=1; j<=n; j++){
                        if(info[i][j]!='.') map[i][j]='*';
                        else{
                                map[i][j]=0;
                                for(k=i-1; k<=i+1; k++){
                                        for(l=j-1; l<=j+1; l++){
                                                if(info[k][l]!='.') map[i][j]+=info[k][l]-'0';
                                        }
                                }
                                if(map[i][j]>=10) map[i][j]='M';
                                else map[i][j]=map[i][j]+'0';
                        }
                }
        }

        for(i=1; i<=n; i++){
                for(j=1; j<=n; j++){
                        printf("%c", map[i][j]);
                }
                printf("\n");
        }

        return 0;
}