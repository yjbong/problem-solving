#include <cstdio>
#include <set>
#define MOD 10000003
using namespace std;
int n; // 수열의 크기
int s[101]; // s[i] = 수열의 i번째 수
int d[101][100001]; // d[i] = 수열 s[1]~s[i] 로부터 수들을 선택하였을 때, 선택한 수들의 최대공약수가 j인 경우의 수
int gcd(int p, int q){
    if (q==0) return p;
    return gcd(q, p%q);
}
set <int> gcdList[101]; // gcdList[i] = 수열 s[1]~s[i] 에서 수들을 선택했을 때 가능한 gcd의 목록

int main(void){

	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&s[i]);

    // 가능한 gcd 목록 구하기
	for(int i=1; i<=n; i++) gcdList[i].insert(s[i]);

	for(int i=1; i<=n; i++){
		set<int>::iterator it;
		for(it=gcdList[i-1].begin(); it!=gcdList[i-1].end(); it++){
			gcdList[i].insert(*it);
			gcdList[i].insert(gcd(*it,s[i]));
		}
	}	

	// DP
	d[0][0]=1;
	for(int i=1; i<=n; i++) d[i][s[i]]=1;

	for(int i=1; i<=n; i++){
		set<int>::iterator it0;
		for(it0=gcdList[i].begin(); it0!=gcdList[i].end(); it0++){
			int j=*it0;
			d[i][j]=(d[i][j]+d[i-1][j])%MOD;

			set<int>::iterator it1;
			for(it1=gcdList[i-1].begin(); it1!=gcdList[i-1].end(); it1++){
				int k=*it1;
				if(gcd(k,s[i])==j) d[i][j]=(d[i][j]+d[i-1][k])%MOD;
			}
		}
	}

	printf("%d\n",d[n][1]);
	return 0;
}