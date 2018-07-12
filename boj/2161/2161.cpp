#include <stdio.h>
int q[3000];
int main(void){
    int i,n,front,tail;
    scanf("%d", &n);
    for(i=0; i<n; i++) q[i]=i+1;
    front=0, tail=n;
    for(i=0; i<n; i++){
        printf("%d", q[front]);
        if(i==n-1) printf("\n");
        else printf(" ");
        front++;
        q[tail]=q[front];
        front++;
        tail++;
    }
    return 0;
}