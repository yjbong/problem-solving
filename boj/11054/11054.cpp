#include <cstdio>
int n; // 수열 길이
int s[1000]; // 수열
int d[1000]; // d[i] = a[i]를 오른쪽 끝으로 하는 LIS 길이 (-> 방향)
int e[1000]; // e[i] = a[i]를 왼쪽 끝으로 하는 LIS 길이 (<- 방향)

int main(void){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&s[i]);
    
	for(int i=0; i<n; i++) d[i]=1;
	for(int i=0; i<n; i++)
		for(int j=0; j<i; j++)
			if(s[j]<s[i] && d[i]<d[j]+1) d[i]=d[j]+1;

	for(int i=n-1; i>=0; i--) e[i]=1;
	for(int i=n-1; i>=0; i--)
		for(int j=n-1; j>i; j--)
			if(s[j]<s[i] && e[i]<e[j]+1) e[i]=e[j]+1;

	int len=0;
	for(int i=0; i<n; i++)
		if(len<d[i]+e[i]-1) len=d[i]+e[i]-1;
	printf("%d\n",len);
	
	return 0;
}