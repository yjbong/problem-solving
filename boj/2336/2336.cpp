#include <cstdio>
#define INF 1000000000

int pos[500001];
int ord[500001];
int ex3[500001];
int bit[1<<20];
int nearp;

int min(int a, int b){
    if(a<b) return a;
    else return b;
}

void update(int idx, int itm){

    int c=nearp+idx;
    bit[c]=itm;
    c/=2;
    while(c>0){
        bit[c]=min(bit[c*2],bit[c*2+1]);
        c/=2;
    }
}

int range_min(int st, int ed){

    int l=nearp+st;
    int r=nearp+ed;
    int cmin=INF;

    while(l<r){
        if(l%2==0) l/=2;
        else{
            if(cmin>bit[l]) cmin=bit[l];
            l=(l+1)/2;
        }
        if(r%2==1) r/=2;
        else{
            if(cmin>bit[r]) cmin=bit[r];
            r=(r-1)/2;
        }
    }
    if(l==r && cmin>bit[l]) cmin=bit[l];
    return cmin;
}

int main(void){

    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int cnum;
        scanf("%d",&cnum);
        pos[cnum]=i;
    }
    for(int i=0; i<n; i++){
        int cnum;
        scanf("%d",&cnum);
        ord[i]=cnum;
    }
    for(int i=0; i<n; i++){
        int cnum;
        scanf("%d",&cnum);
        ex3[cnum]=i;
    }

    nearp=1;
    while(nearp<n) nearp*=2;
    for(int i=0; i<nearp*2; i++) bit[i]=INF;

    int sol=0;
    for(int i=0; i<n; i++){
        int c=ord[i];
        int rmin;
        bool ok=true;
        if(pos[c]>0){
            rmin=range_min(0,pos[c]-1);
            if(rmin<ex3[c]) ok=false;
        }
        if(ok) sol++;
        update(pos[c],ex3[c]);
    }
    printf("%d\n",sol);
    return 0;
}