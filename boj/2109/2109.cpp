#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
#define MAX_N 10000
using namespace std;
typedef pair<int,int> ii; // first:금액 second:기한
priority_queue<ii> pq;
bool cmp(ii a, ii b){ return a.second>b.second; }
int n; // 강연의 수
ii a[MAX_N];
int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d %d",&a[i].first, &a[i].second);
    sort(a,a+n,cmp);
 
    // 가장 기한이 늦은 강의를 하는 날짜부터 생각한다.
    int ans=0;
    int idx=0;
    for(int day=a[0].second; day>=1; day--){
        // 현재 날짜(day)가 기한인 강의들을 모두 heap에 넣는다.
        while(idx<n && a[idx].second==day) pq.push(a[idx++]);
        // 현재 날짜에 할 수 있는 강의 중 가장 이익이 큰 것을 고른다.
        if(!pq.empty()){ ans+=pq.top().first; pq.pop(); }
    }
    // 답
    printf("%d\n",ans);
    return 0;
}
