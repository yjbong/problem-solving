#include <cstdio>
void print(int size, int y, int x){
	if(size==1){
		if(y==1 && x==1) printf(" ");
		else printf("*");
		return;
	}
	else{
		int gy=y/(size/3);
		int gx=x/(size/3);
		if(gy==1 && gx==1){
			printf(" ");
			return;
		}
		else{
			print(size/3, y%(size/3), x%(size/3));
		}
	}
}
int main(void){
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) print(n,i,j);
		printf("\n");
	}
	return 0;
}