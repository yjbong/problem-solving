#include <cstdio>
#include <cstring>
typedef long long ll;

int N; // 숫자의 개수
char num[50][13];
bool exist[10]; // exist[0]=A의 등장 여부, ... , exist[9]=J의 등장 여부
ll dgtSum[10]; // dgtSum[0]=A의 자리수 합, ... , dgtSum[9]=J의 자리수 합
bool haveFirstDgt[10]; // haveFirstDgt[0]=true이면, A가 가장 앞자리인 수가 존재한다는 뜻 --> 즉 이 경우 A는 0이 될 수 없음
ll ans[10]; // ans[0]=A가 나타내는 숫자, ... , ans[9]=J가 나타내는 숫자
ll pow10[13]; // pow10[i] = 10의 i제곱

int main(void){

	pow10[0]=1;
	for(int i=1; i<=12; i++) pow10[i]=pow10[i-1]*10;

	scanf("%d\n",&N);
	for(int i=0; i<N; i++) gets(num[i]);

	// dgtSum 계산
	for(int i=0; i<N; i++){
		for(int j=0; j<strlen(num[i]); j++){
			dgtSum[num[i][j]-'A']+=pow10[strlen(num[i])-1-j];
			if(j==0) haveFirstDgt[num[i][j]-'A']=true;
			exist[num[i][j]-'A']=true;
		}
	}

	// ans 초기화
	for(int i=0; i<10; i++) ans[i]=-1;

	int exists=0;
	for(int i=0; i<10; i++) if(exist[i]) exists++;

	// 만약 A~J까지의 모든 알파벳이 등장했다면, 한 알파벳은 0이 되어야만 한다
	if(exists==10){
		// 0이 되어야 하는 알파벳은 가장 앞자리에 등장한 적이 없는 것들 중에 dgtSum이 가장 작은 알파벳이다
		// (문제 정의에서 이러한 알파벳은 반드시 존재한다고 되어 있음)
		int minIdx=-1;
		for(int i=0; i<10; i++)
			if(exist[i] && haveFirstDgt[i]==false && (minIdx<0 || dgtSum[minIdx]>dgtSum[i])) minIdx=i;
		ans[minIdx]=0;
	}

	// 9부터 차례대로 숫자를 지정한다
	ll curDgt=9;
	do{
		int maxIdx=-1;
		for(int i=0; i<10; i++){
			if(exist[i] && ans[i]<0){ // 아직 값이 정해지지 않은 알파벳에 대해
				if(maxIdx<0 || dgtSum[maxIdx]<dgtSum[i]) maxIdx=i;
			}
		}

		if(maxIdx>=0){
			ans[maxIdx]=curDgt;
			curDgt--;
		}
		else break;

	}while(1);

	// 답 계산
	ll ansVal=0;
	for(int i=0; i<10; i++){
		if(exist[i]){
			ansVal+=dgtSum[i]*ans[i];
		}
	}
	printf("%lld\n",ansVal);
	return 0;
}