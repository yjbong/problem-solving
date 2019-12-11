#include <cstdio>
#include <cstring>
#define MAXLEN 1000
char A[MAXLEN+2], B[MAXLEN+2];
int AL, BL;
int D[MAXLEN+1][MAXLEN+1]; // D[i][j]=A[1~i]와 B[1~j]가 일치되기 위한 최소 편집 횟수
int min2(int a, int b){ return a<b?a:b; }
int main() {
    scanf("%s",A+1);
    scanf("%s",B+1);
    AL=strlen(A+1), BL=strlen(B+1);
 
    //// DP
    // Base case
    D[0][0]=0;
    for(int i=1; i<=AL; i++) D[i][0]=i;
    for(int j=1; j<=BL; j++) D[0][j]=j;
    // Normal case
    for(int i=1; i<=AL; i++)
    for(int j=1; j<=BL; j++){
        D[i][j]=1000000000;
        // 교체 연산: A[i]를 B[j]와 같은 문자로 교체
        D[i][j]=min2(D[i][j], D[i-1][j-1]+(A[i]!=B[j]?1:0));
        // 삭제 연산: A[i]를 삭제
        D[i][j]=min2(D[i][j], D[i-1][j]+1);
        // 삽입 연산: A[i] 바로 뒤에 B[j]와 같은 문자를 삽입
        D[i][j]=min2(D[i][j], D[i][j-1]+1);
    }
 
    printf("%d\n",D[AL][BL]);
    return 0;
}