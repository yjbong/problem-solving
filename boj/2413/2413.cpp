#include <cstdio>
#define SWAP(a,b,t){t=a;a=b;b=t;}
int a[55555];
int p[55555];
bool c[55555];
int main(void){

    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
        p[a[i]]=i;
    }
    int t;
    for(int i=0; i<n; i++){
        if(a[i]>1 && i<p[a[i]-1]){

            int j=p[a[i]-1];
            if((!c[a[i]]) && (!c[a[j]])){
                c[a[i]]=true;
                c[a[j]]=true;

                SWAP(a[i],a[j],t);
                SWAP(p[a[i]],p[a[j]],t);
            }
        }
    }
    for(int i=0; i<n; i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}