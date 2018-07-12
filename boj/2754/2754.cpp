#include <cstdio>
int main(void){
	char s[3];
	scanf("%s",s);
	double score;
	if(s[0]=='A') score=4;	
	else if(s[0]=='B') score=3;
	else if(s[0]=='C') score=2;
	else if(s[0]=='D') score=1;
	else score=0;

	if(score>0){
		if(s[1]=='+') score+=0.3;
		else if(s[1]=='-') score-=0.3;
	}
	printf("%.1lf\n",score);	
	return 0;
}