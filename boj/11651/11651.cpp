#include <cstdio>
#define MAX_N 100000
 
typedef struct{
    int y;
    int x;
}POINT;
 
int N;
POINT arr[MAX_N];
POINT t0[MAX_N/2+1];
POINT t1[MAX_N/2+1];
 
bool compare(POINT a, POINT b){
    if(a.y<b.y) return true;
    else if(a.y>b.y) return false;
    else{
        if(a.x<=b.x) return true;
        else return false;
    }
}
 
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
    for(int i=0; i<N; i++) scanf("%d %d",&arr[i].x,&arr[i].y);
 
    mergeSort(0, N-1);
 
    for(int i=0; i<N; i++) printf("%d %d\n",arr[i].x,arr[i].y);
    return 0;
}