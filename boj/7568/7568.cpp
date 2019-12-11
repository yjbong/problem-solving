#include <cstdio>
#define MAX_N 50
int N; // 전체 사람의 수
int x[MAX_N]; // x[i] = i번 사람의 몸무게
int y[MAX_N]; // y[i] = i번 사람의 키
int r[MAX_N]; // r[i] = i번 사람의 덩치 등수
int main(void){
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d %d",&x[i],&y[i]);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(x[j]>x[i] && y[j]>y[i]) r[i]++;
    for(int i=0; i<N; i++) printf("%d ",r[i]+1);
    printf("\n");
    return 0;
}