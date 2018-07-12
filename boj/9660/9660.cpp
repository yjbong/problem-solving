#include <cstdio>
int main(void){
	long long N;
	scanf("%lld",&N);
	if(N%7==0 || N%7==2) printf("CY\n");
	else printf("SK\n");
	return 0;
}