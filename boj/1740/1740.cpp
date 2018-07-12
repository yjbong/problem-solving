#include <stdio.h>
long long pw[39];
int bit[39];
int main(void){

	long long i,n,sol;
	pw[0]=1;
	for(i=1; i<39; i++) pw[i]=pw[i-1]*3;
	for(i=0; i<39; i++) bit[i]=0;
	scanf("%lld",&n);
	i=0;
	while(n>0){
		bit[i]=n%2;
		n/=2;
		i++;
	}
	
	sol=0;
	for(i=0; i<39; i++)
		if(bit[i]) sol+=pw[i];

	printf("%lld\n",sol);
	return 0;
}