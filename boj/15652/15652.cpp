#include <cstdio>
#define MAX_N 8
#define MAX_M 8

int N,M; // 1~N까지의 자연수 중에서 M개를 뽑아서 수열을 만든다
bool visited[MAX_N+1];
int perm[MAX_M], perms=0;

void getPerm(int cnt, int start){
    if(cnt==M){
        for(int i=0; i<M; i++)
            printf("%d ",perm[i]);
        printf("\n");
        return;
    }
    for(int i=start; i<=N; i++){
        perm[perms++]=i;
        getPerm(cnt+1,i);
        perms--;
    }
}

int main() {
    scanf("%d %d",&N,&M);
    getPerm(0,1);
    return 0;
}