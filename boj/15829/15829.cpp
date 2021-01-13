#include <iostream>
using namespace std;
int N;
string S;
int main() {
	cin >> N;
    cin >> S;
    long long r=31, M=1234567891, hash=0;
    for(int i=S.length()-1; i>=0; i--)
        hash=(hash*r+S[i]-'a'+1)%M;
    cout << hash << endl;
    return 0;
}