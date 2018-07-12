#include <cstdio>
int main(void){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int nextTime=(a*60+b+c)%(24*60);
	printf("%d %d\n",nextTime/60,nextTime%60);
	return 0;
}