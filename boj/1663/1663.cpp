#include <stdio.h>

long long len[101];
long long xs[101],ys[101],zs[101];
int main(void){

    long long i,n,curn,op;
    long long k,curk;
    char c;
    len[1]=1,len[2]=2,len[3]=2;
    xs[1]=1,ys[1]=0,zs[1]=0;
    xs[2]=0,ys[2]=1,zs[2]=1;
    xs[3]=1,ys[3]=0,zs[3]=1;

    for(i=4; i<=100; i++){
        len[i]=len[i-2]+len[i-3];
        xs[i]=xs[i-2]+xs[i-3];
        ys[i]=ys[i-2]+ys[i-3];
        zs[i]=zs[i-2]+zs[i-3];
    }

    scanf("%lld", &op);

    if(op==1){
        scanf("%lld", &n);
        printf("%lld\n", len[n]);
    }
    else if(op==2){
        scanf("%lld", &n);
        scanf("%lld", &k);
        curk=k;
        curn=n;
        while(1){
            if(curn<=3){
                if(curn==1){
                    printf("X\n");
                }
                else if(curn==2){
                    if(curk==1) printf("Y\n");
                    else if(curk==2) printf("Z\n");
                }
                else if(curn==3){
                    if(curk==1) printf("Z\n");
                    else if(curk==2) printf("X\n");
                }
                break;
            }
            else{
                if(curk>len[curn-3]){
                    curk-=len[curn-3];
                    curn=curn-2;
                }
                else{
                    curn=curn-3;
                }
            }
        }
    }
    else if(op==3){
        scanf("%lld\n", &n);
        scanf("%c", &c);
        if(c=='X') printf("%lld\n", xs[n]);
        else if(c=='Y') printf("%lld\n", ys[n]);
        else if(c=='Z') printf("%lld\n", zs[n]);
    }

    return 0;
}