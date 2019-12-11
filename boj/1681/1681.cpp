#include <iostream>
using namespace std;
int N,L;
bool isValid(int n, int l){
    while(n>0){
        if(n%10==l) return false;
        n/=10;
    }
    return true;
}
int main() {
    cin >> N >> L;
    for(int i=1, j=1; ; j++){
        if(isValid(j,L)){
            if(i==N){ cout << j << endl; break; }
            i++;
        }
    }
    return 0;
}