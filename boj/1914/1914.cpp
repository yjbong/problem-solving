#include <cstdio>
#define MOD 100000000000000000ll
long long a[2],b[2],c[2];

void add(long long a[2], long long b[2]){

    a[0]+=b[0];
    a[1]+=a[0]/MOD;
    a[0]%=MOD;
    a[1]+=b[1];
}

void sub(long long a[2], long long b[2]){

    a[0]-=b[0];
    if(a[0]<0){
        a[0]+=MOD;
        a[1]--;
    }
    a[1]-=b[1];
}

void print(long long a[2]){

    if(a[1]>0) printf("%lld%017lld\n",a[1],a[0]);
    else printf("%lld\n",a[0]);
}

void hanoi(int n, int from, int to, int aux){

    if(n==1) printf("%d %d\n",from,to);
    else{
        hanoi(n-1,from,aux,to);
        hanoi(1,from,to,aux);
        hanoi(n-1,aux,to,from);
    }
}

int main(void){

    int n;
    scanf("%d",&n);
    if(n<1) printf("0\n");
    else{
        a[0]=1, a[1]=0, c[0]=1, c[1]=0;
        for(int i=1; i<=n; i++){
            b[0]=a[0], b[1]=a[1];
            add(a,b);
        }
        sub(a,c);
        print(a);
        if(n<=20) hanoi(n,1,3,2);
    }
    return 0;
}