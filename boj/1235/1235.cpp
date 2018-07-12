#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[1001][1001];
char ss[1001][1001];
char old_ss[1001];

int cmp(const void *a, const void *b){

    if(strcmp((char*)a, (char*)b)>0) return 1;
    else return 0;
}

int main(void){

    int i,j,n;
    int maxlen,sol;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%s", s[i]);
    maxlen=strlen(s[0]);
    for(i=1; i<=maxlen; i++){
        for(j=0; j<n; j++){
            strncpy(ss[j], s[j]+maxlen-i, i);
            ss[j][i]='\0';
        }
        qsort(ss, n, sizeof(char)*1001, cmp);
        old_ss[0]='\0';
        for(j=0; j<n; j++){
            if(strcmp(old_ss, ss[j])==0) break;
            else strcpy(old_ss, ss[j]);
        }
        if(j==n){
            sol=i;
            break;
        }
    }
    printf("%d\n", sol);

    return 0;
}