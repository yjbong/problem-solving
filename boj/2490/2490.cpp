#include <cstdio>
int a[4];
int main(void){
	for(int i=0; i<3; i++){
		for(int j=0; j<4; j++) scanf("%d",&a[j]);
		int cnt=0;
		for(int j=0; j<4; j++) if(!a[j]) cnt++;

		if(cnt==1) printf("A\n");
		else if(cnt==2) printf("B\n");
		else if(cnt==3) printf("C\n");
		else if(cnt==4) printf("D\n");
		else if(cnt==0) printf("E\n");
	}
	return 0;
}