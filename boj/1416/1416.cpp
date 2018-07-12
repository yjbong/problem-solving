#include <cstdio>
#include <cstring>
#define MAX_K 50
#define IDX_ADD MAX_K*9
#define MODVAL 999983

int K; // K = 티켓 자리수 길이의 절반
char numList[11]; // numList = 티켓에 등장하는 숫자 목록
//int d[100+1][900+1][900+1]; // d[i][j][k] = 1~i번째 자리에 대해서, (홀수 자리 수의 합-짝수 자리 수의 합)+450=j,
			    // (1~K번째 자리 수의 합)-(K+1~2K번째 자리 수의 합)+450=k인 경우의 수
int d[2][900+1][900+1];
int main(void){
	scanf("%d",&K);
	scanf("%s",numList);

	int numLists=strlen(numList);
	for(int i=0; i<numLists; i++) numList[i]-='0';

	d[0][IDX_ADD][IDX_ADD]=1;
	int curIdx=1; // idx for sliding window
	for(int i=1; i<=2*K; i++){
		int jStart = -((i/2)*9)+IDX_ADD;
		int jEnd = ((i+1)/2)*9+IDX_ADD;
		int kStart = i>K ? -(i-K)*9+IDX_ADD : IDX_ADD;
		int kEnd = i<=K ? i*9+IDX_ADD : K*9+IDX_ADD;
		//printf("for i=%d --> j range = %d~%d, k range = %d~%d\n", i, jStart-IDX_ADD, jEnd-IDX_ADD, kStart-IDX_ADD, kEnd-IDX_ADD);
		for(int j=jStart; j<=jEnd; j++){
			for(int k=kStart; k<=kEnd; k++){
				d[curIdx][j][k]=0;
				for(int l=0; l<numLists; l++){
					int prevJ, prevK;
					prevJ = i%2 ? j-numList[l] : j+numList[l];
					prevK = i<=K ? k-numList[l] : k+numList[l];
					if(prevJ>=0 && prevJ<=IDX_ADD*2 && prevK>=0 && prevK<=IDX_ADD*2)
						d[curIdx][j][k]=(d[curIdx][j][k]+d[1-curIdx][prevJ][prevK])%MODVAL;
				}
			}
		}
		curIdx=1-curIdx;
	}

	int ans=0;
	for(int j=0; j<=IDX_ADD*2; j++) ans=(ans+d[1-curIdx][j][IDX_ADD])%MODVAL;
	for(int k=0; k<=IDX_ADD*2; k++) ans=(ans+d[1-curIdx][IDX_ADD][k])%MODVAL;
	ans=(ans+MODVAL-d[1-curIdx][IDX_ADD][IDX_ADD])%MODVAL;
	printf("%d\n",ans);
	return 0;
}