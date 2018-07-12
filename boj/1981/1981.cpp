#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int,int> ii;
int n; // 배열의 크기 n*n
int a[100][100]; // 배열
bool c[100][100]; // 방문 여부
const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,-1,1};

// (0,0)에서 (n-1,n-1)로의 이동 경로 중, 경로에 있는 숫자 중 최소값이 lowerBound 이상이고, 최대값이 upperBound 이하인 것이 있는지 여부
bool movable(int lowerBound, int upperBound){
	if(a[0][0]<lowerBound || a[0][0]>upperBound) return false;

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) c[i][j]=false;

	queue <ii> q;
	q.push(make_pair(0,0));
	c[0][0]=true;

	while(!q.empty()){
		int fy=q.front().first;
		int fx=q.front().second;
		q.pop();

		// (n-1,n-1)에 도달하는 경로가 존재하는 경우
		if(fy==n-1 && fx==n-1) return true;

		for(int i=0; i<4; i++){
			int cy=fy+dy[i];
			int cx=fx+dx[i];
			if(cy<0 || cy>=n || cx<0 || cx>=n) continue;
			if(c[cy][cx]==false && a[cy][cx]>=lowerBound && a[cy][cx]<=upperBound){
				q.push(make_pair(cy,cx));
				c[cy][cx]=true;
			}	
		}
	}
	return false;
}

int main(void){
	scanf("%d",&n);

	int min=1000000000, max=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d",&a[i][j]);
			if(min>a[i][j]) min=a[i][j];
			if(max<a[i][j]) max=a[i][j];
		}
	}

	int ans=max-min;
	for(int i=min; i<=max; i++){ // lowerBound는 특정 값으로 고정

		// lowerBound가 고정된 상태에서 이분탐색으로 최적의 upperBound값을 찾음
		int left=i, right=max;
		while(left<=right){
			int mid=(left+right)/2;
			if(movable(i,mid)){ // upperBound=mid일 때 이동 가능한 경우
				if(ans>mid-i) ans=mid-i;
				right=mid-1;
			}
			else left=mid+1;
		}
	}
	printf("%d\n",ans);
	return 0;
}