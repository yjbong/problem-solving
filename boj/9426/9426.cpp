#include <cstdio>
typedef long long ll;
int N,K;
ll A[250000];

ll seg[131072];
const int base=65536; // segment tree에서 실제 data의 시작 idx

// update(idx,add) = segment tree의 idx번째 data를 add만큼 증가
void update(int idx, ll add){
	idx+=base;
	seg[idx]+=add;
	idx/=2;
	while(idx>=1){
		seg[idx]=seg[idx*2]+seg[idx*2+1];
		idx/=2;
	}
}

// query(num) = segment tree에서 num번째 숫자를 찾는다
ll query(int num){
	if(seg[1]<=0) return -1; // error
	while(num>seg[1]) num-=seg[1];

	int idx=1;
	while(idx<base){
		if(num<=seg[idx*2]) idx=idx*2;
		else{
			num-=seg[idx*2];
			idx=idx*2+1;
		}
	}
	return idx-base;
}

int main(void){
	scanf("%d %d",&N,&K);
	for(int i=0; i<N; i++) scanf("%lld",&A[i]);

	ll ans=0;
	for(int i=0; i<N-K+1; i++){
		if(i==0) for(int j=0; j<K; j++) update(A[j],1);
		else{
			update(A[i-1],-1);
			update(A[i+K-1],1);
		}
		ans+=query((K+1)/2);
	}
	printf("%lld\n",ans);
	return 0;
}