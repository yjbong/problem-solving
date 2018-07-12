#include <cstdio>
#define SWAP(a,b,t) {t=a;a=b;b=t;}
int main(void){
        int n,m,t,c;
        scanf("%d %d %d",&n,&m,&t);
        if(n>m) SWAP(n,m,c);
        for(int i=0; i<=(t%n); i++){
                c=t-i;
                for(int j=c/n; j>=0; j--){
                        if(((c-n*j)%m)==0){
                                printf("%d %d\n",j+((c-n*j)/m),i);
                                goto out;
                        }
                }
        }
        out:
        return 0;
}