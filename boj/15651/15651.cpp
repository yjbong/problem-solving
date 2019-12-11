#include <cstdio>
#define MAX_N 7
#define MAX_M 7

int N,M; // 1~N까지의 자연수 중에서 M개를 뽑아서 수열을 만든다
int perm[MAX_M], perms=0;

void getPerm(int cnt){
    if(cnt==M){
        for(int i=0; i<M; i++)
            printf("%d ",perm[i]);
        printf("\n");
        return;
    }
    for(int i=1; i<=N; i++){
        perm[perms++]=i;
        getPerm(cnt+1);
        perms--;
    }
}

int main() {
    scanf("%d %d",&N,&M);
    getPerm(0);
    return 0;
}