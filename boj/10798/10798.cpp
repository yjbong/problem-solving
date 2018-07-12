#include <cstdio>
#include <cstring>
char line[5][16];

int main(void){
	for(int i=0; i<5; i++) gets(line[i]);

	int maxLen=0;
	for(int i=0; i<5; i++)
		if(maxLen<strlen(line[i])) maxLen=strlen(line[i]);

	for(int i=0; i<maxLen; i++)
		for(int j=0; j<5; j++)
			if(i<strlen(line[j])) printf("%c",line[j][i]);
	printf("\n");
			
	return 0;
}