#include <cstdio>
#define INF 1000000000
int T; // TC수
int C; // 거스름돈
int Q; // 필요한 쿼터의 개수
int D; // 필요한 다임의 개수
int N; // 필요한 니켈의 개수
int P; // 필요한 페니의 개수
int main() {
    scanf("%d",&T);
    while(T--){
        scanf("%d",&C);
        int sum=INF;
        for(int i=0; i<=C/25; i++){ // 쿼터가 i개일 때
            int tmp=C, CQ, CD, CN, CP;
            CQ=i; tmp-=CQ*25;
            CD=tmp/10; tmp-=CD*10;
            CN=tmp/5; tmp-=CN*5;
            CP=tmp;
            int curSum=CQ+CD+CN+CP;
            if(sum>curSum){
                sum=curSum;
                Q=CQ; D=CD; N=CN; P=CP;
            }
        }
        printf("%d %d %d %d\n",Q,D,N,P);
    }
    return 0;
}