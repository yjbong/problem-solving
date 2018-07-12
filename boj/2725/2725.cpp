#include <cstdio>

int d[1111]; // d[i] = i*i 크기에서 보이는 점의 개수

int gcd(int a, int b){
	if(b==0) return a;
	else return gcd(b, a%b);
}

int main(void){

	// precalc
	d[0]=0; d[1]=3;
	for(int i=2; i<=1000; i++){
		d[i]=d[i-1];
		for(int j=1; j<i; j++) if(gcd(j,i)==1) d[i]+=2;
	}

	int c;
	scanf("%d",&c);
	while(c--){
		int n;
		scanf("%d",&n);
		printf("%d\n",d[n]);
	}
	return 0;
}