#include <cstdio>
#include <cstdlib>
#include <cstring>
char a[1001];
char b[1001];
int d[1001][1001];
int max2(int a, int b){ return a>b?a:b; }
int main(void){
	gets(a);
	gets(b);
	int alen=strlen(a);	
	int blen=strlen(b);
	for(int i=1; i<=alen; i++){
		for(int j=1; j<=blen; j++){
			if(a[i-1]==b[j-1]) d[i][j]=d[i-1][j-1]+1;
			else d[i][j]=max2(d[i][j-1], d[i-1][j]);
		}
	}
	int ans=alen+blen-d[alen][blen];
	printf("%d\n",ans);
	return 0;
}