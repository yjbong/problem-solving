#include <cstdio>

int d[1000001]; // d[j] = maximum profit with money j at i-th day (for i-th iteration)
int p[10][50]; // p[i][j] : j-th stock price of i-th day (0<=i<d, 0<=j<n)
int stocks; // # of kinds of stock
int days; // # of days
int money; // initial money
int max2(int a, int b){ return a>b?a:b; }
int main(void){

	scanf("%d %d %d",&stocks,&days,&money);

	for(int j=0; j<stocks; j++)
		for(int i=0; i<days; i++) scanf("%d",&p[i][j]);

	// DP
	for(int i=0; i<days-1; i++){
		for(int j=0; j<=money; j++){
			d[j]=0;
			for(int k=0; k<stocks; k++)
				if(j>=p[i][k]) d[j]=max2(d[j],d[j-p[i][k]]+p[i+1][k]-p[i][k]);
		}
		money = money + d[money]; // update money with maximum possible profit of day
	}
	printf("%d\n",money);
	return 0;
}