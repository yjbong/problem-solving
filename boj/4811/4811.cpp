#include <cstdio>
typedef long long ll;
ll d[33][66]; // cache

ll go(int w, int h){
	if(d[w][h]>=0) return d[w][h];
	if(w==0 && h==1) return (d[w][h]=1);
	else{
		ll ret=0;
		if(w>0) ret+=go(w-1,h+1);
		if(h>0) ret+=go(w,h-1);
		return (d[w][h]=ret);
	}
}
int main(void){
	for(int i=0; i<33; i++)
	for(int j=0; j<66; j++)
		d[i][j]=-1;
	while(1){
		int n;
		scanf("%d",&n);
		if(n==0) break;
		printf("%lld\n", go(n,0));
	}
	return 0;
}