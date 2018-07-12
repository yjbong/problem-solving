#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){

    if(*((int*)a)>*((int*)b)) return 1;
    else return 0;
}

int c[50],b[10000];
int load[50];
int main(void){

    int i,j,cs,bs,start;
    int ch,sum,sol;
    scanf("%d",&cs);
    for(i=0; i<cs; i++) scanf("%d",&c[i]);
    scanf("%d",&bs);
    for(i=0; i<bs; i++) scanf("%d",&b[i]);

    qsort(c,cs,sizeof(int),cmp);
    qsort(b,bs,sizeof(int),cmp);

    if(c[cs-1]<b[bs-1]) printf("-1\n");
    else{

        for(i=0; i<cs; i++) load[i]=0;
        start=0;
        for(i=0; i<cs; i++){
            for(j=start; j<bs; j++){
                if(b[j]<=c[i]) load[i]++;
                else{
                    start=j;
                    break;
                }
            }
            if(j>=bs) break;
        }

        do{
            ch=0;
            for(i=1; i<cs; i++){
                if(c[i-1]<c[i]){
                    if(load[i-1]>load[i]){
                        sum=load[i-1]+load[i];
                        load[i-1]=sum/2;
                        load[i]=sum-sum/2;
                        ch=1;
                    }
                }
                else if(c[i-1]==c[i]){

                    if(load[i-1]>load[i] || load[i]>load[i-1]+1){
                        sum=load[i-1]+load[i];
                        load[i-1]=sum/2;
                        load[i]=sum-sum/2;
                        ch=1;
                    }
                }
            }
        }while(ch);

        sol=load[0];
        for(i=1; i<cs; i++) if(sol<load[i]) sol=load[i];
        printf("%d\n",sol);
    }
    return 0;
}