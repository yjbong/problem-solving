#include <cstdio>
#define MAXN 100
#define MAXWON 100000
typedef struct{
    int won; // 액면가
    int cnt; // 개수
} COIN;
 
int N; // 동전의 가짓수
COIN coin[MAXN];
 
int newCoins; // 새(?) 동전의 가짓수
int newCoin[MAXN*18];
 
bool D[MAXN*18][MAXWON/2+1]; // D[i][j] = newCoin[0~i] 가 주어질 때, j원을 만들 수 있는지?
 
int main() {
 
    for(int tc=0; tc<3; tc++){
        scanf("%d",&N);
        int totalWon=0; // 동전 금액의 총합
        for(int i=0; i<N; i++){
            scanf("%d %d",&coin[i].won,&coin[i].cnt);
            totalWon+=coin[i].won*coin[i].cnt;
        }
        int ans=0;
        if(totalWon==0) ans=1;
        else if(totalWon%2==0){
            // newCoin 데이터 생성
            newCoins=0;
            for(int i=0; i<N; i++){
                for(int j=0; j<17; j++){
                    if(coin[i].cnt>=(1<<j)){
                        newCoin[newCoins++]=coin[i].won*(1<<j);
                        coin[i].cnt-=(1<<j);
                    }
                }
                if(coin[i].cnt>0){
                    newCoin[newCoins++]=coin[i].won*coin[i].cnt;
                }
            }
 
            // DP
            for(int j=0; j<=totalWon/2; j++) D[0][j]=false;
            D[0][0]=true; D[0][newCoin[0]]=true;
            for(int i=1; i<newCoins; i++){
                for(int j=0; j<=totalWon/2; j++){
                    // newCoin[i]를 고르지 않는 경우
                    D[i][j]=D[i-1][j];
                    // newCoin[i]를 고르는 경우
                    if(j>=newCoin[i] && D[i-1][j-newCoin[i]]) D[i][j]=true;
                }
            }
            if(D[newCoins-1][totalWon/2]) ans=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}