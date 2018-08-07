#include <cstdio>
int c,n;
int a[555];
int d[555];
int main(void){

    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",&a[i]);

        int ans=1;
        d[0]=1;
        for(int i=1; i<n; i++){
            d[i]=1;
            for(int j=0; j<i; j++)
                if(a[j]<a[i] && d[i]<d[j]+1) d[i]=d[j]+1;
            if(ans<d[i]) ans=d[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}