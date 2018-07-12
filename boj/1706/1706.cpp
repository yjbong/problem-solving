#include <stdio.h>
#include <string.h>
#define MAX_ROWS 20
#define MAX_COLS 20
#define MAX_WORDS 400
int main(void){

        int i,j;
        int rows, cols;
        char line[MAX_COLS+1];
        int line_len;
        char word[MAX_WORDS][MAX_COLS+1];
        int words;
        char board[MAX_ROWS+2][MAX_COLS+2];
        int min_word_idx;
        scanf("%d %d", &rows, &cols);
        for(i=1; i<=rows; i++){
                scanf("%s", line);
                for(j=1; j<=cols; j++) board[i][j]=line[j-1];
        }

        for(i=0; i<=rows+1; i++){
                board[i][0]='#';
                board[i][cols+1]='#';
        }

        for(j=0; j<=cols+1; j++){
                board[0][j]='#';
                board[rows+1][j]='#';
        }

        words=0;
        for(i=0; i<=rows+1; i++){

                line_len=0;
                for(j=0; j<=cols+1; j++){

                        if(board[i][j]!='#'){
                                line[line_len]=board[i][j];
                                line_len++;
                        }
                        if(board[i][j]=='#'){
                                if(line_len>0){
                                        line[line_len]='\0';
                                        if(line_len>1){
                                                strcpy(word[words], line);
                                                words++;
                                        }
                                        line_len=0;
                                }
                        }
                }
        }

        for(i=0; i<=cols+1; i++){

                line_len=0;
                for(j=0; j<=rows+1; j++){

                        if(board[j][i]!='#'){
                                line[line_len]=board[j][i];
                                line_len++;
                        }
                        if(board[j][i]=='#'){
                                if(line_len>0){
                                        line[line_len]='\0';
                                        if(line_len>1){
                                                strcpy(word[words], line);
                                                words++;
                                        }
                                        line_len=0;
                                }
                        }
                }
        }

        min_word_idx=0;
        for(i=1; i<words; i++)
                if(strcmp(word[min_word_idx], word[i])>0) min_word_idx=i;

        printf("%s\n", word[min_word_idx]);
        return 0;
}