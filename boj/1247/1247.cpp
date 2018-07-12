#include <stdio.h>
#define BIG 1000000000000000000ll
long long plus_num[2];
long long minus_num[2];

long long abs2(long long n){

    if(n<0) return (-n);
    else return n;
}

int main(void){

    int cases,n;
    int sign;
    long long cur_num;

    cases=3;
    while(cases--){

        plus_num[0]=plus_num[1]=0;
        minus_num[0]=minus_num[1]=0;
        scanf("%d", &n);
        while(n--){
            scanf("%lld", &cur_num);
            if(cur_num>=0){
                plus_num[1]+=cur_num/BIG;
                plus_num[0]+=cur_num%BIG;
                if(plus_num[0]>=BIG){
                    plus_num[1]+=plus_num[0]/BIG;
                    plus_num[0]%=BIG;
                }
            }
            else{
                cur_num=abs2(cur_num);
                minus_num[1]+=cur_num/BIG;
                minus_num[0]+=cur_num%BIG;
                if(minus_num[0]>=BIG){
                    minus_num[1]+=minus_num[0]/BIG;
                    minus_num[0]%=BIG;
                }
            }
        }

        if(plus_num[1]>minus_num[1]) sign=1;
        else if(plus_num[1]<minus_num[1]) sign=-1;
        else{
            if(plus_num[0]>minus_num[0]) sign=1;
            else if(plus_num[0]<minus_num[0]) sign=-1;
            else sign=0;
        }

        if(sign==-1) printf("-\n");
        if(sign==0) printf("0\n");
        if(sign==1) printf("+\n");
    }

    return 0;
}