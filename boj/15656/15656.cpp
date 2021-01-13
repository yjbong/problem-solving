#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N,M,A[8];
bool pick[8];
vector <int> pickSeq;
void go(vector <int> pickSeq){
    if(pickSeq.size()==M){
        for(int i=0; i<M; i++) printf("%d ",A[pickSeq[i]]);
        printf("\n");
        return;
    }
    for(int i=0; i<N; i++){
        pickSeq.push_back(i);
        go(pickSeq);
        pickSeq.pop_back();
    }
}
int main() {
    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++) scanf("%d",&A[i]);
    sort(A,A+N);
    go(pickSeq);
    return 0;
}