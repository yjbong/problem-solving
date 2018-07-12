#include <stdio.h>

long long facto_num[20];
long long is_ok;

void go(long long cur_num, long long cur_facto_idx){

        long long i;

        if(cur_num==0){
                is_ok=1;
                return;
        }

        else if(cur_num<0) return;

        for(i=cur_facto_idx+1; i<=20; i++){
                go(cur_num-facto_num[i], i);
        }
}

int main(void){

        long long i,n;
        facto_num[0]=1;
        for(i=1; i<=20; i++)
                facto_num[i]=facto_num[i-1]*i;

        scanf("%lld", &n);

        is_ok=0;
        if(n>0) go(n, -1);

        if(is_ok==1) printf("YES\n");
        else printf("NO\n");
        return 0;
}