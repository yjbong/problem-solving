#include <cstdio>
#include <cstring>
#include <cstdlib>
char key[11];
int keylen;
char ring[100][11];
int rings;
int main(void){
	gets(key);
	keylen=strlen(key);

	scanf("%d\n",&rings);
	for(int i=0; i<rings; i++) gets(ring[i]);
	
	int ans=0;
	for(int i=0; i<rings; i++){
		bool found=false;
		for(int j=0; j<10; j++){
			int k;
			for(k=0; k<keylen; k++)
				if(ring[i][(j+k)%10]!=key[k]) break;
			if(k==keylen){ found=true; break; }
		}
		if(found) ans++;
	}
	printf("%d\n",ans);

	return 0;
}