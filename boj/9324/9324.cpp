#include <iostream>
#include <cstring>
#define MAXLEN 100000
using namespace std;
int T;
char M[MAXLEN+1];
int cnt[26]; // 문자열에 있는 각 알파벳의 개수
int main() {
    cin >> T;
    cin.get();
    while(T--){
        cin.getline(M,MAXLEN+1);
        //cout << M << endl;
        int len=strlen(M);
        for(int i=0; i<26; i++) cnt[i]=0;
        bool ok=true;
        for(int i=0; i<len; i++){
            cnt[M[i]-'A']++;
            if(cnt[M[i]-'A']%3==0){
                if(i==len-1 || M[i+1]!=M[i]){ ok=false; break; }
                i++;
            }
        }
        if(ok) cout << "OK" << endl;
        else cout << "FAKE" << endl;
    }
	return 0;
}