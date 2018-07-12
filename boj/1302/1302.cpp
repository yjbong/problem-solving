#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char book[1000][51];
int books;
int cmp(const void *a, const void *b){
    if(strcmp((char*)a, (char*)b)>0) return 1;
    else return 0;
}

int main(void){

    int i;
    int cur_frq, max_frq;
    char cur_book[51];
    char max_book[51];

    scanf("%d", &books);
    for(i=0; i<books; i++) scanf("%s", book[i]);
    qsort(book, books, sizeof(char)*51, cmp);
    max_frq=cur_frq=0;
    cur_book[0]='\0';
    for(i=0; i<books; i++){
        if(strcmp(cur_book, book[i])!=0){
            if(max_frq<cur_frq){
                max_frq=cur_frq;
                strcpy(max_book, cur_book);
            }
            strcpy(cur_book, book[i]);
            cur_frq=1;
        }
        else cur_frq++;
    }
    if(max_frq<cur_frq){
        max_frq=cur_frq;
        strcpy(max_book, cur_book);
    }

    printf("%s\n", max_book);
    return 0;
}