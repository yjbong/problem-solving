#include <cstdio>
int main(void){
	while(1){
		int n;
		scanf("%d",&n);
		if(n==0) break;
		while(n>9){
			int tmp=0;
			while(n>0){ tmp+=n%10; n/=10; }
			n=tmp;
		}
		printf("%d\n",n);
	}
	return 0;
}