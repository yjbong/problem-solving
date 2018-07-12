#include <cstdio>
int main(void){
	while(1){
		int n;
		scanf("%d",&n);
		if(n==0) break;

		int dgt[5];
		int dgts=0;
		while(n>0){ dgt[dgts++]=n%10; n/=10; }

		bool ok=true;
		for(int i=0,j=dgts-1; i<=j; i++,j--)
			if(dgt[i]!=dgt[j]){ ok=false; break; }
		if(ok) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}