#include <cstdio>
int c[31]; // c[i] = i일에 준 떡의 개수
int main(void){

	int d,k;
	scanf("%d %d",&d,&k);

	c[d]=k;
	for(int i=1; i<k; i++){
		bool ok=true;
		c[d-1]=i; // (i-1)일에 준 떡이 i개라고 가정
		for(int j=d-2; j>=1; j--){
			c[j]=c[j+2]-c[j+1];
			if(c[j]>c[j+1]){ ok=false; break; }
		}
		if(ok && c[1]>0){ // 첫 날에 준 떡은 1개 이상이어야 함
			printf("%d\n%d\n",c[1],c[2]);
			break;
		}
	}
	return 0;
}