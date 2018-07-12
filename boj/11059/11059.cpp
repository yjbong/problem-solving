#include <cstdio>
#include <cstring>
char s[1001];
int sLen;
int d[1001]; // d[i] = s[0~i]까지의 자리수 합
int main(void){
	scanf("%s",s);
	sLen=strlen(s);
	d[0]=s[0]-'0';
	for(int i=1; i<sLen; i++) d[i]=d[i-1]+s[i]-'0';

	int ans=0;
	for(int i=0; i<sLen; i++){
		for(int j=i; j<sLen; j++){ // 문자열의 앞의 반쪽이 s[i~j]라고 가정
			int curLen=j-i+1; // 앞의 반쪽 길이
			if(j+curLen<sLen){ // s[i~j] 같은 길이의 뒤쪽 문자열 s[j+1~j+curLen]이 존재하는 경우
				int lsum=d[j]; // 앞의 반쪽의 자리수 합
				if(i>0) lsum-=d[i-1];
				int rsum=d[j+curLen]-d[j]; // 뒤의 반쪽의 자리수 합

				// 답 업데이트
				if(lsum==rsum){
					if(ans<curLen*2) ans=curLen*2;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}