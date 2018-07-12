#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int> > iii; // first=height, second.first=left, second.second=right

iii bld[111111]; int blds;
int point[222222]; int points;
priority_queue <iii> pq;

bool cmp(iii a, iii b){
    if(a.second.first <= b.second.first) return true;
    else return false;
}

int main(void){

    scanf("%d",&blds);
    for(int i=0; i<blds; i++){
        int l,h,r;
        scanf("%d %d %d",&l,&h,&r);
        bld[i].first=h; bld[i].second.first=l; bld[i].second.second=r;
    }
    sort(bld,bld+blds,cmp);
    points=0;
    for(int i=0; i<blds; i++){
        point[points++]=bld[i].second.first;
        point[points++]=bld[i].second.second;
    }
    sort(point,point+points);

    pq.push(make_pair(0,make_pair(0,1000000001)));
    int cur_bld=0; int cur_h=0;
    for(int i=0; i<points; i++){
        if(i>0 && point[i-1]==point[i]) continue;
        while(cur_bld<blds && bld[cur_bld].second.first<=point[i]){
            pq.push(bld[cur_bld]);
            cur_bld++;
        }
        while(pq.empty()==false && pq.top().second.second<=point[i]) pq.pop();
        if(pq.empty()==false && pq.top().first!=cur_h){
            cur_h=pq.top().first;
            printf("%d %d ",point[i],cur_h);
        }
    }
    printf("\n");
    return 0;
}