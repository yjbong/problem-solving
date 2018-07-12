#include <cstdio>

int N,M; // 행렬 A 크기(N*M);
int K; // 행렬 B 크기(M*K);

int A[100][100]; // 행렬 A
int B[100][100]; // 행렬 B
int C[100][100]; // C=A*B (N*K)

int main(void){
	scanf("%d %d",&N,&M);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%d",&A[i][j]);

	scanf("%*d %d",&K);
	for(int i=0; i<M; i++)
		for(int j=0; j<K; j++)
			scanf("%d",&B[i][j]);

	for(int i=0; i<N; i++)
		for(int j=0; j<K; j++)
			for(int k=0; k<M; k++)
				C[i][j]+=A[i][k]*B[k][j];

	for(int i=0; i<N; i++){
		for(int j=0; j<K; j++) printf("%d ",C[i][j]);
		printf("\n");
	}
	return 0;
}