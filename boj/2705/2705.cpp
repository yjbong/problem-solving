#include <cstdio>
int pal[1001]; // pal[i] = i의 재귀적인 팰린드롬 파티션의 개수

int main(void){

	pal[0]=1; pal[1]=1;
	for(int i=2; i<=1000; i++){
		pal[i]=0;
		if(i%2==0) pal[i]+=pal[i/2]; // 중앙에 위치한 수가 없는 경우
		for(int j=1; j<=i; j++){ // 중앙에 위치한 수가 j인 경우
			if((i-j)%2==0){
				pal[i]+=pal[(i-j)/2];
			}
		}
	}

	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		printf("%d\n",pal[n]);
	}
	return 0;
}