#include <cstdio>
typedef long long ll;
ll M,N; // M행 N열 표
int main(void){

	scanf("%lld %lld",&M,&N);

	ll lastY=1,lastX=1;
	ll turns=0;

	if(M>N){ // M,N중 작은 수가 기준
		// N이 홀수인 경우
		if(N%2==1){
			// N/2 바퀴를 돎
			lastY+=N/2;
			lastX+=N/2;
			turns+=(N/2)*4;

			// (1+N/2, 1+N/2)에서 (M-N/2, 1+N/2)로 이동
			lastY=M-N/2;
			turns++;
		}
		// N이 짝수인 경우
		else{
			// (N-2)/2 바퀴를 돎
			lastY+=(N-2)/2;
			lastX+=(N-2)/2;
			turns+=((N-2)/2)*4;

			// (1+(N-2)/2, 1+(N-2)/2)에서 (1+(N-2)/2+1, 1+(N-2)/2)로 이동
			lastY++;
			turns+=3;
		}
	}
	else if(M<N){
		// M이 홀수인 경우
		if(M%2==1){
			// M/2 바퀴를 돎
			lastY+=M/2;
			lastX+=M/2;
			turns+=(M/2)*4;

			// (1+M/2, 1+M/2)에서 (1+M/2,N-M/2)로 이동
			lastX=N-M/2;
		}
		// M이 짝수인 경우
		else{
			// (M-2)/2 바퀴를 돎
			lastY+=(M-2)/2;
			lastX+=(M-2)/2;
			turns+=((M-2)/2)*4;

			// (1+(M-2)/2, 1+(M-2)/2)에서 (1+(M-2)/2+1, 1+(M-2)/2)로 이동
			lastY++;
			turns+=2;
		}

	}
	else{ // M과 N이 같은 경우
		// 홀수인 경우
		if(M%2==1){
			// M/2 바퀴를 돎
			lastY+=M/2;
			lastX+=M/2;
			turns+=(M/2)*4;

			// (1+M/2, 1+M/2)에서 이동할 곳이 없음
		}
		// 짝수인 경우
		else{
			// (M-2)/2 바퀴를 돎
			lastY+=(M-2)/2;
			lastX+=(M-2)/2;
			turns+=((M-2)/2)*4;

			// (1+(M-2)/2, 1+(M-2)/2)에서 (1+(M-2)/2+1, 1+(M-2)/2)로 이동
			lastY++;
			turns+=2;
		}
	}
	printf("%lld\n",turns);
	printf("%lld %lld\n",lastY,lastX);
	return 0;
}