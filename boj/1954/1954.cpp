#include <cstdio>

int n;
int a[100];
int b[100];
int m;
int main(void){

    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d %d",&a[i],&b[i]);
    scanf("%d",&m);

    int max=0;
    for(int i=0; i<n; i++)
        if(max < a[i]*m+b[i]) max = a[i]*m+b[i];

    int sol=0;
    for(int i=0; i<=max; i++){
        int cur_m=m;
        bool ok=true;
        for(int j=0; j<n; j++){
            if(i<b[j]){
                ok=false;
                break;
            }
            int x=(i-b[j])/a[j];
            if(a[j]*x+b[j]!=i){
                ok=false;
                break;
            }
            cur_m-=x;
        }
        if(ok && cur_m==0){
            sol=i;
            break;
        }
    }
    printf("%d\n",sol);
    return 0;
}