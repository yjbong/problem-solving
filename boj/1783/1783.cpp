#include <cstdio>
int N; // 세로 길이
int M; // 가로 길이
int max2(int a, int b){ return a>b?a:b; }
int main(void){
	scanf("%d %d",&N,&M);
	int ans=0;
	if(N>=3){
		if(M>=5) ans=max2(4, M-2);
		else ans=M;
	}
	else if(N==2){
		if(M>=7) ans=4;
		else if(M>=5) ans=3;
		else if(M>=3) ans=2;
		else if(M>=1) ans=1;
	}
	else if(N==1){
		if(M>=1) ans=1;
		else ans=0;
	}

	printf("%d\n",ans);
	return 0;
}