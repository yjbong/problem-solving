#include <cstdio>
int a[100000];
int main(void){

    int n,m,b=0;
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    int w=0;
    for(int i=0; i<n; i++){
        w+=a[i];
        if(w>m){
            w=0;
            i--;
            b++;
        }
    }
    if(w>0) b++;
    printf("%d\n",b);
    return 0;
}