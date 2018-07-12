#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
ll N;
vector <ll> prime; // 32000 미만인 소수 목록
bool isNotPrime[32000];

vector <ll> elem[10]; // elem[0] = N의 서로 다른 소인수 목록
	                  // elem[1] = elem[0]에서 임의의 2개의 수에 대한 최소공배수 목록
		              // elem[2] = elem[0]에서 임의의 3개의 수에 대한 최소공배수 목록
		              // ...
		              // elem[elem[0].size()-1] = elem[0]에서 임의의 elem[0].size()개의 수에 대한 최소공배수 목록

ll gcd(ll a, ll b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
ll lcm(ll a, ll b){
	return a*b/gcd(a,b);
}

bool picked[10];
void combination(int startIdx, int curElements, int numElements){ // numElement개의 원소를 갖는 모든 조합을 탐색
	if(curElements==numElements){
		// 현재 조합으로 최소공배수를 구한다
		ll curLcm=1;
		for(int i=0; i<elem[0].size(); i++){
			if(picked[i]){
				curLcm=lcm(curLcm,elem[0][i]);
			}
		}

		// 구한 최소공배수가 이미 존재하는지 확인하고 추가한다
		bool isDup=false;
		for(int i=0; i<elem[numElements-1].size(); i++){
			if(curLcm==elem[numElements-1][i]){
				isDup=true; break;
			}
		}
		if(!isDup) elem[numElements-1].push_back(curLcm);
	}

	// 선택한 원소의 수가 목표에 미치지 못하면 계속 고른다
	for(int i=startIdx; i<elem[0].size(); i++){
		if(!picked[i]){
			picked[i]=true;
			combination(i+1, curElements+1, numElements);
			picked[i]=false;
		}
	}
}

int main(void){
	
	// 소수 구하기
	isNotPrime[0]=isNotPrime[1]=true;
	for(ll i=2; i<32000; i++)
		if(isNotPrime[i]==false)
			for(ll j=i*2; j<32000; j+=i) isNotPrime[j]=true;
	for(ll i=0; i<32000; i++) if(!isNotPrime[i]) prime.push_back(i);

	int t;
	scanf("%d",&t);
	for(int z=1; z<=t; z++){
		ll A,B;
		scanf("%lld %lld %lld",&A,&B,&N);

		for(int i=0; i<10; i++) elem[i].clear();

		for(int i=0; i<prime.size(); i++){
			if(N%prime[i]==0){
				elem[0].push_back(prime[i]);
				while(N%prime[i]==0) N/=prime[i];
			}
		}
		if(N>1) elem[0].push_back(N);

		// elem[1] ~ elem[elem[0].size()-1] 목록 생성
		for(int i=2; i<=elem[0].size(); i++){
			for(int j=0; j<elem[0].size(); j++) picked[j]=false;
			combination(0, 0, i);
		}

		// 포함 배제 원리 적용 (N과 서로소가 아닌 수의 개수 구하기)	
		ll ans=0;
		for(int i=0; i<elem[0].size(); i++){
			for(int j=0; j<elem[i].size(); j++){
				if(i%2==0) ans += B/elem[i][j] - (A-1)/elem[i][j];
				else ans -= B/elem[i][j] - (A-1)/elem[i][j];
			}
		}
		// 이 시점에서 ans는 N과 서로소가 아닌 수의 개수를 갖고 있으므로, 전체 수의 개수에서 이 값을 빼야 답이다
		ans=B-(A-1)-ans;

		printf("Case #%d: %lld\n",z,ans);
	}
	return 0;
}