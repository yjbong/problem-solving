#include <cstdio>
int main(void){
	int S,T,a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	S=a+b+c+d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	T=a+b+c+d;
	if(S>=T) printf("%d\n",S);
	else printf("%d\n",T);
	return 0;
}