#include <cstdio>
int main(void){
	int one,two,three,four,five,six;
	scanf("%d %d",&one,&two);
	three=one*(two%10);
	four=one*((two%100)/10);
	five=one*(two/100);
	six=three+four*10+five*100;
	printf("%d\n",three);
	printf("%d\n",four);
	printf("%d\n",five);
	printf("%d\n",six);
	return 0;
}