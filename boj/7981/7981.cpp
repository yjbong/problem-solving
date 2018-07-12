#include <cstdio>
#include <vector>
#define MAX_N 200000

using namespace std;
typedef long long ll;

int n; // 장비의 개수 (장비는 1번부터 시작)
ll u[MAX_N+1]; // u[i] = i번 장비에 약한 충격을 주기 위한 전력
ll z[MAX_N+1]; // z[i] = i번 장비에 강한 충격을 주기 위한 전력
int r[MAX_N+1]; // r[i] = i번 장비에 약한 충격을 주었을 때 다시 동작하는 장비의 개수

vector <int> rlist[MAX_N+1]; // rlist[i]= i번 장비에 약한 충격을 주었을 때 다시 동작하는 장비 목록

bool visited[MAX_N+1];
ll d[MAX_N+1]; // d[i] = i번 장비를 완전히 정지(i번 장비를 정지시키면서 작동한 장비들을 포함)시키기 위해 필요한 최소 전력

ll min2(ll a, ll b){ return a < b ? a : b; }

ll go(int idx){
	if (d[idx] >= 0) return d[idx]; // memoization
	ll ret = z[idx]; // 강한 충격을 주는 경우

	visited[idx] = true;

	// 사이클 체크
	bool uPossible = true;
	for (int i = 0; i < r[idx]; i++){
		if (visited[rlist[idx][i]] == true){
			uPossible = false; break;
		}
	}

	// 사이클 없는 경우에만 약한 충격 가능
	if (uPossible){
		ll uSum = 0; // idx번 장비에 약한 충격을 주고 난 후 재작동한 장비들을 모두 정지시키기 위한 최소 전력
		for (int i = 0; i < r[idx]; i++)
			uSum += go(rlist[idx][i]);

		ret = min2(ret, u[idx] + uSum);
	}

	visited[idx] = false;
	return (d[idx] = ret);
}


int main(void){

	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%lld %lld %d", &u[i], &z[i], &r[i]);
		for (int j = 0; j < r[i]; j++){
			int t;
			scanf("%d", &t);
			rlist[i].push_back(t);
		}
	}

	for (int i = 1; i <= n; i++) d[i] = -1;
	// 최초에는 1번 장비가 동작하고 있음
	printf("%lld\n", go(1));
	
	return 0;
}