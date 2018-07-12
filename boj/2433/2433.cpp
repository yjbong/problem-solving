#include <cstdio>
#include <queue>
using namespace std;
int a[1000000];
int f[1000001];
priority_queue <int> mx;
priority_queue <int> mn;

int main(void){

    int n,m,c;
    scanf("%d %d %d",&n,&m,&c);

    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    for(int i=0; i<m; i++){
        f[a[i]]++;
        mx.push(a[i]);
        mn.push(-a[i]);
    }
    bool none=true;
    if(mx.top()+mn.top()<=c){
        none=false;
        printf("1\n");
    }

    for(int i=m,j=2; i<n; i++,j++){
        f[a[i-m]]--;
        f[a[i]]++;
        mx.push(a[i]);
        mn.push(-a[i]);

        while(f[mx.top()]==0) mx.pop();
        while(f[-mn.top()]==0) mn.pop();

        if(mx.top()+mn.top()<=c){
            none=false;
            printf("%d\n",j);
        }
    }
    if(none) printf("NONE\n");
    return 0;
}