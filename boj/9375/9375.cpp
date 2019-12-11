#include <map>
#include <cstdio>
#include <string>
using namespace std;
 
int T;
int N;
map <string, int> item;
int main() {
    scanf("%d\n",&T);
    while(T--){
        item.clear();
        char curType[22];
        map <string, int>::iterator it;
        scanf("%d\n",&N);
        for(int i=0; i<N; i++){
            scanf("%*s %s",curType);
            it=item.find(string(curType));
            if(it==item.end()) item.insert(make_pair(string(curType), 1));
            else it->second++;
        }
 
        int ans=1;
        for(it=item.begin(); it!=item.end(); it++) ans*=(it->second)+1;
        ans--;
        printf("%d\n",ans);
    }
    return 0;
}