#include <stdio.h>
#include <string.h>
#define MAX 10000
const char piano[]="AXBCXDXEFXGX";
const int start_pos[7]={0,2,3,5,7,8,10};
int note[MAX];
int notes;
int main(void){

        int i,j,piano_len,cur_pos;

        piano_len=strlen(piano);
        scanf("%d", &notes);
        for(i=0; i<notes; i++) scanf("%d", &note[i]);

        for(i=0; i<7; i++){
                cur_pos=start_pos[i];
                for(j=0; j<notes; j++){
                        cur_pos+=note[j];
                        while(cur_pos<0) cur_pos+=piano_len;
                        cur_pos%=piano_len;
                        if(piano[cur_pos]=='X') break;
                }
                if(j==notes) printf("%c %c\n", piano[start_pos[i]], piano[cur_pos]);
        }
        return 0;
}