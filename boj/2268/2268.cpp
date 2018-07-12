#include <cstdio>
#define SWAP(a,b,t){t=a;a=b;b=t;}
long long near_pw;
long long d[1<<21];
long long sum(long long i, long long j){

    long long left=near_pw+i-1;
    long long right=near_pw+j-1;
    long long sol=0;

    while(left<right){

        if(left%2==0) left=left/2;
        else{
            sol+=d[left];
            left=(left+1)/2;
        }

        if(right%2==1) right=right/2;
        else{
            sol+=d[right];
            right=(right-1)/2;
        }
    }

    if(left==right) sol+=d[left];
    return sol;
}

long long modify(long long i, long long k){

    long long idx=near_pw+i-1;
    d[idx]=k;
    long long t=idx/2;
    while(t>0){
        d[t]=d[t*2]+d[t*2+1];
        t/=2;
    }
}

int main(void){

    long long n,m;
    scanf("%lld %lld",&n,&m);
    near_pw=1;
    while(near_pw<n) near_pw*=2;

    while(m--){

        long long op,i,j,t;
        scanf("%lld %lld %lld",&op,&i,&j);

        if(!op){
            if(i>j) SWAP(i,j,t);
            printf("%lld\n",sum(i,j));
        }
        else modify(i,j);
    }
    return 0;
}