#include <cstdio>
int n; // 수열의 길이
int a[1000];
int d[1000]; // d[i]=a[i]를 마지막으로 하는 최장 감소 수열의 길이

int main(void){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	for(int i=0; i<n; i++) d[i]=1;

	for(int i=0; i<n; i++)
		for(int j=0; j<i; j++)
			if(a[i]<a[j] && d[i]<d[j]+1) d[i]=d[j]+1;
	int ans=0;
	for(int i=0; i<n; i++) if(ans<d[i]) ans=d[i];
	printf("%d\n",ans);
	return 0;
}