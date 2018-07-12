#include <cstdio>
#include <cstring>
char num[20];
const int char2num[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
int main(void){
	scanf("%s",num);
	int ans=0;
	for(int i=0; i<strlen(num); i++) ans+=char2num[num[i]-'A']+1;
	printf("%d\n",ans);
	return 0;
}