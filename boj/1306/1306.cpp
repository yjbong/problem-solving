#include <cstdio>
#include <queue>
using namespace std;
int f[1000001];
int a[1000001];
priority_queue <int> pq;
int main(void){

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    for(int i=0; i<2*m-1; i++){
        f[a[i]]++;
        if(f[a[i]]==1) pq.push(a[i]);
    }
    printf("%d ",pq.top());
    for(int i=2*m-1; i<n; i++){
        f[a[i-(2*m-1)]]--;
        f[a[i]]++;
        if(f[a[i]]==1) pq.push(a[i]);
        while(f[pq.top()]==0) pq.pop();
        printf("%d ",pq.top());
    }
    printf("\n");
    return 0;
}