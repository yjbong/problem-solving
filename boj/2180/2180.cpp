#include <stdio.h>
#include <stdlib.h>
#define INF 100000000.0

typedef struct _info{

        long long a;
        long long b;
        double b_div_a;
}INFO;

int cmp(const void *a, const void *b){

        double a1,b1;
        a1=((INFO*)a)->b_div_a, b1=((INFO*)b)->b_div_a;

        if(a1>b1) return 1;
        else return 0;
}
INFO f[222222];
int main(void){

        int i,n;
        long long t,sol;
        scanf("%d",&n);
        for(i=0; i<n; i++){
                scanf("%lld %lld",&f[i].a, &f[i].b);
                if(f[i].a==0) f[i].b_div_a=INF;
                else f[i].b_div_a=(double)(f[i].b)/(double)(f[i].a);
        }

        qsort(f,n,sizeof(INFO),cmp);

        t=0,sol=0;
        for(i=0; i<n; i++){
                sol=(sol+(f[i].a)*t+f[i].b)%40000;
                t=(t+(f[i].a)*t+f[i].b)%40000;
        }
        printf("%lld\n",sol);

        return 0;
}