#include <stdio.h>
#include <string.h>
#define SWAP(a,b,tmp) {tmp=a;a=b;b=tmp;}
int main(void){

    int i,j,k,len;
    char line[51];
    char min[51];
    char cur1[51],cur2[51],cur3[51],cur[51];
    int cur1len,cur2len,cur3len;
    char tmp;

    scanf("%s", line);
    len=strlen(line);
    min[0]='\0';
    for(i=0; i<len-2; i++){
        for(j=i+1; j<len-1; j++){
            strncpy(cur1,line,i+1);
            cur1[i+1]='\0';
            cur1len=strlen(cur1);
            strncpy(cur2,line+i+1,j-i);
            cur2[j-i]='\0';
            cur2len=strlen(cur2);
            strncpy(cur3,line+j+1,len-1-j);
            cur3[len-1-j]='\0';
            cur3len=strlen(cur3);

            for(k=0; k<=(cur1len-1)/2; k++)
                SWAP(cur1[k],cur1[cur1len-1-k],tmp);
            for(k=0; k<=(cur2len-1)/2; k++)
                SWAP(cur2[k],cur2[cur2len-1-k],tmp);
            for(k=0; k<=(cur3len-1)/2; k++)
                SWAP(cur3[k],cur3[cur3len-1-k],tmp);

            strcpy(cur,cur1);
            strcat(cur,cur2);
            strcat(cur,cur3);
            if(strlen(min)==0 || strcmp(min,cur)>0) strcpy(min,cur);
        }
    }
    printf("%s\n", min);

    return 0;
}