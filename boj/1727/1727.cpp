#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define INF 1000000000000000ll
ll a[1001]; int as;
ll b[1001]; int bs;
ll d[1001][1001];

ll abs2(ll a){
	if(a<0) return (-a);
	else return a;
}

int main(void){

	int i,j;

	scanf("%d %d",&as,&bs);
	if(as>bs){
		int t;
		t=as; as=bs; bs=t;
		for(i=1; i<=bs; i++) scanf("%lld",&b[i]);
		for(i=1; i<=as; i++) scanf("%lld",&a[i]);
	}
	else{			   
		for(i=1; i<=as; i++) scanf("%lld",&a[i]);
		for(i=1; i<=bs; i++) scanf("%lld",&b[i]);
	}

	sort(a+1,a+as+1);
	sort(b+1,b+bs+1);

	for(i=0; i<=as; i++)
		for(j=0; j<=bs; j++) d[i][j]=INF;
		
	for(i=1; i<=bs; i++)
		for(j=1; j<=i; j++)
			if(d[1][i]>abs2(a[1]-b[j])) d[1][i]=abs2(a[1]-b[j]);
		
	for(i=2; i<=as; i++){
		for(j=i; j<=bs; j++){
			if(d[i][j]>d[i][j-1] ) d[i][j]=d[i][j-1];
			if(d[i][j]>d[i-1][j-1]+abs2(a[i]-b[j])) d[i][j]=d[i-1][j-1]+abs2(a[i]-b[j]);
		}
	}		
	printf("%lld\n",d[as][bs]);
	return 0;
}