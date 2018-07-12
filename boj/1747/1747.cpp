#include <cstdio>
bool p[1111111];
int n;
bool is_pal(int a){
    int dgt[10];
    int dgts=0;
    while(a>0){
        dgt[dgts++]=a%10;
        a/=10;
    }
    for(int i=0; i<=(dgts-1)/2; i++)
        if(dgt[i]!=dgt[dgts-1-i]) return false;

    return true;
}
int main(void){
    scanf("%d",&n);
    p[0]=p[1]=true;
    for(int i=0; i<1111111; i++){
        if(!p[i]){
            for(int j=p[i]*2; j<1111111; j+=i) p[j]=true;
            if(is_pal(i) && n<=i){
                printf("%d\n",i);
                goto out;
            }
        }
    }
    out:
    return 0;
}