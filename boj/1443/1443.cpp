#include <cstdio>
#define MAX_D 8
#define MAX_P 30
#define INF 1000000000ll
typedef long long ll;
int D; // 표시할 수 있는 자리수
int P; // 곱셈 연산 횟수
 
ll max2(ll a, ll b){ return a>b?a:b; }
ll limit;
ll myPow[11][MAX_P+1]; // myPow[i][j]=i의 j승 (그 값이 INF보다 크다면 INF로...)
 
ll ans;
void go(ll curNum, int digitStart, int remainMult){
    if(!remainMult){
        ans=max2(ans, curNum);
        return;
    }
    else if(curNum*myPow[2][remainMult]>limit) return;
    else if(curNum*myPow[9][remainMult]<=limit){
        ans=max2(ans, curNum*myPow[9][remainMult]);
        return;
    }
    for(int i=digitStart; i<=9; i++)
        if(curNum*i<=limit)
            go(curNum*i, i, remainMult-1);
}
 
int main() {
    for(int i=1; i<=10; i++){
        myPow[i][0]=1;
        for(int j=1; j<=MAX_P; j++){
            myPow[i][j]=myPow[i][j-1]*i;
            if(myPow[i][j]>INF) myPow[i][j]=INF;
        }
    }
 
    scanf("%d %d",&D,&P);
    limit=myPow[10][D]-1;
    ans=-1;
    go(1, 2, P);
    printf("%lld\n",ans);
	return 0;
}