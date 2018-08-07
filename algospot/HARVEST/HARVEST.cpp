#include <cstdio>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int,int> ii;

int t,n,m,k;

ii tree[20000];
int y[20000], ys;
int x[20000], xs;
map<int,int> ymap;
map<int,int> xmap;

int d[20000]; // d[i] = possible maximum passing trees when current position is tree[i]
int BIT[1<<16]; // binary indexed tree for getting maximum d value
int BIT_base; // Real values are in index [BIT_base, BIT_base*2-1]

int max2(int a, int b){
    return a>b?a:b;
}

void init_BIT(int size){

    BIT_base=1;
    while(BIT_base<size) BIT_base*=2;
    for(int i=0; i<BIT_base*2; i++) BIT[i]=0;
}

int query_BIT(int left, int right){ // get maximum value from range [left, right]
    left+=BIT_base; right+=BIT_base;
    int ret=0;

    while(left<right){
        if(left%2==0) left/=2;
        else{
            ret=max2(ret,BIT[left]);
            left=(left+1)/2;
        }

        if(right%2==1) right/=2;
        else{
            ret=max2(ret,BIT[right]);
            right=(right-1)/2;
        }
    }

    if(left==right) ret=max2(ret,BIT[left]);
    return ret;
}

void update_BIT(int idx, int val){ // update idx-th element to new value

    int curidx=BIT_base+idx;

    BIT[curidx]=val;
    curidx/=2;
    while(curidx>0){
        BIT[curidx]=max2(BIT[curidx*2],BIT[curidx*2+1]);
        curidx/=2;
    }
}

int main(void){

    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&m,&k);

        ys=xs=0;
        for(int i=0; i<k; i++){
            int cy,cx;
            scanf("%d %d",&cy,&cx);
            tree[i].first=cy; tree[i].second=cx;
            y[ys++]=cy; x[xs++]=cx;
        }

        // make y and x coordinate map from existing y and x coords
        sort(y,y+ys); sort(x,x+xs);
        ymap.clear(); xmap.clear();

        int ynum=0;
        for(int i=0; i<ys; i++){
            if(ymap.find(y[i])==ymap.end()){
                ymap.insert(make_pair(y[i],ynum));
                ynum++;
            }
        }
        int xnum=0;
        for(int i=0; i<xs; i++){
            if(xmap.find(x[i])==xmap.end()){
                xmap.insert(make_pair(x[i],xnum));
                xnum++;
            }
        }

        // convert tree's original coord into relative coord (by map)
        for(int i=0; i<k; i++){
            tree[i].first=(ymap.find(tree[i].first))->second;
            tree[i].second=(xmap.find(tree[i].second))->second;
        }

        // sort tree array by y coord (ascending)
        sort(tree,tree+k);

        // calculate d array
        init_BIT(xnum);
        for(int i=0; i<k; i++){
            d[i]=query_BIT(0,tree[i].second)+1;
            if(d[i]>BIT[BIT_base+tree[i].second]) update_BIT(tree[i].second,d[i]);
        }

        // print answer
        int ans=0;
        for(int i=0; i<k; i++) ans=max2(ans,d[i]);
        printf("%d\n",ans);
    }
    return 0;
}