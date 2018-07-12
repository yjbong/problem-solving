#include <cstdio>
#include <queue>
#include <utility>
#define INF 1000000000
using namespace std;

typedef pair<int,int> ii;
priority_queue <ii> max_pq;
priority_queue <ii> min_pq;

int n,b,k;
int base;

int a[250][250];
int max_bit[250][512];
int min_bit[250][512];

int max(int a, int b){
    if(a<b) return b;
    else return a;
}
int min(int a, int b){
    if(a<b) return a;
    else return b;
}

int get_max(int idx, int start, int end){

    int cmax=0;
    int l=base+start;
    int r=base+end;

    while(l<r){
        if(l%2==0) l=l/2;
        else{
            if(cmax < max_bit[idx][l]) cmax = max_bit[idx][l];
            l=(l+1)/2;
        }
        if(r%2==1) r=r/2;
        else{
            if(cmax < max_bit[idx][r]) cmax = max_bit[idx][r];
            r=(r-1)/2;
        }
    }

    if(l==r && cmax < max_bit[idx][l]) cmax = max_bit[idx][l];
    return cmax;
}

int get_min(int idx, int start, int end){

    int cmin=INF;
    int l=base+start;
    int r=base+end;

    while(l<r){
        if(l%2==0) l=l/2;
        else{
            if(cmin > min_bit[idx][l]) cmin = min_bit[idx][l];
            l=(l+1)/2;
        }
        if(r%2==1) r=r/2;
        else{
            if(cmin > min_bit[idx][r]) cmin = min_bit[idx][r];
            r=(r-1)/2;
        }
    }

    if(l==r && cmin > min_bit[idx][l]) cmin = min_bit[idx][l];
    return cmin;
}

int main(void){

    for(int i=0; i<250; i++)
        for(int j=0; j<512; j++) min_bit[i][j]=INF;

    scanf("%d %d %d",&n,&b,&k);

    base=1;
    while(base<n) base*=2;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d",&a[i][j]);

    for(int i=0; i<n; i++){
        for(int j=0; j<b; j++){
            max_pq.push(make_pair(a[i][j],j));
            min_pq.push(make_pair(-a[i][j],j));
        }
        for(int j=0; j<n-b+1; j++){
            while(max_pq.top().second<j) max_pq.pop();
            max_bit[j][base+i]=max_pq.top().first;
            if(j+b<n) max_pq.push(make_pair(a[i][j+b],j+b));

            while(min_pq.top().second<j) min_pq.pop();
            min_bit[j][base+i]=-(min_pq.top().first);
            if(j+b<n) min_pq.push(make_pair(-a[i][j+b],j+b));
        }

        while(!max_pq.empty()) max_pq.pop();
        while(!min_pq.empty()) min_pq.pop();
    }

    for(int i=0; i<n; i++){
        for(int j=base-1; j>=1; j--){
            max_bit[i][j]=max(max_bit[i][j*2], max_bit[i][j*2+1]);
            min_bit[i][j]=min(min_bit[i][j*2], min_bit[i][j*2+1]);
        }
    }

    for(int i=0; i<k; i++){
        int r,c;
        scanf("%d %d",&r,&c);
        r--,c--;
        int cmax=get_max(c,r,r+b-1);
        int cmin=get_min(c,r,r+b-1);

        printf("%d\n",cmax-cmin);
    }

    return 0;
}