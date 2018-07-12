#include <cstdio>
#include <cstring>
char s[41];
int ans[8];
int main(void){
	int p;
	scanf("%d",&p);
	while(p--){
		scanf("%s",s);
		for(int i=0; i<8; i++) ans[i]=0;
		for(int i=2; i<strlen(s); i++){
			int idx=0;
			for(int j=i-2; j<=i; j++){
				idx*=2;
				if(s[j]=='H') idx++;
			}
			ans[idx]++;
		}
		for(int i=0; i<8; i++) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}