#include <stdio.h>

char line[51];
int rowc[50];
int colc[50];
int rows, cols;
int rowrem, colrem;
int main(void){

    int i,j,sol;
    int rows, cols;
    char curchar;
    scanf("%d %d", &rows, &cols);
    for(i=0; i<rows; i++) rowc[i]=0;
    for(i=0; i<cols; i++) colc[i]=0;
    rowrem=rows, colrem=cols;

    for(i=0; i<rows; i++){

        scanf("%s", line);
        for(j=0; j<cols; j++){
            if(line[j]=='X'){
                if(rowc[i]==0){
                    rowrem--;
                    rowc[i]=1;
                }
                if(colc[j]==0){
                    colrem--;
                    colc[j]=1;
                }
            }
        }
    }
    if(rowrem>colrem) sol=rowrem;
    else sol=colrem;
    printf("%d\n", sol);
    return 0;
}