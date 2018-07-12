#include <cstdio>
#define MAX_N 1000000
int N;
int a[MAX_N+1];
bool isNotPrime[MAX_N+100000];
int main(void){
	scanf("%d",&N);
	for(int i=1; i<=N; i++) scanf("%d",&a[i]);

	bool ok=true;
	for(int i=1; i<=N; i++) if(a[i]==i){ ok=false; break; }

	// 넣었을 때 제자리로 돌아오는 경우가 하나라도 있으면 잭팟은 불가능
	if(!ok) printf("-1\n");
	// 그렇지 않은 경우, N보다 큰 소수(prime)가 답이 될 수 있음
	// proof --> https://en.m.wikipedia.org/wiki/Pseudoforest#Graphs_of_functions
	else{
		isNotPrime[0]=isNotPrime[1]=true;
		for(int i=2; i<N+100000; i++)
			if(isNotPrime[i]==false)
				for(int j=i*2; j<N+100000; j+=i) isNotPrime[j]=true;

		for(int i=N+1; i<N+100000; i++)
			if(isNotPrime[i]==false){ printf("%d\n", i); break; }
	}
	return 0;
}