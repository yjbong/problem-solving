#include <stdio.h>
#include <string.h>
int frq[10001];
char name[10001][11];
int main(void){

    int i,u,n,min;
    char curname[11];
    int money;
    scanf("%d %d", &u, &n);
    for(i=1; i<=u; i++) frq[i]=0;
    for(i=0; i<n; i++){
        scanf("%s %d", curname, &money);
        if(frq[money]==0) strcpy(name[money], curname);
        frq[money]++;
    }

    min=0;
    for(i=1; i<=u; i++)
        if(frq[i]>0 && (min==0 || frq[min]>frq[i])) min=i;

    printf("%s %d\n", name[min], min);
    return 0;
}