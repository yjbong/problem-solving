#include <cstdio>
int d[333][333];
int w[333][333];
int main(void){

	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0; i<k; i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(w[a][b]<c) w[a][b]=c;
	}
	for(int i=0; i<=m; i++)
		for(int j=0; j<=n; j++) d[i][j]=-1;

	d[1][1]=0;
	for(int i=2; i<=m; i++)
		for(int j=2; j<=n; j++)
			for(int k=1; k<j; k++)
				if(d[i-1][k]>=0 && w[k][j]>0)
					if(d[i][j]<d[i-1][k]+w[k][j])
						d[i][j]=d[i-1][k]+w[k][j];
	
	int sol=-1;
	for(int i=2; i<=m; i++)
		if(sol<d[i][n]) sol=d[i][n];

	printf("%d\n",sol);
	return 0;
}