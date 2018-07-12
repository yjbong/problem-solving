#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char line[111111];
int main(void){
    int len,n;
    scanf("%d %s", &n, line);
    len=strlen(line);
    printf("%c\n", line[len-1]);
    return 0;
}