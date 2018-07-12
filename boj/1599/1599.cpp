#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char input[1000][51];
typedef struct _newstr{
    char s[51];
    int num;
}NEWSTR;
NEWSTR newstr[1000];

int cmp(const void *a, const void *b){

    if(strcmp(((NEWSTR*)a)->s, ((NEWSTR*)b)->s)>0) return 1;
    else return 0;
}

int main(void){

    int i,j,k,n,len;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%s", input[i]);
    for(i=0; i<n; i++){
        newstr[i].num=i;
        for(j=0,k=0; j<strlen(input[i]); j++,k++){
            if(input[i][j]=='k') newstr[i].s[k]='c';
            else if(input[i][j]>='g' && input[i][j]<='i') newstr[i].s[k]=input[i][j]-1;
            else if(input[i][j]>='l' && input[i][j]<='n'){
                newstr[i].s[k]=input[i][j]-3;
                if(input[i][j]=='n' && (j+1<strlen(input[i]) && input[i][j+1]=='g')){
                    newstr[i].s[k]++;
                    j++;
                }
            }
            else if(input[i][j]>='o' && input[i][j]<='p') newstr[i].s[k]=input[i][j]-2;
            else if(input[i][j]>='r' && input[i][j]<='u') newstr[i].s[k]=input[i][j]-3;
            else if(input[i][j]=='w') newstr[i].s[k]='s';
            else if(input[i][j]=='y') newstr[i].s[k]='t';
            else newstr[i].s[k]=input[i][j];
        }
        newstr[i].s[k]='\0';
    }
    qsort(newstr, n, sizeof(NEWSTR), cmp);
    for(i=0; i<n; i++){
        printf("%s\n", input[newstr[i].num]);
    }

    return 0;
}