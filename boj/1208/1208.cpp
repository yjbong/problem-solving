#include <cstdio>
int f[8000001];
int a[40];
int main(void){

    int n,s;
    scanf("%d %d",&n,&s);

    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    for(int i=0; i<(1<<(n/2)); i++){
        int t,j,sum;
        t=i; j=0; sum=0;
        while(t>0){
            if(t%2) sum+=a[j];
            t/=2; j++;
        }
        f[sum+4000000]++;
    }

    long long sol=0;
    for(int i=0; i<(1<<(n-n/2)); i++){
        int t,j,sum;
        t=i; j=n/2; sum=0;
        while(t>0){
            if(t%2) sum+=a[j];
            t/=2; j++;
        }
        sol+=f[s-sum+4000000];
    }

    if(s==0) sol--;
    printf("%lld\n",sol);
    return 0;
}