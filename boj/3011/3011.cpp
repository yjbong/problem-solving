#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_N 100
#define INF 1000000001
using namespace std;
int N; // 아들의 수
int name[MAX_N]; // name[i]=i번 아들의 이름
int A,B; // 구간
vector<int> candidate; // 딸의 이름 후보
 
int main() {
    cin >> N;
    for(int i=0; i<N; i++) cin >> name[i];
    cin >> A >> B;
    sort(name,name+N);
 
    // candidate 생성
    candidate.push_back(A%2?A:A+1);
    candidate.push_back(B%2?B:B-1);
    for(int i=0; i<N-1; i++){
        // name[i]~name[i+1] 구간을 고려
        int mid=(name[i]+name[i+1])/2;
        if(mid%2) candidate.push_back(mid);
        else{
            candidate.push_back(mid-1);
            candidate.push_back(mid+1);
        }
    }
 
    // 가장 적합한 candidate 선택
    int ans=INF, maxDiff=-1;
    int candidates=candidate.size();
    for(int i=0; i<candidates; i++){
        int cur=candidate[i];
        if(cur<A || cur>B) continue;
 
        int curDiff=INF;
        for(int j=0; j<N; j++)
            if(curDiff>abs(cur-name[j]))
                curDiff=abs(cur-name[j]);
 
        if(maxDiff<curDiff){
            maxDiff=curDiff;
            ans=cur;
        }
    }
 
    cout << ans << endl;
    return 0;
}