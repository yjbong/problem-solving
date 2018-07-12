#include <stdio.h>
#define MAXROWS 100
#define MAXCOLS 100
int main(void){

        int i, j;
        int rows, cols;
        char line[MAXCOLS+1];
        int room[MAXROWS][MAXCOLS];
        int woods;

        scanf("%d %d", &rows, &cols);
        woods=rows*cols;
        for(i=0; i<rows; i++){
                scanf("%s", line);
                for(j=0; j<cols; j++){
                        if(line[j]=='-') room[i][j]=0;
                        else if(line[j]=='|') room[i][j]=1;
                }
        }

        for(i=0; i<rows; i++){
                for(j=0; j<cols-1; j++){
                        if(room[i][j]==0 && room[i][j+1]==0) woods--;
                }
        }

        for(i=0; i<cols; i++){
                for(j=0; j<rows-1; j++){
                        if(room[j][i]==1 && room[j+1][i]==1) woods--;
                }
        }

        printf("%d\n", woods);
        return 0;
}