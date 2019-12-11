#include <cstdio>
#define MAX_N 100
int N; // 카드의 개수
int M; // 목표수
int a[MAX_N]; // a[i] = i번 카드의 숫자
int main(void){
    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++) scanf("%d",&a[i]);
    int ans=0;
    for(int i=0; i<N; i++)
    for(int j=i+1; j<N; j++)
    for(int k=j+1; k<N; k++)
        if(ans<a[i]+a[j]+a[k] && a[i]+a[j]+a[k]<=M) ans=a[i]+a[j]+a[k];
    printf("%d\n",ans);
    return 0;
}