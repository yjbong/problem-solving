#include <cstdio>
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		int candies,sons;
		scanf("%d %d",&candies,&sons);
		printf("You get %d piece(s) and your dad gets %d piece(s).\n", candies/sons, candies%sons);
	}
	return 0;
}