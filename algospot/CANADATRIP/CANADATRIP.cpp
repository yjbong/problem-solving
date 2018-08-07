#include <cstdio>
int t,n,k;
int l[5000];
int m[5000];
int g[5000];

int signs(int pos){
        int ret=0;
        for(int i=0; i<n; i++){
                int from_m_pos=pos-(l[i]-m[i]);
                if(from_m_pos>=0){
                        if(from_m_pos>m[i]) from_m_pos=m[i];
                        ret += (from_m_pos/g[i])+1;
                }
        }
        return ret;
}

int main(void){

        scanf("%d",&t);
        while(t--){
                scanf("%d %d",&n,&k);
                for(int i=0; i<n; i++) scanf("%d %d %d",&l[i],&m[i],&g[i]);
                int left=0, right=8030000;
                int ans=right+1;
                while(left<=right){
                        int mid=(left+right)/2;
                        int cur_signs=signs(mid);
                        if(cur_signs<k) left=mid+1;
                        else{
                                if(ans>mid) ans=mid;
                                right=mid-1;
                        }
                }
                printf("%d\n",ans);
        }
        return 0;
}