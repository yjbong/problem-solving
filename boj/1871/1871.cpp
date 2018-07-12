#include <cstdio>
#include <cstdlib>

char num[10];
int main(void){

	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%s",num);
		int alpha=0;
		for(int i=0; i<=2; i++){
			alpha*=26;
			alpha+=num[i]-'A';
		}

		int digit=0;
		for(int i=4; i<=7; i++){
			digit*=10;
			digit+=num[i]-'0';
		}

		if(abs(alpha-digit)<=100) printf("nice\n");
		else printf("not nice\n");
	}
	return 0;
}