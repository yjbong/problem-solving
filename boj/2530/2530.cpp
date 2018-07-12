#include <cstdio>
int main(void){
	int h,m,s,time;
	scanf("%d %d %d %d",&h,&m,&s,&time);
	int curTime=h*60*60+m*60+s;
	int newTime=(curTime+time)%(24*60*60);
	int nh=newTime/(60*60);
	int nm=(newTime-nh*60*60)/60;
	int ns=newTime%60;
	printf("%d %d %d\n",nh,nm,ns);
	return 0;
}