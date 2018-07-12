#include <stdio.h>

long long abs2(long long a){

    if(a>=0) return a;
    else return (-a);
}

long long max2(long long a, long long b){

    if(a>b) return a;
    else return b;
}

long long sol[50][10];
long long len[50][10];
int main(void){

    long long i,j,k;
    long long r1,c1,r2,c2;
    long long group_num,elem_num,tot_num,curlen,maxlen;

    scanf("%lld %lld %lld %lld",&r1,&c1,&r2,&c2);
    maxlen=0;
    for(i=r1; i<=r2; i++){
        for(j=c1; j<=c2; j++){
            group_num=max2(abs2(i),abs2(j));
            if(abs2(i)==group_num && abs2(j)==group_num){
                if(i<=0 && j>=0) elem_num=group_num*2;
                else if(i<=0 && j<=0) elem_num=group_num*2*2;
                else if(i>=0 && j<=0) elem_num=group_num*2*3;
                else if(i>=0 && j>=0) elem_num=group_num*2*4;
            }
            else{
                if(j==group_num) elem_num=group_num-i;
                else if(i==(-group_num)) elem_num=group_num*2+group_num-j;
                else if(j==(-group_num)) elem_num=group_num*2*2+group_num+i;
                else if(i==group_num) elem_num=group_num*2*3+group_num+j;
            }
            tot_num=elem_num+(2*group_num-1)*(2*group_num-1);
            sol[i-r1][j-c1]=tot_num;

            curlen=0;
            while(tot_num>0){
                tot_num/=10;
                curlen++;
            }
            if(curlen==0) curlen=1;
            len[i-r1][j-c1]=curlen;
            if(maxlen<curlen) maxlen=curlen;
        }
    }

    for(i=0; i<=r2-r1; i++){
        for(j=0; j<=c2-c1; j++){
            for(k=0; k<maxlen-len[i][j]; k++) printf(" ");
            printf("%lld",sol[i][j]);
            if(j==c2-c1) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}