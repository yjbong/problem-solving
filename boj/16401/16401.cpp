#include <cstdio>
#define MAX_M 1000000
#define MAX_N 1000000
 
int M; // 조카의 수
int N; // 과자의 수
int L[MAX_N]; // L[i]=i번 과자의 길이
bool isPossible(int length){
    int num=0;
    for(int i=0; i<N; i++){
        num+=L[i]/length;
        if(num>=M) return true;
    }
    return false;
}
int main() {
    scanf("%d %d",&M,&N);
    for(int i=0; i<N; i++) scanf("%d",&L[i]);
    int ans=0;
    int left=1, right=1000000000;
    // Parametric search
    while(left<=right){
        int mid=(left+right)/2;
        if(isPossible(mid)){
            if(ans<mid) ans=mid;
            left=mid+1;
        }
        else right=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}