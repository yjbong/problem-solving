#include <cstdio>
#include <queue>
#define INF 1000000000
#define SWAP(a,b,t){t=a;a=b;b=t;}
using namespace std;

int a[10];
int b[10];

int n,k;

int fac[10];
int d[8*7*6*5*4*3*2*1];

queue <int> q;

void rev(int *s, int st, int ed){
    int t;
    for(int i=st; i<=st+(ed-st)/2; i++) SWAP(s[i],s[ed-i+st],t);
}

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

    int t;
    scanf("%d %d",&n,&k);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
        a[i]--;
    }

    fac[0]=1;
    for(int i=1; i<=n; i++) fac[i]=fac[i-1]*i;
    for(int i=0; i<fac[n]; i++) d[i]=INF;

    for(int i=0; i<n; i++) b[i]=i;
    int tgt_idx = get_idx(b,n);
    int st_idx = get_idx(a,n);

    d[st_idx]=0;
    q.push(st_idx);

    while(!q.empty()){
        int f=q.front();
        q.pop();
        get_seq(f,a,n);

        for(int i=0; i+k-1<n; i++){
            for(int j=0; j<n; j++) b[j]=a[j];
            rev(b,i,i+k-1);
            int cur_idx=get_idx(b,n);
            if(d[cur_idx]>d[f]+1){
                d[cur_idx]=d[f]+1;
                q.push(cur_idx);
            }
        }
    }

    if(d[tgt_idx]<INF) printf("%d\n",d[tgt_idx]);
    else printf("-1\n");
    return 0;
}