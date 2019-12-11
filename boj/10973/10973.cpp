#include <cstdio>
#include <algorithm>
#define MAX_N 10000
using namespace std;

int N;
int A[MAX_N];
int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&A[i]);
    for(int i=0; i<N; i++) A[i]=-A[i];
    if(next_permutation(A,A+N)){
        for(int i=0; i<N; i++) printf("%d ",-A[i]);
    }
    else printf("-1");
    return 0;
}