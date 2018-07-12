#include <cstdio>
typedef long long ll;
ll n;
int dgt[10], dgts;
ll pow[10];
int main(void){

	// 10의 거듭제곱 계산
	pow[0]=1;
	for(int i=1; i<10; i++) pow[i]=pow[i-1]*10;

	scanf("%lld",&n);
	dgts=0;
	long long tmp=n;
	while(tmp>0){
		if(tmp%10>0) dgt[dgts++]=tmp%10; // 0아닌 n의 자릿수 추가
		tmp/=10;
	}

	// 1,2,3, ... , 9의 최소공배수는 2520이므로, 최대 4자리를 더 붙이는 것으로 충분함
	for(int i=0; i<5; i++){
		for(int j=0; j<pow[i]; j++){
			ll curNum=n*pow[i]+j;
			bool ok=true;
			for(int k=0; k<dgts; k++){
				if(curNum%dgt[k]>0){
					ok=false;
					break;
				}
			}
			if(ok){
				printf("%lld\n",curNum);
				goto out;
			}
		}
	}
out:
	return 0;
}