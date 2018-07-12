#include <cstdio>
#include <cmath>
#include <algorithm>
#define BIG 2000000000.0
using namespace std;
double a[20][2];
int c[20];
int main(void){

    int t;
    scanf("%d",&t);

    while(t--){

        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%lf %lf",&a[i][0],&a[i][1]);

        for(int i=0; i<n; i++){
            if(i<n/2) c[i]=0;
            else c[i]=1;
        }

        double sol=BIG;
        do{
            double y,x,dst;
            y=x=0.0;
            for(int i=0; i<n; i++){
                if(c[i]){
                    y-=a[i][0];
                    x-=a[i][1];
                }
                else{
                    y+=a[i][0];
                    x+=a[i][1];
                }
            }

            dst=sqrt(y*y+x*x);
            if(sol>dst) sol=dst;

        }while(next_permutation(c,c+n));
        printf("%.6lf\n",sol);
    }
    return 0;
}