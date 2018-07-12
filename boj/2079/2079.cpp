#include <cstdio>
#include <cstring>

char s[3001];
bool c[3000][3000];
int d[3000];
int main(void){

	scanf("%s",s);
	int l=strlen(s);
	for(int i=0; i<l; i++) c[i][i]=true;
	for(int i=0; i<l-1; i++){
		if(s[i]==s[i+1]) c[i][i+1]=true;
		else c[i][i+1]=false;
	}
	for(int j=2; j<l; j++){
		for(int i=0; i<l-j; i++){
			if(c[i+1][i+j-1] && s[i]==s[i+j]) c[i][i+j]=true;
			else c[i][i+j]=false;
		}
	}
	for(int i=0; i<l; i++){
		if(c[0][i]) d[i]=1;
		else{
			d[i]=i+1;
			for(int j=0; j<i; j++)
				if(c[j+1][i] && d[i]>d[j]+1) d[i]=d[j]+1;
		}
	}
	printf("%d\n",d[l-1]);
	return 0;
}