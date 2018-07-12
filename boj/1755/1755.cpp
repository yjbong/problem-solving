#include <stdio.h>
#include <string.h>
#define SWAP(a, b, tmp) {tmp=a; a=b; b=tmp;}
char digit[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int rank[1000];
char num_str[1000][30];
int cur_print[1000];
int main(void){
        int i,j,M,N,tmp;
        int cur_prints;

        for(i=0; i<1000; i++){

                num_str[i][0]='\0';
                if(i>=100) strcat(num_str[i], digit[(i-i%100)/100]);
                if(i>=10) strcat(num_str[i], digit[(i-i/100*100-i%10)/10]);
                if(i>=0) strcat(num_str[i], digit[i%10]);
        }

        for(i=0; i<1000; i++) rank[i]=0;
        for(i=0; i<1000; i++)
                for(j=0; j<1000; j++)
                        if(strcmp(num_str[i], num_str[j])>=0) rank[i]++;


        scanf("%d %d", &M, &N);
        if(M>N) SWAP(M, N, tmp);
        cur_prints=N-M+1;
        for(i=0; i<cur_prints; i++)
                cur_print[i]=M+i;

        for(i=0; i<cur_prints-1; i++){
                for(j=i+1; j<cur_prints; j++){
                        if(rank[cur_print[i]]>rank[cur_print[j]]) SWAP(cur_print[i], cur_print[j], tmp);
                }
        }

        for(i=0; i<cur_prints; i++){
                printf("%d", cur_print[i]);
                if(i%10==9 || i==cur_prints-1) printf("\n");
                else if(i<cur_prints-1) printf(" ");
        }
        return 0;
}