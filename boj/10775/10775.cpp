#include <cstdio>
#include <set>
using namespace std;
int G; // 게이트의 수
int P; // 비행기의 수
set<int> gate;
int main() {
    scanf("%d %d",&G,&P);
    for(int i=1; i<=G; i++) gate.insert(-i);
    int ans=0;
    for(int i=0; i<P; i++){
        int g;
        scanf("%d",&g);
        // 1~g번 중 가장 뒤쪽인(인덱스가 큰) 비어 있는 게이트 선택
        set<int>::iterator it=gate.lower_bound(-g);
        if(it!=gate.end()){
            //printf("For request [1~%d] => Gate %d\n",g,-(*it));
            ans++;
            gate.erase(it);
        }
        else break; // 비행기가 들어갈 게이트가 없음 --> 사고 발생
    }
    printf("%d\n",ans);
    return 0;
}