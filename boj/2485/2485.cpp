#include <cstdio>
#include <algorithm>
#define MAXN 100000
using namespace std;

int N; // 이미 심어져 있는 가로수의 수
int P[MAXN]; // P[i] = i번째 가로수의 위치
int S[MAXN - 1]; // S[i] = i번째 가로수와 i+1번째 가로수의 간격

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main(void) {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &P[i]);
	sort(P, P + N);

	// 나무 사이 간격 계산 (N개의 나무가 있다면 N-1개의 간격이 있음)
	for (int i = 0; i < N - 1; i++) S[i] = P[i + 1] - P[i];
	
	// 간격들의 최대공약수 계산
	int gcdS = S[0];
	for (int i = 1; i < N - 1; i++) gcdS = gcd(gcdS, S[i]);

	// 답 계산
	int ans = 0;
	for (int i = 0; i < N - 1; i++) ans += S[i] / gcdS - 1;

	printf("%d\n", ans);

	return 0;
}