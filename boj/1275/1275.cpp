#include <cstdio>
typedef long long ll;
int N; // 숫자의 개수
int Q; // 턴의 개수
// for segment tree
ll seg[1<<18];
int base;

ll query(int left, int right){ // left~right번째 숫자의 합을 구함
	left+=base, right+=base;
	ll ret=0;
	while(left<right){
		if(left%2==0) left/=2;
		else{
			ret+=seg[left];
			left=(left+1)/2;
		}
		if(right%2==1) right/=2;
		else{
			ret+=seg[right];
			right=(right-1)/2;
		}
	}
	if(left==right) ret+=seg[left];
	return ret;
}
void update(int idx, ll val){ // idx번 숫자를 val로 바꿈
	idx+=base;
	seg[idx]=val;
	idx/=2;
	while(idx>=1){
		seg[idx]=seg[idx*2]+seg[idx*2+1];
		idx/=2;
	}
}
int main(void){
	scanf("%d %d",&N,&Q);

	// segment tree 초기화
	base=1;
	while(base<N) base*=2;
	for(int i=0; i<N; i++) scanf("%lld",&seg[base+i]);
	for(int i=base-1; i>=1; i--) seg[i]=seg[i*2]+seg[i*2+1];

	for(int i=0; i<Q; i++){
		int x,y,a,tmp;
		ll b;
		scanf("%d %d %d %lld",&x,&y,&a,&b);
		// x~y까지의 합을 구한다
		if(x>y){ tmp=x; x=y; y=tmp; }
		printf("%lld\n",query(x-1,y-1));
		// a번째 숫자를 b로 바꾼다
		update(a-1,b);
	}
	return 0;
}