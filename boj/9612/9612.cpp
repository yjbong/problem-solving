#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n;
string word[1000];
int main(void){
	cin >> n;
	for(int i=0; i<n; i++) cin >> word[i];
	sort(word,word+n);

	int ansIdx=-1, ansCnt=0;
	int curIdx=0, curCnt=1;
	for(int i=1; i<n; i++){
		if(word[i-1]==word[i]) curCnt++;
		else{
			if(ansCnt<=curCnt){ ansIdx=curIdx, ansCnt=curCnt; }
			curIdx=i; curCnt=1;
		}
	}
	if(ansCnt<=curCnt){ ansIdx=curIdx, ansCnt=curCnt; }
	cout << word[ansIdx] << " " << ansCnt << endl;
	return 0;
}