#include <cstdio>
#include <cstring>
#define MAX_N 50
#define MAXLEN 50
int N;
bool isValid[MAX_N];
char word[MAX_N][MAXLEN+1];

bool isSame(char a[], char b[]){
	int aLen=strlen(a);
	int bLen=strlen(b);
	if(aLen!=bLen) return false;
	for(int j=0; j<aLen; j++){
		bool ok=true;
		for(int i=0; i<aLen; i++)
			if(a[i]!=b[(i+j)%aLen]){ ok=false; break; }
		if(ok) return true;
	}
	return false;
}
int main(void){
	scanf("%d\n",&N);
	for(int i=0; i<N; i++){
		gets(word[i]);
		isValid[i]=true;
	}

	for(int i=0; i<N; i++)
		if(isValid[i])
			for(int j=i+1; j<N; j++) if(isSame(word[i],word[j])) isValid[j]=false;

	int ans=0;
	for(int i=0; i<N; i++) if(isValid[i]) ans++;
	printf("%d\n",ans);
	return 0;
}