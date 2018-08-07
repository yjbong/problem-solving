#include <cstdio>
int t,m;
double n,p;
bool possible(double dept, int mon, double mon_interest, double repay){
        for(int i=0; i<mon && dept>0.0; i++){
                dept*=(1.0+mon_interest);
                dept-=repay;
        }
        if(dept<=0.0) return true;
        else return false;
}

int main(void){
        scanf("%d",&t);
        while(t--){
                scanf("%lf %d %lf",&n,&m,&p);
                p/=100.0;
                p/=12.0;
                double left=0, right=10000000000.0;
                double ans=right;
                for(int i=0; i<100; i++){
                        double mid=(left+right)*0.5;
                        if(possible(n,m,p,mid)){
                                if(ans>mid) ans=mid;
                                right=mid;
                        }
                        else left=mid;
                }
                printf("%.10lf\n",ans);
        }
        return 0;
}