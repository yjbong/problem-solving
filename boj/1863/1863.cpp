#include <stdio.h>
int stack[50000];
int h[50000];

int top;
int main(void){

    int i,n;
    int cur_s, cur_h;
    int sol=0;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d %d", &cur_s, &cur_h);
        h[i]=cur_h;
    }

    top=-1;
    for(i=0; i<n; i++){
        if(h[i]>0 && top<0){
            top++;
            stack[top]=h[i];
        }
        else{
            while(stack[top]>h[i]){
                sol++;
                top--;
            }

            if(h[i]>0 && (top<0 || stack[top]<h[i])){
                top++;
                stack[top]=h[i];
            }
        }
    }
    sol+=(top+1);
    printf("%d\n", sol);
    return 0;
}