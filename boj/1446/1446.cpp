#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
typedef pair <int,int> ii;
vector <ii> v[10001];
int d[10001];
int n,dst;

int main(void){

    scanf("%d %d",&n,&dst);
    for(int i=0; i<=dst; i++) d[i]=i;
    for(int i=0; i<n; i++){
        int from,to,cost;
        scanf("%d %d %d",&from,&to,&cost);
        if(to<=dst && to-from>cost) v[to].push_back(make_pair(from, cost));
    }
    for(int i=0; i<=dst; i++){
        for(int j=0; j<v[i].size(); j++)
            if(d[i]>d[v[i][j].first]+v[i][j].second) d[i]=d[v[i][j].first]+v[i][j].second;
        for(int j=i-d[i]+1; j<i; j++)
            if(d[i]>d[j]+(i-j)) d[i]=d[j]+i-j;
    }
    printf("%d\n",d[dst]);
    return 0;
}