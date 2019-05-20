#include <cstdio>
#include <cstring>
int N;
char str[101];
int A[100];
int S[100]; //S[i]=A[0]+A[1]+...+A[i]
int main() {
	scanf("%s",str);
    N=strlen(str);
    for(int i=0; i<N; i++) A[i]=str[i]-'0';
    S[0]=A[0];
    for(int i=1; i<N; i++) S[i]=S[i-1]+A[i];

    int ans=0;
    for(int i=N/2*2; i>=2; i-=2){ // i=부분 문자열 길이
        for(int j=0; j+i-1<N; j++){ // j=부분 문자열 시작 위치
            int left=S[j+i/2-1]-(j>0?S[j-1]:0);
            int right=S[j+i-1]-S[j+i/2-1];
            if(left==right){ ans=i; goto out; }
        }
    }
out:
    printf("%d\n",ans);
	return 0;
}