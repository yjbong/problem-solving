#include <cstdio>
#include <stack>
#define MAX_N 1000000
using namespace std;
int N;
int A[MAX_N];
int NGE[MAX_N];
stack <int> s;
int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&A[i]);
    for(int i=N-1; i>=0; i--){
        NGE[i]=-1;
        while(!s.empty()){
            if(s.top()>A[i]){ NGE[i]=s.top(); break; }
            else s.pop();
        }
        s.push(A[i]);
    }
    for(int i=0; i<N; i++) printf("%d ",NGE[i]);
    printf("\n");
    return 0;
}