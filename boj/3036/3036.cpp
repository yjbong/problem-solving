#include <cstdio>
int n; // 링의 개수
int r[100]; // r[i] = i번 링의 반지름

int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int main(void){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&r[i]);
	for(int i=1; i<n; i++) printf("%d/%d\n",r[0]/gcd(r[0],r[i]),r[i]/gcd(r[0],r[i]));
	return 0;
}