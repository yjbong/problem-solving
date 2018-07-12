#include <cstdio>
int a[10];
int main(void){

	for(int i=1; i<=9; i++) scanf("%d",&a[i]);
	int maxIdx=0, maxVal=a[0];
	for(int i=1; i<=9; i++){
		if(maxVal<a[i]){
			maxIdx=i;
			maxVal=a[i];
		}
	}
	printf("%d\n",maxVal);
	printf("%d\n",maxIdx);	
	return 0;
}