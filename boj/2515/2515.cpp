#include <cstdio>
#include <utility>
#include <algorithm>
#define MAX_N 300000
using namespace std;
typedef pair<int, int> ii; // first: 높이, second: 가격

int N; // 그림의 개수
int S; // 그림을 팔기 위해 보여야 하는 길이
ii pic[MAX_N]; // pic[i] = i번 그림의 높이, 가격

//int idx2h[MAX_N]; // idx2h[i] = j --> segment tree에서 i번째 데이터(가장 아래쪽 레벨에 위치한 노드 중 왼쪽 i번째)에 대응되는 height값

int d[MAX_N]; // i번 그림을 마지막으로 구매가능하도록 배치할 때의 최대 수입
int seg[1 << 20]; // segment tree
int base; /// segment tree에서 실제 데이터가 시작되는 idx
int max2(int a, int b){ return a > b ? a : b; }

int binsearch(int key){ // key값보다 height가 작거나 같은 그림 중 가장 오른쪽 idx를 리턴

	int left = 0, right = N - 1;

	int ret = -1;
	while (left <= right){
		int mid = (left + right) / 2;
		if (key >= pic[mid].first){
			ret = max2(ret, mid);
			left = mid + 1;
		}
		else right = mid - 1;
	}
	return ret;
}

void update(int idx, int val){
	idx += base;
	seg[idx] = max2(seg[idx],val);

	idx /= 2;
	while (idx >= 1){
		seg[idx] = max2(seg[idx * 2], seg[idx * 2 + 1]);
		idx /= 2;
	}
}

int query(int left, int right){

	int ret = 0;
	left += base;
	right += base;
	while (left < right){
		if (left % 2 == 0) left /= 2;
		else{
			ret = max2(ret, seg[left]);
			left = (left + 1) / 2;
		}
		if (right % 2 == 1) right /= 2;
		else{
			ret = max2(ret, seg[right]);
			right = (right - 1) / 2;
		}
	}

	if (left == right) ret = max2(ret, seg[left]);
	return ret;
}

int main(void){

	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) scanf("%d %d", &pic[i].first, &pic[i].second);
	sort(pic, pic + N); // 높이의 오름차순 정렬

	// base값 초기화
	base = 1;
	while (base < N) base *= 2;

	// DP
	for (int i = 0; i < N; i++){
		d[i] = pic[i].second;
		if (i > 0){
			int rightIdx = binsearch(pic[i].first - S); // i번 그림 앞에 세워놔도 i번 그림을 팔 수 있을만큼 보이게 하는 가장 오른쪽 그림의 위치
			d[i] += query(0, rightIdx);
		}
		update(i, d[i]);
	}

	// 답 출력
	int ans = 0;
	for (int i = 0; i < N; i++) ans = max2(ans, d[i]);
	printf("%d\n", ans);
	return 0;
}