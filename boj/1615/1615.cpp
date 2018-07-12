#include <stdio.h>
#include <stdlib.h>

typedef struct _line{
    long long a;
    long long b;
}LINE;
LINE line[2000000];

long long bit[40000];
long long nearpow;
long long n,m;

int cmp(const void *a, const void *b){

    if((((LINE*)a)->a) > (((LINE*)b)->a)) return 1;
    else if((((LINE*)a)->a) == (((LINE*)b)->a)){
        if((((LINE*)a)->b) > (((LINE*)b)->b)) return 1;
        else return 0;
    }
    else return 0;
}

void init(){

    long long i;
    for(i=nearpow; i<nearpow*2; i++) bit[i]=0;
    for(i=1; i<nearpow; i++) bit[i]=bit[i*2]+bit[i*2+1];
}

void update(long long idx){

    long long cur_par;
    bit[nearpow+idx-1]++;
    cur_par=(nearpow+idx-1)/2;
    while(cur_par>=1){
        bit[cur_par]=bit[cur_par*2]+bit[cur_par*2+1];
        cur_par/=2;
    }
}

long long count(long long start, long long end){

    long long sum;
    long long old_start,old_end;
    sum=0;
    start=nearpow+start-1;
    end=nearpow+end-1;

    if(start>=nearpow*2 || end>=nearpow*2) return 0;
    do{
        old_start=start;
        old_end=end;
        if(start%2==0) start/=2;
        else{
            sum+=bit[start];
            start=(start+1)/2;
        }

        if(end%2==1) end/=2;
        else{
            sum+=bit[end];
            end=(end-1)/2;
        }

        if(start==end){
            sum+=bit[start];
        }
    }while(start<end);
    return sum;
}

int main(void){

    long long i,sol;
    scanf("%lld %lld",&n,&m);
    nearpow=1;
    while(nearpow<n) nearpow*=2;

    for(i=0; i<m; i++) scanf("%lld %lld",&(line[i].a),&(line[i].b));
    qsort(line,m,sizeof(LINE),cmp);

    init();
    sol=0;
    for(i=0; i<m; i++){
        sol+=count(line[i].b+1,n);
        update(line[i].b);
    }

    printf("%lld\n",sol);
    return 0;
}