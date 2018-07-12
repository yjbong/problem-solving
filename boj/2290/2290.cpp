#include <cstdio>
#include <cstring>
int s; // size
char n[20];
//  00
// 1  2
// 1  2
//  33
// 4  5
// 4  5
//  66
const int seg[10][7]={
	{1,1,1,0,1,1,1}, // 0
	{0,0,1,0,0,1,0}, // 1
	{1,0,1,1,1,0,1}, // 2
	{1,0,1,1,0,1,1}, // 3
	{0,1,1,1,0,1,0}, // 4
	{1,1,0,1,0,1,1}, // 5
	{1,1,0,1,1,1,1}, // 6
	{1,0,1,0,0,1,0}, // 7
	{1,1,1,1,1,1,1}, // 8
	{1,1,1,1,0,1,1} // 9
};

int main(void){
	scanf("%d %s",&s,n);

	for(int i=0; i<strlen(n); i++){
		printf(" ");
		if(seg[n[i]-'0'][0]) for(int j=0; j<s; j++) printf("-");
		else for(int j=0; j<s; j++) printf(" ");
		printf(" ");

		printf(" ");
	}
	printf("\n");

	for(int i=0; i<s; i++){
		for(int j=0; j<strlen(n); j++){
			if(seg[n[j]-'0'][1]) printf("|");
			else printf(" ");
			for(int k=0; k<s; k++) printf(" ");
			if(seg[n[j]-'0'][2]) printf("|");
			else printf(" ");

			printf(" ");
		}
		printf("\n");
	}

	for(int i=0; i<strlen(n); i++){
		printf(" ");
		if(seg[n[i]-'0'][3]) for(int j=0; j<s; j++) printf("-");
		else for(int j=0; j<s; j++) printf(" ");
		printf(" ");

		printf(" ");
	}
	printf("\n");

	for(int i=0; i<s; i++){
		for(int j=0; j<strlen(n); j++){
			if(seg[n[j]-'0'][4]) printf("|");
			else printf(" ");
			for(int k=0; k<s; k++) printf(" ");
			if(seg[n[j]-'0'][5]) printf("|");
			else printf(" ");

			printf(" ");
		}
		printf("\n");
	}
	for(int i=0; i<strlen(n); i++){
		printf(" ");
		if(seg[n[i]-'0'][6]) for(int j=0; j<s; j++) printf("-");
		else for(int j=0; j<s; j++) printf(" ");
		printf(" ");

		printf(" ");
	}
	printf("\n");
	
	return 0;
}