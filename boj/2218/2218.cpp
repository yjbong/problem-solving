#include <cstdio>
int sc[1001][1001];
int a[1001];
int b[1001];

int d[1001][1001];
int t[1001][1001];
int n,as,bs;
int sol[2222];
int sols;

int max(int a, int b){
	if(a>b) return a;
	else return b;
}
int main(void){
	
	scanf("%d %d %d",&n,&as,&bs);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) scanf("%d",&sc[i][j]);

	for(int i=1; i<=as; i++) scanf("%d",&a[i]);
	for(int i=1; i<=bs; i++) scanf("%d",&b[i]);

	for(int i=0; i<=as; i++){
		d[i][0]=0;
		t[i][0]=1;
	}
	for(int j=0; j<=bs; j++){
		d[0][j]=0;
		t[0][j]=2;
	}

	for(int i=1; i<=as; i++){
		for(int j=1; j<=bs; j++){

			int s1=d[i-1][j];
			int s2=d[i][j-1];
			int s3=d[i-1][j-1]+sc[a[i]][b[j]];

			d[i][j]=max(max(s1,s2),s3);

			if(d[i][j]==s1) t[i][j]=1;
			else if(d[i][j]==s2) t[i][j]=2;
			else if(d[i][j]==s3) t[i][j]=3;
		}
	}
	
	printf("%d\n",d[as][bs]);
	
	int ca=as;
	int cb=bs;
	sols=0;

	while(ca>0 || cb>0){
		if(t[ca][cb]==1){
			sol[sols++]=1;
			ca--;
		}
		else if(t[ca][cb]==2){
			sol[sols++]=2;
			cb--;
		}
		else if(t[ca][cb]==3){
			sol[sols++]=3;
			ca--; cb--;
		}
	}

	for(int i=sols-1; i>=0; i--) printf("%d ",sol[i]);
	printf("\n");

	return 0;
}