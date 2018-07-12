#include <cstdio>
int a[10];
int b[10];
int main(void){
	for(int i=0; i<10; i++) scanf("%d",&a[i]);
	for(int i=0; i<10; i++) scanf("%d",&b[i]);
	int awin=0,bwin=0;
	for(int i=0; i<10; i++){
		if(a[i]>b[i]) awin++;
		else if(a[i]<b[i]) bwin++;
	}
	if(awin>bwin) printf("A\n");
	else if(awin<bwin) printf("B\n");
	else printf("D\n");
	return 0;
}