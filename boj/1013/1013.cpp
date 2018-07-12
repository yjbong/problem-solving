#include <stdio.h>
#include <string.h>

int stat[10][2];
char line[201];

int main(void){

    int i,t,len,curstat;

    stat[0][0]=7, stat[0][1]=1; /*NULL*/
    stat[1][0]=2, stat[1][1]=9; /*1*/
    stat[2][0]=3, stat[2][1]=9; /*10*/
    stat[3][0]=3, stat[3][1]=4; /*100*/
    stat[4][0]=7, stat[4][1]=5; /*1001*/
    stat[5][0]=6, stat[5][1]=5; /*10011*/
    stat[6][0]=3, stat[6][1]=8; /*100110*/
    stat[7][0]=9, stat[7][1]=8; /*0*/
    stat[8][0]=7, stat[8][1]=1; /*01*/
    stat[9][0]=9, stat[9][1]=9; /*trap*/

    scanf("%d", &t);
    while(t--){
        scanf("%s", line);
        len=strlen(line);
        curstat=0;
        for(i=0; i<len; i++)
            curstat=stat[curstat][line[i]-'0'];

        if(curstat==4 || curstat==5 || curstat==8) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}