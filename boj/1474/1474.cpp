#include <stdio.h>
#include <string.h>
int n; // 단어의 개수
int m; // 새로운 단어의 길이

// 사전 순으로 앞인 순서 : 'A'~'Z', '_' , 'a'~'z'

char word[111][2222];
int spaces[111]; // spaces[i] = word[i]와 word[i+1] 사이에 출력할 밑줄의 수

int main(void){
	int totWordLen;
	scanf("%d %d",&n,&m);
	totWordLen=0;
	for(int i=0; i<n; i++){
		scanf("%s",word[i]);
		totWordLen+=strlen(word[i]);
	}

	int totSpaces=m-totWordLen;

	// 일단 밑줄을 단어 사이에 균등하게 분배 (단어가 n개면 구간은 n-1개)
	for(int i=0; i<n-1; i++) spaces[i]=totSpaces/(n-1);
	totSpaces%=(n-1);

	// 남은 밑줄을 앞쪽에서부터 소문자로 시작하는 단어의 앞쪽 구간에 1개씩 최대한 분배
	for(int i=0; i<n-1; i++){
		if(word[i+1][0]>='a' && word[i+1][0]<='z'){
			if(totSpaces>0){
				spaces[i]++;
				totSpaces--;
			}
		}
	}
	// 남은 밑줄을 뒤쪽에서부터 대문자로 시작하는 단어의 앞쪽 구간에 1개씩 최대한 분배
	for(int i=n-2; i>=0; i--){
		if(word[i+1][0]>='A' && word[i+1][0]<='Z'){
			if(totSpaces>0){
				spaces[i]++;
				totSpaces--;
			}
		}
	}

	// 답 출력
	for(int i=0; i<n-1; i++){
		printf("%s",word[i]);
		for(int j=0; j<spaces[i]; j++) printf("_");
	}
	printf("%s\n",word[n-1]);
	
	return 0;
}