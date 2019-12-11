#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char n[10];
    for(int i=0; i<3; i++){
        cin.getline(n,10);
        int ans=1;
        int cnt=1;
        for(int j=1; j<strlen(n); j++){
            if(n[j]==n[j-1]) cnt++;
            else cnt=1;
            if(ans<cnt) ans=cnt;
        }
        cout << ans << endl;
    }
    return 0;
}