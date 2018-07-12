#include <cstdio>
#include <cstring>
char num[111];
int base;
int main(void){
	scanf("%s",num);
	scanf("%d",&base);
	int ans=0;
	for(int i=0; i<strlen(num); i++){
		ans*=base;
		if(num[i]>='A' && num[i]<='Z') ans+=num[i]-'A'+10;
		else ans+=num[i]-'0';	
	}
	printf("%d\n",ans);
	return 0;
}