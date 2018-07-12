#include <cstdio>
#include <algorithm>
using namespace std;
int a[50];
int b[50];
int c[50];
bool use[50];
bool ok;
int abs2(int n){
    if(n<0) return (-n);
    else return n;
}
int main(void){

    int i,j,k,n;
    scanf("%d",&n);
    for(i=0; i<n; i++) scanf("%d",&a[i]);
    sort(a,a+n);

    for(i=1000; i>=0; i--){
        ok=true;
        for(j=0; j<n; j++) use[j]=false;
        b[0]=a[0];
        use[0]=true;
        for(j=n-1; j>=1; j--){
            for(k=n-1; k>=1; k--){
                if(use[k]==false){
                    if(j==n-1){
                        if(abs2(b[0]-a[k])<=i) break;
                    }
                    else if(j==1){
                        if(abs2(b[2]-a[k])<=i && abs2(b[0]-a[k])<=i) break;
                    }
                    else{
                        if(abs2(b[j+1]-a[k])<=i) break;
                    }
                }
            }
            if(k>=1){
                b[j]=a[k];
                use[k]=true;
            }
            else{
                ok=false;
                break;
            }
        }
        if(ok){
            //printf("%d\n",i);
            for(j=0; j<n; j++) c[j]=b[j];
        }
    }

    for(i=0; i<n; i++) printf("%d ",c[i]);
    printf("\n");
    return 0;
}