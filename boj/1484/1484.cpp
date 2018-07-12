#include <cstdio>
#define SIZE 100000
typedef long long ll;

ll G;
ll sqNum[SIZE+1]; // 1부터 10만까지의 제곱수 리스트

int main(void){

	for(ll i=1; i<=SIZE; i++) sqNum[i]=i*i;

	scanf("%lld",&G);

	bool ok=false;
	for(int i=1; i<=SIZE; i++){
		int left=1, right=SIZE;
		ll key=sqNum[i]-G;
		while(left<=right){
			int mid=(left+right)/2;
			if(sqNum[mid]<key) left=mid+1;
			else if(sqNum[mid]>key) right=mid-1;
			else{
				printf("%d\n",i);
				ok=true;
				break;			
			}
		}
	}
	if(!ok) printf("-1\n");

	return 0;
}