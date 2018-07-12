#include <cstdio>
#include <cstring>
char str[11111];
char tmp[11111];

int main(void){

	str[0]='\0';
	while(gets(tmp)!=NULL) strcat(str,tmp);		

	int num=0,sum=0;
	int len=strlen(str);
	for(int i=0; i<len; i++){
		if(str[i]==','){
			sum+=num;
			num=0;
		}
		else{
			num*=10;
			num+=str[i]-'0';
		}
	}
	sum+=num;
	printf("%d\n",sum);
	return 0;
}