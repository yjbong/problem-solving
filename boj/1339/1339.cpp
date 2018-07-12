#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int,int> ii;
int n;
char a[10][10];
ii num[26];
int pow[10];
int main(void){

	// precalc pow[i]=10^i
	pow[0]=1;
	for(int i=1; i<10; i++) pow[i]=pow[i-1]*10;

	// get input
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%s",a[i]);

	// calc weight of each alphabet
	for(int i=0; i<26; i++){
		num[i].first=0;
		num[i].second=i;
	}
	for(int i=0; i<n; i++)
		for(int j=0; j<strlen(a[i]); j++) num[a[i][j]-'A'].first+=pow[strlen(a[i])-1-j];
	sort(num,num+26);

	// get answer
	int ans=0;
	for(int i=25, curDgt=9; i>=0; i--){
		ans+=num[i].first*curDgt;
		if(curDgt>0) curDgt--;
	}
	printf("%d\n",ans);
	return 0;
}