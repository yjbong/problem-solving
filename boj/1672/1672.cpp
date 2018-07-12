#include <cstdio>
char a[1000001];
char f[128][128];
int main(void){
	f['A']['A']='A'; f['A']['G']='C'; f['A']['C']='A'; f['A']['T']='G';
	f['G']['A']='C'; f['G']['G']='G'; f['G']['C']='T'; f['G']['T']='A';
	f['C']['A']='A'; f['C']['G']='T'; f['C']['C']='C'; f['C']['T']='G';
	f['T']['A']='G'; f['T']['G']='A'; f['T']['C']='G'; f['T']['T']='T';
	int n;
	scanf("%d",&n);
	scanf("%s",a);
	for(int i=n-1; i>=1; i--) a[i-1]=f[a[i-1]][a[i]];
	printf("%c\n",a[0]);
	return 0;
}