#include <stdio.h>
long long d[12][10];
long long pw[15];
long long sol[10];
int main(void){

    long long i,j,k;
    long long l,u,dgts,tmp;
    long long lresult,uresult;

    pw[0]=1;
    for(i=1; i<15; i++) pw[i]=pw[i-1]*10;

    scanf("%lld %lld",&l,&u);

    if(u<1) uresult=0;
    else{

        for(i=0; i<12; i++)
            for(j=0; j<10; j++) d[i][j]=0;

        tmp=u,dgts=0;
        while(tmp>0){
            tmp/=10;
            dgts++;
        }
        d[0][0]=0,d[0][u/pw[dgts-1]]=u%pw[dgts-1]+1;
        for(i=1; i<u/pw[dgts-1]; i++) d[0][i]=pw[dgts-1];

        for(i=1,j=dgts-1; i<dgts; i++,j--){
            for(k=0; k<=9; k++){
                if(k==0){
                    d[i][k]=(u/pw[j]-1)*pw[j-1];
                    tmp=u%pw[j]+1;
                    if(tmp>pw[j-1]) tmp=pw[j-1];
                    else if(tmp<0) tmp=0;
                    d[i][k]+=tmp;
                }
                else{
                    d[i][k]=(u/pw[j])*pw[j-1];
                    tmp=u%pw[j]-k*pw[j-1]+1;
                    if(tmp>pw[j-1]) tmp=pw[j-1];
                    else if(tmp<0) tmp=0;
                    d[i][k]+=tmp;
                }
            }
        }
        for(i=0; i<=9; i++) sol[i]=0;
        for(i=0; i<dgts; i++){
            for(j=0; j<=9; j++){
                sol[j]+=d[i][j];
            }
        }

        uresult=0;
        for(i=0; i<=9; i++) uresult+=(sol[i]*i);
    }

//////////////////////////////////////////////////////////////

    l--;

    if(l<1) lresult=0;
    else{

        for(i=0; i<12; i++)
            for(j=0; j<10; j++) d[i][j]=0;
        tmp=l,dgts=0;
        while(tmp>0){
            tmp/=10;
            dgts++;
        }
        d[0][0]=0,d[0][l/pw[dgts-1]]=l%pw[dgts-1]+1;
        for(i=1; i<l/pw[dgts-1]; i++) d[0][i]=pw[dgts-1];

        for(i=1,j=dgts-1; i<dgts; i++,j--){
            for(k=0; k<=9; k++){
                if(k==0){
                    d[i][k]=(l/pw[j]-1)*pw[j-1];
                    tmp=l%pw[j]+1;
                    if(tmp>pw[j-1]) tmp=pw[j-1];
                    else if(tmp<0) tmp=0;
                    d[i][k]+=tmp;
                }
                else{
                    d[i][k]=(l/pw[j])*pw[j-1];
                    tmp=l%pw[j]-k*pw[j-1]+1;
                    if(tmp>pw[j-1]) tmp=pw[j-1];
                    else if(tmp<0) tmp=0;
                    d[i][k]+=tmp;
                }
            }
        }

        for(i=0; i<=9; i++) sol[i]=0;
        for(i=0; i<dgts; i++){
            for(j=0; j<=9; j++){
                sol[j]+=d[i][j];
            }
        }

        lresult=0;
        for(i=0; i<=9; i++) lresult+=(sol[i]*i);
    }

    printf("%lld\n",uresult-lresult);
    return 0;
}