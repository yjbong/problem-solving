#include <cstdio>
#include <cstdlib>
#include <cstring>
#define INF 1000000000
int cases; // 테스트 케이스 수
char A[5001]; // A[i] = 합쳐지기 전 1차선에 있는 i번째 차량의 색 (i=1부터 시작)
int As; // 1차선 차량의 수
char B[5001]; // B[j] = 합쳐지기 전 2차선에 있는 j번쨰 차량의 색 (j=1부터 시작)
int Bs; // 2차선 차량의 수
int d[5001][5001]; // A[1~i], B[1~j] 가 합쳐진 차선에 들어갔을 때 색상의 길이의 합의 최소값

int AColorSum[5001][26]; // AColorSum[i][j] = A[1~i]에서 색이 j인 차량의 개수
int BColorSum[5001][26]; // BColorSum[i][j] = B[1~i]에서 색이 j인 차량의 개수

int main(void){
	scanf("%d\n",&cases);
	while(cases--){
		gets(A+1);
		gets(B+1);
		As=strlen(A+1);
		Bs=strlen(B+1);

		for(int i=1; i<=As; i++)
			for(int j=0; j<26; j++) // j = A~Z색
				AColorSum[i][j]=AColorSum[i-1][j]+(A[i]==j+'A'?1:0);

		for(int i=1; i<=Bs; i++)
			for(int j=0; j<26; j++) // j = A~Z색
				BColorSum[i][j]=BColorSum[i-1][j]+(B[i]==j+'A'?1:0);

		for(int i=0; i<=As; i++){
			for(int j=0; j<=Bs; j++){
				if(i+j==0) d[i][j]=0;
				else{
					d[i][j]=INF;
					int curD;

					// 마지막에 A[i]가 합쳐진 길로 들어가는 경우
					if(i>0){
						curD=d[i-1][j];
						int curColor=A[i]-'A'; // curColor = A[i] 의 색
						int beforeCars = AColorSum[i-1][curColor]+BColorSum[j][curColor]; // A[i]와 같은 색이면서 합쳐진 차선에 들어가 있는 차량의 수
						int afterCars = AColorSum[As][curColor]+BColorSum[Bs][curColor]-beforeCars; // A[i]와 같은 색이면서 아직 합쳐진 차선에 들어가지 않은 차량의 수 (A[i] 포함)

						if(beforeCars==0 && afterCars>1) curD-=(i+j); // A[i]와 같은 색인 차가 아직 합쳐진 차선에 들어오지 않았고, A[i]와 같은 색인 차가 남아 있는 경우
						else if(beforeCars>0 && afterCars==1) curD+=(i+j); // A[i]와 같은 색인 차가 이미 합쳐진 차선에 들어와 있고, A[i]가 같은 색인 차 중 가장 마지막인 경우

						if(d[i][j]>curD) d[i][j]=curD;
					}
					// 마지막에 B[j]가 합쳐진 길로 들어가는 경우
					if(j>0){
						curD=d[i][j-1];
						int curColor=B[j]-'A'; // curColor = B[j] 의 색
						int beforeCars = AColorSum[i][curColor]+BColorSum[j-1][curColor]; // B[j]와 같은 색이면서 합쳐진 차선에 들어가 있는 차량의 수
						int afterCars = AColorSum[As][curColor]+BColorSum[Bs][curColor]-beforeCars; // B[j]와 같은 색이면서 아직 합쳐진 차선에 들어가지 않은 차량의 수 (B[j] 포함)

						if(beforeCars==0 && afterCars>1) curD-=(i+j); // B[j]와 같은 색인 차가 아직 합쳐진 차선에 들어오지 않았고, B[j]와 같은 색인 차가 남아 있는 경우
						else if(beforeCars>0 && afterCars==1) curD+=(i+j); // B[j]와 같은 색인 차가 이미 합쳐진 차선에 들어와 있고, B[j]가 같은 색인 차 중 가장 마지막인 경우

						if(d[i][j]>curD) d[i][j]=curD;
					}
				}
			}
		}
		// 출력 
		printf("%d\n", d[As][Bs]);
	}
	return 0;
}