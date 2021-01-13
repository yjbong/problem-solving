#include <cstdio>
int A,B;
int main() {
    scanf("%d %d",&A,&B);
    printf("%d",A/B);
    A%=B;
    if(A>0){
        printf(".");
        int digits=1500;
        int cnt=0;
        while(A>0 && cnt<digits){
            A*=10;
            printf("%d",A/B); A%=B; cnt++;
        }
    }
    return 0;
}