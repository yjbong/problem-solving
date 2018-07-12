#include <stdio.h>
int sol[100];
int sol_len;
int abs(int n){

    if(n<0) return (-n);
    else return n;
}
int main(void){

    int i, num, base, q, r;
    scanf("%d %d", &num, &base);
    if(num==0) printf("0\n");
    else{

        if(base<0){
            sol_len=0;
            while(abs(num)>0){
                q=num/base;
                r=num-base*q;
                if(r<0){
                    r-=base;
                    q++;
                }
                num=q;
                sol[sol_len]=r;
                sol_len++;
            }
        }

        else{
            if(num<0){
                printf("-");
                num=abs(num);
            }
            sol_len=0;
            while(num>0){
                q=num/base;
                r=num-base*q;
                num=q;
                sol[sol_len]=r;
                sol_len++;
            }
        }

        for(i=sol_len-1; i>=0; i--)
            printf("%d", sol[i]);
        printf("\n");
    }
    return 0;
}