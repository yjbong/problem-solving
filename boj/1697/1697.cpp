#include <cstdio>
#include <queue>
#define INF 1000000000
using namespace std;
int d[200002];
queue <int> q;
int main(void){
	
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0; i<200002; i++) d[i]=INF;
	
	d[n]=0;
	q.push(n);
	while(!q.empty()){
		int f=q.front();
		q.pop();
		if(f-1>=0 && d[f-1]>d[f]+1){
			d[f-1]=d[f]+1;
			q.push(f-1);
		}
		if(f+1<200002 && d[f+1]>d[f]+1){
			d[f+1]=d[f]+1;
			q.push(f+1);
		}
		if(f*2<200002 && d[f*2]>d[f]+1){
			d[f*2]=d[f]+1;
			q.push(f*2);
		}
	}
	printf("%d\n",d[k]);
	return 0;
}