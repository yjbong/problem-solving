#include <cstdio>
#include <cstring>
char a[1002]; // a[i] = 문자열 a의 i번째 글자 (i=1부터)
char b[1002]; // b[i] = 문자열 b의 i번째 글자 (i=1부터)
int d[1001][1001]; // d[i][j] = 부분문자열 a[1~i]와 b[1~j] 의 LCS 길이
int max2(int a, int b){ return a>b?a:b; }
int main(void){
	scanf("%s",a+1);
	scanf("%s",b+1);
	int alen=strlen(a+1);
	int blen=strlen(b+1);
	for(int i=1; i<=alen; i++){
		for(int j=1; j<=blen; j++){
			d[i][j]=max2(d[i-1][j],d[i][j-1]);
			if(a[i]==b[j]) d[i][j]=max2(d[i][j],d[i-1][j-1]+1);
		}
	}
	printf("%d\n",d[alen][blen]);
	return 0;
}