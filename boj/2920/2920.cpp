#include <cstdio>
int a[8];
int main(void){
	for(int i=0; i<8; i++) scanf("%d",&a[i]);
	bool inc,dec;
	inc=dec=true;
	for(int i=0; i<8; i++) if(a[i]!=i+1) inc=false;
	for(int i=0; i<8; i++) if(a[i]!=8-i) dec=false;
	if(inc) printf("ascending\n");
	else if(dec) printf("descending\n");
	else printf("mixed\n");
	return 0;
}