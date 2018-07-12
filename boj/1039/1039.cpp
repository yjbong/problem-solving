#include <cstdio>
#define MAXNUM 1000000
#define MAXSWAPS 10

int ans;
int digits;
int num, swaps;

bool visited[MAXSWAPS+1][MAXNUM+1];
int pow[7] = { 1, 10, 100, 1000, 10000, 100000, 1000000 };

void go(int doneSwaps, int curNum){

	if (visited[doneSwaps][curNum]) return;
	visited[doneSwaps][curNum] = true;

	if (doneSwaps == swaps){
		if (curNum > ans) ans = curNum;
		return;
	}
	else{
		for (int i = 0; i < digits; i++){
			for (int j = i + 1; j < digits; j++){
				int iDigit = (curNum / pow[i]) % 10;
				int jDigit = (curNum / pow[j]) % 10;
				if (!(iDigit == 0 && j == digits - 1)){
					int newNum = curNum + (jDigit - iDigit)*pow[i] + (iDigit - jDigit)*pow[j];
					go(doneSwaps + 1, newNum);
				}
			}
		}
	}
}

int main(void){

	scanf("%d %d", &num, &swaps);

	digits = 0;
	int tmp = num;
	while (tmp > 0){
		digits++; tmp /= 10;
	}
	if (digits == 0) digits++;

	ans = -1;
	if (digits > 1){
		for (int i = 0; i <= MAXSWAPS; i++)
			for (int j = 0; j <= MAXNUM; j++)
				visited[i][j] = false;

		go(0, num);
	}

	printf("%d\n", ans);
	return 0;
}