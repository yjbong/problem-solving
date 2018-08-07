#include <cstdio>
#define MAX 20000
#define MIN 0
int c,n,q;
int max_ht[262144];
int min_ht[262144];
int base;
int max2(int a, int b){
        return a>b?a:b;
}
int min2(int a, int b){
        return a<b?a:b;
}
int get_max(int s, int e){
        int ret=MIN-1;
        s+=base; e+=base;
        while(s<e){
                if(s%2==0) s/=2;
                else{
                        ret=max2(ret,max_ht[s]);
                        s=(s+1)/2;
                }

                if(e%2==1) e/=2;
                else{
                        ret=max2(ret,max_ht[e]);
                        e=(e-1)/2;
                }
        }
        if(s==e) ret=max2(ret,max_ht[s]);
        return ret;
}
int get_min(int s, int e){
        int ret=MAX+1;
        s+=base; e+=base;
        while(s<e){
                if(s%2==0) s/=2;
                else{
                        ret=min2(ret,min_ht[s]);
                        s=(s+1)/2;
                }

                if(e%2==1) e/=2;
                else{
                        ret=min2(ret,min_ht[e]);
                        e=(e-1)/2;
                }
        }
        if(s==e) ret=min2(ret,min_ht[s]);
        return ret;
}

int main(void){
        scanf("%d",&c);
        while(c--){
                scanf("%d %d",&n,&q);
                base=1;
                while(base<n) base*=2;
                for(int i=base; i<base+n; i++){
                        int tmp;
                        scanf("%d",&tmp);
                        max_ht[i]=min_ht[i]=tmp;
                }
                for(int i=base+n; i<base*2; i++){
                        max_ht[i]=MIN-1;
                        min_ht[i]=MAX+1;
                }

                for(int i=base-1; i>=1; i--){
                        max_ht[i]=max2(max_ht[i*2],max_ht[i*2+1]);
                        min_ht[i]=min2(min_ht[i*2],min_ht[i*2+1]);
                }

                for(int i=0; i<q; i++){
                        int s,e;
                        scanf("%d %d",&s,&e);
                        printf("%d\n",get_max(s,e)-get_min(s,e));
                }
        }
        return 0;
}