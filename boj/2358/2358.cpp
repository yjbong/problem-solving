#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
ii p[100000];

bool cmp1(ii a,ii b){
    if(a.first>=b.first) return false;
    else return true;
}
bool cmp2(ii a,ii b){
    if(a.second>=b.second) return false;
    else return true;
}
int main(void){

    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d %d",&p[i].first,&p[i].second);

    long long sol,cp;
    bool add;

    sort(p,p+n,cmp1);
    cp=0, sol=0;
    add=false;
    for(int i=1; i<n; i++){
        if(p[cp].first==p[i].first) add=true;
        else{
            cp=i;
            if(add) sol++;
            add=false;
        }
    }
    if(add) sol++;

    sort(p,p+n,cmp2);
    cp=0;
    add=false;
    for(int i=1; i<n; i++){
        if(p[cp].second==p[i].second) add=true;
        else{
            cp=i;
            if(add) sol++;
            add=false;
        }
    }
    if(add) sol++;

    printf("%lld\n",sol);
    return 0;
}