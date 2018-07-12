#include <cstdio>
#include <cstring>

int n;
char str[10];
bool proof[128][128]; // a[i][j] = true if i-->j is true

int main(void){
	// get input
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("\n");
		gets(str);
		char from = str[0];
		char to = str[strlen(str)-1];
		proof[from][to]=true;
	}

	for(int i=0; i<128; i++) proof[i][i]=true;

	// floyd
	for(int k=0; k<128; k++)
		for(int i=0; i<128; i++)
			for(int j=0; j<128; j++)
				if(proof[i][k] && proof[k][j]) proof[i][j]=true;
	// print answer
	int ans=0;
	for(int i=0; i<128; i++)
		for(int j=0; j<128; j++)
			if(i!=j && proof[i][j]) ans++;
	printf("%d\n",ans);
	for(int i=0; i<128; i++)
		for(int j=0; j<128; j++)
			if(i!=j && proof[i][j]) printf("%c => %c\n",i,j);

	return 0;
}