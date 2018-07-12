#include <cstdio>
#include <cstring>
char a[1002]; // a[i] = 문자열 a의 i번째 글자 (i=1부터)
char b[1002]; // b[i] = 문자열 b의 i번째 글자 (i=1부터)
int d[1001][1001]; // d[i][j] = 부분문자열 a[1~i]와 b[1~j] 의 LCS 길이
int t[1001][1001]; // t[i][j] = trace for d[i][j] (0-->t[i-1][j], 1-->t[i][j-1], 2-->t[i-1][j-1])
int max2(int a, int b){ return a>b?a:b; }
char lcs[1002];
int lcslen;
int main(void){
	scanf("%s",a+1);
	scanf("%s",b+1);
	int alen=strlen(a+1);
	int blen=strlen(b+1);
	for(int i=1; i<=alen; i++){
		for(int j=1; j<=blen; j++){
			if(d[i][j]<d[i-1][j]){ d[i][j]=d[i-1][j]; t[i][j]=0; }
			if(d[i][j]<d[i][j-1]){ d[i][j]=d[i][j-1]; t[i][j]=1; }
			if(a[i]==b[j] && d[i][j]<d[i-1][j-1]+1){ d[i][j]=d[i-1][j-1]+1; t[i][j]=2; }
		}
	}
	printf("%d\n",d[alen][blen]);

	int i=alen, j=blen;
	lcslen=0;
	while(i>0 && j>0){
		if(t[i][j]==0) i--;
		else if(t[i][j]==1) j--;
		else if(t[i][j]==2){
			lcs[++lcslen]=a[i];
			i--, j--;
		}
	}
	for(int i=lcslen; i>=1; i--) printf("%c",lcs[i]);
	printf("\n");
	return 0;
}