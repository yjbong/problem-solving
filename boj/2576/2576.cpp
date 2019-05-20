#include <cstdio>
int a[7];
int main() {
	for(int i=0; i<7; i++) scanf("%d",&a[i]);
	bool ok=false;
	int sum=0;
	int min=100000000;
	for(int i=0; i<7; i++){
		if(a[i]%2){
			ok=true;
			sum+=a[i];
			if(min>a[i]) min=a[i];
		}
	}
	if(ok) printf("%d\n%d\n",sum,min);
	else printf("-1\n");
	return 0;
}