#include <stdio.h>
#define MAX 64
int b[MAX][MAX];

void go(int r, int c, int size){

    int i,j,all_same;

    all_same=1;
    for(i=r; i<r+size; i++){
        for(j=c; j<c+size; j++){
            if(b[r][c]!=b[i][j]){
                all_same=0;
                break;
            }
        }
    }

    if(all_same) printf("%d", b[r][c]);
    else{
        printf("(");
        go(r, c, size/2);
        go(r, c+size/2, size/2);
        go(r+size/2, c, size/2);
        go(r+size/2, c+size/2, size/2);
        printf(")");
    }
}

int main(void){

    int i,j,size;
    scanf("%d\n", &size);
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            scanf("%1d", &b[i][j]);
        }
        if(i<size-1) scanf("\n");
    }
    go(0, 0, size);
    printf("\n");
    return 0;
}