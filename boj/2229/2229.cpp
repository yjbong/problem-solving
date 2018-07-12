#include <stdio.h>
int diff[1000][1000];
int sc[1000];
int d[1000];
int main(void){

    int i,j,tmp,n,min,max,curmax;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &sc[i]);
    for(i=0; i<n; i++){
        min=sc[i];
        max=sc[i];
        for(j=i; j<n; j++){
            if(min>sc[j]) min=sc[j];
            if(max<sc[j]) max=sc[j];
            diff[i][j]=max-min;
        }
    }

    d[0]=0;
    for(i=1; i<n; i++){
        curmax=diff[0][i];
        for(j=0; j<i; j++){
            tmp=d[i-j-1]+diff[i-j][i];
            if(curmax<tmp) curmax=tmp;
        }
        d[i]=curmax;
    }
    printf("%d\n", d[n-1]);
    return 0;
}