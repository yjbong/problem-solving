#include <stdio.h>
int pair[11111];
int main(void){

    int i,n,cur_n,nearpow;

    scanf("%d", &n);
    for(i=1; i<=n; i++) pair[i]=-1;
    cur_n=n;
    while(cur_n>=1){
        nearpow=1;
        while(nearpow<=cur_n) nearpow*=2;
        nearpow/=2;
        i=nearpow;
        while(pair[i]<0 && i<=cur_n){
            pair[i]=nearpow*2-i;
            pair[nearpow*2-i]=i;
            i++;
        }
        cur_n=nearpow-1;
    }

    for(i=1; i<=n; i++)
        printf("%d\n", pair[i]);

    return 0;
}