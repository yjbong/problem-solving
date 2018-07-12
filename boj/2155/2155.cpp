#include <stdio.h>
#include <math.h>
#define SWAP(a,b,tmp){tmp=a;a=b;b=tmp;}

int main(void){

        long long a,b,tmp;
        long long  a_groupn, a_elen, b_groupn, b_elen;
        double tmp2;
        long long floor_sqr;
        long long tmp3;

        long long range_start, range_end;
        long long length;

        scanf("%lld %lld", &a, &b);

        if(a==1) a_groupn=1, a_elen=1;
        else{
                tmp2=sqrt(a);
                if(tmp2==(long long)(sqrt(a))) floor_sqr=(long long)(sqrt(a));
                else floor_sqr=(long long)(sqrt(a))+1;

                a_groupn=2*floor_sqr-2;
                tmp3=a-(floor_sqr-1)*(floor_sqr-1);

                if(tmp3%2==1){
                        a_groupn++;
                        a_elen=tmp3/2+1;
                }
                else{
                        a_elen=tmp3/2;
                }
        }

        if(b==1) b_groupn=1, b_elen=1;
        else{
                tmp2=sqrt(b);
                if(tmp2==(long long)(sqrt(b))) floor_sqr=(long long)(sqrt(b));
                else floor_sqr=(long long)(sqrt(b))+1;

                b_groupn=2*floor_sqr-2;
                tmp3=b-(floor_sqr-1)*(floor_sqr-1);

                if(tmp3%2==1){
                        b_groupn++;
                        b_elen=tmp3/2+1;
                }
                else{
                        b_elen=tmp3/2;
                }
        }

        if((a_groupn>b_groupn) || ((a_groupn==b_groupn) && (a_elen>b_elen))){
                SWAP(a_groupn, b_groupn, tmp);
                SWAP(a_elen, b_elen, tmp);
        }

        if(a_groupn==b_groupn) range_start=range_end=a_elen;
        else{
                range_start=a_elen;
                if(a_groupn%2==0)
                        range_end=range_start+(b_groupn-a_groupn)/2+(b_groupn-a_groupn)%2;
                else
                        range_end=range_start+(b_groupn-a_groupn)/2;
        }

        if(b_elen>=range_start && b_elen<=range_end) length=b_groupn-a_groupn;
        else if(b_elen<range_start) length=b_groupn-a_groupn+(range_start-b_elen)*2;
        else if(b_elen>range_end) length=b_groupn-a_groupn+(b_elen-range_end)*2;

        printf("%lld\n", length);
        return 0;
}