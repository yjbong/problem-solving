#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct xy{
    int x;
    int y;
    int s;
}XY;

int u[1000];
XY xy[1000*1000];
int xys;

bool cmp(XY a, XY b){

    if(a.s<b.s) return true;
    else if(a.s==b.s){
        if(a.y<=b.y) return true;
        else return false;
    }
    else return false;
}

bool bsearch(int z, int key){

    bool ok=false;
    int l,m,r;
    l=0,r=xys-1;
    while(l<=r){
        m=(l+r)/2;
        if(xy[m].s<key) l=m+1;
        else if(xy[m].s>key) r=m-1;
        else{
            if(xy[m].y>z) r=m-1;
            else{
                ok=true;
                break;
            }
        }
    }
    return ok;
}

int main(void){

    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&u[i]);

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            xy[xys].x=i, xy[xys].y=j;
            xy[xys].s=u[i]+u[j];
            xys++;
        }
    }

    sort(xy,xy+xys,cmp);

    int sol=0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int key=u[j]-u[i];
            if(bsearch(i,key)){
                if(sol<u[j]) sol=u[j];
            }
        }
    }
    printf("%d\n",sol);
    return 0;
}