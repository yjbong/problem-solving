#include <stdio.h>
int a[1001];
int main(void){

    int i,j,s,e,num,sum;
    num=1;
    j=0;
    for(i=1; i<=1000; i++){
        j++;
        if(j>num){
            num++;
            j=1;
        }
        a[i]=num;
    }
    scanf("%d %d", &s, &e);

    sum=0;
    for(i=s; i<=e; i++) sum+=a[i];
    printf("%d\n", sum);

    return 0;
}