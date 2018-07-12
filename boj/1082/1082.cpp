#include <cstdio>
int n;
int cost[10];
int minCost;
int money;

int main(void){

	while(scanf("%d",&n) == 1){
		for(int i=0; i<n; i++) scanf("%d",&cost[i]);
		scanf("%d",&money);

		minCost=cost[0];
		for(int i=1; i<n; i++)
			if(cost[i]<minCost) minCost=cost[i];

		bool firstDgt=true;
		while(money>=minCost){
			if(firstDgt){
				int curDgt=-1;
				for(int i=n-1; i>=1; i--){
					if(money-cost[i]>=0){
						if(curDgt<0 || ( (money-cost[curDgt])/minCost < (money-cost[i])/minCost) ) curDgt=i;
					}
				}

				if(curDgt<0){ printf("0"); break; }
				else{ printf("%d",curDgt); firstDgt=false; money-=cost[curDgt]; }
			}
			else{
				int curDgt=-1;
				for(int i=n-1; i>=0; i--){
					if(money-cost[i]>=0){
						if(curDgt<0 || ( (money-cost[curDgt])/minCost < (money-cost[i])/minCost) ) curDgt=i;
					}
				}
				if(curDgt>=0) { printf("%d",curDgt); money-=cost[curDgt]; }
			}
		}
		printf("\n");
	}
	return 0;
}