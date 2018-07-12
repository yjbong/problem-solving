#include <cstdio>
typedef long long ll;
int main(void){

    ll n,t,min=-1;
    scanf("%lld %lld",&n,&t);
    while(n--){
        ll st,term,num,bus_num;
        scanf("%lld %lld %lld",&st,&term,&num);
        if(t<st){
            if(min<0 || min>st-t) min=st-t;
        }
        else{
            bus_num=(t-st)/term;
            if((t-st)%term) bus_num++;
            if(bus_num<num)
                if(min<0 || min>st+term*bus_num-t) min=st+term*bus_num-t;
        }
    }
    printf("%lld\n",min);
    return 0;
}