#include <cstdio>
int main(void){
	int T;
	scanf("%d",&T);
	while(T--){
		int M,N,x,y;
		scanf("%d %d %d %d",&M,&N,&x,&y);
	
		int rows,cols;
		// M, N 중 작은 수를 달력 열의 개수로 생각한다
		if(M<N){ cols=M; rows=N; }
		else{ cols=N; rows=M; }

		int ans=1;
		bool isValidYear=false;

		// N열인 경우
		if(cols==N){
			// 달력에서 1열이 될 때까지 왼쪽으로 이동시킨다 (1열 이동 시 인덱스 1 증가)
			while(y>1){
				x--, y--;
				if(x<1) x+=rows;
				ans++;
			}
			// 달력에서 1행이 될 때까지 위쪽으로 이동시킨다 (1행 이동 시 인덱스는 열의 개수만큼 증가)
			for(int i=0; i<rows; i++){
				if(x==1){ isValidYear=true; break; } // 이동한 결과 (1,1)을 만나면 (x,y)는 가능한 해이다
				else{
					x-=cols;
					if(x<1) x+=rows;
					ans+=cols;
				}
			}
		}
		// M열인 경우
		else{
			while(x>1){
				x--, y--;
				if(y<1) y+=rows;
				ans++;
			}
			for(int i=0; i<rows; i++){
				if(y==1){ isValidYear=true; break; }
				else{
					y-=cols;
					if(y<1) y+=rows;
					ans+=cols;
				}
			}
		}
		if(isValidYear) printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}