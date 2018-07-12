#include <cstdio>
int main(void){
	int month,day;
	scanf("%d %d",&month,&day);
	if(month<2) printf("Before\n");
	else if(month>2) printf("After\n");
	else{
		if(day<18) printf("Before\n");
		else if(day>18) printf("After\n");
		else printf("Special\n");
	}
	return 0;
}