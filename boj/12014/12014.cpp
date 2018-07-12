#include <cstdio>
int t; // 케이스 수
int n; // 전체 일수
int k; // 목표 거래 횟수
int p[10000]; // p[i] = i일 째의 주가
int d[10000]; // d[i] = 마지막 거래가 i일에 있을 때, 주식을 살 수 있는 날짜의 최대 수

int seg[32768];
int base=16384; // seg[base]=주가 0일 때, 지금까지 구한 d[x] 중 최대값 (p[x]==0), ... , seg[base+10000]=주가 10000일 때, 지금까지 구한 최대 d[x] (p[x]==10000)

int max2(int a, int b){ return a>b?a:b; }
void init(){ for(int i=0; i<32768; i++) seg[i]=0; }

// 구간 left~right에서 최대값 확인
int query(int left, int right){
	int ret=0;
	left+=base;
	right+=base;
	while(left<right){
		if(left%2==0) left/=2;
		else{
			ret=max2(ret,seg[left]);
			left=(left+1)/2;
		}
		if(right%2==1) right/=2;
		else{
			ret=max2(ret,seg[right]);
			right=(right-1)/2;
		}
	}
	if(left==right) ret=max2(ret,seg[left]);
	return ret;
}

// seg[base+idx]를 val로 변경
void update(int idx, int val){
	idx+=base;
	if(seg[idx]<val){
		seg[idx]=val;
		idx/=2;
		while(idx>=1){
			seg[idx]=max2(seg[idx*2],seg[idx*2+1]);
			idx/=2;
		}
	}
}

int main(void){
	scanf("%d",&t);
	for(int z=1; z<=t; z++){
		scanf("%d %d",&n,&k);
		for(int i=0; i<n; i++) scanf("%d",&p[i]);

		init();
		for(int i=0; i<n; i++) d[i]=1;

		for(int i=0; i<n; i++){
			d[i]=max2(d[i],query(0,p[i]-1)+1);
			update(p[i],d[i]);
		}
		int lisLen=0;
		for(int i=0; i<n; i++) lisLen=max2(lisLen,d[i]);

		printf("Case #%d\n",z);
		if(lisLen>=k) printf("1\n");
		else printf("0\n");
	}
	return 0;
}