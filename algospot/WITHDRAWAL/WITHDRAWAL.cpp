#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
int t,n,k;
int r[1000];
int c[1000];
double tmp[1000];
bool possible(double rank){
        for(int i=0; i<n; i++)
                tmp[i]=rank*c[i]-r[i];

        sort(tmp,tmp+n,greater<double>());

        double cur=0;
        for(int i=0; i<k; i++) cur+=tmp[i];

        if(cur>=0) return true;
        else return false;
}
int main(void){
        scanf("%d",&t);
        while(t--){
                scanf("%d %d",&n,&k);
                for(int i=0; i<n; i++) scanf("%d %d",&r[i],&c[i]);
                double left=0, right=1;
                double ans=right;
                for(int i=0; i<100; i++){
                        double mid=(left+right)*0.5;
                        if(possible(mid)){
                                if(ans>mid) ans=mid;
                                right=mid;
                        }
                        else left=mid;
                }
                printf("%.10lf\n",ans);
        }
        return 0;
}