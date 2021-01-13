#include <iostream>
#include <vector>
#define MAXN 1000000
using namespace std;
vector <int> fibo;
// num을 Zeckendorf 분해했을 때 가장 작은 값
int minZeckendorf(int num){
    int curFibo;
    do{
        int left=0, right=fibo.size()-1;
        curFibo=0;
        while(left<=right){
            int mid=(left+right)/2;
            if(num<fibo[mid]) right=mid-1;
            else{
                if(curFibo<fibo[mid]) curFibo=fibo[mid];
                left=mid+1;
            }
        }
        num-=curFibo;
    }while(num>0);
    return curFibo;
}
int main() {
    fibo.push_back(1);
    fibo.push_back(2);
 
    while(fibo[fibo.size()-1]+fibo[fibo.size()-2]<=MAXN) fibo.push_back(fibo[fibo.size()-1]+fibo[fibo.size()-2]);
 
    int N;
    cin >> N;
    int ans=minZeckendorf(N);
    if(ans==N) ans=-1;
    cout << ans << endl;
    return 0;
}