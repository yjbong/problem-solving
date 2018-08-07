#include <cstdio>
#define MAX_K 1000000000
int c,n,m,k;
int cache[111][111];
int count(int longsigs, int shortsigs){

        if(cache[longsigs][shortsigs]>=0) return cache[longsigs][shortsigs];

        if(longsigs==0 && shortsigs==0) return (cache[longsigs][shortsigs]=0);
        else if(longsigs==0) return (cache[longsigs][shortsigs]=1);
        else if(shortsigs==0) return (cache[longsigs][shortsigs]=1);
        else{
                int ret=0;
                ret+=count(longsigs-1, shortsigs);
                ret+=count(longsigs, shortsigs-1);
                if(ret>MAX_K) ret=MAX_K+1;
                return (cache[longsigs][shortsigs]=ret);
        }
}

void morse(int longsigs, int shortsigs, int index){

        if(longsigs==0 && shortsigs==0) return;
        else if(longsigs==0){
                for(int i=0; i<shortsigs; i++) printf("o");
        }
        else if(shortsigs==0){
                for(int i=0; i<longsigs; i++) printf("-");
        }
        else{
                if(index <= count(longsigs-1, shortsigs)){
                        printf("-");
                        morse(longsigs-1, shortsigs, index);
                }
                else{
                        printf("o");
                        morse(longsigs, shortsigs-1, index-count(longsigs-1, shortsigs));
                }
        }
}

int main(void){

        scanf("%d",&c);
        while(c--){
                scanf("%d %d %d",&n,&m,&k);
                for(int i=0; i<=n; i++)
                        for(int j=0; j<=m; j++) cache[i][j]=-1;
                count(n,m);
                morse(n,m,k);
                printf("\n");
        }
        return 0;
}