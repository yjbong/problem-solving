#include <cstdio>
bool isNotPrime[33333];
int main(void){

	isNotPrime[0]=isNotPrime[1]=true;
	for(int i=2; i<33333; i++)
		if(!isNotPrime[i])
			for(int j=i*2; j<33333; j+=i) isNotPrime[j]=true;	
	int N;
	scanf("%d",&N);

	int ans=N-1;
	for(int i=2; i<33333; i++){
		if(isNotPrime[i]==false && N%i==0){
			ans=N-N/i;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}