#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int A[11];
int opCnt[4];
vector<int> op;
int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&A[i]);
    for(int i=0; i<4; i++) scanf("%d",&opCnt[i]);
    for(int i=0; i<4; i++)
        for(int j=0; j<opCnt[i]; j++) op.push_back(i);
 
    int min=1000000001;
    int max=-1000000001;
    do{
        int cur=A[0];
        for(int i=0; i<N-1; i++){
            switch(op[i]){
                case 0:
                    cur+=A[i+1]; break;
                case 1:
                    cur-=A[i+1]; break;
                case 2:
                    cur*=A[i+1]; break;
                case 3:
                    cur/=A[i+1]; break;
            }
        }
        if(min>cur) min=cur;
        if(max<cur) max=cur;
    }while(next_permutation(op.begin(), op.end()));
    printf("%d\n%d\n",max,min);
    return 0;
}