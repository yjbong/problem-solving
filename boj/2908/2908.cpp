#include <cstdio>
int main(void){
	int a,b;
	scanf("%d %d",&a,&b);
	int rev_a,rev_b;
	rev_a=(a%10)*100 + (a/10%10)*10 + a/100;
	rev_b=(b%10)*100 + (b/10%10)*10 + b/100;
	if(rev_a>rev_b) printf("%d\n",rev_a);
	else printf("%d\n",rev_b);
	return 0;
}