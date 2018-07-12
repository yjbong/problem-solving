#include <cstdio>
int main(void){
	int t;
	int bags=0;
	scanf("%d",&t);
	while(t--){
		double length,width,depth,weight;
		scanf("%lf %lf %lf %lf",&length,&width,&depth,&weight);
		if(((length<=56 && width<=45 && depth<=25) || length+width+depth<=125) && weight<=7){
			printf("1\n");
			bags++;
		}
		else{
			printf("0\n");
		}
	}
	printf("%d\n",bags);
	return 0;
}