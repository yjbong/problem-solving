#include <stdio.h>

int main(void){

        int g,i,j,n,a;
        int c[10];
        int sol,cur,tmp,ok;

        for(i=0; i<10; i++) c[i]=1;
        scanf("%d", &g);
        scanf("%d", &n);
        for(i=0; i<n; i++){
                scanf("%d", &a);
                c[a]=0;
        }
        sol=g-100;
        if(sol<0) sol=-sol;
        for(i=0; i<1000000; i++){

                ok=1;
                tmp=i;
                if(tmp==0){
                        j=1;
                        if(c[0]==0){
                                ok=0;
                        }
                        if(ok==1){
                                cur=g-i;
                                if(cur<0) cur=-cur;
                                cur+=j;
                                if(sol>cur) sol=cur;
                        }
                }

                else{
                        j=0;
                        while(tmp>0){
                                if(c[tmp%10]==0){
                                        ok=0;
                                        break;
                                }
                                tmp/=10;
                                j++;
                        }

                        if(ok==1){
                                cur=g-i;
                                if(cur<0) cur=-cur;
                                cur+=j;
                                if(sol>cur) sol=cur;
                        }
                }
        }
        printf("%d\n", sol);
        return 0;
}