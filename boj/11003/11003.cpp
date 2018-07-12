#include <cstdio>
#include <deque>

#define MAXN 5000000
using namespace std;
typedef pair<int, int> ii; // first = 값 ( A[i] ) , second = 인덱스 ( i )
deque <ii> dq;

int N; // 수열의 길이
int A[MAXN];
int L; // 최소값을 구할 윈도우의 크기
int main(void) {
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	for (int i = 0; i < N; i++) {

		// 현재 dq에 들어있는 원소들은 당연히 인덱스가 i보다 작다.
		// i보다 인덱스가 작으면서 값이 A[i]보다 큰 원소들은 존재할 필요가 없으므로
		// (A[i] 가 들어온 후, 이 원소들은 최소값이 될 가능성이 없으므로) 뒤에서부터 빼준다.
		while (dq.empty() == false && dq.back().first >= A[i]) dq.pop_back();
		dq.push_back(make_pair(A[i], i));

		// 위와 같은 방식으로 새 원소를 push_back 하면 dp는 항상 값이 작은 순서대로 정렬된다. (즉, dp.front()가 가장 작은 값)
		// 단, front가 i번째 원소를 포함했을 때에도 윈도우 내에 있는지 확인해야 한다.
		// 윈도우 바깥에 있는 원소는 유효하지 않으므로 버린다.
		while (dq.front().second < i - L + 1) dq.pop_front();

		// A[i]를 포함한 후 현재 윈도우 내의 최소값 출력
		// (방금 추가한 pair (A[i], i) 는 바로 위의 while문에서 pop되지 않으므로 dq는 empty가 아닌 것이 보장됨)
		printf("%d ", dq.front());
	}
	printf("\n");
	return 0;
}