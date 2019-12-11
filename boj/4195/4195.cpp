#include <iostream>
#include <string>
#include <map>
#define MAX_F 100000
using namespace std;
 
int T; // 테스트 케이스의 수
int F; // 친구 관계의 수
int names; // 입력에 등장한 이름의 가짓수
int p[MAX_F*2]; // p[i]=i번째 등장한 이름의 부모 idx, 이 값이 음수라면 이걸 루트로 하는 집합의 크기가 -p[i]
map <string, int> name2idx; // 이름과 등장한 순서(0부터)를 매핑
 
int find2(int idx){
    while(p[idx]>=0) idx=p[idx];
    return idx;
}
int union2(int idx1, int idx2){ // 합친 후의 집합 크기를 리턴
    int p1=find2(idx1), p2=find2(idx2);
    if(p1==p2) return -p[p1];
    if(p[p1]<=p[p2]){ // 집합 p1의 크기가 p2의 크기보다 크거나 같음
        p[p1]+=p[p2];
        p[p2]=p1;
        return -p[p1];
    }
    else{ // 집합 p2의 크기가 p1의 크기보다 큼
        p[p2]+=p[p1];
        p[p1]=p2;
        return -p[p2];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> F; cin.get();
        names=0; name2idx.clear();
        for(int i=0; i<F; i++){
 
            // 입력된 친구 관계를 n1, n2로 저장
            string s;
            getline(cin, s);
            string n1="", n2="";
            int j=0;
            for(; j<s.size() && s[j]!=' '; j++) n1.push_back(s[j]);
            j++;
            for(; j<s.size() && s[j]!=' '; j++) n2.push_back(s[j]);
 
            // n1, n2의 idx 확인
            int idx1,idx2;
            map<string, int>::iterator it;
            it=name2idx.find(n1);
            if(it!=name2idx.end()) idx1=it->second;
            else{ // n1이 등장한 적이 없는 이름인 경우
                idx1=names;
                p[names]=-1;
                name2idx.insert(make_pair(n1, names++));
            }
            it=name2idx.find(n2);
            if(it!=name2idx.end()) idx2=it->second;
            else{ // n2가 등장한 적이 없는 이름인 경우
                idx2=names;
                p[names]=-1;
                name2idx.insert(make_pair(n2, names++));
            }
            cout << union2(idx1,idx2) << "\n";
        }
    }
    return 0;
}