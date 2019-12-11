#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
int T;
char S[1001];
int main() {
    cin >> T;
    cin.get(); // 개행 문자 제거
    while(T--){
        std::cin.getline(S, 1000);
        int len=strlen(S);
        int ans=0, num=0;
        for(int i=0; i<len; i++){
            if(isdigit(S[i])){ num*=10; num+=S[i]-'0'; }
            else{ ans+=num; num=0; }
        }
        ans+=num;
        cout << ans << endl;
    }
    return 0;
}