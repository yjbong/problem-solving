#include <cstdio>
bool ok[33];
int main(void){
	for(int i=0; i<28; i++){
		int num;
		scanf("%d",&num);
		ok[num]=true;
	}
	for(int i=1; i<=30; i++) if(!ok[i]) printf("%d\n",i);
	return 0;
}