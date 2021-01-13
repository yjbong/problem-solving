#include <cstdio>
int N;
int A[100][100];
int D[100][100];
int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++) scanf("%d",&A[i][j]);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++) D[i][j]=A[i][j];
    for(int k=0; k<N; k++)
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                if(D[i][k] && D[k][j]) D[i][j]=1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            printf("%d ",D[i][j]);
        printf("\n");
    }
    return 0;
}