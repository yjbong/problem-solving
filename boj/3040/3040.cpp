#include <cstdio>
int a[9];
int main(void){
	for(int i=0; i<9; i++) scanf("%d",&a[i]);
	int sum=0;
	for(int i=0; i<9; i++) sum+=a[i];

	for(int i=0; i<9; i++){
		for(int j=i+1; j<9; j++){
			if(a[i]+a[j]==sum-100){
				for(int l=0; l<9; l++){
					if(l!=i && l!=j) printf("%d\n",a[l]);
				}
				goto out;
			}
		}
	}
out:
	return 0;
}