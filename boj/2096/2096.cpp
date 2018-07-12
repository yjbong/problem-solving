#include <cstdio>
int a[3];
int mn[3];
int mx[3];
int t[3];
int min2(int a, int b){
    if(a<b) return a;
    else return b;
}
int max2(int a, int b){
    if(a>b) return a;
    else return b;
}
int main(void){

    int n;
    bool first=true;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++) scanf("%d",&a[j]);
        if(first){
            mn[0]=a[0],mn[1]=a[1],mn[2]=a[2];
            mx[0]=a[0],mx[1]=a[1],mx[2]=a[2];
            first=false;
        }
        else{
            t[0]=min2(mn[0],mn[1])+a[0];
            t[1]=min2(min2(mn[0],mn[1]),mn[2])+a[1];
            t[2]=min2(mn[1],mn[2])+a[2];
            mn[0]=t[0],mn[1]=t[1],mn[2]=t[2];

            t[0]=max2(mx[0],mx[1])+a[0];
            t[1]=max2(max2(mx[0],mx[1]),mx[2])+a[1];
            t[2]=max2(mx[1],mx[2])+a[2];
            mx[0]=t[0],mx[1]=t[1],mx[2]=t[2];
        }
    }
    int smax=max2(max2(mx[0],mx[1]),mx[2]);
    int smin=min2(min2(mn[0],mn[1]),mn[2]);

    printf("%d %d\n",smax,smin);
    return 0;
}