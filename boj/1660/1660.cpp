#include <stdio.h>
#define INF 2147483647
int l[150];
int f[300001];
int main(void){

	int i,j,ls,cur,n;
	scanf("%d",&n);

	for(i=0; i<=n; i++) f[i]=INF;
	l[0]=0;
	for(i=1; ; i++){
		cur=l[i-1]+i*(i+1)/2;
		if(cur>n) break;
		l[i]=cur;
		f[cur]=1;
	}
	ls=i;
	for(i=0; i<=n; i++){
		if(f[i]!=INF){
			for(j=1; j<ls; j++){
				cur=i+l[j];
				if(cur>n) break;
				else if(f[cur]>f[i]+1) f[cur]=f[i]+1;
			}
		}
	}

	printf("%d\n",f[n]);
	return 0;
}