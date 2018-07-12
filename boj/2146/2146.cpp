#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int,int> ii;
int a[111][111];
bool c[111][111];
int t[111][111]; // time when added

int n;
queue <ii> q;
vector <ii> v;
const int dy[4]={-1,1,0,0};
const int dx[4]={0,0,1,-1};

int main(void){

	scanf("%d",&n);
	for(int i=0; i<=n+1; i++)
		for(int j=0; j<=n+1; j++) a[i][j]=-1;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) scanf("%d",&a[i][j]);

	// marking
	for(int i=0; i<=n+1; i++)
		for(int j=0; j<=n+1; j++) c[i][j]=false;

	int mark=1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(!c[i][j] && a[i][j]>0){
				a[i][j]=mark;
				c[i][j]=true;
				q.push(make_pair(i,j));
				while(!q.empty()){
					ii f=q.front();
					q.pop();
					for(int k=0; k<4; k++){
						int cy=f.first+dy[k];
						int cx=f.second+dx[k];
						if(!c[cy][cx] && a[cy][cx]>0){
							a[cy][cx]=mark;
							c[cy][cx]=true;
							q.push(make_pair(cy,cx));
						}
					}
				}
				mark++;
			}
		}
	}


	// growing island step by step
	int ans=0;
	
	if(mark>2){
		for(int i=0; i<=n+1; i++)
			for(int j=0; j<=n+1; j++) t[i][j]=0;

		int ctime=1;

		while(1){
		
			// init visit state
			for(int i=0; i<=n+1; i++)
				for(int j=0; j<=n+1; j++) c[i][j]=false;

			bool is_plus1 = false;

			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++){
					if(!c[i][j] && a[i][j]>0){
						int cmark=a[i][j];
						c[i][j]=true;
						q.push(make_pair(i,j));
						while(!q.empty()){
							ii f=q.front();
							q.pop();
							for(int k=0; k<4; k++){
								int cy=f.first+dy[k];
								int cx=f.second+dx[k];

								if(a[cy][cx]>0 && a[cy][cx]!=cmark){ // connected to another island
									if(t[cy][cx]==ctime) is_plus1 = true;
									else goto out;
								}

								else if(!c[cy][cx] && a[cy][cx]==0){
									c[cy][cx]=true;
									v.push_back(make_pair(cy,cx));
								}
								else if(!c[cy][cx] && a[cy][cx]==cmark){
									c[cy][cx]=true;
									q.push(make_pair(cy,cx));
								}
							}
						}

						// grow
						for(int k=0; k<v.size(); k++){
							a[v[k].first][v[k].second]=cmark;
							t[v[k].first][v[k].second]=ctime;
						}
						v.clear();
					}
				}
			}
			if(is_plus1){ ans++; break; }
			
			ans+=2;
			ctime++;
		}
out:
	;
		printf("%d\n",ans);
	}

	return 0;
}