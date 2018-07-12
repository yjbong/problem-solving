#include <cstdio>
#include <vector>
using namespace std;

// 평형값의 정의 : (저울의 왼쪽 가중치 - 저울의 오른쪽 가중치)
int N; // 추 집합의 크기
int w[10]; // w[i] = i번째 추의 무게
int d[10][10][1<<9][271]; // d[i][j][k][l+135] = 숫자 w[j](1~9 사이의 값)로 시작하며 추 집합의 사용 상태가 k인 (i+1)자리 평형 정수 중 평형값 = l인 것의 개수
				// 만약 j=n 이라면 숫자 0으로 시작하는 것임

int K; // 찾고자 하는 평형정수의 순서값

vector <int> state[11]; // state[i] = 1인 bit가 i개 이하인 비트마스크의 목록

int changeVal(int i, int j){ // i번째 자리에 무게가 추 w[j]를 놓아서 증감하는 평형값의 크기
	if(i>=0 && i<=4) return w[j]*(i-5);
	else if(i>=5 && i<=9) return w[j]*(i-4);
	else return 0;
}

int main(void){

	// state 구하기
	for(int i=0; i<(1<<9); i++){
		int setBits=0;
		for(int j=0; j<9; j++) if(i&(1<<j)) setBits++;
		for(int j=setBits; j<=10; j++) state[j].push_back(i);
	}

	scanf("%d",&N);
	for(int j=0; j<N; j++) scanf("%d",&w[j]);

	// DP 테이블 초기화
	d[0][N][0][0+135]=1; // 0번 자리에 추를 놓지 않음
	for(int j=0; j<N; j++)
		for(int l=-135; l<=135; l++)
			if(changeVal(0,j)==l) d[0][j][1<<j][l+135]=1; // 0번 자리에 w[j] 무게 추를 놓음

	
	for(int i=1; i<10; i++){ // 9~1번 자릿수에 대한 DP
		for(int j=0; j<=N; j++){
			if(j<N){ // i번째 자리에 추 w[j] 사용
				for(int k=0; k<state[i+1].size(); k++){ // 상태값에서 1인 Bit수 <= i+1 일 때만 가능
					int curState=state[i+1][k];
					if(curState & (1<<j)){ // 현재 상태는 반드시 j번 추를 사용한 상태여야 함

						for(int l=-135; l<=135; l++){ // 모든 가능한 평형값에 대하여 반복

							for(int m=0; m<=N; m++){
								d[i][j][curState][l+135]+=d[i-1][m][curState-(1<<j)][l-changeVal(i,j)+135];
							}
						}	
					}	
				}
			}
			else{ // i번째 자릿수가 0
				for(int k=0; k<state[i+1].size(); k++){
					int curState=state[i+1][k];
					for(int l=-135; l<=135; l++){
						for(int m=0; m<=N; m++){
							d[i][j][curState][l+135]+=d[i-1][m][curState][l+135];
						}
					}
				}
			}
		}
	}	
	
	// K번째 평형 정수 찾기
	scanf("%d",&K);

	int totalEqualNums=0;
	for(int j=0; j<=N; j++)
		for(int k=0; k<(1<<9); k++)
			totalEqualNums+=d[9][j][k][0+135];

	if(K>=totalEqualNums) K=totalEqualNums-1; // K번째 평형 정수가 존재하지 않는다면, 가능한 가장 큰 평형 정수 출력

	bool nonZero=false;
	int curl=0; int curUseState=0;

	for(int i=9; i>=0; i--){

		// 현재 상태에서 남은 자리 중 최상위 자리가 0으로 시작하는 평형 정수의 개수 구하기 (추를 사용하지 않음)
		int curEqualNums=0;
		for(int k=0; k<(1<<9); k++){
			if((curUseState & k)==0){ // 가능한 상태
				curEqualNums+=d[i][N][k][curl+135];
			}
		}

		if(K<curEqualNums){
			if(nonZero || i==0) printf("0");
			continue;
		}
		else K-=curEqualNums;

		// 추를 사용 (무게 1~9)
		for(int j=0; j<N; j++){

			// 현재 상태에서 남은 자리 중 최상위 자리가 w[j]로 시작하는 평형 정수의 개수 구하기
			int curEqualNums=0;
			for(int k=0; k<(1<<9); k++){
				if((curUseState & k)==0){ // 가능한 상태
					curEqualNums+=d[i][j][k][curl+135];
				}
			}

			if(K<curEqualNums){
				printf("%d",w[j]);
				curl-=changeVal(i,j); // 맞춰야 할 평형값 업데이트
				curUseState |= (1<<j); // 사용 상태 업데이트
				nonZero=true;
				break;
			}
			else K-=curEqualNums;
		}
	}
	printf("\n");

	return 0;
}