#include <cstdio>
#include <cmath>
int a[100000][2]; // a[i][j] = j행 i열에 있는 스티커의 점수
int d[100000][3]; // d[i][j] = i열까지의 스티커를 골랐고, i열의 상태가 j일 때 가능한 최대 점수 합
				  // j = 0 --> i열에서 스티커를 선택하지 않음
				  // j = 1 --> i열에서 윗줄(0행)의 스티커를 선택
				  // j = 2 --> i열에서 아랫줄(1행)의 스티커를 선택
int n; // 열의 개수
int max2(int a, int b) { return a>b?a:b; }
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int j=0; j<2; j++)
			for(int i=0; i<n; i++) scanf("%d",&a[i][j]);

		d[0][0]=0; d[0][1]=a[0][0]; d[0][2]=a[0][1];
		for(int i=1; i<n; i++){
			d[i][0]=max2(d[i-1][0],max2(d[i-1][1],d[i-1][2]));
			d[i][1]=max2(d[i-1][0],d[i-1][2])+a[i][0];
			d[i][2]=max2(d[i-1][0],d[i-1][1])+a[i][1];
		}
		int ans=max2(d[n-1][0],max2(d[n-1][1],d[n-1][2]));
		printf("%d\n",ans);
	}
	return 0;
}