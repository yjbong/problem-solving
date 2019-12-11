#include <cstdio>
#define MAX_N 10000
int N;
int A[MAX_N];
int main(){
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        for(int i=0; i<N; i++) scanf("%d",&A[i]);
        int avg=0;
        for(int i=0; i<N; i++) avg+=A[i];
        avg/=N;
        int ans=0;
        for(int i=0; i<N; i++)
            if(A[i]<=avg) ans++;
        printf("%d\n",ans);
    }
    return 0;
}