#include <stdio.h>
#define INF 2147483647
int sq[316];
int sol[100001];
int main(void){

	int i,j,n,sqs=0;

	//freopen("input1.txt", "r", stdin);

	for(i=0; i<=100000; i++) sol[i]=INF;
	for(i=1; i*i<=100000; i++){
		sq[sqs++]=i*i;
		sol[i*i]=1;
	}

	for(i=1; i<=100000; i++){
		if(sol[i]!=INF){
			for(j=0; j<sqs && i+sq[j]<=100000; j++){
				if(sol[i+sq[j]]>sol[i]+1) sol[i+sq[j]]=sol[i]+1;
			}
		}
	}

	scanf("%d",&n);
	printf("%d\n",sol[n]);
	return 0;
}