#include <cstdio>
int c,n;
int a[111][111];
int cache[111][111];
int go(int i,int j){
        if(i==n-1 && j==n-1) return 1;
        else if(i<0 || i>=n || j<0 || j>=n) return 0;
        else if(cache[i][j]>=0) return cache[i][j];
        else{
                int ret=0;
                if(go(i,j+a[i][j])==1) ret=1;
                if(go(i+a[i][j],j)==1) ret=1;
                return (cache[i][j]=ret);
        }
}

int main(void){

        scanf("%d",&c);
        while(c--){
                scanf("%d",&n);
                for(int i=0; i<n; i++){
                        for(int j=0; j<n; j++){
                                scanf("%d",&a[i][j]);
                                cache[i][j]=-1;
                        }
                }
                if(go(0,0)==1) printf("YES\n");
                else printf("NO\n");
        }
        return 0;
}