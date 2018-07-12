#include <cstdio>
#define HORIZONTAL 0
#define VERTICAL 1
#define BOTH 2
int n; // 석판의 크기
int a[21][21]; // 석판의 정보
int imp[21][21]; // 영역 a[(1,1) ~ (i,j)]에 포함된 불순물의 개수
int jwl[21][21]; // 영역 a[(1,1) ~ (i,j)]에 포함된 보석의 개수

long long cache[21][21][21][21][3]; // for memoization

// 영역 a[(topLeftY,topLeftX) ~ (bottomRightY,bottomRightX)] 에 포함된 불순물의 개수
int impCount(int topLeftY, int topLeftX, int bottomRightY, int bottomRightX){
	return imp[bottomRightY][bottomRightX]-imp[bottomRightY][topLeftX-1]-imp[topLeftY-1][bottomRightX]+imp[topLeftY-1][topLeftX-1];
}
// 영역 a[(topLeftY,topLeftX) ~ (bottomRightY,bottomRightX)] 에 포함된 보석의 개수
int jwlCount(int topLeftY, int topLeftX, int bottomRightY, int bottomRightX){
	return jwl[bottomRightY][bottomRightX]-jwl[bottomRightY][topLeftX-1]-jwl[topLeftY-1][bottomRightX]+jwl[topLeftY-1][topLeftX-1];
}

// 석판 a[(topLeftY,topLeftX) ~ (bottomRightY,bottomRightX)] 를 규칙에 맞게 나누는 방법의 수 (단, cutDirection에 표시된 방향으로만 자를 수 있음)
long long cutWays(int topLeftY, int topLeftX, int bottomRightY, int bottomRightX, int cutDirection){

	if(cache[topLeftY][topLeftX][bottomRightY][bottomRightX][cutDirection]>=0) return cache[topLeftY][topLeftX][bottomRightY][bottomRightX][cutDirection]; // memoization
	int jewels=jwlCount(topLeftY,topLeftX,bottomRightY,bottomRightX);
	if(jewels==0){
		return (cache[topLeftY][topLeftX][bottomRightY][bottomRightX][cutDirection]=0);
	}
	else if(jewels==1){
		if(impCount(topLeftY,topLeftX,bottomRightY,bottomRightX)==0){
			return (cache[topLeftY][topLeftX][bottomRightY][bottomRightX][cutDirection]=1);
		}
		else{
			return (cache[topLeftY][topLeftX][bottomRightY][bottomRightX][cutDirection]=0);
		}
	}
	else{
		long long ret=0;

		// 가로 방향으로 자르는 경우
		if(cutDirection==HORIZONTAL || cutDirection==BOTH){
			for(int i=topLeftY+1; i<=bottomRightY-1; i++){
				if(jwlCount(i,topLeftX,i,bottomRightX)==0){ // 잘리는 부분에 보석이 없어야 함
					ret+=(cutWays(topLeftY,topLeftX,i-1,bottomRightX,VERTICAL)*cutWays(i+1,topLeftX,bottomRightY,bottomRightX,VERTICAL));
				}
			}
		}
		
		// 세로 방향으로 자르는 경우
		if(cutDirection==VERTICAL || cutDirection==BOTH){
			for(int j=topLeftX+1; j<=bottomRightX-1; j++){
				if(jwlCount(topLeftY,j,bottomRightY,j)==0){ // 잘리는 부분에 보석이 없어야 함
					ret+=(cutWays(topLeftY,topLeftX,bottomRightY,j-1,HORIZONTAL)*cutWays(topLeftY,j+1,bottomRightY,bottomRightX,HORIZONTAL));
				}
			}
		}
		return (cache[topLeftY][topLeftX][bottomRightY][bottomRightX][cutDirection]=ret);
	}
}

int main(void){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) scanf("%d",&a[i][j]);

	// imp 계산
	imp[1][1]=(a[1][1]==1?1:0);
	for(int i=2; i<=n; i++) imp[i][1]=imp[i-1][1]+(a[i][1]==1?1:0);
	for(int j=2; j<=n; j++) imp[1][j]=imp[1][j-1]+(a[1][j]==1?1:0);
	for(int i=2; i<=n; i++)
		for(int j=2; j<=n; j++)
			imp[i][j]=imp[i-1][j]+imp[i][j-1]-imp[i-1][j-1]+(a[i][j]==1?1:0);

	// jwl 계산
	jwl[1][1]=(a[1][1]==2?1:0);
	for(int i=2; i<=n; i++) jwl[i][1]=jwl[i-1][1]+(a[i][1]==2?1:0);
	for(int j=2; j<=n; j++) jwl[1][j]=jwl[1][j-1]+(a[1][j]==2?1:0);
	for(int i=2; i<=n; i++)
		for(int j=2; j<=n; j++)
			jwl[i][j]=jwl[i-1][j]+jwl[i][j-1]-jwl[i-1][j-1]+(a[i][j]==2?1:0);

	// cutWays 계산
	for(int i=1; i<=n; i++)
	for(int j=1; j<=n; j++)
	for(int k=1; k<=n; k++)
	for(int l=1; l<=n; l++)
	for(int m=0; m<3; m++)
		cache[i][j][k][l][m]=-1;
	long long ans=cutWays(1,1,n,n,BOTH);

	// 답 출력
	if(ans==0) ans=-1;
	printf("%lld\n",ans);

	return 0;
}