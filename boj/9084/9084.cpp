#include <cstdio>
int t;
int n;
int m;
int c[21]; // c[i] = i번째 동전의 가치
int cs; // 동전의 가짓수
int d[21][10001]; // d[i][j] = 1~i번 종류의 동전들로 j원을 만드는 방법의 수

int main(void){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);

		cs=1;
		for(int i=1; i<=n; i++){
			scanf("%d",&c[cs]);
			if(!(cs>1 && c[cs-1]==c[cs])) cs++;
		}
		cs--;
		
		scanf("%d",&m);

		for(int i=0; i<=cs; i++)
			for(int j=0; j<=m; j++) d[i][j]=0;

		d[0][0]=1;
		for(int i=1; i<=cs; i++)
			for(int j=0; j<=m; j++)
				for(int k=0; k*c[i]<=j; k++)
					d[i][j]+=d[i-1][j-k*c[i]];

		printf("%d\n",d[cs][m]);
	}		
	return 0;
}