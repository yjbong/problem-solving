#include <stdio.h>
#include <string.h>
#define MAXLEN 50
int main(void){
        int i, is_first;
        int lines, line_len;
        char result_line[MAXLEN+1];
        char cur_line[MAXLEN+1];
        scanf("%d", &lines);
        is_first=1;
        while(lines--){
                scanf("%s", cur_line);
                line_len=strlen(cur_line);
                if(is_first){
                        is_first=0;
                        strcpy(result_line, cur_line);
                }
                else{
                        for(i=0; i<line_len; i++)
                                if(result_line[i]!=cur_line[i])
                                        result_line[i]='?';
                }
        }
        printf("%s\n", result_line);
        return 0;
}