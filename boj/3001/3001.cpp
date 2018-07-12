#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;

ll A,B; // 구간
int S; // 자릿수의 합

ll D[16][10][136]; // D[i][j][k] = 최상위 자리수가 j이고, 자리수의 합이 k인 i자리수의 개수

ll pow2(ll base, ll exp){
	ll ret=1;
	for(int i=0; i<exp; i++) ret*=base;
	return ret;
}

// upperBound보다 작거나 같고 각 자리수의 합이 dgtSum인 len자리 수의 개수
ll count(ll upperBound, ll len, ll dgtSum){

	ll ret=0;
	for(int j=0; j<=9; j++){ // 최상위 자리를 0~9로 하는 경우를 고려
		ll curDgtLowerBound=(j)*pow2(10, len-1);
		ll curDgtUpperBound=(j+1)*pow2(10, len-1)-1;
		if(curDgtUpperBound<=upperBound){
			ret+=D[len][j][dgtSum];
		}
		else if(curDgtLowerBound<=upperBound){
			ret+=count(upperBound%(pow2(10,len-1)), len-1, dgtSum-j);
		}
	}
	return ret;
}

vector <int> ansNum;
bool getNum(ll lowerBound, ll len, ll dgtSum, bool needBoundCheck){

	for(int j=0; j<=9; j++){ // 최상위 자리를 0~9로 하는 경우를 고려

		if(D[len][j][dgtSum]>0){ // 최상위 자리를 숫자 j로 하였을 때 자리수의 합이 dgtSum 인 수가 있을 때

			// 범위 체크가 필요한 경우
			if(needBoundCheck){
				// 최상위 자리가 숫자 j일 때, 수의 범위
				ll curMin = j*pow2(10, len-1); // 범위에서의 최소값
				ll curMax = (j+1)*pow2(10, len-1)-1; // 범위에서의 최대값

				if(curMin>=lowerBound){ // 이 범위 내의 어떤 값이라도 lowerBound보다 큼
					getNum(lowerBound%(pow2(10, len-1)), len-1, dgtSum-j, false);
					ansNum.push_back(j);
					return true;
				}
				else if(curMax>=lowerBound){ // 이 범위 내의 일부분이 lowerBound보다 큼
					if(getNum(lowerBound%(pow2(10, len-1)), len-1, dgtSum-j, true)){
						ansNum.push_back(j);
						return true;
					}
				}
			}

			// 범위 체크가 필요 없는 경우
			else{
				getNum(lowerBound%(pow2(10, len-1)), len-1, dgtSum-j, false);
				ansNum.push_back(j);
				return true;
			}
		}
	}
	return false;
}

int main(void){

	scanf("%lld %lld %d",&A,&B,&S);

	// D 배열 계산
	for(int j=0; j<=9; j++) D[1][j][j]=1;

	for(int i=2; i<=15; i++)
	for(int j=0; j<=9; j++)
	for(int k=0; k<=135; k++)
	for(int l=0; l<=9; l++)
		if(k-j>=0) D[i][j][k]+=D[i-1][l][k-j];

	// 조건을 만족하는 수의 개수를 출력
	ll ans=count(B, 15, S) - count(A-1, 15, S);
	printf("%lld\n",ans);

	// 조건을 만족하는 가장 작은 수를 출력
	getNum(A, 15, S, true);

	bool leadingZero=true;
	for(int i=ansNum.size()-1; i>=0; i--){
		if(leadingZero==false || ansNum[i]!=0){
			printf("%d",ansNum[i]);
			leadingZero=false;
		}
	}
	printf("\n");

	return 0;
}