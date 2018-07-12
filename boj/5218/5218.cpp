#include <cstdio>
#include <cstring>
char a[22];
char b[22];
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s %s",a,b);
		printf("Distances:");
		for(int i=0; i<strlen(a); i++){
			int distance=b[i]-a[i];
			if(distance<0) distance+=26;
			printf(" %d",distance);
		}
		printf("\n");
	}
	return 0;
}