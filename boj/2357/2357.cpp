#include <cstdio>
#define SWAP(a,b,t){t=a;a=b;b=t;}
int itms;
long long mn[1<<19];
long long mx[1<<19];
long long min2(long long a, long long b){
    if(a<b) return a;
    else return b;
}
long long max2(long long a, long long b){
    if(a>b) return a;
    else return b;
}

void print_sol(int a, int b){

    int l,r;

    l=itms+a-1;
    r=itms+b-1;
    long long smn=mn[l];
    while(l<r){
        if(l%2==0) l=l/2;
        else{
            if(smn>mn[l]) smn=mn[l];
            l=(l+1)/2;
        }
        if(r%2==1) r=r/2;
        else{
            if(smn>mn[r]) smn=mn[r];
            r=(r-1)/2;
        }
    }
    if(l==r && smn>mn[l]) smn=mn[l];

    l=itms+a-1;
    r=itms+b-1;
    long long smx=mx[l];
    while(l<r){
        if(l%2==0) l=l/2;
        else{
            if(smx<mx[l]) smx=mx[l];
            l=(l+1)/2;
        }
        if(r%2==1) r=r/2;
        else{
            if(smx<mx[r]) smx=mx[r];
            r=(r-1)/2;
        }
    }
    if(l==r && smx<mx[l]) smx=mx[l];

    printf("%lld %lld\n",smn,smx);
}

int main(void){

    int n,m;
    scanf("%d %d",&n,&m);
    itms=1;
    while(itms<n) itms*=2;

    for(int i=0; i<n; i++){
        long long c;
        scanf("%lld",&c);
        mn[itms+i]=mx[itms+i]=c;
    }

    for(int i=itms-1; i>=1; i--){
        mn[i]=min2(mn[i*2],mn[i*2+1]);
        mx[i]=max2(mx[i*2],mx[i*2+1]);
    }

    for(int i=0; i<m; i++){
        int a,b,t;
        scanf("%d %d",&a,&b);
        if(a>b) SWAP(a,b,t);
        print_sol(a,b);
    }
    return 0;
}