#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
 
int N,M,A[8];
bool pick[8];
vector <int> pickSeq;
void go(int numPick, vector <int> pickSeq){
    if(numPick==M){
        for(int i=0; i<M; i++) printf("%d ",A[pickSeq[i]]);
        printf("\n");
        return;
    }
    for(int i=0; i<N; i++){
        if(!pick[i]){
            pick[i]=true; pickSeq.push_back(i);
            go(numPick+1,pickSeq);
            pick[i]=false; pickSeq.pop_back();
        }
    }
}
int main() {
    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++) scanf("%d",&A[i]);
    sort(A,A+N);
    go(0,pickSeq);
    return 0;
}