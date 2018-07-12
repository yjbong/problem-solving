#include <cstdio>
#include <algorithm>
using namespace std;
long long p1[50];
long long p2[50];
long long p3[50];
int main(void){

    long long n,pr;
    scanf("%lld %lld",&n,&pr);
    int p1s,p2s,p3s;
    p1s=p2s=p3s=0;
    for(int i=0; i<n; i++){
        long long c,per;
        scanf("%lld %lld",&c,&per);
        if(per==1) p1[p1s++]=c;
        else if(per==2) p2[p2s++]=c;
        else if(per==3) p3[p3s++]=c;
    }
    sort(p1,p1+p1s);
    sort(p2,p2+p2s);
    sort(p3,p3+p3s);

    double sol=pr;
    for(int i=0; i<=p1s; i++){
        for(int j=0; j<=p2s; j++){
            for(int k=0; k<=p3s; k++){
                double csol=pr;

                for(int l=0; l<k; l++) csol*=0.97;
                for(int l=0; l<j; l++) csol*=0.98;
                for(int l=0; l<i; l++) csol*=0.99;

                for(int l=0; l<i; l++) csol+=p1[l];
                for(int l=0; l<j; l++) csol+=p2[l];
                for(int l=0; l<k; l++) csol+=p3[l];

                if(sol>csol) sol=csol;
            }
        }
    }
    printf("%.10lf\n",sol);
    return 0;
}