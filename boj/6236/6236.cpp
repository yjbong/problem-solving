#include <cstdio>
int N,M;
int K;
int A[100000];
bool isOk(int K){
	int cnt=1;
	int csum=0;
	for(int i=0; i<N; i++){
		if(csum+A[i]<=K) csum+=A[i];
		else{
			cnt++;
			csum=A[i];
		}
	}
	return cnt<=M;
}

int main() {
    scanf("%d %d",&N,&M);
	int l=0,r=0;
	for(int i=0; i<N; i++){
		scanf("%d",&A[i]);
		if(l<A[i]) l=A[i]; // left=A[i] 중 최대값
		r+=A[i]; // right=A[i]들의 합
	}

	// 이분탐색
	int ans=r;
	while(l<=r){
		int m=(l+r)/2;
		if(isOk(m)){
			if(ans>m) ans=m;
			r=m-1;
		}
		else l=m+1;
	}
	printf("%d\n",ans);
	return 0;
}