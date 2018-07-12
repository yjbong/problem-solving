#include <stdio.h>
int main(void){

        int i, result;
        char board[8*8], tmp;
        i=0;
        while(i<8*8){
                scanf("%c", &tmp);
                if(tmp=='.' || tmp=='F'){
                        board[i]=tmp;
                        i++;
                }
        }
        result=0;
        for(i=0; i<8*8; i++)
                if((i/8)%2==i%2 && board[i]=='F') result++;
        printf("%d\n", result);
        return 0;
}