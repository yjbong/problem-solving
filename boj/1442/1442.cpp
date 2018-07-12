#include <cstdio>

typedef long long ll;
ll L,R;
// d[i][j][k][l] = i자리 이진수 중에서 j(0또는 1)로 시작하며, 그 j가 앞에서부터 k번(k=3보다 큰 경우는 k=3)
//		연속되며 이전에 0 또는 1이 3번 이상 반복되었는지 여부가 l(0또는 1)인 수의 개수
ll d[32][2][4][2];

// prefix로 시작하면서 limit 보다 작거나 같고, 남은 자릿수가 digits인 멋진 수의 개수
ll niceNums(ll prefix, ll digits, ll limit){

	ll curStartValue=prefix<<digits;
	ll curEndValue=curStartValue+(1ll<<digits)-1;
	if(curStartValue>limit) return 0;
	else if(curEndValue>limit)
		return niceNums(prefix<<1ll, digits-1, limit) + niceNums((prefix<<1ll)+1, digits-1, limit);
	else{
		// prefix의 자리수 구하기
		ll tmp=prefix;
		ll prefixDigits=0;
		while(tmp>0){
			tmp>>=1ll;
			prefixDigits++;	
		}

		// prefix에서 이미 0 또는 1이 3번 이상 반복되었는지 확인
		bool leadingZero=true;
		ll zeros=0, ones=0;
		bool ok=false;
		for(ll i=prefixDigits-1; i>=0; i--){
			if((prefix&(1ll<<i))==0){
				ones=0;
				if(leadingZero==false) zeros++;
				if(zeros==3){ ok=true; break; }
			}
			else{
				zeros=0;
				leadingZero=false;
				ones++;
				if(ones==3){ ok=true; break; }
			}
		}
			
		// prefix에서 이미 0 또는 1이 3번 이상 반복됨
		ll ret=0;
		if(ok) ret=1ll<<digits;
		else{
			// 그렇지 않은 경우 prefix의 하위 2비트에서 0또는 1이 몇 번 연속되어 있는지 확인
			ll lastDigit=prefix&0x1; // lastDigit = prefix의 최하위 비트
			ll lastDigits=1ll; // lastDigit가 최하위 비트에서부터 반복된 횟수

			// 최하위 비트 바로 위의 비트가 lastDigit와 같을 경우 반복 횟수 추가
			if((prefixDigits>1ll) && (((prefix&0x2)>>1ll) == lastDigit)) lastDigits++;

			// 현재 prefix에 digits 길이의 이진수가 붙어서 나올 수 있는 멋진 수의 개수를 계산
			ret=0;
			for(ll i=3-lastDigits; i<=3; i++) ret+=d[digits][lastDigit][i][0];
			ret+=d[digits][1-lastDigit][3][0];
	
			for(ll i=0; i<2; i++)
				for(ll j=0; j<4; j++)
					ret+=d[digits][i][j][1];
		}

		return ret;
	}
}

int main(void){
	scanf("%lld %lld",&L,&R);

	// d 배열 계산
	d[1][0][1][0]=1; d[1][1][1][0]=1; // base case
	for(ll i=2; i<32; i++){
		d[i][0][1][0] = d[i-1][1][1][0] + d[i-1][1][2][0];
		d[i][0][2][0] = d[i-1][0][1][0];
		d[i][0][3][0] = d[i-1][0][2][0] + d[i-1][0][3][0];

		d[i][0][1][1] = d[i-1][1][1][1] + d[i-1][1][2][1] + d[i-1][1][3][0] + d[i-1][1][3][1];
		d[i][0][2][1] = d[i-1][0][1][1];
		d[i][0][3][1] = d[i-1][0][2][1] + d[i-1][0][3][1];

		d[i][1][1][0] = d[i-1][0][1][0] + d[i-1][0][2][0];
		d[i][1][2][0] = d[i-1][1][1][0];
		d[i][1][3][0] = d[i-1][1][2][0] + d[i-1][1][3][0];

		d[i][1][1][1] = d[i-1][0][1][1] + d[i-1][0][2][1] + d[i-1][0][3][0] + d[i-1][0][3][1];
		d[i][1][2][1] = d[i-1][1][1][1];
		d[i][1][3][1] = d[i-1][1][2][1] + d[i-1][1][3][1];
	}

	// 답 계산
	ll ans=0;
	for(ll i=0; i<31; i++){
		ll curRightValue=niceNums(1ll,i,R);
		ll curLeftValue=niceNums(1ll,i,L-1);	
		ans+=niceNums(1ll,i,R)-niceNums(1ll,i,L-1);
	}
	
	// 출력
	printf("%lld\n",ans);
	return 0;
}