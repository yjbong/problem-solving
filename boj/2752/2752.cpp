#include <cstdio>
int main(void){
	int a[3],t;
	for(int i=0; i<3; i++) scanf("%d",&a[i]);
	for(int i=0; i<3; i++)
	for(int j=i+1; j<3; j++)
		if(a[i]>a[j]){
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	
	for(int i=0; i<3; i++) printf("%d ",a[i]);
	printf("\n");
	return 0;
}