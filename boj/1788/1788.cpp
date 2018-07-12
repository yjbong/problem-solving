#include <stdio.h>
#define MAXNUMS 1000000
#define DIVNUM 1000000000

typedef struct _fibo_num{

        long long sign;
        long long abs_num;
}FIBO;

FIBO fibo_num[MAXNUMS*2+1];

long long plus_fibo(long long n);
long long minus_fibo(long long n);
int main(void){
        long long i, n;

        plus_fibo(1000000);
        minus_fibo(1000000);

        scanf("%lld", &n);
        printf("%lld\n", fibo_num[n+1000000].sign);
        printf("%lld\n", fibo_num[n+1000000].abs_num);
        return 0;
}

long long plus_fibo(long long n){

        long long i;
        long long a=0, b=1, result;

        for(i=0; i<= n; i++){
                if(i==0){
                        fibo_num[1000000+i].abs_num=0;
                        fibo_num[1000000+i].sign=0;
                        continue;
                }
                else if(i==1){
                        fibo_num[1000000+i].abs_num=1;
                        fibo_num[1000000+i].sign=1;
                }

                result = (a + b)%DIVNUM;
                fibo_num[1000000+i].abs_num=result;
                fibo_num[1000000+i].sign=1;
                b = a;
                a = result;
        }

        return result;
}

long long minus_fibo(long long n){

        long long i;
        long long a=1, b=0, result;
        long long cur_sign;

        for(i = 1; i <= n ; i++){
                result = a - b;
                if(result==0){
                        fibo_num[1000000-i].abs_num=0;
                        fibo_num[1000000-i].sign=0;
                        cur_sign=0;
                }
                else if(result>0){
                        fibo_num[1000000-i].abs_num=result%DIVNUM;
                        fibo_num[1000000-i].sign=1;
                        cur_sign=1;
                }
                else{
                        fibo_num[1000000-i].abs_num=(-result)%DIVNUM;
                        fibo_num[1000000-i].sign=-1;
                        cur_sign=-1;
                }

                if(cur_sign==-1){
                        result= (-result)%DIVNUM;
                        result= -result;
                }
                else result=result%DIVNUM;

                a = b;
                b = result;
        }

        return result;
}