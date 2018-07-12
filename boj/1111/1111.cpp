#include <cstdio>
typedef long long ll;
int n; // length of sequence
ll seq[55]; // sequence
int main(void){

	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%lld",&seq[i]);

	if(n==1) printf("A\n");
	else if(n==2){
		if(seq[0]==seq[1]) printf("%lld\n",seq[0]);
		else printf("A\n");
	}
	else{
		// setting a and b
		ll a,b;
		if(seq[1]-seq[0]==0) a=0;
		else a=(seq[2]-seq[1])/(seq[1]-seq[0]);
		b=seq[1]-a*seq[0];

		// check if given sequence is valid
		bool ok=true;
		for(int i=1; i<n; i++){
			if(seq[i]!=a*seq[i-1]+b){
				ok=false;
				break;
			}
		}
		if(ok) printf("%lld\n",a*seq[n-1]+b);
		else printf("B\n");
	}
	return 0;
}