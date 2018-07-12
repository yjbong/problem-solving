#include <cstdio>
int min2(int a, int b){ return a<b?a:b; }
int max2(int a, int b){ return a>b?a:b; }
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		int l; // 막대의 길이
		int n; // 개미의 수
		scanf("%d %d",&l,&n);
		int minTime=0,maxTime=0;
		for(int i=0; i<n; i++){
			int pos;
			scanf("%d",&pos);
			if(pos>=0 && pos<=l){
				minTime=max2(minTime,min2(pos,l-pos));
				maxTime=max2(maxTime,max2(pos,l-pos));
			}
		}
		printf("%d %d\n",minTime,maxTime);
	}
	return 0;
}