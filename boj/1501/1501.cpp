#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int N; // 사전에 있는 단어들의 개수
int M; // 해석할 문장의 개수

string dic[10001]; // dic[i] : 사전에서 i번째 단어

map <string,int> dictionary[10001]; // dictionary[i] = 길이가 i인 단어들의 목록

int main(void){
	cin >> N;

	for(int i=0; i<N; i++){

		cin >> dic[i];

		// 단어의 첫 글자와 마지막 글자를 빼고는 순서가 상관 없으므로 정렬시켜 놓음
		if(dic[i].size()>=4) sort(dic[i].begin()+1, dic[i].end()-1);

		map<string,int>::iterator it;
		it=dictionary[dic[i].size()].find(dic[i]);
		// 현재 key string이 map에 없는 경우, 추가
		if(it==dictionary[dic[i].size()].end()) dictionary[dic[i].size()].insert(pair<string,int>(dic[i],1));
		// 이미 있는 경우, 개수만 증가시킴
		else (it->second)++;
	}

	cin >> M;
	while(cin.get() != '\n') continue;

	for(int i=0; i<M; i++){

		int ans=1;

		// 한 줄씩 sentence에 입력받음
		string sentence;
		getline(cin,sentence,'\n');

		// sentence를 공백 문자로 token 구분하여, 각 token별로 dictionary 검색
		istringstream ss(sentence);
		string token;

		while(getline(ss, token, ' ')){

			// 입력된 문자열의 첫 글자와 마지막 글자를 빼고 정렬시킨 상태에서 map을 검색함
			if(token.size()>=4) sort(token.begin()+1, token.end()-1);
			map<string,int>::iterator it;
			it=dictionary[token.size()].find(token);
			if(it!=dictionary[token.size()].end()) ans*=(it->second);
			else ans=0;
		}

		cout << ans << endl;
	}
	
	return 0;
}