#include <cstdio>
#include <cstring>
#define MAX 10000

int n;
char str[MAX+1];
int As,Cs,Gs,Ts;
char ansChar;
int ansCnt;
int main(void){

	scanf("%d\n",&n);
	scanf("%s",str);
	As=Cs=Gs=Ts=0;
	for(int i=0; i<strlen(str); i++){
		if(str[i]=='A') As++;
		else if(str[i]=='C') Cs++;
		else if(str[i]=='G') Gs++;
		else if(str[i]=='T') Ts++;
	}
	
	ansChar='A'; ansCnt=As;
	if(ansCnt>Cs){ ansChar='C'; ansCnt=Cs; }
	if(ansCnt>Gs){ ansChar='G'; ansCnt=Gs; }
	if(ansCnt>Ts){ ansChar='T'; ansCnt=Ts; }

	printf("%d\n",ansCnt);
	for(int i=0; i<n; i++) printf("%c",ansChar);
	printf("\n");

	return 0;
}