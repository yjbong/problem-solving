#include <stdio.h>
int num[21];
int pw[21];
int main(void){

    int i,j,n,s,cur_s,tmp,sol;
    pw[0]=1;
    for(i=1; i<=20; i++) pw[i]=pw[i-1]*2;

    scanf("%d %d", &n, &s);
    for(i=0; i<n; i++) scanf("%d", &num[i]);

    sol=0;
    for(i=1; i<pw[n]; i++){
        tmp=i;
        cur_s=0;
        j=0;
        while(tmp>0){
            if(tmp%2==1) cur_s+=num[j];
            tmp/=2;
            j++;
        }
        if(cur_s==s) sol++;
    }
    printf("%d\n", sol);
    return 0;
}