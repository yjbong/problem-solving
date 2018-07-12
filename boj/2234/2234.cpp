#include <cstdio>
#include <queue>
const int dy[4]={0,-1,0,1};
const int dx[4]={-1,0,1,0};
const int w[4]={1,2,4,8};
using namespace std;
typedef pair<int,int> ii;
int a[50][50];
int b[50][50];
int size[50*50+1];
queue <ii> q;
int n,m;
int main(void){
	
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++) scanf("%d",&a[i][j]);
	
	int rooms=0;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(!b[i][j]){
				rooms++;
				size[rooms]=0;

				q.push(make_pair(i,j));
				while(!q.empty()){
					ii f=q.front();
					q.pop();
					size[rooms]++;

					int fy=f.first;
					int fx=f.second;
					b[fy][fx]=rooms;
					for(int k=0; k<4; k++){
						int cy=fy+dy[k];
						int cx=fx+dx[k];
						if(!(a[fy][fx]&w[k])){
							if(!b[cy][cx]){
								b[cy][cx]=rooms;
								q.push(make_pair(cy,cx));
							}
						}
					}
				}
			}
		}
	}
	
	printf("%d\n",rooms);
	int max_size=0;
	for(int i=1; i<=rooms; i++) if(max_size<size[i]) max_size=size[i];
	printf("%d\n",max_size);

	int max_sum_size=0;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<4; k++){
				int cy=i+dy[k];
				int cx=j+dx[k];
				if(cy>=0 && cy<m && cx>=0 && cx<n){
					if(b[i][j]!=b[cy][cx]){
						if(max_sum_size<size[b[i][j]]+size[b[cy][cx]])
							max_sum_size=size[b[i][j]]+size[b[cy][cx]];
					}
				}
			}
		}
	}
	printf("%d\n",max_sum_size);
	return 0;
}