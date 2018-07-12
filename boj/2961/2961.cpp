#include <cstdio>
#include <cstdlib>

int N;
int sour[10];
int bitter[10];

int ans;
bool pick[10];

void go(int idx){
	if(idx==N){
		// ans 갱신
		int totalSour=1;
		int totalBitter=0;

		bool validAns=false;
		for(int i=0; i<N; i++){
			if(pick[i]){
				validAns=true; // 최소 1개 재료를 골랐음
				totalSour*=sour[i];
				totalBitter+=bitter[i];
			}
		}
		int curAns=abs(totalSour-totalBitter);
		if(validAns && ans>curAns) ans=curAns;

		return;
	}

	pick[idx]=true;
	go(idx+1);
	pick[idx]=false;
	go(idx+1);
}

int main(void){
	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%d %d",&sour[i],&bitter[i]);

	ans=2147483647;
	go(0);
	printf("%d\n",ans);
	return 0;
}