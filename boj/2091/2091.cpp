#include <cstdio>
#define INF 1000000000
#define CENT 0
#define NICKEL 1
#define DIME 2
#define QUARTER 3
int price; // coffee price

typedef struct{
	int kind;
	int quantity;
	int value; 
}COIN;

int kindQuantity[4]; // # of cents, nickels, dimes, quarters
const int kindValue[4]={1,5,10,25};

COIN coin[101]; // coin list (idx range: 1~coins)
int coins; // coin list size

int d[101][10001]; // d[i][j] = maximum # of coins with their value sum=j from coin[1~i]
int t[101][10001]; // t[i][j] = true if coin[i] is selected for d[i][j], false if not selected

int ansQuantity[4]; // answer # of cents, nickels, dimes, quarters

int main(void){

	scanf("%d",&price);
	for(int i=0; i<4; i++) scanf("%d",&kindQuantity[i]);
	
	// make coin list
	coins=0;
	for(int i=0; i<4; i++){
		int curQuantity=1;

		while(curQuantity<=kindQuantity[i]){
			coins++;
			coin[coins].kind=i;
			coin[coins].quantity=curQuantity;
			coin[coins].value=kindValue[i]*curQuantity;

			kindQuantity[i]-=curQuantity;
			curQuantity*=2;
		}
		if(kindQuantity[i]>0){
			coins++;
			coin[coins].kind=i;
			coin[coins].quantity=kindQuantity[i];
			coin[coins].value=kindValue[i]*kindQuantity[i];
		}
	}

	// Dynamic Programming

	// init table
	for(int i=0; i<=coins; i++)
		for(int j=0; j<=price; j++) d[i][j]=-INF;

	// Base case
	d[0][0]=0;

	// Run DP
	for(int i=1; i<=coins; i++){
		for(int j=0; j<=price; j++){
			d[i][j]=d[i-1][j];
			t[i][j]=0;
			if(j-coin[i].value>=0 && d[i][j]<d[i-1][j-coin[i].value]+coin[i].quantity){
				d[i][j]=d[i-1][j-coin[i].value]+coin[i].quantity;
				t[i][j]=1;
			}
		}
	}

	// calc answer quantity
	if(d[coins][price]>=0){
		int ci=coins, cj=price;
		while(ci>=1){
			if(t[ci][cj]){
				ansQuantity[coin[ci].kind]+=coin[ci].quantity;
				cj-=coin[ci].value;
				ci--;
			}
			else ci--;
		}
	}

	// print answer
	for(int i=0; i<4; i++)
		printf("%d ",ansQuantity[i]);
	printf("\n");

	return 0;
}