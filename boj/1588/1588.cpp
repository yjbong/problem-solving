#include <cstdio>
typedef long long ll;
ll d[22][4][4];
ll pw[22];
ll sol[4];
ll st,l,r,n;

ll go(ll sec, ll cur, ll nums, ll tgt){

    if(nums==0) return 0;
    if(sec==0) return d[0][cur][tgt];

    ll q=nums/pw[sec-1];
    if(cur==1){ //132
        if(q==0) return go(sec-1,1,nums,tgt);
        else if(q==1) return d[sec-1][1][tgt]+go(sec-1,3,nums-q*pw[sec-1],tgt);
        else if(q==2) return d[sec-1][1][tgt]+d[sec-1][3][tgt]+go(sec-1,2,nums%pw[sec-1],tgt);
        else return d[sec][cur][tgt];
    }
    else if(cur==2){ //211
        if(q==0) return go(sec-1,2,nums,tgt);
        else if(q==1) return d[sec-1][2][tgt]+go(sec-1,1,nums-q*pw[sec-1],tgt);
        else if(q==2) return d[sec-1][2][tgt]+d[sec-1][1][tgt]+go(sec-1,1,nums%pw[sec-1],tgt);
        else return d[sec][cur][tgt];
    }

    else if(cur==3){ //232
        if(q==0) return go(sec-1,2,nums,tgt);
        else if(q==1) return d[sec-1][2][tgt]+go(sec-1,3,nums%pw[sec-1],tgt);
        else if(q==2) return d[sec-1][2][tgt]+d[sec-1][3][tgt]+go(sec-1,2,nums%pw[sec-1],tgt);
        else return d[sec][cur][tgt];
    }
}

int main(void){

    pw[0]=1;
    for(int i=1; i<=20; i++) pw[i]=pw[i-1]*3;

    scanf("%lld %lld %lld %lld",&st,&l,&r,&n);
    l++, r++;

    d[0][1][1]=d[0][2][2]=d[0][3][3]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=3; j++){
            d[i][1][j]=d[i-1][1][j]+d[i-1][3][j]+d[i-1][2][j];
            d[i][2][j]=d[i-1][2][j]+d[i-1][1][j]+d[i-1][1][j];
            d[i][3][j]=d[i-1][2][j]+d[i-1][3][j]+d[i-1][2][j];
        }
    }

    for(int i=1; i<=3; i++)
        sol[i]=go(n,st,r,i);
    for(int i=1; i<=3; i++)
        sol[i]-=go(n,st,l-1,i);

    for(int i=1; i<=3; i++) printf("%lld ",sol[i]);
    printf("\n");
    return 0;
}