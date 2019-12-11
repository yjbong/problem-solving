#include <cstdio>
#include <algorithm>
#define MAX_N 8
using namespace std;
int N;
int A[MAX_N];
int main(void){
    scanf("%d",&N);
    for(int i=0; i<N; i++) A[i]=i+1;
    do{
        for(int i=0; i<N; i++) printf("%d ",A[i]);
        printf("\n");
    }while(next_permutation(A,A+N));
    return 0;
}