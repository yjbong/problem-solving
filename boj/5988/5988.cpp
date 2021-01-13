#include <iostream>
#include <cstring>
using namespace std;
int N;
char num[61];
int main() {
    cin >> N;
    cin.get();
    for(int i=0; i<N; i++){
        cin.getline(num, 61);
        int lastDgt=num[strlen(num)-1]-'0';
        if(lastDgt%2) cout << "odd" << endl;
        else cout << "even" << endl;
    }
    return 0;
}