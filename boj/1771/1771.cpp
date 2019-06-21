#include <cstdio>
#define MAX_N 500000
using namespace std;
int N; // 카드 수
int A[MAX_N]; // A[i] = i번째 카드에 있는 수
typedef struct{
    int small; // 현재 카드묶음에서 가장 작은 수
    int big; // 현재 카드묶음에서 가장 큰 수
    int lastIdx; // 현재 카드묶음에 속한 카드 중 가장 뒤쪽 카드의 idx
}GROUP;
 
GROUP myStack[MAX_N]; int top;
 
int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&A[i]);
 
    // init stack
    top=-1;
    GROUP t;
    t.small=t.big=A[0]; t.lastIdx=0;
    myStack[++top]=t;
 
    // get ans
    for(int i=1; i<N; i++){
        t.small=t.big=A[i]; t.lastIdx=i;
        myStack[++top]=t;
        while(top>0){ // 스택에 원소가 2개 이상이어야 합치기 가능
            if(myStack[top-1].big+1==myStack[top].small){
                printf("%d ", myStack[top-1].lastIdx+1);
                myStack[top-1].big=myStack[top].big;
                myStack[top-1].lastIdx=myStack[top].lastIdx;
                top--;
            }
            else if(myStack[top-1].small==myStack[top].big+1){
                printf("%d ", myStack[top-1].lastIdx+1);
                myStack[top-1].small=myStack[top].small;
                myStack[top-1].lastIdx=myStack[top].lastIdx;
                top--;
            }
            else break;
        }
    }
    printf("\n");
    return 0;
}