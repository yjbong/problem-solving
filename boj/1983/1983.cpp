#include <cstdio>
#define MINF -1000000000
int a[444];
int b[444];
int as,bs;
int d[444][444][444];
int max(int a, int b){
	if(a>b) return a;
	else return b;
}
int main(void){
	
	int n;
	scanf("%d",&n);
	as=1;
	for(int i=0; i<n; i++){
		int t;
		scanf("%d",&t);
		if(t!=0) a[as++]=t;
	}

	bs=1;
	for(int i=0; i<n; i++){
		int t;
		scanf("%d",&t);
		if(t!=0) b[bs++]=t;
	}
	as--; bs--;
	
	for(int i=0; i<=as; i++){
		for(int k=0; k<=n; k++){
			if(max(i,0) > k) d[i][0][k]=MINF;
			else d[i][0][k]=0;
		}
	}

	for(int j=0; j<=bs; j++){
		for(int k=0; k<=n; k++){
			if(max(0,j) > k) d[0][j][k]=MINF;
			else d[0][j][k]=0;
		}
	}

	for(int i=1; i<=as; i++){
		for(int j=1; j<=bs; j++){
			for(int k=1; k<=n; k++){
				if(max(i,j) > k) d[i][j][k]=MINF;
				else d[i][j][k]=max(max(d[i][j-1][k-1],d[i-1][j][k-1]),d[i-1][j-1][k-1]+a[i]*b[j]);
			}
		}
	}
	
	int sol;
	bool first=true;
	for(int k=max(as,bs); k<=n; k++){
		if(first){
			sol=d[as][bs][k];
			first=false;
		}
		else if(sol<d[as][bs][k]) sol=d[as][bs][k];
	}
	printf("%d\n",sol);
	return 0;
}