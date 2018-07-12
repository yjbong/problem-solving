#include <cstdio>

int events; // # of events
int d[401][401]; // d[i][j] = -1 if event i is before event j
		 // d[i][j] =  order between i and j is unknown
		 // d[i][j] =  1 if event i is after event j

int orders; // # of known orders
int queries; // # of queries

int main(void){

	// input
	scanf("%d %d",&events,&orders);
	for(int i=0; i<orders; i++){
		int from, to;
		scanf("%d %d",&from,&to);
		d[from][to]=-1;
		d[to][from]=1;
	}
	
	// floyd
	for(int k=1; k<=events; k++){
		for(int i=1; i<=events; i++){
			for(int j=1; j<=events; j++){
				if(d[i][k]==-1 && d[k][j]==-1) d[i][j]=-1;
				if(d[i][k]==1 && d[k][j]==1) d[i][j]=1;
			}
		}
	}

	// answer
	scanf("%d",&queries);
	for(int i=0; i<queries; i++){
		int from, to;
		scanf("%d %d",&from,&to);
		printf("%d\n",d[from][to]);
	}
	return 0;
}