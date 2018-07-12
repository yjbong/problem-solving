#include <cstdio>
int a[1500][1500];
int pos[1500];
int n;
int main(void){

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		scanf("%d", &a[i][j]);

	for (int i = 0; i < n; i++)
		pos[i] = n - 1;

	for (int i = 0; i < n; i++){
		int maxCol = -1;
		for (int j = 0; j < n; j++)
			if (pos[j] >= 0)
				if (maxCol < 0 || (a[pos[maxCol]][maxCol] < a[pos[j]][j])) maxCol = j;

		if (maxCol >= 0){
				if (i == n - 1) printf("%d\n", a[pos[maxCol]][maxCol]);
				pos[maxCol]--;
		}
	}
	return 0;
}