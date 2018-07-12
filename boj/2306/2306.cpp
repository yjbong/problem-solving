#include <cstdio>
#include <cstring>
char a[555];
int d[555][555];
int n;
int main(void){

	scanf("%s",&a);
	n = strlen(a);

	for(int i=1; i<n; i++){
		for(int j=0; j+i<n; j++){
			if((a[j]=='a' && a[j+i]=='t') || (a[j]=='g' && a[j+i]=='c'))
				if(d[j][j+i]<d[j+1][j+i-1]+2) d[j][j+i]=d[j+1][j+i-1]+2;
			
			for(int k=j; k<j+i; k++)
				if(d[j][j+i]<d[j][k]+d[k+1][j+i])
					d[j][j+i]=d[j][k]+d[k+1][j+i];
			
		}
	}
	printf("%d\n",d[0][n-1]);
	return 0;
}