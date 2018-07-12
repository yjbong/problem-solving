#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define INF 2147483647
int N; // 용액의 수
int A0[100000]; // A0[i] = i번 용액의 특성값 (오름차순)
int A1[100000]; // A1[i] = i번 용액의 특성값 (내림차순)
int main(void){
	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%d",&A0[i]);
	std::sort(A0,A0+N);

	for(int i=0,j=N-1; i<N; i++, j--) A1[i]=A0[j];

	int minDiff=INF;
	int ans[2];
	for(int i=0; i<N; i++){
		int key=-A0[i];
		int left=0, right=N-1;
		while(left<=right){
			int mid=(left+right)/2;
			if(key<A0[mid]){
				if(minDiff>abs(A0[i]+A0[mid]) && A0[i]!=A0[mid]){
					minDiff=abs(A0[i]+A0[mid]);
					ans[0]=A0[i], ans[1]=A0[mid];
				}	
				right=mid-1;
			}
			else if(key>A0[mid]){
				if(minDiff>abs(A0[i]+A0[mid]) && A0[i]!=A0[mid]){
					minDiff=abs(A0[i]+A0[mid]);
					ans[0]=A0[i], ans[1]=A0[mid];
				}	
				left=mid+1;	
			}
			else{
				if(minDiff>abs(A0[i]+A0[mid]) && A0[i]!=A0[mid]){
					minDiff=abs(A0[i]+A0[mid]);
					ans[0]=A0[i], ans[1]=A0[mid];
				}
				break;
			}
		}
	}
	
	for(int i=0; i<N; i++){
		int key=-A1[i];
		int left=0, right=N-1;
		while(left<=right){
			int mid=(left+right)/2;
			if(key<A1[mid]){
				if(minDiff>abs(A1[i]+A1[mid]) && A1[i]!=A1[mid]){
					minDiff=abs(A1[i]+A1[mid]);
					ans[0]=A1[i], ans[1]=A1[mid];
				}	
				left=mid+1;
			}
			else if(key>A1[mid]){
				if(minDiff>abs(A1[i]+A1[mid]) && A1[i]!=A1[mid]){
					minDiff=abs(A1[i]+A1[mid]);
					ans[0]=A1[i], ans[1]=A1[mid];
				}	
				right=mid-1;
			}
			else{
				if(minDiff>abs(A1[i]+A1[mid]) && A1[i]!=A1[mid]){
					minDiff=abs(A1[i]+A1[mid]);
					ans[0]=A1[i], ans[1]=A1[mid];
				}
				break;
			}
		}
	}

	if(ans[0]>ans[1]){
		int tmp=ans[0];
		ans[0]=ans[1];
		ans[1]=tmp;
	}

	printf("%d %d\n",ans[0],ans[1]);
	return 0;
}