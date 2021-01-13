#include <cstdio>
#include <set>
using namespace std;
multiset <int> q;
multiset <int>::iterator it;
int main() {
    int T; // 테스트 케이스
    scanf("%d\n",&T);
    while(T--){
        q.clear();
        int k;
        scanf("%d\n",&k);
        for(int i=0; i<k; i++){
            char op;
            int num;
            scanf("%c %d\n",&op,&num);
            if(op=='I') q.insert(num);
            else if(num>0){
                if(q.size()>0){ it=q.end(); q.erase(--it); }
            }
            else{
                if(q.size()>0){ it=q.begin(); q.erase(it); }
            }
        }
        if(q.size()>0){
            it=q.begin();
            int min=*it;
            it=q.end(); it--;
            int max=*it;
            printf("%d %d\n",max,min);
        }
        else printf("EMPTY\n");
    }
    return 0;
}