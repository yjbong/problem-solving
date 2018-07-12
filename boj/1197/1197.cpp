#include <stdio.h>
#include <stdlib.h>

typedef struct _edge{
    long long from;
    long long to;
    long long cost;
}EDGE;

EDGE e[100000];
long long pa[10001];
long long chs[10001];
long long vs,es;

void union2(long long a, long long b){

    while(a!=pa[a]) a=pa[a];
    while(b!=pa[b]) b=pa[b];

    if(a!=b){
        if(chs[a]>=chs[b]){
            pa[b]=a;
            chs[a]++;
        }
        else{
            pa[a]=b;
            chs[b]++;
        }
    }
}

long long find2(long long a){

    while(a!=pa[a]) a=pa[a];
    return a;
}

int cmp(const void *a, const void *b){

    if( ((EDGE*)a)->cost > ((EDGE*)b)->cost) return 1;
    else return 0;
}


int main(void){

    long long i,sum;
    long long from_top, to_top;
    scanf("%lld %lld", &vs, &es);

    for(i=0; i<=vs; i++){
        pa[i]=i;
        chs[i]=0;
    }

    for(i=0; i<es; i++){
        scanf("%lld %lld %lld", &(e[i].from), &(e[i].to), &(e[i].cost));
    }
    qsort(e, es, sizeof(EDGE), cmp);

    sum=0;
    for(i=0; i<es; i++){

        from_top=find2(e[i].from);
        to_top=find2(e[i].to);
        if(from_top==to_top) continue;
        else{
            union2(from_top, to_top);
            sum+=e[i].cost;
        }
    }
    printf("%lld\n", sum);
    return 0;
}