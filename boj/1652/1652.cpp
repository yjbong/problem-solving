#include <stdio.h>
char b[111][111];
int main(void){

        int i,j,n;
        int cur_len,garo,sero;
        scanf("%d\n",&n);
        for(i=0; i<n; i++) gets(b[i]);
        /*
        for(i=0; i<n; i++){
                for(j=0; j<n; j++){
                        printf("%c",b[i][j]);
                }
                printf("\n");
        }
        */
        garo=0;
        for(i=0; i<n; i++){
                cur_len=0;
                for(j=0; j<n; j++){
                        if(b[i][j]=='.') cur_len++;
                        else{
                                if(cur_len>=2) garo++;
                                cur_len=0;
                        }
                }
                if(cur_len>=2) garo++;
        }
        sero=0;
        for(i=0; i<n; i++){
                cur_len=0;
                for(j=0; j<n; j++){
                        if(b[j][i]=='.') cur_len++;
                        else{
                                if(cur_len>=2) sero++;
                                cur_len=0;
                        }
                }
                if(cur_len>=2) sero++;
        }
        printf("%d %d\n",garo,sero);
        return 0;
}