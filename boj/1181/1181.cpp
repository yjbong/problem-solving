#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char word[20000][51];
int words;

int cmp(const void *a, const void *b){
    if(strlen((char*)a)>strlen((char*)b)) return 1;
    else if(strlen((char*)a)<strlen((char*)b)) return 0;
    else if(strcmp((char*)a, (char*)b)>0) return 1;
    else return 0;
}

int main(void){

    int i;
    char old_word[51];
    scanf("%d", &words);
    for(i=0; i<words; i++) scanf("%s", &word[i]);
    qsort(word, words, sizeof(char)*51, cmp);
    old_word[0]='\0';
    for(i=0; i<words; i++){
        if(strcmp(old_word, word[i])!=0){
            printf("%s\n", word[i]);
            strcpy(old_word, word[i]);
        }
    }
    return 0;
}