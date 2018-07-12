#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int n, m; // n: 고기의 갯수, m: 목표 무게
vector<pair<int, int> > meat; // first: 가격, second: 무게

int priceList[111111]; // 입력에 나타난 가격의 목록
int priceLists; // 가격 목록의 크기

int sum[111111]; // sum[i] = meat[0~i] 까지의 무게 합
int priceSum[111111]; // priceSum[i] = 가격이 priceList[i]보다 싼 고기들의 무게 합

vector <int> weightList[111111]; // weightList[i] = 가격이 priceList[i] 인 고기들의 무게

int main(void){
	
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++){
		int weight, price;
		scanf("%d %d", &weight, &price);
		meat.push_back(make_pair(price, weight));
	}
	sort(meat.begin(), meat.end());

	int oldPrice;
	// priceList 생성
	priceLists = 0;
	oldPrice = -1;
	for (int i = 0; i < meat.size(); i++){
		if (oldPrice != meat[i].first){
			priceList[priceLists++] = meat[i].first;
			oldPrice = meat[i].first;
			weightList[priceLists - 1].push_back(meat[i].second); // weightList 추가
		}
		else weightList[priceLists - 1].push_back(meat[i].second); // weightList 추가
	}

	// sum 생성
	sum[0] = meat[0].second;
	for (int i = 1; i < meat.size(); i++) sum[i] = sum[i - 1] + meat[i].second;

	// priceSum 생성
	priceSum[0] = 0; // 등장했던 최저 가격보다 더 싼 고기는 있을 수 없음
	oldPrice = meat[0].first;
	for (int i = 1, j = 1; i < meat.size(); i++){
		if (oldPrice < meat[i].first){
			priceSum[j++] = sum[i - 1];
			oldPrice = meat[i].first;
		}
	}

	int ans = -1;
	for (int i = 0; i < priceLists; i++){
		int curSum=0; // 동일 가격 대에서 구매하는 고기의 무게 합
		for (int j = weightList[i].size() - 1; j >= 0; j--){ // 같은 가격의 고기를 무거운 순서대로 1, 2, ... 개 선택
			curSum += weightList[i][j];
			if (curSum + priceSum[i] >= m){ // 목표 무게를 만족한 경우
				int curNumMeatBuy = weightList[i].size() - j; // 이번 iteration에서 사는 동일 가격대의 고기 갯수
				int curPrice = curNumMeatBuy * priceList[i]; // 지불해야 하는 총 금액
				if (ans < 0 || ans > curPrice) ans = curPrice; // 최소금액 업데이트
			}
		}
	}

	printf("%d\n", ans); // 최소금액 출력
	return 0;
}