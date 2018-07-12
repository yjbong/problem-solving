#include <cstdio>
int N;
int count[10001];
int main(void){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		int num;
		scanf("%d",&num);
		count[num]++;
	}
	for(int i=1; i<=10000; i++)
		for(int j=0; j<count[i]; j++) printf("%d\n",i);
	
	return 0;
}