#include <cstdio>
int main(void){
	int kings,queens,rooks,bishops,knights,pawns;
	scanf("%d %d %d %d %d %d",&kings,&queens,&rooks,&bishops,&knights,&pawns);
	printf("%d %d %d %d %d %d\n",1-kings,1-queens,2-rooks,2-bishops,2-knights,8-pawns);
	return 0;
}