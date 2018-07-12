#include <stdio.h>

int pendulums;
int pendulum[33];
int d[33][30 * 500 + 1]; // d[i][j] = 1 if measuring weight j is possible with given pendulum [1,i], otherwise 0

int queries;

int abs2(int x){
	return x >= 0 ? x : (-x);
}
int main(void){

	scanf("%d", &pendulums);
	int totalSum = 0;
	for (int i = 1; i <= pendulums; i++){
		scanf("%d", &pendulum[i]);
		totalSum += pendulum[i];
	}

	d[0][0] = 1;
	for (int i = 1; i <= pendulums; i++){
		for (int j = 0; j <= totalSum; j++){
			d[i][j] = d[i-1][j] || d[i - 1][abs2(j - pendulum[i])] || d[i - 1][j + pendulum[i]];
		}
	}

	scanf("%d", &queries);
	for (int i = 0; i < queries; i++){
		int query;
		scanf("%d", &query);
		if (query<=totalSum && d[pendulums][query]) printf("Y ");
		else printf("N ");
	}
	printf("\n");
	return 0;
}