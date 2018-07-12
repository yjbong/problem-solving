#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct{
	int l; //left
	int h; //height
}POLE;

bool cmp(POLE a, POLE b){
	if(a.h>b.h) return true;
	else return false;
}

int n;
int h[1111];
POLE p[1111];

int main(void){

	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d %d",&p[i].l,&p[i].h);

	sort(p,p+n,cmp);

	h[p[0].l]=p[0].h;
	for(int i=1; i<n; i++){
		if(p[i].l < p[i-1].l){
			for(int j=p[i].l; j<p[i-1].l; j++){
				if(h[j]<p[i].h) h[j]=p[i].h;
				else break;
			}
		}
		else{
			for(int j=p[i].l; j>p[i-1].l; j--){
				if(h[j]<p[i].h) h[j]=p[i].h;
				else break;
			}
		}
	}
	
	int sol=0;
	for(int i=0; i<1111; i++) sol+=h[i];
	printf("%d\n",sol);
	return 0;
}