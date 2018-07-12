#include <stdio.h>
int main(void){

    long long i;
    long long n,k,l,r,m,tmp;
    long long m_end_idx, m_start_idx;

    scanf("%lld %lld", &n, &k);
    l=1, r=n*n;

    while(l<=r){
        m=(l+r)/2;
        m_end_idx=0;
        for(i=1; i<=n; i++){
            if(m/i>n) m_end_idx+=n;
            else m_end_idx+=(m/i);
        }

        if(m==1) m_start_idx=1;
        else{
            tmp=m-1;
            m_start_idx=0;
            for(i=1; i<=n; i++){
                if(tmp/i>n) m_start_idx+=n;
                else m_start_idx+=(tmp/i);
            }
            m_start_idx=m_start_idx+1;
        }

        if(k>=m_start_idx && k<=m_end_idx){
            printf("%lld\n", m);
            break;
        }
        else if(k<m_start_idx){
            r=m-1;
        }
        else if(k>m_end_idx){
            l=m+1;
        }
    }

    return 0;
}