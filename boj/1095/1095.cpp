#include <cstdio>

int s,f,m;
bool sieve[111111];
int prime[10000]; int primes;
int factor[10000];

void make_prime_table(){

        sieve[0]=sieve[1]=true;
        for(int i=2; i<=333; i++)
                if(sieve[i]==false)
                        for(int j=i*i; j<=100000; j+=i) sieve[j]=true;

        primes=0;
        for(int i=0; i<=100000; i++){
                if(sieve[i]==false) prime[primes++]=i;
        }

        for(int i=0; i<primes; i++) factor[i]=0;
}

int main(void){

        make_prime_table();
        scanf("%d %d %d",&s,&f,&m); // (s+f)C(s)

        for(int i=0; i<primes; i++){
                int t=s+f;
                while( (t=t/prime[i])>0){
                        factor[i] += t;
                }
        }
        for(int i=0; i<primes; i++){
                int t=s;
                while( (t=t/prime[i])>0){
                        factor[i] -= t;
                }
        }
        for(int i=0; i<primes; i++){
                int t=f;
                while( (t=t/prime[i])>0){
                        factor[i] -= t;
                }
        }

        int ans=1;
        for(int i=m; i>=2; i--){
                int t=i;
                int j;
                for(j=0; j<primes; j++){
                        int k=0;
                        while(t%prime[j]==0){ t/=prime[j]; k++; }
                        if(k>factor[j]) break;
                }
                if(j==primes){
                        ans=i;
                        break;
                }
        }
        printf("%d\n",ans);
        return 0;
}