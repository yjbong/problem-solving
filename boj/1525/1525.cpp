#include <cstdio>
#include <queue>
#include <utility>
#define SWAP(a,b,t){t=a;a=b;b=t;}

#define INF 1000000000
using namespace std;

int a[10];
int b[10];

int fac[10];

int d[9*8*7*6*5*4*3*2*1];
queue <int> q;

int get_idx(int seq[],int seqs){  // it gets an order number from a certain permutation.

    bool v[10];
    for(int j=0; j<10; j++) v[j]=false;

    int ret=0;
    for(int i=0; i<seqs; i++){
        int k=0;
        for(int j=0; j<seqs; j++){
            if(seq[i]==j){
                v[j]=true;
                break;
            }
            if(!v[j]) k++;
        }
        ret+=k*fac[seqs-1-i];
    }
    return ret;
}

void get_seq(int idx, int seq[], int seqs){ // it gets a permutation from a certain order number.

    bool v[10];
    for(int j=0; j<10; j++) v[j]=false;

    for(int i=0; i<seqs; i++){
        int k=0;

        for(int j=0; j<seqs; j++){
            if(!v[j]){
                if(k==idx/fac[seqs-1-i]){
                    seq[i]=j;
                    v[j]=true;
                    idx%=fac[seqs-1-i];
                    break;
                }
                k++;
            }
        }
    }
}

int main(void){

    int n=9;

    fac[0]=1;
    for(int i=1; i<=n; i++) fac[i]=fac[i-1]*i;

    for(int i=0; i<n-1; i++) a[i]=i+1;
    a[n-1]=0;
    int tgt_idx=get_idx(a,n);

    for(int i=0; i<fac[n]; i++) d[i]=INF;

    for(int i=0; i<n; i++) scanf("%d",&a[i]);

    int t;

    t=get_idx(a,n);
    q.push(t);
    d[t]=0;

    while(!q.empty()){
        int f=q.front();
        q.pop();

        get_seq(f,a,n);

        int zero_idx;
        for(int i=0; i<n; i++){
            if(a[i]==0){
                zero_idx=i;
                break;
            }
        }

        int zr = zero_idx/3;
        int zc = zero_idx%3;

        // swap with left

        if(zc>0){
            for(int i=0; i<n; i++) b[i]=a[i];
            SWAP(b[zr*3+zc],b[zr*3+(zc-1)],t);

            t=get_idx(b,n);

            if(d[t]>d[f]+1){
                d[t]=d[f]+1;
                q.push(t);
            }
        }

        // swap with right

        if(zc<3-1){

            for(int i=0; i<n; i++) b[i]=a[i];
            SWAP(b[zr*3+zc],b[zr*3+(zc+1)],t);

            t=get_idx(b,n);
            if(d[t]>d[f]+1){
                d[t]=d[f]+1;
                q.push(t);
            }
        }

        // swap with up

        if(zr>0){

            for(int i=0; i<n; i++) b[i]=a[i];
            SWAP(b[zr*3+zc],b[(zr-1)*3+zc],t);

            t=get_idx(b,n);
            if(d[t]>d[f]+1){
                d[t]=d[f]+1;
                q.push(t);
            }
        }

        // swap with down

        if(zr<3-1){

            for(int i=0; i<n; i++) b[i]=a[i];
            SWAP(b[zr*3+zc],b[(zr+1)*3+zc],t);

            t=get_idx(b,n);
            if(d[t]>d[f]+1){
                d[t]=d[f]+1;
                q.push(t);
            }
        }
    }

    if(d[tgt_idx]<INF) printf("%d\n",d[tgt_idx]);
    else printf("-1\n");
    return 0;
}