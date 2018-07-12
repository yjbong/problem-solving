#include <stdio.h>

int seq[14][10000];

int base[5][4]={{0,0,0,0},{1,4,2,3},{2,3,1,4},{3,2,4,1},{4,1,3,2}};

int pw[15];
int main(void){

    int i,j,k;
    int n,in,levels,tmp;
    int seed,sw;
    scanf("%d %d",&n,&in);
    levels=0;
    tmp=1;

    pw[0]=1;
    for(i=1; i<15; i++) pw[i]=pw[i-1]*2;

    while(tmp<n){
        tmp*=2;
        levels++;
    }

    if(levels==1){
        if(in==1) printf("1 2\n");
        else if(in==2) printf("2 1\n");
    }

    else if(levels==2){
        for(i=0; i<4; i++)
            printf("%d ", base[in][i]);
        printf("\n");
    }

    else{
        seq[levels][0]=in;
        tmp=levels-1;
        while(1){
            if(tmp==2){
                if(in>pw[tmp]) in-=pw[tmp];

                for(i=0; i<4; i++) seq[tmp][i]=base[in][i];
                break;
            }
            if(in>pw[tmp]) in-=pw[tmp];
            seq[tmp][0]=in;
            tmp--;
        }

        for(i=3; i<=levels; i++){

            if(seq[i][0]>pw[i]/2) sw=0;
            else sw=1;

            for(j=1; j<pw[i]/2; j++){
                seq[i][j]=seq[i-1][j]+sw*(pw[i]/2);
                sw=1-sw;
            }

            for(j=pw[i]/2, k=pw[i]/2-1; j<pw[i]; j++,k--){
                if(seq[i][k]>pw[i]/2) seq[i][j]=seq[i][k]-pw[i]/2;
                else seq[i][j]=seq[i][k]+pw[i]/2;
            }
        }

        for(i=0; i<pw[levels]; i++)
            printf("%d ",seq[levels][i]);
        printf("\n");
    }

    return 0;
}