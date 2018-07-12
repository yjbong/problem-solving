#include <cstdio>
typedef long long ll;
int N; // board size (N*N)
int L; // target palindrome path length
int a[22][22]; // board

// direction array
const int dy[8]={-1,-1,-1, 0, 0, 1, 1, 1};
const int dx[8]={-1, 0, 1,-1, 1,-1, 0, 1};

ll d[21][21][21][21][21]; // d[i][j][k][l][m] = # of length i palindrome path with starting point (j,k), ending point(l,m)

int max2(int a, int b){ return a>b?a:b; }
int min2(int a, int b){ return a<b?a:b; }

int main(void){

	// get input
	scanf("%d %d",&N,&L);

	for(int i=0; i<=N+1; i++) a[i][0]=a[i][N+1]=-1;
	for(int i=0; i<=N+1; i++) a[0][i]=a[N+1][i]=-1;

	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			scanf("%d",&a[i][j]);

	// init every element in d array to impossible
	for(int i=0; i<=L; i++)
	for(int j=0; j<=N; j++)
	for(int k=0; k<=N; k++)
	for(int l=0; l<=N; l++)
	for(int m=0; m<=N; m++)
		d[i][j][k][l][m] = -1; // negative number --> impossible

	// init base case (path length is 1)
	for(int j=1; j<=N; j++)
	for(int k=1; k<=N; k++)
		d[1][j][k][j][k] = 1; // for length 1, starting and ending point should be same
	
	// init base case (path length is 2)
	if(L>1){
		for(int j=1; j<=N; j++)
		for(int k=1; k<=N; k++)
		for(int l=max2(1,j-1); l<=min2(N,j+1); l++)
		for(int m=max2(1,k-1); m<=min2(N,k+1); m++)
			if((j!=l || k!=m) && a[j][k]==a[l][m]) d[2][j][k][l][m]=1;
	}

	// DP (path length is greater than 2)
	for(int i=3; i<=L; i++){
		for(int j=1; j<=N; j++)
		for(int k=1; k<=N; k++)
		for(int l=max2(1,j-(i-1)); l<=min2(N,j+(i-1)); l++)
		for(int m=max2(1,k-(i-1)); m<=min2(N,k+(i-1)); m++){
			if(a[j][k]==a[l][m]){ // board value of starting point and ending point should be same
				for(int n=0; n<8; n++)
				for(int o=0; o<8; o++){
					// try to add (j,k) as starting and (l,m) as ending point to the palindrome path (cY0, cX0), ... , (cY1, cX1)
					int cY0=j+dy[n], cX0=k+dx[n];
					int cY1=l+dy[o], cX1=m+dx[o];

					if(a[cY0][cX0]<0 || a[cY1][cX1]<0) continue; // out of board boundary
	
					if(d[i-2][cY0][cX0][cY1][cX1]>=0){ // valid updating condition
						if(d[i][j][k][l][m]<0) d[i][j][k][l][m] = d[i-2][cY0][cX0][cY1][cX1];
						else d[i][j][k][l][m] += d[i-2][cY0][cX0][cY1][cX1];
					}
				}
			}
		}
	}

	// get answer
	ll ans=0;
	for(int j=1; j<=N; j++)
	for(int k=1; k<=N; k++)
	for(int l=1; l<=N; l++)
	for(int m=1; m<=N; m++)
		if(d[L][j][k][l][m]>=0) ans+=d[L][j][k][l][m];

	printf("%lld\n",ans);
	return 0;
}