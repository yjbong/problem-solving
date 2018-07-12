#include <cstdio>
int n; // 수열 a의 크기
int a[1000];
int d[1000]; // a[i]를 맨 끝으로 하는 수열 중의 최대 합
int main(void){

	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		d[i]=a[i];
	}
	for(int i=0; i<n; i++)
		for(int j=0; j<i; j++)
			if(a[j]<a[i] && d[i]<d[j]+a[i]) d[i]=d[j]+a[i];

	int ans=0;
	for(int i=0; i<n; i++)
		if(ans<d[i]) ans=d[i];
	printf("%d\n",ans);
	return 0;
}