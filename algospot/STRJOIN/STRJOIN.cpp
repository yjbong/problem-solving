#include <cstdio>
#include <queue>
using namespace std;

int c,n;
int l[100];
priority_queue <int> pq;
int main(void){

    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",&l[i]);

        int ans=0;
        while(!pq.empty()) pq.pop();
        for(int i=0; i<n; i++) pq.push(-l[i]);
        while(pq.size()>1){
            int min0=-pq.top(); pq.pop();
            int min1=-pq.top(); pq.pop();
            ans+=(min0+min1);
            pq.push(-(min0+min1));
        }
        printf("%d\n",ans);
    }
    return 0;
}