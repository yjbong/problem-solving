#include <cstdio>
#define MOD 1000000007ll
typedef long long ll;
int n; // # of numbers
int c; // target # of confused pairs

//ll d[1001][10001]; // d[i][j] = # of sequences which have j confused pairs from number [1~i]
//ll s[1001][10001]; // s[i][j] = d[i][0]+d[i][1]+...+d[i][j]

ll d[2][10001]; // reduce memory
ll s[2][10001];

int main(void){

	scanf("%d %d",&n,&c);

	// init d
	d[1][0]=1;
	// init s
	for(int i=0; i<=c; i++) s[1][i]=1;

	// DP
	int cur=0;
	for(int i=2; i<=n; i++){
		for(int j=0; j<=(i*(i+1))/2 && j<=c; j++){
			d[cur][j] = s[1-cur][j];
			if(j-i>=0) d[cur][j]=(d[cur][j]+(MOD-s[1-cur][j-i]))%MOD;
		}

		s[cur][0]=d[cur][0];
		for(int j=1; j<=c; j++)
			s[cur][j]=(s[cur][j-1]+d[cur][j])%MOD;

		// flip cur
		cur=1-cur;
	}

	// answer
	printf("%lld\n",d[1-cur][c]);
	return 0;
}