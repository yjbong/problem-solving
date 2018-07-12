#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXDIGIT 7
int main(void){

        int i;
        char N[MAXDIGIT+1];
        char Shom_N[MAXDIGIT+1];
        char tmp[MAXDIGIT+1];
        int N_len, fill_start;

        scanf("%s", N);
        N_len=strlen(N);

        for(i=0; i<MAXDIGIT; i++) Shom_N[i]='0';
        Shom_N[i]='\0';

        for(i=0; i<MAXDIGIT-N_len; i++) tmp[i]='0';
        tmp[i]='\0';
        strcat(tmp, N);
        strcpy(N, tmp);

        fill_start=MAXDIGIT+1;
        for(i=MAXDIGIT-N_len; i<MAXDIGIT; i++){
                if(N[i]=='4' || N[i]=='7'){
                        Shom_N[i]=N[i];
                }
                else if(N[i]>'7'){
                        fill_start=i;
                        break;
                }
                else if(N[i]>'4' && N[i]<'7'){
                        Shom_N[i]='4';
                        fill_start=i+1;
                        break;
                }
                else if(N[i]<'4'){
                        if(i>0 && Shom_N[i-1]=='4'){
                                Shom_N[i-1]='0';
                                fill_start=i;
                        }
                        else if(i>0 && Shom_N[i-1]=='7'){
                                Shom_N[i-1]='4';
                                fill_start=i;
                        }
                        else fill_start=i+1;
                        break;
                }
        }

        for(i=fill_start; i<MAXDIGIT; i++) Shom_N[i]='7';
        printf("%d\n", atoi(Shom_N));
        return 0;
}