#include <stdio.h>
int num_flow[10][10]={{0,0}, {1,1}, {1,2,4,8,6}, {1,3,9,7,1}, {1,4,6}, {1,5}, {1,6}, {1,7,9,3,1}, {1,8,4,2,6}, {1,9,1}};
int num_flows[10]={1,1,4,4,2,1,1,4,4,2};
int main(void){
        int cases;
        int a,b,result;
        scanf("%d", &cases);
        while(cases--){
                scanf("%d %d", &a, &b);
                if(b==0) b=0;
                else{
                        b=b%num_flows[a%10];
                        if(b==0) b=num_flows[a%10];
                }
                if(num_flow[a%10][b]==0) result=10;
                else result=num_flow[a%10][b];
                printf("%d\n", result);
        }
        return 0;
}