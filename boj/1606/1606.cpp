#include <cstdio>
long long max2(long long a, long long b){
    if(a>b) return a;
    else return b;
}
long long abs2(long long n){
    if(n<0) return (-n);
    else return n;
}
int main(void){

    long long x,y,g;
    scanf("%lld %lld",&x,&y);
    if(x>=0 && y>=0) g=x+y;
    else if(x<0 && y>=0) g=max2(abs2(x),abs2(y));
    else if(x<0 && y<0) g=abs2(x)+abs2(y);
    else if(x>=0 && y<0) g=max2(abs2(x),abs2(y));

    if(g==0) printf("1\n");
    else{
        long long s;
        if(x==g && y==0) s=1+6*g*(g+1)/2;
        else{
            s=1+6*(g-1)*g/2;
            if(x>=0 && y>=0) s+=y;
            else if(x<0 && y>=0){
                if(abs2(x)<=abs2(y)){
                    s+=g;
                    s+=abs2(x);
                }
                else{
                    s+=2*g;
                    s+=(g-abs2(y));
                }
            }
            else if(x<0 && y<0){
                s+=3*g;
                s+=abs2(y);
            }
            else if(x>=0 && y<0){
                if(abs2(x)<=abs2(y)){
                    s+=4*g;
                    s+=abs2(x);
                }
                else{
                    s+=5*g;
                    s+=(g-abs2(y));
                }
            }
        }
        printf("%lld\n",s);
    }
    return 0;
}