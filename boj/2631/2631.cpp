#include <cstdio>
int n; // 아이들의 수
int a[200]; // 아이들의 번호
int d[200]; // d[i] = a[i]를 마지막으로 하는 LIS 길이

int main(void){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	for(int i=0; i<n; i++) d[i]=1;
	for(int i=0; i<n; i++)
		for(int j=0; j<i; j++)
			if(a[j]<a[i] && d[i]<d[j]+1) d[i]=d[j]+1;

	int len=0;
	for(int i=0; i<n; i++)
		if(len<d[i]) len=d[i];
	printf("%d\n",n-len);
	
	return 0;
}