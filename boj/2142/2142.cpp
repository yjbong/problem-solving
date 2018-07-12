#include <stdio.h>
long long a[500][500];
long long diff[500];
int main(void){

        int i,j,k,t,n,m,ok;
        scanf("%d",&t);
        while(t--){
                scanf("%d %d",&n,&m);
                for(i=0; i<n; i++)
                        for(j=0; j<m; j++) scanf("%lld",&a[j][i]);

                ok=1;
                for(i=0; i<m; i++){
                        for(j=i+1; j<m; j++){
                                for(k=0; k<n; k++) diff[k]=a[j][k]-a[i][k];
                                for(k=1; k<n; k++){
                                        if(diff[k]>diff[k-1]){
                                                ok=0;
                                                goto out;
                                        }
                                }
                        }
                }
out:
                if(ok) printf("YES\n");
                else printf("NO\n");

        }
        return 0;
}