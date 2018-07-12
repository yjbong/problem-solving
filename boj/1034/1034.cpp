#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N,M; // 테이블의 행,열 크기
int K; // 스위치를 누르는 횟수
string table[50]; // table[i] = 테이블 i행의 상태
int main(void){
	cin >> N >> M;
	for(int i=0; i<N; i++) cin >> table[i];
	cin >> K;

	sort(table,table+N);

	int ans=0;
	string oldRow=table[0];
	int cnt=1;
	for(int i=1; i<N; i++){
		if(table[i].compare(oldRow)!=0){
			// oldRow가 K번 스위치를 눌러서 켜진 행이 될 수 있는지 확인
			int offs=0;
			for(int j=0; j<oldRow.size(); j++) if(oldRow.at(j)=='0') offs++;
			if(offs<=K && offs%2==K%2){
				if(ans<cnt) ans=cnt;
			}
			oldRow=table[i];
			cnt=1;
		}
		else cnt++;
	}
	int offs=0;
	for(int j=0; j<oldRow.size(); j++) if(oldRow.at(j)=='0') offs++;
	if(offs<=K && offs%2==K%2){
		if(ans<cnt) ans=cnt;
	}
	cout << ans << endl;

	return 0;
}