#include <cstdio>
int t;
int a[7];
int main(void){
	scanf("%d",&t);
	while(t--){
		int min=101;
		int	sum=0;
		for(int i=0; i<7; i++) scanf("%d",&a[i]);
		for(int i=0; i<7; i++){
			if(a[i]%2==0){
				sum+=a[i];
				if(min>a[i]) min=a[i];
			}
		}
		printf("%d %d\n",sum,min);
	}
	return 0;
}