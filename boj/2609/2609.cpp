#include <cstdio>
int gcd(int p, int q){
    if (q==0) return p;
    return gcd(q, p%q);
}
int main(void){
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d\n",gcd(a,b));
	printf("%d\n",(a*b)/gcd(a,b));
	return 0;
}