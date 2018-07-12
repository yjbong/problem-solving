#include <cstdio>
int n; // 포트의 수
int a[40000]; // a[i] = i번 포트와 연결되야 하는 포트 번호
int d[40000]; // d[i] = a[i]를 마지막으로 하는 LIS 길이

int tree[1<<17]; // segment tree
int base;

int max2(int a, int b){ return a>b?a:b; }

void updateTree(int idx, int val){
	idx+=base;
	tree[idx]=max2(tree[idx],val);

	idx/=2;
	while(idx>0){
		tree[idx]=max2(tree[idx*2],tree[idx*2+1]);
		idx/=2;
	}
}

int queryTree(int left, int right){

	int ret=0;

	left+=base;
	right+=base;

	while(left<right){
		if(left%2==0) left/=2;
		else{
			ret=max2(ret,tree[left]);
			left=(left+1)/2;
		}
		if(right%2==1) right/=2;
		else{
			ret=max2(ret,tree[right]);
			right=(right-1)/2;
		}
	}

	if(left==right) ret=max2(ret,tree[left]);
	return ret;
}

int main(void){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		a[i]--;
	}
	for(int i=0; i<n; i++) d[i]=1;

	base=1;
	while(base<n) base*=2;

	for(int i=0; i<n; i++){
		d[i]=max2(d[i],queryTree(0,a[i])+1);
		updateTree(a[i],d[i]);
	}

	int len=0;
	for(int i=0; i<n; i++)
		if(len<d[i]) len=d[i];
	printf("%d\n",len);
	
	return 0;
}