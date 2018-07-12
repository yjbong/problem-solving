#include <cstdio>
#include <cstring>

char s[222]; // 압축 대상 문자열
int n; // 문자열 길이
int rep[222][222]; // rep[i][j] = 문자열 s[i~j]가 위치 i부터 연속으로 반복되는 횟수
int d[222][222]; // d[i][j] = 문자열 s[i~j]를 압축했을 때 최소의 길이

int min2(int a, int b){
	return a<b?a:b;
}
int numDigit(int a){ // 자연수 a의 자릿수
	int dgts=0;
	while(a>0){
		dgts++;
		a/=10;
	}
	return dgts;
}
int main(void){

	// 입력
	scanf("%s",s);
	n=strlen(s);

	// rep 배열 계산
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			rep[i][j]=1;
			for(int k=j+1; k+j-i<n; k+=(j-i+1)){
				bool ok=true;
				for(int l=0; l<=j-i; l++)
					if(s[k+l]!=s[i+l]){ ok=false; break; }
				
				if(ok) rep[i][j]++;
				else break;
			}
		}
	}

	// d 배열 초기화
	for(int i=0; i<n; i++)
		for(int j=i; j<n; j++)
			d[i][j]=j-i+1; // 압축 전의 길이

	for(int i=0; i<n; i++){ // i+1 : 고려 대상 문자열의 길이
		for(int j=0; j+i<n; j++){ // j : 문자열의 시작 위치

			// s[j~j+i]가 s[j~k], s[k+1~j+i]의 압축 결과를 붙여놓은 것일 때
			for(int k=j; k<j+i; k++)
				d[j][j+i]=min2(d[j][j+i], d[j][k]+d[k+1][j+i]);

			// s[j~j+i]를 s[j~k]가 반복되는 것으로 압축할 때
			for(int k=j; k<=j+i; k++){
				if(rep[j][k]*(k-j+1) == i+1){
					d[j][j+i]=min2(d[j][j+i], d[j][k]+2+numDigit(rep[j][k]));
				}
			}
		}
	}

	// 출력
	printf("%d\n",d[0][n-1]);
	return 0;
}