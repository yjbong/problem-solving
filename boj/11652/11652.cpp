#include <cstdio>
#define MAX_N 1000000
typedef long long ll;
 
int N;
ll arr[MAX_N];
ll t0[MAX_N/2+1];
ll t1[MAX_N/2+1];
 
bool compare(ll a, ll b){ return a<=b; }
 
void mergeSort(int left, int right){
    if(left==right) return; // 구간 크기가 1인 경우 정렬 불필요
 
    // Divide
    int mid=(left+right)/2;
    mergeSort(left, mid);
    mergeSort(mid+1, right);
 
    // Conquer
    for(int i=left, j=0; i<=mid; i++, j++) t0[j]=arr[i];
    for(int i=mid+1, j=0; i<=right; i++, j++) t1[j]=arr[i];
    int t0size=mid-left+1, t1size=right-mid;
    int i=left, j=0, k=0;
    while(j<t0size || k<t1size){
        if(j<t0size && k<t1size){
            // compare
            if(compare(t0[j], t1[k])) arr[i++]=t0[j++];
            else arr[i++]=t1[k++];
        }
        else if(j<t0size) arr[i++]=t0[j++];
        else arr[i++]=t1[k++];
    }
}
int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%lld",&arr[i]);
 
    mergeSort(0, N-1);
 
    int maxCnt=0;
    ll ans=arr[0];
    int cnt=1;
    for(int i=1; i<N; i++){
        if(arr[i]!=arr[i-1]){
            if(maxCnt<cnt){ ans=arr[i-1]; maxCnt=cnt; }
            cnt=1;
        }
        else cnt++;
    }
    if(maxCnt<cnt){ ans=arr[N-1]; maxCnt=cnt; }
    printf("%lld\n",ans);
    return 0;
}