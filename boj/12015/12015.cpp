#include <cstdio>
using namespace std;
int N;
int A[1000000];
int seq[1000000];
int seqs;
int main() {
    seqs=0;
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&A[i]);
    seq[seqs++]=A[0];
    for(int i=1; i<N; i++){
        // A[i]가 seq의 마지막 수보다 크면 뒤에 추가
        if(A[i]>seq[seqs-1]){ seq[seqs++]=A[i]; continue; }
        
        // 이분탐색으로 seq 배열에 현재 A[i]가 들어갈 위치를 찾음
        int left=0, right=seqs-1;
        int lowBnd=right;
        while(left<=right){
            int mid=(left+right)/2;
            if(seq[mid]>=A[i]){
                if(lowBnd>mid) lowBnd=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        seq[lowBnd]=A[i]; // 찾은 위치를 A[i]로 업데이트
    }
    printf("%d\n",seqs);
    return 0;
}