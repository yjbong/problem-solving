#include <cstdio>
int r,l;
long long b;
long long x[111111];

int s,e,m;
long long sum;

int main(void){
        scanf("%d %d %lld",&r,&l,&b);
        for(int i=0; i<r; i++) scanf("%lld",&x[i]);

        int sol=1;
        s=e=0;
        sum=0;
        do{
                if(b < sum || e==r-1){ // 왼쪽에서 구간 축소
                        s++;
                        int om=(s-1+e)/2; int nm=(s+e)/2;
                        sum -= (x[om]-x[s-1]);
                        if(nm!=om){
                                sum += (x[nm]-x[om])*(nm-s);
                                sum -= (x[nm]-x[om])*(e-om);
                        }
                }
                else{ // 오른쪽에서 구간 확대
                        e++;
                        int om=(s+e-1)/2; int nm=(s+e)/2;
                        sum += (x[e]-x[om]);
                        if(nm!=om){
                                sum += (x[nm]-x[om])*(nm-s);
                                sum -= (x[nm]-x[om])*(e-om);
                        }
                }
                if(b >= sum && sol < e-s+1) sol=e-s+1;

        }while(!(s==r-1 && e==r-1));

        printf("%d\n",sol);
        return 0;
}