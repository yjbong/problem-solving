#include <cstdio>
int main(void){

    int t;
    scanf("%d",&t);
    while(t--){
        long long p;
        scanf("%lld",&p);

        int sol=0;
        while(p>0){
            int c=p%100;
            int csol=c/10+c%10;

            int i=1;
            while(c-25*i>=0){
                int ccsol=i+(c-25*i)/10+(c-25*i)%10;
                if(csol>ccsol) csol=ccsol;
                i++;
            }
            sol+=csol;
            p/=100;
        }
        printf("%d\n",sol);
    }
    return 0;
}