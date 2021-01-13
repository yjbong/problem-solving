#include <cstdio>
#include <algorithm>
#define MAXN 4000
 
using namespace std;
int N;
int A[MAXN], B[MAXN], C[MAXN], D[MAXN];
int CDSum[MAXN*MAXN];
 
int count(int num){
    int left, right, mid;
    // Get lowest idx equals to num
    left=0, right=N*N-1;
    int low=right+1;
    while(left<=right){
        mid=(left+right)>>1;
        if(num<CDSum[mid]) right=mid-1;
        else if(num>CDSum[mid]) left=mid+1;
        else{
            if(low>mid) low=mid;
            right=mid-1;
        }
    }
    // Get highest idx equals to num
    left=0, right=N*N-1;
    int high=left-1;
    while(left<=right){
        mid=(left+right)>>1;
        if(num<CDSum[mid]) right=mid-1;
        else if(num>CDSum[mid]) left=mid+1;
        else{
            if(high<mid) high=mid;
            left=mid+1;
        }
    }
 
    if(low<=high) return high-low+1;
    else return 0;
}
 
int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++)
        scanf("%d %d %d %d",&A[i],&B[i],&C[i],&D[i]);
 
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int val=C[i]+D[j];
            CDSum[i*N+j]=val;
        }
    }
    sort(CDSum, CDSum+N*N);
 
    long long ans=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int val=-(A[i]+B[j]);
            ans+=count(val);
        }
    }
    printf("%lld\n",ans);
    return 0;
}