#include <cstdio>
int main(void){
	int burger[3];
	for(int i=0; i<3; i++) scanf("%d",&burger[i]);
	int drink[2];
	for(int i=0; i<2; i++) scanf("%d",&drink[i]);

	int cheapBurger=burger[0];
	for(int i=1; i<3; i++) if(cheapBurger>burger[i]) cheapBurger=burger[i];
	int cheapDrink=drink[0];
	for(int i=1; i<2; i++) if(cheapDrink>drink[i]) cheapDrink=drink[i];
	printf("%d\n",cheapBurger+cheapDrink-50);
	return 0;
}