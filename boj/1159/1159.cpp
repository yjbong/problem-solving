#include <cstdio>
#include <cstring>
int n;
char name[222][33];
int cnt[26];
int main(void){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%s",name[i]);
	for(int i=0; i<n; i++) cnt[name[i][0]-'a']++;

	bool ok=false;
	for(int i=0; i<26; i++){
		if(cnt[i]>=5){
			printf("%c",i+'a');
			ok=true;
		}
	}
	if(!ok) printf("PREDAJA");
	printf("\n");
	return 0;
}