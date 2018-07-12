#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[111];
int main(void){
	while(gets(s)!=NULL){
		int lower=0, upper=0, number=0, space=0;
		for(int i=0; i<strlen(s); i++){
			if(s[i]>='a' && s[i]<='z') lower++;
			else if(s[i]>='A' && s[i]<='Z') upper++;
			else if(s[i]>='0' && s[i]<='9') number++;
			else space++;
		}
		printf("%d %d %d %d\n",lower,upper,number,space);
	}
	return 0;
}