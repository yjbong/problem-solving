#include <cstdio>
#include <algorithm>
using namespace std;
int a[10];
int s[20];
int main(void){

    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    sort(a,a+n);
    bool ok;
    do{
        ok=true;
        for(int i=0; i<n*2; i++) s[i]=-1;
        for(int i=0,j=0; i<2*n && j<n; i++){
            if(s[i]<0){
                s[i]=a[j];
                int p=i+a[j]+1;
                if(p<2*n && s[p]<0){
                    s[p]=a[j];
                    j++;
                }
                else{
                    ok=false;
                    break;
                }
            }
        }
        if(ok){
            for(int i=0; i<2*n; i++) printf("%d ",s[i]);
            printf("\n");
            break;
        }
    }while(next_permutation(a,a+n));
    if(!ok) printf("-1\n");
    return 0;
}