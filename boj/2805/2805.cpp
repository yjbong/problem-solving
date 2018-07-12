#include <cstdio>
typedef long long ll;
ll N; // 나무의 수
ll M; // 필요한 나무의 길이
ll a[1000000]; // 각 나무의 높이

// 절단기 높이를 height로 했을 때 가져가는 나무의 길이
ll getLength(ll height){
	ll sum=0;
	for(ll i=0; i<N; i++) if(a[i]-height>0) sum+=a[i]-height;
	return sum;
}

int main(void){
	scanf("%lld %lld",&N,&M);

	ll maxHeight=0;
	for(ll i=0; i<N; i++){
		scanf("%lld",&a[i]);
		if(maxHeight<a[i]) maxHeight=a[i];
	}

	ll ans=0;
	ll left=0, right=maxHeight;
	while(left<=right){
		ll mid=(left+right)/2;
		if(getLength(mid)>=M){
			if(ans<mid) ans=mid;
			left=mid+1;	
		}
		else right=mid-1;
	}
	printf("%lld\n",ans);
	return 0;
}