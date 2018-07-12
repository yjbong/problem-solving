#include <cstdio>
int r[42]; // 42로 나눈 나머지의 빈도
int main(void){
	for(int i=0; i<10; i++){
		int num;
		scanf("%d",&num);
		r[num%42]++;
	}
	int ans=0;
	for(int i=0; i<42; i++) if(r[i]>0) ans++;
	printf("%d\n",ans);
	return 0;
}