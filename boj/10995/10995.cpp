#include <cstdio>
int main() {
    int N;
    scanf("%d",&N);
    if(N==1) printf("*\n");
    else{
        for(int i=1; i<=N; i++){
            if(i%2==1){
                for(int j=1; j<=N; j++) printf("* ");
            }
            else{
                for(int j=1; j<=N; j++) printf(" *");
            }
            printf("\n");
        }
    }
    return 0;
}