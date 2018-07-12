#include <stdio.h>
int a[1000];
int p[1000];
int main(void){

    int i,j,n;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    for(i=0; i<n; i++) p[i]=0;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(a[i]>a[j] || (a[i]==a[j] && j<i)) p[i]++;

    for(i=0; i<n; i++){
        printf("%d", p[i]);
        if(i==n-1) printf("\n");
        else printf(" ");
    }
    return 0;
}