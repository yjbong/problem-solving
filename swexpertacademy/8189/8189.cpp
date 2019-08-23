#include <cstdio>
#define MAX_N 100
#define MAX_ARV 1000
int T, N, A, B;
int read[MAX_N]; // read[i] = i��° ������ ���� �ð�
int arv[MAX_N]; // arv[i] = i��° ������ ������ �ð�

int lastRead; // ���������� ���� ������ ��ȣ
int lastPush; // ���������� �����Կ� �� ������ ��ȣ

int main() {
	scanf("%d", &T);
	for (int z = 1; z <= T; z++) {
		scanf("%d %d %d", &N, &A, &B);
		for (int i = 0; i<N; i++) {
			scanf("%d", &arv[i]);
			read[i] = 0;
		}

		lastRead = lastPush = -1;
		for (int time = 1; time <= MAX_ARV * 100; time++) {
			if (lastRead == N - 1) break;
			if (lastPush<N - 1 && arv[lastPush + 1] == time) lastPush++;
			int num = lastPush - lastRead;
			int waitTime = time - arv[lastRead + 1];
			if (num == A || waitTime == B) {
				int start = lastRead + 1;
				int end = start + num / 2 + num % 2;
				for (int j = start; j<end; j++) read[j] = time;
				lastRead = end - 1;
			}
		}

		printf("#%d ", z);
		for (int i = 0; i<N; i++) printf("%d ", read[i]);
		printf("\n");
	}
	return 0;
}