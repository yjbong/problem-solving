#include <cstdio>
#define MAX_PRICE 20000/100
int c,n,m;
int price[20];
int pleasure[20];
int d[MAX_PRICE+1];

int main(void){

    scanf("%d",&c);
    while(c--){
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++){
            scanf("%d %d",&price[i],&pleasure[i]);
            price[i]/=100;
        }
        m/=100;

        for(int i=0; i<=m; i++){
            d[i%(MAX_PRICE+1)]=0;
            for(int j=0; j<n; j++)
                if(i>=price[j] && d[i%(MAX_PRICE+1)]<d[(i-price[j])%(MAX_PRICE+1)]+pleasure[j])
                    d[i%(MAX_PRICE+1)]=d[(i-price[j])%(MAX_PRICE+1)]+pleasure[j];
        }
        printf("%d\n",d[m%(MAX_PRICE+1)]);
    }
    return 0;
}