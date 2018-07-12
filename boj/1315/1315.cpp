#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int,int> ii;

int STR[111];
int INT[111];
int PNT[111];

int p[1111][1111]; // p[i][j] = sum of poinrs of playable quests when STR=i and INT=j
int a[1111][1111]; // a[i][j] = num of playable quests when STR=i and INT=j
bool d[1111][1111]; // d[i][j] = possiblity of the status that STR=i and INT=j
int n;

queue <ii> q;

int main(void){

	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d %d %d",&STR[i],&INT[i],&PNT[i]);
	for(int i=1; i<=1000; i++){
		for(int j=1; j<=1000; j++){
			for(int k=0; k<n; k++){
				if(STR[k]<=i || INT[k]<=j){
					p[i][j]+=PNT[k];
					a[i][j]++;
				}
			}
		}
	}
	
	q.push(make_pair(1,1));
	d[1][1]=true;
	while(!q.empty()){
		ii f=q.front(); q.pop();
		int fSTR=f.first; int fINT=f.second;
		int fPNT=p[fSTR][fINT];
		int fRemainPNT=fPNT-(fSTR-1+fINT-1);
		for(int i=0; i<=fRemainPNT; i++){
			int cSTR=fSTR+i; int cINT=fINT+(fRemainPNT-i);
			if(cSTR>1000) cSTR=1000; if(cINT>1000) cINT=1000;
			if(d[cSTR][cINT]==false){
				q.push(make_pair(cSTR, cINT));
				d[cSTR][cINT]=true;
			}
		}
	}

	int ans=0;
	for(int i=1; i<=1000; i++)
		for(int j=1; j<=1000; j++)
			if(d[i][j] && a[i][j]>ans) ans=a[i][j];

	printf("%d\n", ans);
	return 0;
}