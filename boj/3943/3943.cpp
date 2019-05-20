#include <cstdio>
#include <vector>
#include <map>
#define MAX_N 100000
using namespace std;
int T; // 테스트 케이스 수
int N; // 헤일스톤 수열의 시작 수
vector<int> seq;
map<int, int> d; // first: i, second: 수 i로부터 시작하는 헤일스톤 수열 중 가장 큰 수 
int main() {
    d.insert(make_pair(1, 1));
	scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        if(d.find(N)!=d.end()){ printf("%d\n",(d.find(N))->second); continue; }
        int tmp=N;
        seq.clear();

        int maxSeq=1;
        while(d.find(tmp)==d.end()){
            seq.push_back(tmp);
            if(tmp%2) tmp=tmp*3+1;
            else tmp/=2;

            if(d.find(tmp)!=d.end()){
                int curMax=(d.find(tmp))->second;
                if(maxSeq<curMax) maxSeq=curMax;
            }
        }

        for(int i=seq.size()-1; i>=0; i--){
            if(maxSeq<seq[i]) maxSeq=seq[i];
            d.insert(make_pair(seq[i], maxSeq));
        }
        printf("%d\n",(d.find(N))->second);
    }
	return 0;
}