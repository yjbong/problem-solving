#include <cstdio>
#include <cstring>
#define DATA_LIMIT 100000000

typedef struct{
	int data[11];
}BIGNUM;

void add(BIGNUM *a, BIGNUM b){ // a=a+b
	int carry = 0;
	for(int i=0; i<11; i++){
		a->data[i] += b.data[i] + carry;
		carry = 0;
		carry = (a->data[i]) / DATA_LIMIT;
		a->data[i] %= DATA_LIMIT;
	}
}

void print(BIGNUM a){
	bool nonzero=false;
	for(int i=10; i>=0; i--){
		if(!nonzero){
			if(a.data[i]!=0){
				nonzero=true;
				printf("%d",a.data[i]);
			}
		}
		else printf("%08d",a.data[i]);
	}
	printf("\n");
}

BIGNUM d[251];

int main(void){
	d[0].data[0] = 1; // d[0]=1
	d[1].data[0] = 1; // d[1]=1

	for(int i=2; i<=250; i++){
		//d[i] = d[i-1] + d[i-2] + d[i-2];
		add(&d[i], d[i-1]);
		add(&d[i], d[i-2]);
		add(&d[i], d[i-2]);
	}

	int n;
	while(scanf("%d",&n)==1) print(d[n]);
	return 0;
}