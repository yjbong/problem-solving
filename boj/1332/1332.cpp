#include <cstdio>
#include <cstdlib>
int N; // 문제 수
int V; // 만족시켜야 하는 흥미도의 차이값

int fun[10000]; // fun[i] = i번 문제를 풀었을 때의 흥미도

int main(void){
	scanf("%d %d",&N,&V);
	for(int i=0; i<N; i++) scanf("%d",&fun[i]);

	int ans;
	if(N<2){
		ans=N;
	}
	else{
		// 흥미도 차이 V를 만족시키지 못할 경우 풀어야 하는 문제의 수
		ans=N;
	
		// 임의로 두 개의 문제를 골라서, 그 문제는 반드시 풀어야 한다고 가정한다
		for(int i=0; i<N; i++){
			for(int j=i+1; j<N; j++){

				// i=0 인 경우 (첫 번째 문제와 j번 문제를 반드시 푼다)
				if(i==0){
					if(abs(fun[0]-fun[j])>=V){ // 흥미도 차이 V를 만족시킨 경우

						// 나머지 문제는 최대한 건너뜀
						int curAns=2; // 0번, j번 문제
						curAns+=(j-0)/2-((j-0)%2==0?1:0); // 0~j번 문제 사이에서 어쩔 수 없이 푸는 문제

						if(ans>curAns) ans=curAns;
					}
				}

				// i>0 인 경우 (첫 번째 문제와 i번, j번 문제를 반드시 푼다)
				else{
					if(abs(fun[0]-fun[i])>=V || abs(fun[0]-fun[j])>=V || abs(fun[i]-fun[j])>=V){ // 흥미도 차이 V를 만족시킨 경우

						// 나머지 문제는 최대한 건너뜀
						int curAns=3; // 0, i, j번 문제
						curAns+=(i-0)/2-((i-0)%2==0?1:0); // 0~i번 문제 사이에서 어쩔 수 없이 푸는 문제
						curAns+=(j-i)/2-((j-i)%2==0?1:0); // i~j번 문제 사이에서 어쩔 수 없이 푸는 문제

						if(ans>curAns) ans=curAns;
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}