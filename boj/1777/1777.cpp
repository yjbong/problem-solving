#include <cstdio>
int n;
int in[111111];
int s[1<<18];
int base;
int ans[111111];

int find(int k){

    int t=1;
    while(t<base){
        if(s[t*2]>=k) t=t*2;
        else{
            k-=s[t*2];
            t=t*2+1;
        }
    }
    return (t-base);
}

void update(int k){

    k+=base;
    k/=2;
    while(k>0){
        s[k]=s[k*2]+s[k*2+1];
        k/=2;
    }
}

int main(void){

    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&in[i]);

    base=1;
    while(base<n) base*=2;

    for(int i=base; i<base*2; i++) i<base+n ? s[i]=1 : s[i]=0;
    for(int i=base-1; i>=1; i--) s[i]=s[i*2]+s[i*2+1];

    for(int i=n-1; i>=0; i--){
        int idx=find(in[i]+1);
        ans[idx]=i+1;
        s[base+idx]=0; update(idx);
    }

    for(int i=n-1; i>=0; i--) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}