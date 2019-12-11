#include <cstdio>
#include <cstring>
#define MAX_R 1500
#define MAX_C 1500
using namespace std;
int R,C; // 땅의 크기
char str[5];
int A[MAX_R][MAX_C]; // A[i][j]=i,j에 있는 사과 수
int B[MAX_R][MAX_C]; // B[i][j]=i,j에 있는 바나나 수
int AS[MAX_R][MAX_C]; // AS[i][j]=A[0][j]+A[1][j]+...+A[i][j]
int BS[MAX_R][MAX_C]; // BS[i][j]=B[0][j]+B[1][j]+...+B[i][j]

int D[MAX_R][MAX_C]; // D[i][j]=불도저가 i,j까지 왔을 때, 0~j열까지의 영토에 대해서 A나라가 확보하는 사과의 수와 B나라가 확보하는 바나나 수의 합의 최대값
int max2(int a, int b){ return a>b?a:b; }
int main() {
    scanf("%d %d",&R,&C);
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            scanf("%s",str);
            int num=0;
            for(int k=1; k<strlen(str); k++){
                num*=10;
                num+=str[k]-'0';
            }
            if(str[0]=='A') A[i][j]=num;
            else B[i][j]=num;
        }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(i==0) AS[i][j]=A[i][j];
            else AS[i][j]=AS[i-1][j]+A[i][j];
            if(i==0) BS[i][j]=B[i][j];
            else BS[i][j]=BS[i-1][j]+B[i][j];
        }
    }

    // DP
    D[0][0]=AS[R-1][0]-AS[0][0];
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            // case 1: (i-1, j)로부터 아래로 한칸 이동한 경우
            if(i>0) D[i][j]=max2(D[i][j], D[i-1][j]-A[i][j]); 
            // case 2: (i, j-1)로부터 오른쪽으로 한칸 이동한 경우
            if(j>0) D[i][j]=max2(D[i][j], D[i][j-1]+(AS[R-1][j]-AS[i][j])+(i>0?BS[i-1][j]:0));
            // case 3: (i-1, j-1)로부터 대각선 이동한 경우
            if(i>0 && j>0) D[i][j]=max2(D[i][j], D[i-1][j-1]+(AS[R-1][j]-AS[i][j])+(i>0?BS[i-1][j]:0));
        }
    }

    printf("%d\n",D[R-1][C-1]);

    return 0;
}