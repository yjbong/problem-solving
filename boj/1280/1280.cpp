#include <cstdio>
#include <cassert>
#define MOD 1000000007ll
typedef long long ll;
ll a[222222];
ll sum_ft[1<<19]; // fenwick tree
ll num_ft[1<<19];

void update_ft(int idx){

        int t=idx;
        t += (1<<18);
        sum_ft[t] += idx;
        num_ft[t] += 1;

        t/=2;
        while(t>0){
                sum_ft[t] = sum_ft[t*2]+sum_ft[t*2+1];
                num_ft[t] = num_ft[t*2]+num_ft[t*2+1];
                t/=2;
        }
}

ll calc_sum(int l, int r){

        l += (1<<18);
        r += (1<<18);

        ll sum=0;
        while(l<r){
                if(l%2==0) l/=2;
                else{
                        sum += sum_ft[l];
                        l=(l+1)/2;
                }

                if(r%2==1) r/=2;
                else{
                        sum += sum_ft[r];
                        r=(r-1)/2;
                }
        }
        if(l==r) sum += sum_ft[l];

        return sum;
}

ll calc_num(int l, int r){

        l += (1<<18);
        r += (1<<18);

        ll num=0;
        while(l<r){
                if(l%2==0) l/=2;
                else{
                        num += num_ft[l];
                        l=(l+1)/2;
                }

                if(r%2==1) r/=2;
                else{
                        num += num_ft[r];
                        r=(r-1)/2;
                }
        }
        if(l==r) num += num_ft[l];

        return num;
}

int main(void){

        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++){
                scanf("%lld",&a[i]);
                assert(a[i]>=0);
        }

        ll sol;
        if(n<=1) sol=0;
        else{
                sol=1;
                for(int i=0; i<n; i++){
                        if(i>0){
                                ll dst_sum=0;
                                dst_sum = (dst_sum + (a[i]*calc_num(0,a[i]-1) - calc_sum(0,a[i]-1))) % MOD;
                                dst_sum = (dst_sum + calc_sum(a[i]+1,(1<<18)-1) - a[i]*calc_num(a[i]+1,(1<<18)-1)) % MOD;

                                sol = (sol*dst_sum)%MOD;
                        }
                        update_ft(a[i]);
                }
        }

        printf("%lld\n",sol);
        return 0;
}