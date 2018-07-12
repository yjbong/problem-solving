#include <cstdio>
int m,n;
bool isNotPrime[10001];
int main(void){
	isNotPrime[0]=isNotPrime[1]=true;
	for(int i=2; i<=10000; i++)
		if(!isNotPrime[i])
			for(int j=i*2; j<=10000; j+=i) isNotPrime[j]=true;

	scanf("%d %d",&m,&n);
	int minPrime=-1;
	int primeSum=0;
	for(int i=m; i<=n; i++){
		if(!isNotPrime[i]){
			if(minPrime<0) minPrime=i;
			primeSum+=i;
		}
	}
	if(minPrime<0) printf("-1\n");
	else printf("%d\n%d\n",primeSum,minPrime);
	
	return 0;
}