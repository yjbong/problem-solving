#include <cstdio>
int main(void){
	bool first=true;
	while(1){
		double old;
		double cur;
		scanf("%lf",&cur);
		if(cur==999.0) break;

		if(first) first=false;
		else printf("%.2lf\n",cur-old);
		old=cur;
	}	
	return 0;
}