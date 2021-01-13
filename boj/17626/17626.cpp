#include <iostream>
#define MAXN 50000
#define SQ_MAXN 223
using namespace std;
int N;
bool isSquare(int N){
    if(N<0) return false;
    int left=1, right=N;
    while(left<=right){
        int mid=(left+right)/2;
        if(mid*mid<N) left=mid+1;
        else if(mid*mid>N) right=mid-1;
        else return true;
    }
    return false;
}
int main() {
    cin >> N;
    if(isSquare(N)) { cout << "1" << endl; return 0; }
    for(int i=1; i<=SQ_MAXN; i++)
        if(isSquare(N-i*i)){ cout << "2" << endl; return 0; }
    for(int i=1; i<=SQ_MAXN; i++)
        for(int j=1; j<=SQ_MAXN; j++)
            if(isSquare(N-i*i-j*j)){ cout << "3" << endl; return 0; }
    cout << "4" << endl;
    return 0;
}