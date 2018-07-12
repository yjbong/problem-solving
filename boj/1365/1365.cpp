#include <cstdio>
int a[111111];
int b[111111];

int binsearch(int left, int right, int key){

	int mid,ret=-1;
	if(b[left]>key+1) return left;
	if(b[right]<key+1) return right+1;

	while(left<=right){
		mid=(left+right)/2;
		if(b[mid]<=key){
			left=mid+1;
			ret=mid+1;
		}
		else right=mid-1;
	}
	return ret;
}
int main(void){

	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);

	int bs=1;
	b[0]=a[0];

	for(int i=1; i<n; i++){
		int idx=binsearch(0,bs-1,a[i]-1);
		if(idx<0);
		else if(idx==bs) b[bs++]=a[i];
		else b[idx]=a[i];
	}
	printf("%d\n",n-bs);
	return 0;
}