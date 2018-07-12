#include <cstdio>
int earn[21][301]; // earn[i][j] : i번 기업에 (invest[j])만원을 투자했을 때 얻는 이익
int invest[301]; // invest[i] = i번째 투자 가능 금액
int invests; // 투자 가능 금액의 가짓수
int d[21][301]; // d[i][j] : 1~i번 기업에 대해, j만원 이하를 투자해서 얻을 수 있는 최대 이익
int ans[21]; // 최대 이익을 얻기 위해 i번 기업에 투자한 금액

int money; // 자금
int comps; // 회사의 수
int main(void){
	scanf("%d %d",&money,&comps);
	invests=0;
	invest[invests++]=0; // 0만원을 투자할 수도 있음

	int curInvest;
	while(scanf("%d",&curInvest)==1){
		invest[invests]=curInvest;
		for(int i=1; i<=comps; i++) scanf("%d",&earn[i][invests]);
		invests++;
	}
	
	for(int i=1; i<=comps; i++){
		for(int j=0; j<=money; j++){
			for(int k=0; k<invests; k++){ // i번 기업에 invest[k]만원을 투자하는 경우
				if(j>=invest[k] && d[i][j]<d[i-1][j-invest[k]]+earn[i][k]){
					d[i][j]=d[i-1][j-invest[k]]+earn[i][k];
				}
			}
		}
	}

	// 최대 이익
	printf("%d\n",d[comps][money]);

	// 최적 투자 방법
	int curMoney=money;
	for(int i=comps; i>=1; i--){
		for(int k=0; k<invests; k++){
			if(curMoney>=invest[k] && d[i][curMoney]==d[i-1][curMoney-invest[k]]+earn[i][k]){
				ans[i]=invest[k];
				curMoney-=invest[k];
				break;
			}
		}
	}
	for(int i=1; i<=comps; i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}