#include <cstdio>
#define MAX_N 10000
typedef long long ll;
int N; // 운동시간
int M; // 최대 지침 지수
ll a[MAX_N+1]; // a[i] = i분인 시점에 달리는 거리
ll s[MAX_N+1]; // s[i] = a[1]+a[2]+...+a[i]
ll d[MAX_N+1]; // i분인 시점에서 지침지수가 0이라고 할 때, 그때까지 최대한 멀리 갈 수 있는 거리

int main(void){
	scanf("%d %d",&N,&M);
	for(int i=1; i<=N; i++) scanf("%lld",&a[i]);

	s[0]=0;
	for(int i=1; i<=N; i++) s[i]=s[i-1]+a[i];

	for(int i=0; i<=N; i++) d[i]=0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){ // 최대 지침 지수까지 뛰는 경우를 고려
			// 시점 t=i-1 에서 쉬었을 경우
			if(d[i]<d[i-1]) d[i]=d[i-1];

			// 시점 t=i-1 에서 달리는 경우
			// (연속으로 j분 달리고(t=i-j*2일 때부터), 연속으로 j분 휴식(t=i일 때까지)했을 때의 답을 고려)
			if(i-j*2>=0 && d[i]<d[i-j*2]+s[i-j]-s[i-j*2]) d[i]=d[i-j*2]+s[i-j]-s[i-j*2];
		}
	}

	printf("%lld\n",d[N]);
	return 0;
}