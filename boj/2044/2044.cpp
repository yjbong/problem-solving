#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define MAXLEN 10
typedef struct _win{

        char name[MAXLEN+1];
        int height;
        int width;
        int namelen;
}WIN;

WIN win[MAX*MAX];
int wins;

char board[MAX][MAX];
char sol[MAX][MAX];
int crossmark_check[MAX][MAX];

int cmp(const void *a, const void *b){

        if(strcmp(((WIN*)a)->name, ((WIN*)b)->name)>0) return 1;
        else return 0;
}

int main(void){

        int i, j, k, l, m;
        int M, N;
        scanf("%d %d\n", &M, &N);
        for(i=0; i<M; i++){
                for(j=0; j<N; j++){
                        scanf("%c", &board[i][j]);
                }
                scanf("\n");
        }

        for(i=0; i<M; i++)
                for(j=0; j<N; j++) sol[i][j]='X', crossmark_check[i][j]=0;

        wins=0;
        for(i=0; i<M; i++){
                for(j=0; j<N; j++){
                        if(board[i][j]=='+' && crossmark_check[i][j]==0){
                                crossmark_check[i][j]=1;
                                for(k=i+1; k<M; k++){
                                        if(board[k][j]=='+'){
                                                crossmark_check[k][j]=1;
                                                break;
                                        }
                                }
                                win[wins].height=k-i+1;

                                for(l=j+1; l<N; l++){
                                        if(board[i][l]=='+'){
                                                crossmark_check[i][l]=1;
                                                break;
                                        }
                                }
                                win[wins].width=l-j+1;

                                crossmark_check[k][l]=1;

                                for(k=j+1; k<N; k++){
                                        if(board[i][k]=='|'){
                                                for(l=k+1, m=0; board[i][l]!='|'; l++, m++){
                                                        win[wins].name[m]=board[i][l];
                                                }
                                                win[wins].name[m]='\0';
                                                win[wins].namelen=strlen(win[wins].name);
                                                break;
                                        }
                                }

                                wins++;
                        }
                }
        }

        qsort(win, wins, sizeof(WIN), cmp);

        for(i=wins-1; i>=0; i--){
                for(j=i; j<i+win[i].height; j++){
                        for(k=i; k<i+win[i].width; k++){

                                if(sol[j][k]=='X'){

                                        if(j==i){
                                                if(k==i || k==i+win[i].width-1) sol[j][k]='+';
                                                else if(k==i+(win[i].width-(win[i].namelen+2))/2 || k==i+(win[i].width-(win[i].namelen+2))/2+win[i].namelen+1) sol[j][k]='|';
                                                else if(k>i+(win[i].width-(win[i].namelen+2))/2 && k<i+(win[i].width-(win[i].namelen+2))/2+win[i].namelen+1)
                                                        sol[j][k]=win[i].name[k-(i+(win[i].width-(win[i].namelen+2))/2)-1];
                                                else sol[j][k]='-';
                                        }

                                        else if(j==i+win[i].height-1){
                                                if(k==i || k==i+win[i].width-1) sol[j][k]='+';
                                                else sol[j][k]='-';
                                        }

                                        else{
                                                if(k==i || k==i+win[i].width-1) sol[j][k]='|';
                                                else sol[j][k]='.';
                                        }
                                }
                        }
                }
        }

        for(i=0; i<M; i++)
                for(j=0; j<N; j++)
                        if(sol[i][j]=='X') sol[i][j]='.';

        for(i=0; i<M; i++){
                for(j=0; j<N; j++){
                        printf("%c", sol[i][j]);
                }
                printf("\n");
        }

        return 0;
}