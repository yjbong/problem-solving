#include <cstdio>
int n;
int s[11][11];
int sol[11];
bool sol_found;

void go(int level){
	
	if(sol_found) return;

	bool ok;
	for(int i=(-10); i<=10; i++){

		if(sol_found) return;

		ok=true;
		sol[level]=i;

		for(int j=0; j<=level; j++){
			for(int k=j; k<=level; k++){

				int sum=0;
				for(int l=j; l<=k; l++) sum+=sol[l];
			
				if(sum==0){
					if(s[j][k]!=0){
						ok=false;
						goto out;
					}
				}
				else if(sum*s[j][k]<=0){
					ok=false;
					goto out;
				}
			}
		}

out:

		if(ok){
			if(level>=(n-1)){
				sol_found=true;
				return;
			}
			else go(level+1);
		}
	}
}

int main(void){
	
	scanf("%d\n",&n);
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			char c;
			scanf("%c",&c);
			if(c=='-') s[i][j]=-1;
			else if(c=='+') s[i][j]=1;
			else s[i][j]=0;
		}
	}

	sol_found=false;
	go(0);
	
	if(sol_found){
		for(int i=0; i<n; i++) printf("%d ",sol[i]);
		printf("\n");
	}
	return 0;
}