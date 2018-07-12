#include <cstdio>
int n; // 성냥 개수
int w,h; // 박스 크기

int main(void){
	scanf("%d %d %d",&n,&w,&h);
	for(int i=0; i<n; i++){
		int l;
		scanf("%d",&l);
		if(w*w+h*h>=l*l) printf("DA\n");
		else printf("NE\n");
	}
	return 0;
}