#include <cstdio>
typedef long long ll;
ll a[250000];
int main(void){

	while(1){
		int n;
		ll max;
		scanf("%d",&n);
		if(n==0) break;
		for(int i=0; i<n; i++){
			scanf("%lld",&a[i]);
			if(i==0 || max<a[i]) max=a[i];
		}

		ll sum=0; bool ok=false;
		for(int i=0; i<n; i++){
			if(ok && max<sum) max=sum;
			if(sum+a[i]<0){ sum=0; ok=false; }
			else{ sum+=a[i]; ok=true; }
		}
		if(ok && max<sum) max=sum;
		printf("%lld\n",max);
	}
	return 0;
}