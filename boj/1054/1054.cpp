#include <cstdio>
#include <cstring>
typedef long long ll;

int N; // 단어의 개수
char W[13][14]; // W[i] = i번 단어

// D[i][j][k][0] : 사용한 단어 집합이 i이고, 현재 왼쪽 끝에서 j번 단어가 팰린드롬에 완전히 속하지 않고 남아있으며
// j번 단어에서 k개 문자까지는 팰린드롬에 속할 경우, (현재 상황을 포함해서) 앞으로 만들 수 있는 팰린드롬 문장의 수
// D[i][j][k][1] : 사용한 단어 집합이 i이고, 현재 오른쪽 끝에서 j번 단어가 팰린드롬에 완전히 속하지 않고 남아있으며
// j번 단어에서 k개 문자까지는 팰린드롬에 속할 경우, (현재 상황을 포함해서) 앞으로 만들 수 있는 팰린드롬 문장의 수
// D[i][13][0][0] : 사용한 단어 집합이 i이고, 현재 팰린드롬에 완전히 속하지 않은 단어가 없을 때, (현재 상황을 포함해서)
// 앞으로 만들 수 있는 팰린드롬 문장의 수
ll D[1<<13][14][14][2];

ll go(int stat, int lastWord, int partialMatchLen, int isRight){
	ll ret=0;
	bool ok;

	if(D[stat][lastWord][partialMatchLen][isRight]>=0) return D[stat][lastWord][partialMatchLen][isRight];

	if(lastWord==13){ // 사용된 단어의 모든 부분이 팰린드롬을 이룸

		// Case 1: 현재 상태에서 멈춤 (현 상태가 팰린드롬 문장인지 확인)
		if(stat>0) ret++; // 남은 부분이 없으므로 사용된 단어가 하나라도 있다면 현 상태는 무조건 팰린드롬

		// Case 2: 현재 상태에서 오른쪽에 새 단어를 붙임 (이 경우 왼쪽에 붙여도 같은 상황이므로 한 쪽만 고려하여 중복 방지)
		for(int i=0; i<N; i++){
			if(!(stat&(1<<i))){
				ret+=go(stat|(1<<i), i, 0, 1);
			}
		}
	}
	else if(isRight==0){ // 왼쪽 끝에 팰린드롬에 속하지 않은 문자열이 남아 있음

		// Case 1: 현재 상태에서 멈춤 (현 상태가 팰린드롬 문장인지 확인)
		// 왼쪽 끝에 남은 부분이 팰린드롬이라면 현 상태가 팰린드롬 문장임
		ok=true;
		for(int i=partialMatchLen, j=strlen(W[lastWord])-1; i<=j; i++, j--)
			if(W[lastWord][i]!=W[lastWord][j]){ ok=false; break; }	
		if(ok) ret++;

		// Case 2: 현재 상태에서 오른쪽에 새 단어를 붙임
		for(int i=0; i<N; i++){
			if(!(stat&(1<<i))){

				ok=true;
				for(int j=partialMatchLen, k=strlen(W[i])-1; j<strlen(W[lastWord]) && k>=0; j++, k--)
					if(W[lastWord][j]!=W[i][k]) { ok=false; break; }

				if(ok){
					int remainWordLen = strlen(W[lastWord])-partialMatchLen; // 현재 왼쪽에 남아 있는 문자열의 길이
					int newWordLen = strlen(W[i]); // 새로 추가할 문자열의 길이
					if(remainWordLen<newWordLen) ret+=go(stat|(1<<i), i, remainWordLen, 1);
					else if(remainWordLen>newWordLen) ret+=go(stat|(1<<i), lastWord, partialMatchLen+newWordLen, 0);
					else ret+=go(stat|(1<<i), 13, 0, 0);
				}
			}
		}
	}
	else{ // 오른쪽 끝에 팰린드롬에 속하지 않은 문자열이 남아 있음

		// Case 1: 현재 상태에서 멈춤 (현 상태가 팰린드롬 문장인지 확인)
		// 오른쪽 끝에 남은 부분이 팰린드롬이라면 현 상태가 팰린드롬 문장임
		ok=true;
		for(int i=0, j=strlen(W[lastWord])-partialMatchLen-1; i<=j; i++, j--)
			if(W[lastWord][i]!=W[lastWord][j]){ ok=false; break; }
		if(ok) ret++;

		// Case 2: 현재 상태에서 왼쪽에 새 단어를 붙임
		for(int i=0; i<N; i++){
			if(!(stat&(1<<i))){

				ok=true;
				for(int j=0, k=strlen(W[lastWord])-partialMatchLen-1; j<strlen(W[i]) && k>=0; j++, k--)
					if(W[i][j]!=W[lastWord][k]) { ok=false; break; }

				if(ok){
					int remainWordLen = strlen(W[lastWord])-partialMatchLen; // 현재 오른쪽에 남아 있는 문자열의 길이
					int newWordLen = strlen(W[i]); // 새로 추가할 문자열의 길이
					if(remainWordLen<newWordLen) ret+=go(stat|(1<<i), i, remainWordLen, 0);
					else if(remainWordLen>newWordLen) ret+=go(stat|(1<<i), lastWord, partialMatchLen+newWordLen, 1);
					else ret+=go(stat|(1<<i), 13, 0, 0);
				}
			}
		}
	}

	return (D[stat][lastWord][partialMatchLen][isRight]=ret);
}

int main(void){

	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%s",W[i]);

	for(int i=0; i<(1<<N); i++)
	for(int j=0; j<14; j++)
	for(int k=0; k<14; k++)
	for(int l=0; l<2; l++)
		D[i][j][k][l]=-1;

	ll ans=go(0,13,0,0);
	printf("%lld\n", ans);
	return 0;
}