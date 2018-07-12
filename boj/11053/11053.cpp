#include <cstdio>
int n;
int a[1111];
int d[1111];
int main(void){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	for(int i=0; i<n; i++) d[i]=1;
	for(int i=1; i<n; i++)
		for(int j=0; j<i; j++)
			if(a[j]<a[i] && d[i]<d[j]+1) d[i]=d[j]+1;

	int ans=d[0];
	for(int i=1; i<n; i++)
		if(ans<d[i]) ans=d[i];
	printf("%d\n", ans);
	return 0;
}