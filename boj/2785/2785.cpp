#include <cstdio>
#include <algorithm>
using namespace std;
 
int N;
int A[500000];
int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&A[i]);
    sort(A,A+N);
    int ans=0;
    for(int i=0; i<N; i++){
        if(ans+A[i]<N-i-2) ans+=A[i];
        else{
            if(ans+A[i]==N-i-2) ans=N-i-2;
            else ans=N-i-1;
            break;
        }
    }
    printf("%d\n",ans);
	return 0;
}