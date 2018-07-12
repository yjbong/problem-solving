#include <stdio.h>
int card[1111111];
int main(void){
    int i,n;
    int start,end;
    scanf("%d",&n);
    for(i=0; i<n; i++) card[i]=i+1;
    start=0,end=n-1;

    while(!(start==end)){
        start++;
        end++;
        card[end]=card[start];
        start++;
    }
    printf("%d\n",card[start]);
    return 0;
}