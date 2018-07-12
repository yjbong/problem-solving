#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int rows,cols;
char puzzle[22][22];
char word[444][22]; int words; // word list
char tmp[22];

int main(void){

	// input
	scanf("%d %d\n",&rows,&cols);
	for(int i=0; i<rows; i++)
		gets(puzzle[i]);

	words=0;

	// horizontal words
	for(int i=0; i<rows; i++){
		int curWordLen=0;
		for(int j=0; j<cols; j++){
			if(puzzle[i][j]!='#') word[words][curWordLen++]=puzzle[i][j];
			if(puzzle[i][j]=='#' || j==cols-1){
				word[words][curWordLen]='\0';
				if(curWordLen>=2) words++;
				curWordLen=0;
			}
		}
	}

	// vertical words
	for(int j=0; j<cols; j++){
		int curWordLen=0;
		for(int i=0; i<rows; i++){
			if(puzzle[i][j]!='#') word[words][curWordLen++]=puzzle[i][j];
			if(puzzle[i][j]=='#' || i==rows-1){
				word[words][curWordLen]='\0';
				if(curWordLen>=2) words++;
				curWordLen=0;
			}
		}
	}

	// bubble sort
	for(int i=0; i<words; i++){
		for(int j=i+1; j<words; j++){
			if(strcmp(word[i],word[j])>0){
				strcpy(tmp,word[i]);
				strcpy(word[i],word[j]);
				strcpy(word[j],tmp);
			}
		}
	}

	// answer
	printf("%s\n",word[0]);
	
	return 0;
}