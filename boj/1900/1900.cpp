#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct wr{
    int pos;
    int pwr;
    int mgc;
}WR;
WR w[11111];
bool cmp(WR a, WR b){
    if(a.pwr+a.mgc*b.pwr>b.pwr+b.mgc*a.pwr) return true;
    else return false;
}
int main(void){

    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int p,m;
        scanf("%d %d",&p,&m);
        w[i].pos=i+1;
        w[i].pwr=p;
        w[i].mgc=m;
    }
    sort(w,w+n,cmp);
    for(int i=0; i<n; i++) printf("%d\n",w[i].pos);
    return 0;
}