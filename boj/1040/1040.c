#include <stdio.h>
typedef long long ll;
ll n,k;
int d[20][10][1<<10];
int c[1<<10];

int v[2][1<<10]; int vs[2];

int n_dgt[20];
int n_dgts;

int sol_dgt[20];
int sol_dgts;

int solved;

void go(int dgt_pos, int cur_dgt, int cur_state, int zero_start){

    if(solved) return;

    if(dgt_pos==0){
        sol_dgt[dgt_pos]=cur_dgt;
        int t=cur_state;
        int set_bit=0;
        while(t>0){
            if(t%2) set_bit++;
            t/=2;
        }
        if(set_bit==k) solved=1;
    }

    else{
        sol_dgt[dgt_pos]=cur_dgt;
        int i,j;
        if(zero_start) i=0;
        else i=n_dgt[dgt_pos-1];

        for(; i<10; i++){
            int ok=0;
            for(j=0; j<(1<<10); j++){
                if(d[dgt_pos-1][i][j]){
                    int t=cur_state | j;
                    int set_bit=0;
                    while(t>0){
                        if(t%2) set_bit++;
                        t/=2;
                    }
                    if(set_bit==k) ok=1;
                }
            }

            if(ok && !solved){
                if(zero_start==0 && i==n_dgt[dgt_pos-1])
                    go(dgt_pos-1, i, cur_state | (1<<i), 0);
                else go(dgt_pos-1, i, cur_state | (1<<i), 1);
            }
        }
    }
}

int main(void){

    int i,j,l;
    vs[0]=vs[1]=0;
    for(i=0; i<10; i++){
        d[0][i][1<<i]=1;
        if(!c[1<<i]){
            v[0][vs[0]++]=1<<i;
            c[1<<i]=1;
        }
    }

    for(i=1; i<20; i++){
        int cv=i%2;
        int ov=1-cv;
        for(j=0; j<(1<<10); j++) c[j]=0;
        for(j=0; j<vs[ov]; j++){
            for(l=0; l<10; l++){
                d[i][l][v[ov][j] | (1<<l)] = 1;
                if(!c[v[ov][j] | (1<<l)]){
                    v[cv][vs[cv]++] = (v[ov][j] | (1<<l));
                    c[v[ov][j] | (1<<l)] = 1;
                }
            }
        }
        vs[ov]=0;
    }

    scanf("%lld %lld",&n,&k);

    ll t=n;
    n_dgts=0;

    while(t>0){
        n_dgt[n_dgts]=t%10;
        n_dgts++;
        t/=10;
    }

    solved=0;
    for(i=n_dgt[n_dgts-1]; i<10; i++){
        if(solved) break;
        if(i==n_dgt[n_dgts-1]) go(n_dgts-1, i, 1<<i, 0);
        else go(n_dgts-1, i, 1<<i, 1);
    }

    if(!solved){
        for(i=n_dgts; i<20; i++){
            if(solved) break;
            for(j=1; j<10; j++){
                if(solved) break;
                go(i, j, 1<<j, 1);
            }
        }
    }

    ll sol=0;
    for(i=19; i>=0; i--){
        sol*=10;
        sol+=sol_dgt[i];
    }
    printf("%lld\n",sol);
    return 0;
}