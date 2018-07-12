#include <stdio.h>

int g[1700000];
int main(void){

        int i, n;
        int cur_sum, cur_num, cnt;
        scanf("%d", &n);

        cnt=0, cur_sum=0, cur_num=1;
        g[1]=1;
        for(i=1; i<=1700000; i++){

                if(g[cur_num]>cnt){
                        g[i]=cur_num;
                        cnt++;
                        cur_sum+=g[i];
                }
                else{
                        cur_num++;
                        cnt=1;
                        g[i]=cur_num;
                        cur_sum+=g[i];
                }

                if(cur_sum>=n){
                        printf("%d\n", i);
                        break;
                }
        }
        return 0;
}