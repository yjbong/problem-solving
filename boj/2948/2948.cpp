#include <cstdio>

const int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int main(void){
	int M,D;
	scanf("%d %d",&D,&M);

	int idx=0;
	for(int i=0; i<M-1; i++) idx+=days[i];
	idx+=D-1;

	// Thursday=0, Friday=1, ... , Wednesday=6
	switch(idx%7){
		case 0: printf("Thursday\n"); break;
		case 1: printf("Friday\n"); break;
		case 2: printf("Saturday\n"); break;
		case 3: printf("Sunday\n"); break;
		case 4: printf("Monday\n"); break;
		case 5: printf("Tuesday\n"); break;
		case 6: printf("Wednesday\n"); break;
	}
	
	return 0;	
}