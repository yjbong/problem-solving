#include <stdio.h>
#define MAXSIZE 500

int tri[MAXSIZE][MAXSIZE];
int size;
int max_sum;
int sum[MAXSIZE][MAXSIZE];
int max(int a, int b){
        if(a>b) return a;
        else return b;
}

int main(void){

        int i,j;
        scanf("%d", &size);
        for(i=0; i<size; i++)
                for(j=0; j<=i; j++)
                        scanf("%d", &tri[i][j]);
        max_sum=0;
        sum[0][0]=tri[0][0];
        for(i=1; i<size; i++){
                for(j=0; j<=i; j++){
                        if(j==0) sum[i][j]=sum[i-1][j]+tri[i][j];
                        else if(j==i) sum[i][j]=sum[i-1][j-1]+tri[i][j];
                        else sum[i][j]=max(sum[i-1][j-1], sum[i-1][j])+tri[i][j];

                        if(i==size-1 && max_sum<sum[i][j]) max_sum=sum[i][j];
                }
        }

        printf("%d\n", max_sum);
        return 0;
}