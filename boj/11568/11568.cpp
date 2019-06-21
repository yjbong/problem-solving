#include <cstdio>
int N;
int A[1000];
int D[1000]; // D[i]=A[i]가 마지막 수인 LIS길이
int main(){
    scanf("%d",&N);
    for(int i=0; i<N; i++)
        scanf("%d",&A[i]);
    for(int i=0; i<N; i++) D[i]=1;
    for(int i=0; i<N; i++)
        for(int j=0; j<i; j++)
            if(A[j]<A[i] && D[i]<D[j]+1)
                D[i]=D[j]+1;
 
    int ans=0;
    for(int i=0; i<N; i++)
        if(ans<D[i]) ans=D[i];
    printf("%d\n",ans);
    return 0;
}