#include <cstdio>
int t; // # of test cases
int n; // 보석의 수
int d[200]; // d[i] = i번 보석을 마지막으로 하는 수열의 최대 길이
double w[200]; // w[i] = i번 보석의 무게
double c[200]; // c[i] = i번 보석의 선명도
int main(void){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0; i<n; i++) scanf("%lf %lf",&w[i],&c[i]);

		for(int i=0; i<n; i++) d[i]=1;
		for(int i=0; i<n; i++)
			for(int j=0; j<i; j++)
				if(w[j]<w[i] && c[j]>c[i] && d[i]<d[j]+1) d[i]=d[j]+1;

		int ans=1;
		for(int i=0; i<n; i++) if(ans<d[i]) ans=d[i];
		printf("%d\n",ans);
	}	
	return 0;
}