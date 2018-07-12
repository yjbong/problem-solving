#include <cstdio>
#include <cstring>
#define INF 1000000000

char number[1001];
int n; // number의 길이
int cache[1000];
int trace[1000];

// quality(s,e)=number[s~e]의 품질 (e-s==1 || e-s==2)
int quality(int s, int e){
	if(e-s==1){
		if(number[s]==number[s+1]) return 2;
		else return 0;
	}
	else if(e-s==2){
		if(number[s]==number[s+1] && number[s+1]==number[s+2]) return 2;
		else if(number[s]==number[s+1] || number[s]==number[s+2] || number[s+1]==number[s+2]) return 1;
		else return 0;
	}
	else return -INF;
}

// go(idx)=number[idx~N-1])을 적절히 그룹으로 나눴을 때 얻을 수 있는 최대 품질
int go(int idx){
	int ret=-INF;
	if(idx>=n) return 0;
	else if(cache[idx]>-INF*2) return cache[idx];
	else{
		int q1=-INF, q2=-INF;
		if(idx+1<n){
			// number[idx~idx+1]을 한 그룹으로 묶는 경우
			q1=quality(idx,idx+1)+go(idx+2);
		}
		if(idx+2<n){
			// number[idx~idx+2]을 한 그룹으로 묶음
			q2=quality(idx,idx+2)+go(idx+3);
		}

		// '-'가 숫자보다 사전순으로 앞이므로, 품질이 같다면 앞에서부터 적은 숫자를 그룹으로 묶어야 함
		if(q1>=q2){
			trace[idx]=idx+2;
			ret=q1;
		}
		else{
			trace[idx]=idx+3;
			ret=q2;
		}
	}
	return (cache[idx]=ret);
}

int main(void){
	scanf("%s",number);
	n=strlen(number);
	for(int i=0; i<n; i++) cache[i]=-INF*2;

	// Top down DP
	go(0);

	// 답 출력
	int curIdx=0;
	while(curIdx<n){
		int nextIdx=trace[curIdx];
		for(int i=curIdx; i<nextIdx; i++) printf("%c",number[i]);
		if(nextIdx<n) printf("-");
		curIdx=nextIdx;
	}
	printf("\n");
	return 0;
}