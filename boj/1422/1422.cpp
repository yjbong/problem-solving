#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

int k; // 가지고 있는 수의 개수
int n; // 뽑아야 하는 수의 개수 (k<=n)
vector <ii> numList; // 수의 리스트(중복되지 않음) first: 수, second: 이 수의 개수

void itoa2(char str[], int a){ // 자연수 a를 문자열로 변환
	int i=0;
	while(a>0){
		str[i++]=(a%10)+'0';
		a/=10;
	}
	str[i]='\0';
	for(int i=0; i<strlen(str)/2; i++){
		char tmp=str[i];
		str[i]=str[strlen(str)-1-i];
		str[strlen(str)-1-i]=tmp;
	}
}

int gcd(int a, int b){ // a와 b의 최대공약수
	if(b==0) return a;
	return gcd(b, a%b);
}

int lcm(int a, int b){ // a와 b의 최소공배수
	return (a*b)/gcd(a,b);
}

bool compare(ii a, ii b){ // 수를 사전 순으로 비교

	int anum=a.first;
	int bnum=b.first;

	char aStr[11];
	char bStr[11];
	itoa2(aStr, anum);
	itoa2(bStr, bnum);
	int aLen=strlen(aStr);
	int bLen=strlen(bStr);

	// 수 a와 b를 계속 중복시키면서 비교
	int j=0,k=0;
	for(int i=0; i<lcm(aLen,bLen); i++){
		if(aStr[j]<bStr[k]) return true; // a가 b보다 사전순으로 앞
		else if(aStr[j]>bStr[k]) return false; // a가 b보다 사전순으로 뒤
		else{
			j=(j+1)%aLen;
			k=(k+1)%bLen;
		}
	}
	
	return true;
}

int main(void){

	// 입력
	scanf("%d %d",&k,&n);
	for(int i=0; i<k; i++){
		int curNum;
		scanf("%d",&curNum);
		bool dup=false;
		for(int j=0; j<numList.size(); j++){
			if(numList[j].first==curNum){
				numList[j].second++;
				dup=true;
				break;
			}
		}
		if(!dup) numList.push_back(make_pair(curNum,1));
	}

	sort(numList.begin(), numList.end()); // 수를 크기 순으로 소팅

	// 리스트 내의 모든 수를 최소 이용 횟수만큼 사용(k)한 뒤 남은 n값만큼 가장 큰 수를 뽑음
	numList[numList.size()-1].second+=(n-k);

	sort(numList.begin(), numList.end(), compare); // 수를 사전 순으로 소팅

	// 출력
	for(int i=numList.size()-1; i>=0; i--)
		for(int j=0; j<numList[i].second; j++)
			printf("%d",numList[i].first);
	printf("\n");
	return 0;
}