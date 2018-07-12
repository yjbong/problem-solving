#include <cstdio>
bool p[1111111];
int main(void){

	p[1]=true;
	for(int i=2; i<=1000000; i++)
		if(!p[i]) for(int j=i*2; j<=1000000; j+=i) p[j]=true;

	int m,n;
	scanf("%d %d",&m,&n);
	for(int i=m; i<=n; i++) if(!p[i]) printf("%d\n",i);
	return 0;
}