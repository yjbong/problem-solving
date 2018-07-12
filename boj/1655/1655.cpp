#include <stdio.h>
#define SWAP(a, b, tmp){tmp=a; a=b; b=tmp;}
#define INF 1000000
#define MINUSINF -1000000
int a[111111];
int n,nearpow;
int l[1000000];
int ls;
int r[1000000];
int rs;

void init(){

    int i;
    for(i=1; i<=nearpow*2; i++){
        l[i]=MINUSINF;
        r[i]=INF;
    }
}

void put_l(int item){

    int tmp;
    int cur_idx;
    ls++;
    l[ls]=item;

    cur_idx=ls;

    while(cur_idx/2>=1 && l[cur_idx/2]<l[cur_idx]){
        SWAP(l[cur_idx/2], l[cur_idx], tmp);
        cur_idx/=2;
    }
}

void put_r(int item){

    int tmp;
    int cur_idx;
    rs++;
    r[rs]=item;

    cur_idx=rs;

    while(cur_idx/2>=1 && r[cur_idx/2]>r[cur_idx]){
        SWAP(r[cur_idx/2], r[cur_idx], tmp);
        cur_idx/=2;
    }
}

void del_l(){

    int cur_idx;
    int tmp;

    l[1]=MINUSINF;
    cur_idx=1;
    while(cur_idx<=ls){

        if(l[cur_idx*2]>l[cur_idx*2+1]){
            SWAP(l[cur_idx], l[cur_idx*2], tmp);
            cur_idx=cur_idx*2;
        }
        else{
            SWAP(l[cur_idx], l[cur_idx*2+1], tmp);
            cur_idx=cur_idx*2+1;
        }
    }

    cur_idx/=2;
    if(cur_idx<ls){
        l[cur_idx]=l[ls];
        while(cur_idx/2>=1 && l[cur_idx/2]<l[cur_idx]){
            SWAP(l[cur_idx/2], l[cur_idx], tmp);
            cur_idx/=2;
        }
    }

    ls--;
}

void del_r(){

    int cur_idx;
    int tmp;

    r[1]=INF;
    cur_idx=1;
    while(cur_idx<=rs){

        if(r[cur_idx*2]<r[cur_idx*2+1]){
            SWAP(r[cur_idx], r[cur_idx*2], tmp);
            cur_idx=cur_idx*2;
        }
        else{
            SWAP(r[cur_idx], r[cur_idx*2+1], tmp);
            cur_idx=cur_idx*2+1;
        }
    }

    cur_idx/=2;
    if(cur_idx<rs){
        r[cur_idx]=r[rs];
        while(cur_idx/2>=1 && r[cur_idx/2]>r[cur_idx]){
            SWAP(r[cur_idx/2], r[cur_idx], tmp);
            cur_idx/=2;
        }
    }

    rs--;
}

int main(void){

    int i;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);

    nearpow=1;
    while(nearpow<n) nearpow*=2;

    init();

    ls=rs=0;
    for(i=0; i<n; i++){

        if(l[1]<a[i]) put_r(a[i]);
        else put_l(a[i]);

        if(ls-rs>1){
            put_r(l[1]);
            del_l();
        }

        else if(rs-ls>=1){
            put_l(r[1]);
            del_r();
        }

        printf("%d\n", l[1]);
    }

    return 0;
}