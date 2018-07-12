#include <cstdio>
#include <cstring>
char str[55];
int main(void){
	gets(str);

	int ball[3]={1,0,0};
	for(int i=0; i<strlen(str); i++){
		int tmp;
		if(str[i]=='A'){
			tmp=ball[0];
			ball[0]=ball[1];
			ball[1]=tmp;
		}
		else if(str[i]=='B'){
			tmp=ball[1];
			ball[1]=ball[2];
			ball[2]=tmp;
		}
		else if(str[i]=='C'){
			tmp=ball[0];
			ball[0]=ball[2];
			ball[2]=tmp;
		}
	}
	for(int i=0; i<3; i++){
		if(ball[i]){ printf("%d\n",i+1); break; }
	}
	return 0;
}