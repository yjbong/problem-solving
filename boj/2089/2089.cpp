#include <cstdio>
int n;
int sol[50];
int sols=0;
int main(void){

    scanf("%d",&n);
    if(n==0){
        printf("0\n");
    }
    else{
        while(n!=1){
            if(n<0){
                if((-n)%2){
                    n=n/(-2)+1;
                    sol[sols++]=1;
                }
                else{
                    n=n/(-2);
                    sol[sols++]=0;
                }
            }
            else{
                if(n%2){
                    n=n/(-2);
                    sol[sols++]=1;
                }
                else{
                    n=n/(-2);
                    sol[sols++]=0;
                }
            }
        }
        sol[sols++]=1;
        for(int i=sols-1; i>=0; i--) printf("%d",sol[i]);
        printf("\n");
    }
    return 0;
}