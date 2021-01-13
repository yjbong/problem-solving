#include <cstdio>
#define MAXN 1000
int N,K;
bool alive[MAXN];
int main(void){
    scanf("%d %d",&N,&K);
    for(int i=0; i<N; i++) alive[i]=true;
    int start=0;
    printf("<");
    for(int i=0; i<N; i++){
        int curStep=0;
        int j=start;
        for(; ; j=(j+1)%N){
            if(alive[j]) curStep++;
            if(curStep==K){
                printf("%d",j+1);
                alive[j]=false;
                start=(j+1)%N;
                break;
            }
        }
        if(i<N-1) printf(", ");
        else printf(">\n");
    }
    return 0;
}