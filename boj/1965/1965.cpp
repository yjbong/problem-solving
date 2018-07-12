#include <stdio.h>
int num[1000];
int d[1000];
int main(void){
    int i,j,sol,nums,max;
    scanf("%d", &nums);
    for(i=0; i<nums; i++) scanf("%d", &num[i]);
    d[0]=1;
    sol=1;
    for(i=1; i<nums; i++){
        max=0;
        for(j=0; j<i; j++)
            if(num[i]>num[j] && d[j]>max)
                max=d[j];
        d[i]=max+1;
        if(sol<d[i]) sol=d[i];
    }
    printf("%d\n", sol);
    return 0;
}