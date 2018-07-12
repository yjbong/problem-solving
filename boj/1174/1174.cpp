#include <cstdio>
int d[11][11]; // d[i][j] = # of decreasing number of length i whose first digit is j
int s[11][11]; // s[i][j] = d[i][0]+d[i][1]+...+d[i][j]

int main(void){

	// init base case (length 1)
	for(int j=0; j<=9; j++) d[1][j]=1;

	// calc d
	for(int i=2; i<=10; i++)
		for(int j=0; j<=9; j++)
			for(int k=0; k<j; k++) d[i][j]+=d[i-1][k];

	// calc s
	for(int i=1; i<=10; i++){
		s[i][0]=d[i][0];
		for(int j=1; j<=9; j++)
			s[i][j]=s[i][j-1]+d[i][j];
	}

	// find n-th decreasing number
	int n;
	scanf("%d",&n);
	bool ok=false;
	for(int i=1; i<=10; i++){
		if(s[i][9]<n) n-=s[i][9];
		else{
			ok=true;
			int j=i;
			for(int j=i; j>=1; j--){
				for(int k=0; k<=9; k++){
					if(s[j][k]>=n){
						printf("%d",k);
						if(k>0) n-=s[j][k-1];
						break;
					}
				}
				
			}
			break;
		}
	}
	if(!ok) printf("-1");
	printf("\n");

	return 0;
}